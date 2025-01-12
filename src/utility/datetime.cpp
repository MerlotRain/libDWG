/**
 * libDWG - A C++ library for reading and writing DWG and DXF files in CAD.
 *
 * This file is part of libDWG.
 *
 * libDWG is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * libDWG is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * For more information, visit the project's homepage or contact the author.
 */

#include <Poco/Format.h>
#include <assert.h>
#include <chrono>
#include <cstring>
#include <ctime>
#include <dwg/utility/datetime.h>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numeric>
#include <sstream>
#include <stdexcept>
#include <string>

#ifdef _WIN32
#include <Windows.h>
#endif


const Timestamp::TimeVal Timestamp::TIMEVAL_MIN =
        std::numeric_limits<Timestamp::TimeVal>::min();
const Timestamp::TimeVal Timestamp::TIMEVAL_MAX =
        std::numeric_limits<Timestamp::TimeVal>::max();

Timestamp::Timestamp() { update(); }

Timestamp::Timestamp(TimeVal tv) { _ts = tv; }

Timestamp::Timestamp(const Timestamp &other) { _ts = other._ts; }

Timestamp::~Timestamp() {}

Timestamp &Timestamp::operator=(const Timestamp &other)
{
    _ts = other._ts;
    return *this;
}

Timestamp &Timestamp::operator=(TimeVal tv)
{
    _ts = tv;
    return *this;
}

void Timestamp::swap(Timestamp &timestamp) noexcept
{
    std::swap(_ts, timestamp._ts);
}

Timestamp Timestamp::fromEpochTime(std::time_t t)
{
    return Timestamp(TimeVal(t) * resolution());
}

Timestamp Timestamp::fromUtcTime(UtcTimeVal val)
{
    val -= (TimeDiff(0x01b21dd2) << 32) + 0x13814000;
    val /= 10;
    return Timestamp(val);
}

void Timestamp::update()
{
#ifdef _WIN32

    FILETIME ft;
    GetSystemTimeAsFileTime(&ft);

    ULARGE_INTEGER
            epoch;// UNIX epoch (1970-01-01 00:00:00) expressed in Windows NT FILETIME
    epoch.LowPart = 0xD53E8000;
    epoch.HighPart = 0x019DB1DE;

    ULARGE_INTEGER ts;
    ts.LowPart = ft.dwLowDateTime;
    ts.HighPart = ft.dwHighDateTime;
    ts.QuadPart -= epoch.QuadPart;
    _ts = ts.QuadPart / 10;

#else
    struct timespec ts;
    if (clock_gettime(CLOCK_REALTIME, &ts))
        throw SystemException("cannot get time of day");
    _ts = TimeVal(ts.tv_sec) * resolution() + ts.tv_nsec / 1000;
#endif
}

Timestamp Timestamp::operator+(const Timespan &span) const
{
    return *this + span.totalMicroseconds();
}

Timestamp Timestamp::operator-(const Timespan &span) const
{
    return *this - span.totalMicroseconds();
}

Timestamp &Timestamp::operator+=(const Timespan &span)
{
    return *this += span.totalMicroseconds();
}

Timestamp &Timestamp::operator-=(const Timespan &span)
{
    return *this -= span.totalMicroseconds();
}

inline bool Timestamp::operator==(const Timestamp &ts) const
{
    return _ts == ts._ts;
}

inline bool Timestamp::operator!=(const Timestamp &ts) const
{
    return _ts != ts._ts;
}

inline bool Timestamp::operator>(const Timestamp &ts) const
{
    return _ts > ts._ts;
}

inline bool Timestamp::operator>=(const Timestamp &ts) const
{
    return _ts >= ts._ts;
}

inline bool Timestamp::operator<(const Timestamp &ts) const
{
    return _ts < ts._ts;
}

inline bool Timestamp::operator<=(const Timestamp &ts) const
{
    return _ts <= ts._ts;
}

inline Timestamp Timestamp::operator+(Timestamp::TimeDiff d) const
{
    return Timestamp(_ts + d);
}

inline Timestamp Timestamp::operator-(Timestamp::TimeDiff d) const
{
    return Timestamp(_ts - d);
}

inline Timestamp::TimeDiff Timestamp::operator-(const Timestamp &ts) const
{
    return _ts - ts._ts;
}

inline Timestamp &Timestamp::operator+=(Timestamp::TimeDiff d)
{
    _ts += d;
    return *this;
}

inline Timestamp &Timestamp::operator-=(Timestamp::TimeDiff d)
{
    _ts -= d;
    return *this;
}

