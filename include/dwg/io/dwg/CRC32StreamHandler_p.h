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

class CRC32StreamHandlerBase
{
public:
    unsigned int Seed() const;

protected:
    unsigned int _seed;
};

class CRC32InputStreamHandler : public InputStreamWrapper, CRC32StreamHandlerBase
{
public:
    CRC32InputStreamHandler(std::istream *stream);
    CRC32InputStreamHandler(std::vector<unsigned char> &arr, unsigned int seed);
    int RawRead(unsigned char *buff, int nLen);
};

class CRC32OutputStreamHandler : public OutputStreamWrapper, CRC32StreamHandlerBase
{
public:
    CRC32OutputStreamHandler(std::ostream *stream);
    CRC32OutputStreamHandler(std::vector<unsigned char> &arr, unsigned int seed);
};

}// namespace dwg