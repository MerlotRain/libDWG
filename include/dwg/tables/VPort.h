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

#include <dwg/Color.h>
#include <dwg/Coordinate.h>
#include <dwg/OrthographicType.h>
#include <dwg/RenderMode.h>
#include <dwg/tables/DefaultLightingType.h>
#include <dwg/tables/GridFlags.h>
#include <dwg/tables/TableCollection.h>
#include <dwg/tables/TableEntry.h>
#include <dwg/tables/UscIconType.h>
#include <dwg/tables/ViewModeType.h>


namespace dwg {

class VisualStyle;
class UCS;

class LIBDWG_API VPort : public TableEntry
{
public:
    VPort();
    VPort(const std::string &name);

    static constexpr auto DefaultName = "*Active";

    static VPort *Default();

    ObjectType objectType() const override;

    std::string objectName() const override;

    std::string subclassMarker() const override;

    XY bottomLeft() const;
    void setBottomLeft(const XY &);

    XY topRight() const;
    void setTopRight(const XY &);

    XY center() const;
    void setCenter(const XY &);

    XY snapBasePoint() const;
    void setSnapBasePoint(const XY &);

    XY snapSpacing() const;
    void setSnapSpacing(const XY &);

    XY gridSpacing() const;
    void setGridSpacing(const XY &);

    XYZ direction() const;
    void setDirection(const XYZ &);

    XYZ target() const;
    void setTarget(const XYZ &);

    double viewHeight() const;
    void setViewHeight(double);

    double aspectRatio() const;
    void setAspectRatio(double);

    double lensLength() const;
    void setLensLength(double);

    double frontClippingPlane() const;
    void setFrontClippingPlane(double);

    double backClippingPlane() const;
    void setBackClippingPlane(double);

    double snapRotation() const;
    void setSnapRotation(double);

    double twistAngle() const;
    void setTwistAngle(double);

    short circleZoomPercent() const;
    void setCircleZoomPercent(short);

    RenderMode renderMode() const;
    void setRenderMode(RenderMode);

    ViewModeType viewMode() const;
    void setViewMode(ViewModeType);

    UscIconType ucsIconDisplay() const;
    void setUcsIconDisplay(UscIconType);

    bool snapOn() const;
    void setSnapOn(bool);

    bool showGrid() const;
    void setShowGrid(bool);

    bool isometricSnap() const;
    void setIsometricSnap(bool);

    short snapIsoPair() const;
    void setSnapIsoPair(short);

    XYZ origin() const;
    void setOrigin(const XYZ &);

    XYZ xAxis() const;
    void setXAxis(const XYZ &);

    XYZ yAxis() const;
    void setYAxis(const XYZ &);

    UCS *namedUcs() const;
    void setNamedUcs(UCS *);

    UCS *baseUcs() const;
    void setBaseUcs(UCS *);

    OrthographicType orthographicType() const;
    void setOrthographicType(OrthographicType);

    double elevation() const;
    void setElevation(double);

    GridFlags gridFlags() const;
    void setGridFlags(GridFlags);

    short minorGridLinesPerMajorGridLine() const;
    void setMinorGridLinesPerMajorGridLine(short);

    VisualStyle *visualStyle() const;
    void setVisualStyle(VisualStyle *);

    bool useDefaultLighting() const;
    void setUseDefaultLighting(bool);

    DefaultLightingType defaultLighting() const;
    void setDefaultLighting(DefaultLightingType);

    double brightness() const;
    void setBrightness(double);

    double contrast() const;
    void setContrast(double);

    Color ambientColor() const;
    void setAmbientColor(const Color &);
};


class LIBDWG_API VPortsTable : public Table<VPort>
{
public:
    VPortsTable();

    ObjectType objectType() const override;
    std::string objectName() const override;

protected:
    std::vector<std::string> defaultEntries() const override;
};

}// namespace dwg
