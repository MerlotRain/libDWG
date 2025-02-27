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

/// Controls the vertical placement of dimension text in relation to the dimension line.
enum class DimensionTextHorizontalAlignment : unsigned char
{
    /// Centers the dimension text along the dimension line between the extension lines.
    Centered = 0,

    /// Left-justifies the text with the first extension line along the dimension line.
    Left = 1,

    /// Right-justifies the text with the second extension line along the dimension line.
    Right = 2,

    /// Positions the text over or along the first extension line.
    OverFirstExtLine = 3,

    /// Positions the text over or along the second extension line.
    OverSecondExtLine = 4
};

}// namespace dwg