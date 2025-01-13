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
#include <dwg/blocks/BlockTypeFlags.h>
#include <dwg/tables/BlockRecord.h>

namespace dwg {

class LIBDWG_API Block : public Entity
{
    std::string _name;
    BlockTypeFlags _flags;
    XYZ _base_point = XYZ::Zero;
    std::string _xrefPath;
    std::string _comments;
public:
    Block(BlockRecord *record);
    ~Block();

    dwg::ObjectType ObjectType() const override;
    std::string ObjectName() const override;
    std::string SubclassMarker() const override;

    BlockRecordPtr BlockRecord() const;

    std::string Name() const;
    void Name(const std::string& name);

    BlockTypeFlags Flags() const;
    void Flags(BlockTypeFlags flags);

    XYZ BasePoint() const;
    void BasePoint(XYZ p);

    std::string XrefPath() const;
    void XrefPath(const std::string& value);

    std::string Comments() const;
    void Comments(const std::string& value);

protected:
    Block();

};
SMARTER_PTR(Block)

}// namespace dwg