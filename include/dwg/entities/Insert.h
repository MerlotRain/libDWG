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
#include <dwg/tables/BlockRecord.h>
#include <dwg/entities/AttributeEntity.h>

namespace dwg {
namespace entities {

class Insert : Entity
{
    public:
    // name 2
tables::BlockRecord* block;

XYZ insertPoint; // 10, 20, 30

double XScale; // 41
double YScale; // 42
double ZScale; // 43

double rotation; // 50
XYZ normal; // 210, 220, 230

unsigned short columnCount; // 70
unsigned short rowCount; // 71

double columnSpacing; // 44
double rowSpacing; // 45

bool hasAttributes; // 66

SeqendCollection<AttributeEntity> attributes;
};


}// namespace entities
}// namespace dwg