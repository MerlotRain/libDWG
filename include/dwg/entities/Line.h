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

class LIBDWG_API Line : public Entity
{
    RTTR_ENABLE(Entity)

public:
    Line();
    ~Line();

    ObjectType objectType() const override;
    std::string objectName() const override;
    std::string subclassMarker() const override;

    XYZ normal() const;
    void setNormal(const XYZ &normal);

    XYZ startPoint() const;
    void setStartPoint(const XYZ &point);

    XYZ endPoint() const;
    void setEndPoint(const XYZ &point);

    double thickness() const;
    void setThickness(double thickness);

private:
    XYZ _normal;      ///< Normal vector defining the plane of the line.
    XYZ _startPoint;  ///< Start point of the line.
    XYZ _endPoint;    ///< End point of the line.
    double _thickness;///< Thickness of the line.
};

}// namespace dwg