inline std::time_t Timestamp::epochTime() const
{
    return std::time_t(_ts / resolution());
}

inline Timestamp::UtcTimeVal Timestamp::utcTime() const
{
    return _ts * 10 + (TimeDiff(0x01b21dd2) << 32) + 0x13814000;
}

inline Timestamp::TimeVal Timestamp::epochMicroseconds() const { return _ts; }

inline Timestamp::TimeDiff Timestamp::elapsed() const
{
    Timestamp now;
    return now - *this;
}

inline bool Timestamp::isElapsed(Timestamp::TimeDiff interval) const
{
    Timestamp now;
    Timestamp::TimeDiff diff = now - *this;
    return diff >= interval;
}

inline constexpr Timestamp::TimeDiff Timestamp::resolution() { return 1000000; }

inline void swap(Timestamp &s1, Timestamp &s2) noexcept { s1.swap(s2); }

inline Timestamp::TimeVal Timestamp::raw() const { return _ts; }

#if defined(_WIN32)

Timestamp Timestamp::fromFileTimeNP(std::uint32_t fileTimeLow,
                                    std::uint32_t fileTimeHigh)
{
    ULARGE_INTEGER
            epoch;// UNIX epoch (1970-01-01 00:00:00) expressed in Windows NT FILETIME
    epoch.LowPart = 0xD53E8000;
    epoch.HighPart = 0x019DB1DE;

    ULARGE_INTEGER ts;
    ts.LowPart = fileTimeLow;
    ts.HighPart = fileTimeHigh;
    ts.QuadPart -= epoch.QuadPart;

    return Timestamp(ts.QuadPart / 10);
}

void Timestamp::toFileTimeNP(std::uint32_t &fileTimeLow,
                             std::uint32_t &fileTimeHigh) const
{
    ULARGE_INTEGER
            epoch;// UNIX epoch (1970-01-01 00:00:00) expressed in Windows NT FILETIME
    epoch.LowPart = 0xD53E8000;
    epoch.HighPart = 0x019DB1DE;

    ULARGE_INTEGER ts;
    ts.QuadPart = _ts * 10;
    ts.QuadPart += epoch.QuadPart;
    fileTimeLow = ts.LowPart;
    fileTimeHigh = ts.HighPart;
}
#endif


const Timespan::TimeDiff Timespan::MILLISECONDS = 1000;
const Timespan::TimeDiff Timespan::SECONDS = 1000 * Timespan::MILLISECONDS;
const Timespan::TimeDiff Timespan::MINUTES = 60 * Timespan::SECONDS;
const Timespan::TimeDiff Timespan::HOURS = 60 * Timespan::MINUTES;
const Timespan::TimeDiff Timespan::DAYS = 24 * Timespan::HOURS;

Timespan::Timespan() : _span(0) {}

Timespan::Timespan(TimeDiff microSeconds) : _span(microSeconds) {}

Timespan::Timespan(long seconds, long microSeconds)
    : _span(TimeDiff(seconds) * SECONDS + microSeconds)
{
}

Timespan::Timespan(int days, int hours, int minutes, int seconds,
                   int microSeconds)
    : _span(TimeDiff(microSeconds) + TimeDiff(seconds) * SECONDS +
            TimeDiff(minutes) * MINUTES + TimeDiff(hours) * HOURS +
            TimeDiff(days) * DAYS)
{
}

Timespan::Timespan(const Timespan &timespan) : _span(timespan._span) {}

inline Timespan::~Timespan() {}

Timespan &Timespan::operator=(const Timespan &timespan)
{
    _span = timespan._span;
    return *this;
}

Timespan &Timespan::operator=(TimeDiff microSeconds)
{
    _span = microSeconds;
    return *this;
}

inline int Timespan::days() const { return int(_span / DAYS); }

inline int Timespan::hours() const { return int((_span / HOURS) % 24); }

inline int Timespan::totalHours() const { return int(_span / HOURS); }

inline int Timespan::minutes() const { return int((_span / MINUTES) % 60); }

inline int Timespan::totalMinutes() const { return int(_span / MINUTES); }

inline int Timespan::seconds() const { return int((_span / SECONDS) % 60); }

inline int Timespan::totalSeconds() const { return int(_span / SECONDS); }

inline int Timespan::milliseconds() const
{
    return int((_span / MILLISECONDS) % 1000);
}

inline Timespan::TimeDiff Timespan::totalMilliseconds() const
{
    return _span / MILLISECONDS;
}

