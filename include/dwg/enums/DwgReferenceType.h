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

namespace dwg {

enum class DwgReferenceType
{
    Undefined = 0,

    /// Soft ownership reference: the owner does not need the owned object. The owned object cannot exist by itself.
    SoftOwnership = 2,

    /// Hard ownership reference: the owner needs the owned object. The owned object cannot exist by itself.
    HardOwnership = 3,

    /// Soft pointer reference: the referencing object does not need the referenced object and vice versa.
    SoftPointer = 4,

    /// Hard pointer reference: the referencing object needs the referenced object, but both are owned by another object.
    HardPointer = 5,
};

}// namespace dwg
