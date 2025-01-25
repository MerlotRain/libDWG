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

#include <cpl_ports.h>

namespace dwg {

/// Block-type flags (bit-coded values, may be combined).
enum DG_BlockTypeFlag
{
    /// None
    None = 0,
    /// This is an anonymous block generated by hatching, associative dimensioning, other internal operations, or an application.
    Anonymous = 1,
    /// This block has non-constant attribute definitions
    /// (this bit is not set if the block has any attribute definitions that are constant, or has no attribute definitions at all).
    NonConstantAttributeDefinitions = 2,
    /// This block is an external reference.
    XRef = 4,
    /// This block is an external reference overlay.
    XRefOverlay = 8,
    /// This block is externally dependent.
    XrefDependent = 16,
    /// This is a resolved external reference, or dependent of an external reference (ignored on input).
    XrefResolved = 32,
    /// This definition is a referenced external reference (ignored on input).
    Referenced = 64
};
CPL_DECLARE_FLAGS(DG_BlockTypeFlags, DG_BlockTypeFlag)

}// namespace dwg
