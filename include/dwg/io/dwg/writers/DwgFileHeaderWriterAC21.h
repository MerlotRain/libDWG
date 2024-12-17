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

#include <dwg/io/dwg/writers/DwgFileHeaderWriterAC18.h>

namespace dwg {
namespace io {

	class DwgFileHeaderWriterAC21 : DwgFileHeaderWriterAC18
	{
		protected override int _fileHeaderSize { get { return 0x480; } }

		protected override ICompressor compressor => new DwgLZ77AC21Compressor();

		public DwgFileHeaderWriterAC21(Stream stream, Encoding encoding, CadDocument model) : base(stream, encoding, model)
		{
		}

		protected override void craeteLocalSection(DwgSectionDescriptor descriptor, byte[] buffer, int decompressedSize, ulong offset, int totalSize, bool isCompressed)
		{
			MemoryStream descriptorStream = this.applyCompression(buffer, decompressedSize, offset, totalSize, isCompressed);

			this.writeMagicNumber();

			//Implementation for the LZ77 compressor for AC1021
			//modify the localsection writer to match this specific version
		}
	}

}
}