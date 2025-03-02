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

#include <dwg/io/dwg/CRC_p.h>
#include <dwg/utils/StreamWrapper.h>

namespace dwg {

class CRC8StreamHandlerBase
{
    static unsigned short decode(unsigned short key, unsigned char value);

public:
    CRC8StreamHandlerBase();
    virtual ~CRC8StreamHandlerBase();
    static unsigned short GetCRCValue(unsigned short seed, const std::vector<unsigned char> &buffer, long startPos,
                                      long endPos);
    unsigned short seed() const;
    void setSeed(unsigned short);

protected:
    unsigned short _seed;
};

class CRC8InputStreamHandler : public InputStreamWrapper, public CRC8StreamHandlerBase
{
public:
    CRC8InputStreamHandler();
    CRC8InputStreamHandler(std::istream *stream);
    ~CRC8InputStreamHandler();
};


class CRC8OutputStreamHandler : public OutputStreamWrapper, public CRC8StreamHandlerBase
{
public:
    CRC8OutputStreamHandler();
    CRC8OutputStreamHandler(std::ostream *stream, unsigned short seed);
    ~CRC8OutputStreamHandler();
};

}// namespace dwg