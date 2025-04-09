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

#include <dwg/DxfFileToken_p.h>
#include <dwg/tables/BlockRecord.h>
#include <dwg/tables/collections/BlockRecordsTable.h>

namespace dwg {

BlockRecordsTable::BlockRecordsTable() {}

BlockRecordsTable::BlockRecordsTable(CadDocument *document) : TableCollection(document) {}

BlockRecordsTable::~BlockRecordsTable() {}

ObjectType BlockRecordsTable::objectType() const
{
    return ObjectType::BLOCK_CONTROL_OBJ;
}

std::string BlockRecordsTable::objectName() const
{
    return DxfFileToken::TableBlockRecord;
}

std::vector<std::string> BlockRecordsTable::defaultEntries() const
{
    return {BlockRecord::ModelSpaceName, BlockRecord::PaperSpaceName};
}

bool BlockRecordsTable::assertType(TableEntry *item) const
{
    if (!item)
        return false;

    auto block = dynamic_cast<BlockRecord *>(item);
    return block ? true : false;
}

TableEntry *BlockRecordsTable::createEntry(const std::string &name)
{
    return new BlockRecord(name);
}

}// namespace dwg