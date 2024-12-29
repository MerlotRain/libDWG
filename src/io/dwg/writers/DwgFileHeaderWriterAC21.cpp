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

#include "DwgFileHeaderWriterAC21.h"
#include "DwgLZ77AC21Compressor.h"

namespace dwg {
namespace io {

DwgFileHeaderWriterAC21::DwgFileHeaderWriterAC21(std::ofstream *stream,
                                                 Encoding encoding,
                                                 CadDocument *model)
    : DwgFileHeaderWriterAC18(stream, encoding, model)
{
    compressor = new DwgLZ77AC21Compressor();
}

int DwgFileHeaderWriterAC21::_fileHeaderSize() const { return 0x480; }

void DwgFileHeaderWriterAC21::craeteLocalSection(
        DwgSectionDescriptor descriptor,
        const std::vector<unsigned char> &buffer, int decompressedSize,
        unsigned long long offset, int totalSize, bool isCompressed)
{
    std::ostringstream descriptorStream = applyCompression(
            buffer, decompressedSize, offset, totalSize, isCompressed);
    writeMagicNumber();
}

}// namespace io
}// namespace dwg