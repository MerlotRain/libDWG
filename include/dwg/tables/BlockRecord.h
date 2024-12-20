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

#include <dwg/entities/Viewport.h>
#include <dwg/enums/blockes/BlockTypeFlags.h>
#include <dwg/enums/units/UnitsType.h>
#include <dwg/objects/Layout.h>
#include <dwg/tables/TableEntry.h>

namespace dwg {
namespace tables {

class BlockRecord : public TableEntry
{
public:
    static constexpr auto ModelSpaceName = "*Model_Space";
    static constexpr auto PaperSpaceName = "*Paper_Space";

    static BlockRecord *ModelSpace()
    {
        BlockRecord *record = new BlockRecord(ModelSpaceName);
        Layout *layout = new Layout();
        layout->Name = Layout::ModelLayoutName;
        layout->AssociatedBlock(record);
        return record;
    }

    static BlockRecord *PaperSpace()
    {
        BlockRecord *record = new BlockRecord(PaperSpaceName);
        Layout *layout = new Layout();
        layout->Name = Layout::PaperLayoutName;
        layot->AssociatedBlock(record);
        return record;
    }

    dwg::ObjectType ObjectType() const override
    {
        return ObjectType::BLOCK_HEADER;
    }
    std::string ObjectName() const override
    {
        return DxfFileToken::TableBlockRecord;
    }
    std::string SubclasMarker() const override
    {
        return DxfSubclasMarker::BlockRecord;
    }

    units::UnitsType Units;

    blockes::BlockTypeFlags Flags;

    bool IsExplodable;                 // 280
    bool CanScale;                     // 281
    std::vector<unsigned char> Preview;// 310
    Layout *Layout;                    // handle 340

    bool HasAttributes;
    std::vector<entities::Viewport> Viewports;
    CadObjectCollection<Entity *> Entities;

    Block BlockEntity;
    BlockEnd BlockEnd;
};

class BlockRecordsTable : public Table<BlockRecord>
{
};

}// namespace tables
}// namespace dwg
