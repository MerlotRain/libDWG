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
#include <dwg/entities/InvisibleEdgeFlags.h>

namespace dwg {

class LIBDWG_API Face3D : public Entity
{
    RTTR_ENABLE(Entity)

public:
    Face3D();
    virtual ~Face3D();

    virtual ObjectType objectType() const override;
    virtual std::string objectName() const override;
    virtual std::string subclassMarker() const override;

    XYZ firstCorner() const;
    void setFirstCorner(const XYZ &);

    XYZ secondCorner() const;
    void setSecondCorner(const XYZ &);

    XYZ thirdCorner() const;
    void setThirdCorner(const XYZ &);

    XYZ fourthCorner() const;
    void setFourthCorner(const XYZ &);

    InvisibleEdgeFlags flags() const;
    void setFlags(InvisibleEdgeFlags);

private:
    XYZ _firstCorner;
    XYZ _secondCorner;
    XYZ _thirdCorner;
    XYZ _fourthCorner;
    InvisibleEdgeFlags _flags;
};

}// namespace dwg