inline int Timespan::microseconds() const { return int(_span % 1000); }

inline int Timespan::useconds() const { return int(_span % 1000000); }

inline Timespan::TimeDiff Timespan::totalMicroseconds() const { return _span; }

inline bool Timespan::operator==(const Timespan &ts) const
{
    return _span == ts._span;
}

inline bool Timespan::operator!=(const Timespan &ts) const
{
    return _span != ts._span;
}

inline bool Timespan::operator>(const Timespan &ts) const
{
    return _span > ts._span;
}

inline bool Timespan::operator>=(const Timespan &ts) const
{
    return _span >= ts._span;
}

inline bool Timespan::operator<(const Timespan &ts) const
{
    return _span < ts._span;
}

inline bool Timespan::operator<=(const Timespan &ts) const
{
    return _span <= ts._span;
}

inline bool Timespan::operator==(TimeDiff microSeconds) const
{
    return _span == microSeconds;
}

inline bool Timespan::operator!=(TimeDiff microSeconds) const
{
    return _span != microSeconds;
}

inline bool Timespan::operator>(TimeDiff microSeconds) const
{
    return _span > microSeconds;
}

inline bool Timespan::operator>=(TimeDiff microSeconds) const
{
    return _span >= microSeconds;
}

inline bool Timespan::operator<(TimeDiff microSeconds) const
{
    return _span < microSeconds;
}

inline bool Timespan::operator<=(TimeDiff microSeconds) const
{
    return _span <= microSeconds;
}

inline void swap(Timespan &s1, Timespan &s2) noexcept { s1.swap(s2); }

Timespan &Timespan::assign(int days, int hours, int minutes, int seconds,
                           int microSeconds)
{
    _span = TimeDiff(microSeconds) + TimeDiff(seconds) * SECONDS +
            TimeDiff(minutes) * MINUTES + TimeDiff(hours) * HOURS +
            TimeDiff(days) * DAYS;
    return *this;
}

Timespan &Timespan::assign(long seconds, long microSeconds)
{
    _span = TimeDiff(seconds) * SECONDS + TimeDiff(microSeconds);
    return *this;
}

void Timespan::swap(Timespan &timespan) noexcept
{
    std::swap(_span, timespan._span);
}

Timespan Timespan::operator+(const Timespan &d) const
{
    return Timespan(_span + d._span);
}

Timespan Timespan::operator-(const Timespan &d) const
{
    return Timespan(_span - d._span);
}

Timespan &Timespan::operator+=(const Timespan &d)
{
    _span += d._span;
    return *this;
}

Timespan &Timespan::operator-=(const Timespan &d)
{
    _span -= d._span;
    return *this;
}

Timespan Timespan::operator+(TimeDiff microSeconds) const
{
    return Timespan(_span + microSeconds);
}

Timespan Timespan::operator-(TimeDiff microSeconds) const
{
    return Timespan(_span - microSeconds);
}

Timespan &Timespan::operator+=(TimeDiff microSeconds)
{
    _span += microSeconds;
    return *this;
}

Timespan &Timespan::operator-=(TimeDiff microSeconds)
{
    _span -= microSeconds;
    return *this;
}



DateTime::DateTime()
{
    Timestamp now;
    _utcTime = now.utcTime();
    computeGregorian(julianDay());
    computeDaytime();
    checkValid();
}

DateTime::DateTime(const tm &tmStruct)
    : _year(tmStruct.tm_year + 1900), _month(tmStruct.tm_mon + 1),
      _day(tmStruct.tm_mday), _hour(tmStruct.tm_hour), _minute(tmStruct.tm_min),
      _second(tmStruct.tm_sec), _millisecond(0), _microsecond(0)
{
    checkValid();
    _utcTime = toUtcTime(toJulianDay(_year, _month, _day)) +
               10 * (_hour * Timespan::HOURS + _minute * Timespan::MINUTES +
                     _second * Timespan::SECONDS);
}

DateTime::DateTime(const Timestamp &timestamp) : _utcTime(timestamp.utcTime())
{
    computeGregorian(julianDay());
    computeDaytime();
    checkValid();
}

DateTime::DateTime(int year, int month, int day, int hour, int minute,
                   int second, int millisecond, int microsecond)
    : _year(year), _month(month), _day(day), _hour(hour), _minute(minute),
      _second(second), _millisecond(millisecond), _microsecond(microsecond)
{
    checkValid();
    _utcTime = toUtcTime(toJulianDay(year, month, day)) +
               10 * (hour * Timespan::HOURS + minute * Timespan::MINUTES +
                     second * Timespan::SECONDS +
                     millisecond * Timespan::MILLISECONDS + microsecond);
}

