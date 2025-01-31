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

#include <dwg/objects/NonGraphicalObject.h>
#include <dwg/tables/BlockRecord.h>
#include <vector>

namespace dwg {

class DG_Entity;
class DG_BlockRecord;

class LIBDWG_API SortEntitiesTable : public DG_NonGraphicalObject
{
public:
    struct Sorter
    {
        DG_Entity *Entity;
        unsigned long long Handle;
        Sorter(DG_Entity *entity, unsigned long long handle);
    };

    static constexpr auto DictionaryEntryName = "ACAD_SORTENTS";

public:
    SortEntitiesTable();

    SortEntitiesTable(DG_BlockRecord *owner);

    DG_ObjectType ObjectType() const override;

    std::string ObjectName() const override;

    std::string SubclassMarker() const override;

    DG_BlockRecord *BlockOwner() const;

    void BlockOwner(DG_BlockRecord *);

    std::vector<Sorter> Sorters() const;

    void AddEntity(DG_Entity *, unsigned long long sorterHandle);
};

}// namespace dwg