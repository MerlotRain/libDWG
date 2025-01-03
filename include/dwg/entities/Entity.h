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

#include <dwg/IHandledCadObject.h>
#include <dwg/Transparency.h>
#include <dwg/LineWeightType.h>
#include <dwg/objects/BookColor.h>
#include <dwg/objects/Material.h>
#include <dwg/tables/Layer.h>
#include <dwg/tables/LineType.h>
#include <dwg/base/Color.h>
#include <dwg/base/Coordinate.h>

namespace dwg {

class Entity : public CadObject
{
public:
    Entity();
    std::string SubclassMarker() const { return DxfSubclassMarker::Entity; }

public:
    Layer *layer;       // 8, name
    Color color;                // 62, 420
    LineweightType lineweight;  // 370
    double linetypeScale;       // 48
    bool isInvisible;           // 60
    Transparency transparency;  // 440
    LineType *linetype; // 6, name
    Material *material;// 347, handle

    BookColor bookColor;//430, name

    void MatchProperties(const Entity *other);
};

}// namespace dwg