DateTime::DateTime(double julianDay) : _utcTime(toUtcTime(julianDay))
{
    computeGregorian(julianDay);
    checkValid();
}

DateTime::DateTime(Timestamp::UtcTimeVal utcTime, Timestamp::TimeDiff diff)
    : _utcTime(utcTime + diff * 10)
{
    computeGregorian(julianDay());
    computeDaytime();
    checkValid();
}

DateTime::DateTime(const DateTime &dateTime)
    : _utcTime(dateTime._utcTime), _year(dateTime._year),
      _month(dateTime._month), _day(dateTime._day), _hour(dateTime._hour),
      _minute(dateTime._minute), _second(dateTime._second),
      _millisecond(dateTime._millisecond), _microsecond(dateTime._microsecond)
{
}

DateTime::~DateTime() {}

DateTime &DateTime::operator=(const DateTime &dateTime)
{
    if (&dateTime != this)
    {
        _utcTime = dateTime._utcTime;
        _year = dateTime._year;
        _month = dateTime._month;
        _day = dateTime._day;
        _hour = dateTime._hour;
        _minute = dateTime._minute;
        _second = dateTime._second;
        _millisecond = dateTime._millisecond;
        _microsecond = dateTime._microsecond;
    }
    return *this;
}

DateTime &DateTime::operator=(const Timestamp &timestamp)
{
    _utcTime = timestamp.utcTime();
    computeGregorian(julianDay());
    computeDaytime();
    checkValid();
    return *this;
}

DateTime &DateTime::operator=(double julianDay)
{
    _utcTime = toUtcTime(julianDay);
    computeGregorian(julianDay);
    checkValid();
    return *this;
}

DateTime &DateTime::assign(int year, int month, int day, int hour, int minute,
                           int second, int millisecond, int microsecond)
{
    _utcTime = toUtcTime(toJulianDay(year, month, day)) +
               10 * (hour * Timespan::HOURS + minute * Timespan::MINUTES +
                     second * Timespan::SECONDS +
                     millisecond * Timespan::MILLISECONDS + microsecond);
    _year = year;
    _month = month;
    _day = day;
    _hour = hour;
    _minute = minute;
    _second = second;
    _millisecond = millisecond;
    _microsecond = microsecond;
    checkValid();

    return *this;
}

void DateTime::swap(DateTime &dateTime) noexcept
{
    std::swap(_utcTime, dateTime._utcTime);
    std::swap(_year, dateTime._year);
    std::swap(_month, dateTime._month);
    std::swap(_day, dateTime._day);
    std::swap(_hour, dateTime._hour);
    std::swap(_minute, dateTime._minute);
    std::swap(_second, dateTime._second);
    std::swap(_millisecond, dateTime._millisecond);
    std::swap(_microsecond, dateTime._microsecond);
}

int DateTime::dayOfWeek() const
{
    return int((std::floor(julianDay() + 1.5))) % 7;
}

int DateTime::dayOfYear() const
{
    int doy = 0;
    for (int month = 1; month < _month; ++month)
        doy += daysOfMonth(_year, month);
    doy += _day;
    return doy;
}

int DateTime::daysOfMonth(int year, int month)
{
    static int daysOfMonthTable[] = {0,  31, 28, 31, 30, 31, 30,
                                     31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year)) return 29;
    else if (month < 1 || month > 12)
        return 0;
    return daysOfMonthTable[month];
}

void DateTime::checkValid()
{
    if (!isValid(_year, _month, _day, _hour, _minute, _second, _millisecond,
                 _microsecond))
        throw std::invalid_argument(Poco::format(
                "Date time is %hd-%hd-%hdT%hd:%hd:%hd.%hd.%hd\n"
                "Valid values:\n"
                "-4713 <= year <= 9999\n"
                "1 <= month <= 12\n"
                "1 <= day <=  %d\n"
                "0 <= hour <= 23\n"
                "0 <= minute <= 59\n"
                "0 <= second <= 60\n"
                "0 <= millisecond <= 999\n"
                "0 <= microsecond <= 999",
                _year, _month, _day, _hour, _minute, _second, _millisecond,
                _microsecond, daysOfMonth(_year, _month)));
}

