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

#include <dwg/entities/Entity.h>

namespace dwg {

class LIBDWG_API DG_Solid : public DG_Entity
{
public:
    DG_Solid();

    virtual ~DG_Solid();

    // Override to return the object type of the Arc
    virtual DG_ObjectType objectType() const override;

    // Override to return the name of the object
    virtual std::string objectName() const override;

    // Override to return the subclass marker associated with this object
    virtual std::string subclassMarker() const override;

    XYZ FirstCorner() const;
    void FirstCorner(const XYZ &);

    XYZ SecondCorner() const;
    void SecondCorner(const XYZ &);

    XYZ ThirdCorner() const;
    void ThirdCorner(const XYZ &);

    XYZ FourthCorner() const;
    void FourthCorner(const XYZ &);

    double Thickness() const;
    void Thickness(double);

    XYZ Normal() const;
    void Normal(const XYZ &);
};

}// namespace dwg
