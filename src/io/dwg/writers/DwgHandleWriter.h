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

#pragma once

#include <dwg/io/dwg/DwgSectionIO.h>
#include <dwg/io/dwg/fileheaders/DwgSectionDefinition.h>
#include <dwg/io/dwg/writers/IDwgStreamWriter.h>

#include <dwg/io/dwg/CRC8StreamHandler.h>
#include <sstream>
#include <stdexcept>

namespace dwg {
namespace io {

class DwgHandleWriter : public DwgSectionIO
{
    IDwgStreamWriter *_writer;
    std::vector<unsigned char> _emptyArr;
    std::ostringstream *_stream;
    std::map<unsigned long long, long long> _handleMap;

public:
    std::string SectionName() const { return DwgSectionDefinition::Handles; }

    DwgHandleWriter(ACadVersion version, std::ostringstream *stream,
                    const std::map<unsigned long long, long long> &handlemap)
        : DwgSectionIO(version)
    {
        _stream = stream;
        _handleMap = handlemap;
    }

    void Write(int sectionOffset = 0)
    {
        std::vector<unsigned char> array(10, 0);
        std::vector<unsigned char> array2(5, 0);

        unsigned long long offset = 0ULL;
        long long initialLoc = 0L;

        std::streampos lastPosition = _stream->tellp();

        unsigned char buf_ch = 0;
        _stream->write(reinterpret_cast<const char *>(&buf_ch),
                       sizeof(unsigned char));
        _stream->write(reinterpret_cast<const char *>(&buf_ch),
                       sizeof(unsigned char));


        for (auto pair: _handleMap)
        {
            unsigned long long handleOff = pair.first - offset;
            long long lastLoc = (long long) pair.second + sectionOffset;
            long long locDiff = lastLoc - initialLoc;

            int offsetSize = modularShortToValue(handleOff, array);
            int locSize = signedModularShortToValue((int) locDiff, array2);

            if (_stream->tellp() - lastPosition + (offsetSize + locSize) > 2032)
            {
                processPosition(lastPosition);
                offset = 0uL;
                initialLoc = 0L;
                lastPosition = _stream->tellp();
                _stream->write(reinterpret_cast<const char *>(&buf_ch),
                               sizeof(unsigned char));
                _stream->write(reinterpret_cast<const char *>(&buf_ch),
                               sizeof(unsigned char));
                offset = 0uL;
                initialLoc = 0L;
                handleOff = pair.first - offset;

                if (handleOff == 0) { throw new std::runtime_error(""); }

                locDiff = lastLoc - initialLoc;
                offsetSize = modularShortToValue(handleOff, array);
                locSize = signedModularShortToValue((int) locDiff, array2);
            }

            _stream->write(reinterpret_cast<const char *>(array.data()),
                           offsetSize);
            _stream->write(reinterpret_cast<const char *>(array2.data()),
                           locSize);
            offset = pair.first;
            initialLoc = lastLoc;
        }

        processPosition(lastPosition);
        lastPosition = _stream->tellp();
        _stream->write(reinterpret_cast<const char *>(&buf_ch),
                       sizeof(unsigned char));
        _stream->write(reinterpret_cast<const char *>(&buf_ch),
                       sizeof(unsigned char));
        processPosition(lastPosition);
    }

private:
    int modularShortToValue(unsigned long long value,
                            std::vector<unsigned char> &arr)
    {
        int i = 0;
        while (value >= 0b10000000)
        {
            arr[i] = (unsigned char) ((value & 0b1111111) | 0b10000000);
            i++;
            value >>= 7;
        }
        arr[i] = (unsigned char) value;
        return i + 1;
    }

    int signedModularShortToValue(int value, std::vector<unsigned char> &arr)
    {
        int i = 0;
        if (value < 0)
        {
            for (value = -value; value >= 64; value >>= 7)
            {
                arr[i] = (unsigned char) (((unsigned int) value & 0x7Fu) |
                                          0x80u);
                i++;
            }
            arr[i] = (unsigned char) ((unsigned int) value | 0x40u);
            return i + 1;
        }

        while (value >= 0b1000000)
        {
            arr[i] = (unsigned char) (((unsigned int) value & 0x7Fu) | 0x80u);
            i++;
            value >>= 7;
        }

        arr[i] = (unsigned char) value;
        return i + 1;
    }

    void processPosition(std::streampos pos)
    {
        unsigned short diff = (unsigned short) (_stream->tellp() - pos);
        long streamPos = _stream->tellp();
        _stream->seekp(pos);
        unsigned char ch = (unsigned char) (diff >> 8);
        _stream->write(reinterpret_cast<const char *>(&ch),
                       sizeof(unsigned char));
        ch = (unsigned char) (diff & 0b11111111);
        _stream->write(reinterpret_cast<const char *>(&ch),
                       sizeof(unsigned char));
        _stream->seekp(streamPos);

        unsigned short crc = CRC8StreamHandler::GetCRCValue(
                0xC0C1, _stream->str().data(), pos, _stream->tellp() - pos);

        ch = (unsigned char) (crc >> 8);
        _stream->write(reinterpret_cast<const char *>(&ch),
                       sizeof(unsigned char));
        ch = (unsigned char) (crc & 0b11111111);
        _stream->write(reinterpret_cast<const char *>(&ch),
                       sizeof(unsigned char));
    }
};


}// namespace io
}// namespace dwg