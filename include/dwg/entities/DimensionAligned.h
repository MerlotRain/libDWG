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

#include <dwg/entities/Dimension.h>

namespace dwg {

// The DimensionAligned class represents an aligned dimension, where
// the dimension is applied between two points with an extended line rotation.
class LIBDWG_API DimensionAligned : public Dimension
{
    XYZ _firstPoint; // The first point of the aligned dimension
    XYZ _secondPoint;// The second point of the aligned dimension
    double _extLineRotation;// Rotation angle for the extension lines of the aligned dimension

public:
    // Default constructor for the DimensionAligned class
    DimensionAligned();

    // Destructor for the DimensionAligned class
    ~DimensionAligned();

    // Getter and setter for the first point of the aligned dimension
    XYZ FirstPoint() const;
    void FirstPoint(const XYZ &value);

    // Getter and setter for the second point of the aligned dimension
    XYZ SecondPoint() const;
    void SecondPoint(const XYZ &value);

    // Getter and setter for the extension line rotation angle
    double ExtLineRotation() const;
    void ExtLineRotation(double value);

    // Override the Measurement method to calculate the dimension's measurement
    // based on the two points and extension line rotation
    virtual double Measurement() const override;
};
CPL_SMARTER_PTR(DimensionAligned)

}// namespace dwg