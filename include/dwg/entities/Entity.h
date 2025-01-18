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

#include <dwg/CadObject.h>
#include <dwg/Coordinate.h>
#include <dwg/entities/IEntity.h>

namespace dwg {

class LIBDWG_API Entity : public CadObject, IEntity
{
    dwg::LayerWPtr _layer;
    dwg::Color _color;
    LineweightType _lineweight;
    double _linetypeScale;
    bool _isInvisible;
    dwg::Transparency _transparency;
    dwg::LineTypeWPtr _linetype;
    dwg::BookColorWPtr _bookColor;

public:
    Entity();
    CPL::String SubclassMarker() const;

public:
    void MatchProperties(const Entity *other);
};
CPL_SMARTER_PTR(Entity)

}// namespace dwg
