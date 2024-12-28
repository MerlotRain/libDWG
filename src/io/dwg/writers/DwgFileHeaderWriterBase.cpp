/**
 * libDWG - A C++ library for reading and writing DWG and DXF files in CAD.
 *
 * This file is part of libDWG.
 *
 * libDWG is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General  License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * libDWG is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General  License for more details.
 *
 * You should have received a copy of the GNU General  License
 * along with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * For more information, visit the project's homepage or contact the author.
 */

#pragma once

#include <dwg/io/dwg/writers/IDwgFileHeaderWriter.h>
#include <dwg/enums/ACadVersion.h>
#include <dwg/utils/Encoding.h>
#include <dwg/CadDocument.h>
#include <dwg/io/dwg/DwgCheckSumCalculator.h>
#include <dwg/utils/EndianConverter.h>
#include <dwg/CadUtils.h>
#include <sstream>
#include <fstream>

#include <assert.h>

namespace dwg {
namespace io {

class DwgFileHeaderWriterBase : public IDwgFileHeaderWriter
{
protected:
    ACadVersion _version;
    Encoding _encoding;
    std::ofstream *_stream;
    CadDocument *_document;

    virtual int HandleSectionOffset() const = 0;
    virtual int _fileHeaderSize() const = 0;

public:
    DwgFileHeaderWriterBase(std::ofstream *stream, Encoding encoding,
                            CadDocument *model)
    {
        assert(stream);
        assert(model);
        _document = model;
        _stream = stream;
        _version = model->Header.Version;
        _encoding = encoding;
    }

    unsigned short getFileCodePage()
    {
        unsigned short codePage =  CadUtils::GetCodeIndex(CadUtils::GetCodePage(_document->Header.CodePage));
        if (codePage < 1) { return 30; }
        else { return codePage; }
    }

    void applyMask(std::vector<unsigned char> &buffer, int offset, int length)
    {
        auto&& bytes =
                LittleEndianConverter::Instance()->GetBytes(0x4164536B ^
                                                          (int)_stream->tellp());
        int diff = offset + length;
        while (offset < diff)
        {
            for (int i = 0; i < 4; i++) { buffer[offset + i] ^= bytes[i]; }

            offset += 4;
        }
    }

    bool checkEmptyBytes(const std::vector<unsigned char> &buffer,
                         unsigned long long offset,
                         unsigned long long spearBytes) const
    {
        bool result = true;
        unsigned long long num = offset + spearBytes;

        for (unsigned long long i = offset; i < num; i++)
        {
            if (buffer[i] != 0)
            {
                result = false;
                break;
            }
        }

        return result;
    }

    void writeMagicNumber()
    {
        for (int i = 0; i < (int) (_stream->tellp() % 0x20); i++)
        {
            unsigned char b = DwgCheckSumCalculator::MagicSequence[i];
            _stream->write(reinterpret_cast<char *>(&b), sizeof(unsigned char));
        }
    }

    void applyMagicSequence(std::ostringstream *stream)
    {
        std::string buffer = stream->str();
        for(size_t i = 0; i < buffer.size(); ++i)
        {
            buffer[i] ^= DwgCheckSumCalculator::MagicSequence[i];
        }
        stream->str("");
        stream->clear();
        *stream << buffer;
    }
};

}// namespace io
}// namespace dwg