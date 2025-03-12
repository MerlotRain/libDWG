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

#include <functional>
#include <vector>

namespace dwg {

class DwgLZ77AC21Decompressor
{
    typedef std::function<void(const std::vector<unsigned char> &, unsigned int, std::vector<unsigned char> &,
                               unsigned int)>
            copyDelegate;

    static unsigned int _sourceOffset = 0;
    static unsigned int _length = 0;
    static unsigned int _sourceIndex = 0;
    static unsigned int _opCode = 0;

public:
    static void Decompress(const std::vector<unsigned char> &source, unsigned int initialOffset, unsigned int length,
                           std::vector<unsigned char> &buffer);

private:
    static unsigned int copyDecompressedChunks(const std::vector<unsigned char> &src, unsigned int endIndex,
                                               std::vector<unsigned char> &det, unsigned int destIndex);
    static void readInstructions(std::vector<unsigned char> &buffer);
    static void readLiteralLength(std::vector<unsigned char> &buffer);

    static void copy1b(const std::vector<unsigned char> &src, unsigned int endIndex, std::vector<unsigned char> &det,
                       unsigned int destIndex);
    static void copy2b(const std::vector<unsigned char> &src, unsigned int endIndex, std::vector<unsigned char> &det,
                       unsigned int destIndex);
    static void copy3b(const std::vector<unsigned char> &src, unsigned int endIndex, std::vector<unsigned char> &det,
                       unsigned int destIndex);
    static void copy4b(const std::vector<unsigned char> &src, unsigned int endIndex, std::vector<unsigned char> &det,
                       unsigned int destIndex);
    static void copy8b(const std::vector<unsigned char> &src, unsigned int endIndex, std::vector<unsigned char> &det,
                       unsigned int destIndex);
    static void copy16b(const std::vector<unsigned char> &src, unsigned int endIndex, std::vector<unsigned char> &det,
                        unsigned int destIndex);
};

}// namespace dwg