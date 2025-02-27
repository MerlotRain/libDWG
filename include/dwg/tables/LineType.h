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

#include <dwg/Coordinate.h>
#include <dwg/tables/LinetypeShapeFlags.h>
#include <dwg/tables/TableCollection.h>
#include <dwg/tables/TableEntry.h>
#include <dwg/tables/TextStyle.h>


namespace dwg {

class TextStyle;

class LIBDWG_API LineType : public TableEntry
{
public:
    struct Segment
    {
        double Length;
        LinetypeShapeFlags ShapeFlag;
        short ShapeNumber;
        XY Offset;
        double Rotation;
        double Scale;
        std::string Text;
        TextStyle *Style;
    };

public:
    LineType();

    LineType(const std::string &name);

    static constexpr auto ByLayerName = "ByLayer";

    static constexpr auto ByBlockName = "ByBlock";

    static constexpr auto ContinuousName = "Continuous";

    static LineType *ByLayer();

    static LineType *ByBlock();

    static LineType *Continuous();

    ObjectType objectType() const override;

    std::string objectName() const override;

    std::string subclassMarker() const override;

    std::string Description() const;

    void description(const std::string &);

    double patternLen() const;

    char alignment() const;

    void alignment(char);

    std::vector<Segment> segments() const;

    void segments(const std::vector<Segment> &);

    void addSegment(const Segment &);
};

class LIBDWG_API LineTypesTable : public Table<LineType>
{
public:
    LineType *ByLayer;
    LineType *ByBlock;
    LineType *Continuous;

    ObjectType objectType() const override;

    LineTypesTable() = default;

protected:
    std::vector<std::string> defaultEntries() const;
};

}// namespace dwg
