﻿/**
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

#include <dwg/base/Flags.h>

namespace dwg {

/// Standard layer flags (bit-coded values).
enum LayerFlag : short
{
    /// None
    None = 0,

    /// Layer is frozen; otherwise layer is thawed
    Frozen = 1,

    /// Layer is frozen by default in new viewports
    FrozenNewViewports = 2,

    /// Layer is locked
    Locked = 4,

    /// If set, table entry is externally dependent on an xRef
    XrefDependent = 16,

    /// If both this bit and bit 16 are set, the externally dependent xRef has been successfully resolved
    XrefResolved = 32,

    /// If set, the table entry was referenced by at least one entity in the drawing the last time the
    /// drawing was edited.
    Referenced = 64
};
DECLARE_FLAGS(LayerFlags, LayerFlag)

}// namespace dwg