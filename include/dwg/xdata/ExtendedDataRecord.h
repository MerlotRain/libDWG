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

#include <dwg/DxfCode.h>
#include <dwg/utils/DwgVariant.h>

namespace dwg {

class CadDocument;
class CadObject;
class LIBDWG_API ExtendedDataRecord
{
public:
    virtual ~ExtendedDataRecord() = default;
    DxfCode code() const;
    DwgVariant rawValue() const;

protected:
    ExtendedDataRecord(DxfCode code, const DwgVariant &value);

protected:
    DxfCode _code;
    DwgVariant _value;
};

template<typename T>
class LIBDWG_API ExtendedDataRecordT : public ExtendedDataRecord
{
public:
    virtual ~ExtendedDataRecordT() = default;

    T value()
    {
        return _value;
    }

    void setValue(T value)
    {
        _value = value;
    }

protected:
    ExtendedDataRecordT(DxfCode code, T value) : ExtendedDataRecord(code, value) {}
};


class LIBDWG_API ExtendedDataBinaryChunk : public ExtendedDataRecordT<std::vector<unsigned char>>
{
public:
    ExtendedDataBinaryChunk(const std::vector<unsigned char> &chunk);
};

class LIBDWG_API ExtendedDataControlString : public ExtendedDataRecord
{
    bool _isClosing;

public:
    ExtendedDataControlString(bool close);
    char value() const;
    bool isClosing() const;

    static ExtendedDataControlString *Open();
    static ExtendedDataControlString *Close();
};


class LIBDWG_API ExtendedDataCoordinate : public ExtendedDataRecordT<XYZ>
{
public:
    ExtendedDataCoordinate(const XYZ coordinate);
};


class LIBDWG_API ExtendedDataDirection : public ExtendedDataRecordT<XYZ>
{
public:
    ExtendedDataDirection(const XYZ direction);
};


class LIBDWG_API ExtendedDataDisplacement : public ExtendedDataRecordT<XYZ>
{
public:
    ExtendedDataDisplacement(const XYZ displacement);
};


class LIBDWG_API ExtendedDataWorldCoordinate : public ExtendedDataRecordT<XYZ>
{
public:
    ExtendedDataWorldCoordinate(const XYZ &coordinate);
};


class LIBDWG_API ExtendedDataDistance : public ExtendedDataRecordT<double>
{
public:
    ExtendedDataDistance(double value);
};


class LIBDWG_API ExtendedDataInteger16 : public ExtendedDataRecordT<short>
{
public:
    ExtendedDataInteger16(short value);
};


class LIBDWG_API ExtendedDataInteger32 : public ExtendedDataRecordT<int>
{
public:
    ExtendedDataInteger32(int value);
};


class LIBDWG_API ExtendedDataReal : public ExtendedDataRecordT<double>
{
public:
    ExtendedDataReal(double value);
};


class LIBDWG_API ExtendedDataScale : public ExtendedDataRecordT<double>
{
public:
    ExtendedDataScale(double value);
};


class LIBDWG_API ExtendedDataString : public ExtendedDataRecordT<std::string>
{
public:
    ExtendedDataString(const std::string &value);
};


class LIBDWG_API IExtendedDataHandleReference
{
public:
    IExtendedDataHandleReference() = default;
    virtual ~IExtendedDataHandleReference() = default;
    virtual unsigned long long value() const = 0;
    virtual CadObject *resolveReference(CadDocument *document) const = 0;
};

class LIBDWG_API ExtendedDataHandle : public ExtendedDataRecordT<unsigned long long>,
                                      public IExtendedDataHandleReference
{
public:
    ExtendedDataHandle(unsigned long long handle);
    ~ExtendedDataHandle();
    unsigned long long value() const override;
    CadObject *resolveReference(CadDocument *document) const override;
};

class LIBDWG_API ExtendedDataLayer : public ExtendedDataRecordT<unsigned long long>, public IExtendedDataHandleReference
{
public:
    ExtendedDataLayer(unsigned long long handle);
    ~ExtendedDataLayer();
    unsigned long long value() const override;
    CadObject *resolveReference(CadDocument *document) const override;
};

}// namespace dwg