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

#include "../DwgSectionIO.h"
#include "../CRC8StreamHandler.h"
#include "../fileheaders/DwgSectionDefinition.h"
#include "IDwgStreamWriter.h"
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
    std::string SectionName() const;

    DwgHandleWriter(ACadVersion version, std::ostringstream *stream,
                    const std::map<unsigned long long, long long> &handlemap);

    void Write(int sectionOffset = 0);
private:
    int modularShortToValue(unsigned long long value,
                            std::vector<unsigned char> &arr);
    int signedModularShortToValue(int value, std::vector<unsigned char> &arr);
    void processPosition(std::streampos pos);
};


}// namespace io
}// namespace dwg