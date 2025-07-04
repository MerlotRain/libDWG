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

#include <dwg/io/dwg/writers/ICompressor_p.h>
#include <sstream>

namespace dwg {

class DwgLZ77AC18Compressor : public ICompressor
{
    std::vector<unsigned char> _source;
    std::stringstream _dest;
    std::vector<int> _block;
    int _initialOffset;
    int _currPosition;
    int _currOffset;
    int _totalOffset;

public:
    DwgLZ77AC18Compressor();
    void compress(const std::vector<unsigned char> &source, size_t offset, size_t totalSize,
                  std::iostream *dest) override;

private:
    void restartBlock();
    void writeLen(int len);
    void writeOpCode(int opCode, int compressionOffset, int value);
    void writeLiteralLength(int length);
    void applyMask(int matchPosition, int compressionOffset, int mask);
    bool compressChunk(int &offset, int &matchPos);
};


}// namespace dwg