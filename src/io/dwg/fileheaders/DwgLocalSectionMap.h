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

#include <cstdint>

namespace dwg {
namespace io {

struct DwgLocalSectionMap
{
public:
    int32_t Compression = 2;
    bool IsEmpty;
    uint64_t Offset;
    uint64_t CompressedSize;
    int32_t PageNumber;
    uint64_t DecompressedSize;
    int64_t Seeker;
    int64_t Size;
    uint64_t Checksum;
    uint64_t CRC;
    int64_t PageSize;
    uint32_t ODA;
    int32_t SectionMap;

    DwgLocalSectionMap(int value = 0) : SectionMap(value) {}
};

}// namespace io
}// namespace dwg