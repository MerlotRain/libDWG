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

namespace dwg {

/// \brief Enumeration for text angle types.
enum TextAngleType : short
{
    /// \brief Text angle is equal to last leader line segment angle
    ParllelToLastLeaderLine = 0,

    /// \brief Text is horizontal
    Horizontal = 1,

    /// \brief Text angle is equal to last leader line segment angle, but
    /// potentially rotated by 180 degrees so the right side is up for
    /// readability.
    Optimized = 2,
};

}// namespace dwg