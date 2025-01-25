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

#include <dwg/tables/TableEntry.h>

namespace dwg {

class LIBDWG_API DG_AppId : public DG_TableEntry
{
public:
    DG_AppId(const char *name);
    
    ~DG_AppId();

    static CPL::String DefaultName;

    DG_ObjectType ObjectType() const override;
    
    CPL::String ObjectName() const override;
    
    CPL::String SubclassMarker() const override;
};
CPL_SMARTER_PTR(DG_AppId)

class LIBDWG_API DG_AppIdsTable : public DG_Table
{
public:
    DG_AppIdsTable();
    
    DG_ObjectType ObjectType() const override;
    
    CPL::String ObjectName() const override;

protected:
    std::vector<CPL::String> defaultEntries() const override;
};
CPL_SMARTER_PTR(DG_AppIdsTable)

}// namespace dwg