bool DateTime::isValid(int year, int month, int day, int hour, int minute,
                       int second, int millisecond, int microsecond)
{
    return (year >= -4713 && year <= 9999) && (month >= 1 && month <= 12) &&
           (day >= 1 && day <= daysOfMonth(year, month)) &&
           (hour >= 0 && hour <= 23) && (minute >= 0 && minute <= 59) &&
           (second >= 0 && second <= 60) &&
           (millisecond >= 0 && millisecond <= 999) &&
           (microsecond >= 0 && microsecond <= 999);
}

int DateTime::week(int firstDayOfWeek) const
{
    assert(firstDayOfWeek >= 0 && firstDayOfWeek <= 6);

    /// find the first firstDayOfWeek.
    int baseDay = 1;
    while (DateTime(_year, 1, baseDay).dayOfWeek() != firstDayOfWeek) ++baseDay;

    int doy = dayOfYear();
    int offs = baseDay <= 4 ? 0 : 1;
    if (doy < baseDay) return offs;
    else
        return (doy - baseDay) / 7 + 1 + offs;
}

double DateTime::julianDay() const { return toJulianDay(_utcTime); }

DateTime DateTime::operator+(const Timespan &span) const
{
    return DateTime(_utcTime, span.totalMicroseconds());
}

DateTime DateTime::operator-(const Timespan &span) const
{
    return DateTime(_utcTime, -span.totalMicroseconds());
}

Timespan DateTime::operator-(const DateTime &dateTime) const
{
    return Timespan((_utcTime - dateTime._utcTime) / 10);
}

DateTime &DateTime::operator+=(const Timespan &span)
{
    _utcTime += span.totalMicroseconds() * 10;
    computeGregorian(julianDay());
    computeDaytime();
    checkValid();
    return *this;
}

DateTime &DateTime::operator-=(const Timespan &span)
{
    _utcTime -= span.totalMicroseconds() * 10;
    computeGregorian(julianDay());
    computeDaytime();
    checkValid();
    return *this;
}

tm DateTime::makeTM() const
{
    tm tmStruct;

    tmStruct.tm_sec = _second;
    tmStruct.tm_min = _minute;
    tmStruct.tm_hour = _hour;
    tmStruct.tm_mday = _day;
    assert(_month > 0);
    tmStruct.tm_mon = _month - 1;
    assert(_year >= 1900);
    tmStruct.tm_year = _year - 1900;
    tmStruct.tm_wday = dayOfWeek();
    int doy = dayOfYear();
    assert(_year > 0);
    tmStruct.tm_yday = doy - 1;
    tmStruct.tm_isdst = -1;

    return tmStruct;
}

void DateTime::makeUTC(int tzd)
{
    operator-=(Timespan(((Timestamp::TimeDiff) tzd) * Timespan::SECONDS));
}

void DateTime::makeLocal(int tzd)
{
    operator+=(Timespan(((Timestamp::TimeDiff) tzd) * Timespan::SECONDS));
}

double DateTime::toJulianDay(int year, int month, int day, int hour, int minute,
                             int second, int millisecond, int microsecond)
{
    // lookup table for (153*month - 457)/5 - note that 3 <= month <= 14.
    static int lookup[] = {-91, -60, -30, 0,   31,  61,  92, 122,
                           153, 184, 214, 245, 275, 306, 337};

    // day to double
    double dday =
            double(day) +
            ((double((hour * 60 + minute) * 60 + second) * 1000 + millisecond) *
                     1000 +
             microsecond) /
                    86400000000.0;
    if (month < 3)
    {
        month += 12;
        --year;
    }
    double dyear = double(year);
    return dday + lookup[month] + 365 * year + std::floor(dyear / 4) -
           std::floor(dyear / 100) + std::floor(dyear / 400) + 1721118.5;
}

void DateTime::checkLimit(short &lower, short &higher, short limit)
{
    if (lower >= limit)
    {
        higher += short(lower / limit);
        lower = short(lower % limit);
    }
}

void DateTime::normalize()
{
    checkLimit(_microsecond, _millisecond, 1000);
    checkLimit(_millisecond, _second, 1000);
    checkLimit(_second, _minute, 60);
    checkLimit(_minute, _hour, 60);
    checkLimit(_hour, _day, 24);

    if (_day > daysOfMonth(_year, _month))
    {
        _day -= daysOfMonth(_year, _month);
        if (++_month > 12)
        {
            ++_year;
            _month -= 12;
        }
    }
}

