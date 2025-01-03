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

#include <dwg/CadObjectCollection.h>
#include <dwg/entities/Entity.h>
#include <dwg/entities/IPolyline.h>
#include <dwg/entities/Vertex.h>
#include <dwg/entities/PolylineFlags.h>
#include <dwg/entities/SmoothSurfaceType.h>


namespace dwg {

class Polyline : public Entity, IPolyline
{
public:
    double elevation;// 30
    double thickness;// 39

    XYZ normal;         // 210, 220, 230
    PolylineFlags flags;// 70

    double startWidth;// 40
    double endWidth;  // 41

    SmoothSurfaceType smoothSurface;// 75

    CadObjectCollection<Vertex> vertices;
};

class Polyline2D : public Polyline
{
public:
    Polyline2D();
    ~Polyline2D();
};

class Polyline3D : public Polyline
{
public:
    Polyline3D();
    ~Polyline3D();
};


}// namespace dwg
