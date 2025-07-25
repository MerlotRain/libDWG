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
#include <dwg/entities/LwPolylineFlags.h>
#include <dwg/entities/VertexFlags.h>

namespace dwg {

class LIBDWG_API LwPolyline : public Entity
{
    RTTR_ENABLE(Entity)
public:
    struct Vertex
    {
        XY Location;
        double Bulge;
        double StartWidth;
        double EndWidth;
        VertexFlags Flags;
        double CurveTangent;
        int Id;
    };

    LwPolyline();
    virtual ~LwPolyline();

    ObjectType objectType() const override;
    std::string objectName() const override;
    std::string subclassMarker() const override;

    LwPolylineFlags flags() const;
    void setFlags(LwPolylineFlags);

    double constantWidth() const;
    void setConstantWidth(double);

    double elevation() const;
    void setElevation(double);

    double thickness() const;
    void setThickness(double);

    XYZ normal() const;
    void setNormal(const XYZ &);

    std::vector<Vertex> vertices() const;
    void setVertices(const std::vector<Vertex> &);

    bool isClosed() const;
    void setIsClosed(bool);

private:
    LwPolylineFlags _flags;
    double _constantWidth;
    double _elevation;
    double _thickness;
    XYZ _normal;
    std::vector<Vertex> _vertices;
    bool _isClosed;
};

}// namespace dwg