void DateTime::computeGregorian(double julianDay)
{
    double z = std::floor(julianDay - 1721118.5);
    double r = julianDay - 1721118.5 - z;
    double g = z - 0.25;
    double a = std::floor(g / 36524.25);
    double b = a - std::floor(a / 4);
    _year = short(std::floor((b + g) / 365.25));
    double c = b + z - std::floor(365.25 * _year);
    _month = short(std::floor((5 * c + 456) / 153));
    double dday = c - std::floor((153.0 * _month - 457) / 5) + r;
    _day = short(dday);
    if (_month > 12)
    {
        ++_year;
        _month -= 12;
    }
    r *= 24;
    _hour = short(std::floor(r));
    r -= std::floor(r);
    r *= 60;
    _minute = short(std::floor(r));
    r -= std::floor(r);
    r *= 60;
    _second = short(std::floor(r));
    r -= std::floor(r);
    r *= 1000;
    _millisecond = short(std::floor(r));
    r -= std::floor(r);
    r *= 1000;
    _microsecond = short(r + 0.5);

    normalize();
}

void DateTime::computeDaytime()
{
    Timestamp::UtcTimeVal ut(_utcTime);
    if (ut < 0)
    {
        // GH3723: UtcTimeVal is negative for pre-gregorian dates
        // move it 1600 years to the future
        // keeping hour, minute, second,... for corrections
        ut += std::int64_t(86400) * 1000 * 1000 * 10 * 1600 * 365;
    }
    Timespan span(ut / 10);
    int hour = span.hours();
    // Due to double rounding issues, the previous call to computeGregorian()
    // may have crossed into the next or previous day. We need to correct that.
    if (hour == 23 && _hour == 0)
    {
        _day--;
        if (_day == 0)
        {
            _month--;
            if (_month == 0)
            {
                _month = 12;
                _year--;
            }
            _day = daysOfMonth(_year, _month);
        }
    }
    else if (hour == 0 && _hour == 23)
    {
        _day++;
        if (_day > daysOfMonth(_year, _month))
        {
            _month++;
            if (_month > 12)
            {
                _month = 1;
                _year++;
            }
            _day = 1;
        }
    }
    _hour = hour;
    _minute = span.minutes();
    _second = span.seconds();
    _millisecond = span.milliseconds();
    _microsecond = span.microseconds();
}

inline double DateTime::toJulianDay(Timestamp::UtcTimeVal utcTime)
{
    double utcDays = double(utcTime) / 864000000000.0;
    return utcDays + 2299160.5;// first day of Gregorian reform (Oct 15 1582)
}

inline Timestamp::UtcTimeVal DateTime::toUtcTime(double julianDay)
{
    return Timestamp::UtcTimeVal((julianDay - 2299160.5) * 864000000000.0);
}

inline Timestamp DateTime::timestamp() const
{
    return Timestamp::fromUtcTime(_utcTime);
}

inline Timestamp::UtcTimeVal DateTime::utcTime() const { return _utcTime; }

inline int DateTime::year() const { return _year; }

inline int DateTime::month() const { return _month; }

inline int DateTime::day() const { return _day; }

inline int DateTime::hour() const { return _hour; }

inline int DateTime::hourAMPM() const
{
    if (_hour < 1) return 12;
    else if (_hour > 12)
        return _hour - 12;
    else
        return _hour;
}

inline bool DateTime::isAM() const { return _hour < 12; }

inline bool DateTime::isPM() const { return _hour >= 12; }

inline int DateTime::minute() const { return _minute; }

inline int DateTime::second() const { return _second; }

inline int DateTime::millisecond() const { return _millisecond; }

inline int DateTime::microsecond() const { return _microsecond; }

inline bool DateTime::operator==(const DateTime &dateTime) const
{
    return _utcTime == dateTime._utcTime;
}

inline bool DateTime::operator!=(const DateTime &dateTime) const
{
    return _utcTime != dateTime._utcTime;
}

inline bool DateTime::operator<(const DateTime &dateTime) const
{
    return _utcTime < dateTime._utcTime;
}

inline bool DateTime::operator<=(const DateTime &dateTime) const
{
    return _utcTime <= dateTime._utcTime;
}

inline bool DateTime::operator>(const DateTime &dateTime) const
{
    return _utcTime > dateTime._utcTime;
}

inline bool DateTime::operator>=(const DateTime &dateTime) const
{
    return _utcTime >= dateTime._utcTime;
}

inline bool DateTime::isLeapYear(int year)
{
    return (year % 4) == 0 && ((year % 100) != 0 || (year % 400) == 0);
}

inline void swap(DateTime &d1, DateTime &d2) noexcept { d1.swap(d2); }