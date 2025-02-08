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

#include <cpl_ports.h>
#include <dwg/ACadVersion.h>
#include <dwg/Color.h>
#include <dwg/Coordinate.h>
#include <dwg/LineWeightType.h>
#include <dwg/entities/VerticalAlignmentType.h>
#include <dwg/exports.h>
#include <dwg/header/AttributeVisibilityMode.h>
#include <dwg/header/DimensionAssociation.h>
#include <dwg/header/EntityPlotStyleType.h>
#include <dwg/header/IndexCreationFlags.h>
#include <dwg/header/MeasurementUnits.h>
#include <dwg/header/ObjectSnapMode.h>
#include <dwg/header/ObjectSortingFlags.h>
#include <dwg/header/ShadeEdgeType.h>
#include <dwg/header/ShadowMode.h>
#include <dwg/header/SpaceLineTypeScaling.h>
#include <dwg/header/SplineType.h>
#include <dwg/tables/ArcLengthSymbolPosition.h>
#include <dwg/tables/DimensionTextBackgroundFillMode.h>
#include <dwg/tables/DimensionTextHorizontalAlignment.h>
#include <dwg/tables/DimensionTextVerticalAlignment.h>
#include <dwg/tables/FractionFormat.h>
#include <dwg/tables/TextArrowFitType.h>
#include <dwg/tables/TextDirection.h>
#include <dwg/tables/TextMovement.h>
#include <dwg/tables/ToleranceAlignment.h>
#include <dwg/tables/ZeroHandling.h>
#include <dwg/units/AngularDirection.h>
#include <dwg/units/AngularUnitFormat.h>
#include <dwg/units/LinearUnitFormat.h>
#include <dwg/units/UnitsType.h>

namespace dwg {

class UCS;
class Layer;
class LineType;
class TextStyle;
class DimensionStyle;
class CadDocument;

class CadHeaderPrivate;
class LIBDWG_API CadHeader
{
    CadHeaderPrivate *d;

public:
    CadHeader();
    CadHeader(CadDocument *document);
    CadHeader(ACadVersion version);

    std::string versionString() const;
    void setVersionString(const std::string &);

    ACadVersion version() const;
    void setVersion(ACadVersion);

    short maintenanceVersion() const;
    void setMaintenanceVersion(short);

    std::string codePage() const;
    void setCodePage(const std::string &);

    std::string lastSavedBy() const;
    void setLastSavedBy(const std::string &);

    bool associatedDimensions() const;
    void setAssociatedDimensions(bool);

    bool updateDimensionsWhileDragging() const;
    void setUpdateDimensionsWhileDragging(bool);

    bool dIMSAV() const;
    void setDIMSAV(bool);

    MeasurementUnits measurementUnits() const;
    void setMeasurementUnits(MeasurementUnits);

    bool polylineLineTypeGeneration() const;
    void setPolylineLineTypeGeneration(bool);

    bool orthoMode() const;
    void setOrthoMode(bool);

    bool regenerationMode() const;
    void setRegenerationMode(bool);

    bool fillMode() const;
    void setFillMode(bool);

    bool quickTextMode() const;
    void setQuickTextMode(bool);

    SpaceLineTypeScaling paperSpaceLineTypeScaling() const;
    void setPaperSpaceLineTypeScaling(SpaceLineTypeScaling);

    bool limitCheckingOn() const;
    void setLimitCheckingOn(bool);

    bool blipMode() const;
    void setBlipMode(bool);

    bool userTimer() const;
    void setUserTimer(bool);

    bool sketchPolylines() const;
    void setSketchPolylines(bool);

    AngularDirection angularDirection() const;
    void setAngularDirection(AngularDirection);

    bool showSplineControlPoints() const;
    void setShowSplineControlPoints(bool);

    bool mirrorText() const;
    void setMirrorText(bool);

    bool worldView() const;
    void setWorldView(bool);

    bool showModelSpace() const;
    void setShowModelSpace(bool);

    bool paperSpaceLimitsChecking() const;
    void setPaperSpaceLimitsChecking(bool);

    bool retainXRefDependentVisibilitySettings() const;
    void setRetainXRefDependentVisibilitySettings(bool);

    bool displaySilhouetteCurves() const;
    void setDisplaySilhouetteCurves(bool);

    bool createEllipseAsPolyline() const;
    void setCreateEllipseAsPolyline(bool);

    bool proxyGraphics() const;
    void setProxyGraphics(bool);

    short spatialIndexMaxTreeDepth() const;
    void setSpatialIndexMaxTreeDepth(short);

    LinearUnitFormat linearUnitFormat() const;
    void setLinearUnitFormat(LinearUnitFormat);

    short linearUnitPrecision() const;
    void setLinearUnitPrecision(short);

    AngularUnitFormat angularUnit() const;
    void setAngularUnit(AngularUnitFormat);

    short angularUnitPrecision() const;
    void setAngularUnitPrecision(short);

    ObjectSnapMode objectSnapMode() const;
    void setObjectSnapMode(ObjectSnapMode);

    AttributeVisibilityMode attributeVisibility() const;
    void setAttributeVisibility(AttributeVisibilityMode);

    short pointDisplayMode() const;
    void setPointDisplayMode(short);

    short userShort1() const;
    void setUserShort1(short);

    short userShort2() const;
    void setUserShort2(short);

    short userShort3() const;
    void setUserShort3(short);

    short userShort4() const;
    void setUserShort4(short);

    short userShort5() const;
    void setUserShort5(short);

    short numberOfSplineSegments() const;
    void setNumberOfSplineSegments(short);

    short surfaceDensityU() const;
    void setSurfaceDensityU(short);

    short surfaceDensityV() const;
    void setSurfaceDensityV(short);

    short surfaceType() const;
    void setSurfaceType(short);

    short surfaceMeshTabulationCount1() const;
    void setSurfaceMeshTabulationCount1(short);

    short surfaceMeshTabulationCount2() const;
    void setSurfaceMeshTabulationCount2(short);

    SplineType splineType() const;
    void setSplineType(SplineType);

    ShadeEdgeType shadeEdge() const;
    void setShadeEdge(ShadeEdgeType);

    short shadeDiffuseToAmbientPercentage() const;
    void setShadeDiffuseToAmbientPercentage(short);

    short unitMode() const;
    void setUnitMode(short);

    short maxViewportCount() const;
    void setMaxViewportCount(short);

    short surfaceIsolineCount() const;
    void setSurfaceIsolineCount(short);

    VerticalAlignmentType currentMultilineJustification() const;
    void setCurrentMultilineJustification(VerticalAlignmentType);

    short textQuality() const;
    void setTextQuality(short);

    double lineTypeScale() const;
    void setLineTypeScale(double);

    double textHeightDefault() const;
    void setTextHeightDefault(double);

    std::string textStyleName() const;
    void setTextStyleName(const std::string &);

    std::string currentLayerName() const;
    void setCurrentLayerName(const std::string &);

    std::string currentLineTypeName() const;
    void setCurrentLineTypeName(const std::string &);

    std::string multiLineStyleName() const;
    void setMultiLineStyleName(const std::string &);

    double traceWidthDefault() const;
    void setTraceWidthDefault(double);

    double sketchIncrement() const;
    void setSketchIncrement(double);

    double filletRadius() const;
    void setFilletRadius(double);

    double thicknessDefault() const;
    void setThicknessDefault(double);

    double angleBase() const;
    void setAngleBase(double);

    double pointDisplaySize() const;
    void setPointDisplaySize(double);

    double polylineWidthDefault() const;
    void setPolylineWidthDefault(double);

    double userDouble1() const;
    void setUserDouble1(double);

    double userDouble2() const;
    void setUserDouble2(double);

    double userDouble3() const;
    void setUserDouble3(double);

    double userDouble4() const;
    void setUserDouble4(double);

    double userDouble5() const;
    void setUserDouble5(double);

    double chamferDistance1() const;
    void setChamferDistance1(double);

    double chamferDistance2() const;
    void setChamferDistance2(double);

    double chamferLength() const;
    void setChamferLength(double);

    double chamferAngle() const;
    void setChamferAngle(double);

    double facetResolution() const;
    void setFacetResolution(double);

    double currentMultilineScale() const;
    void setCurrentMultilineScale(double);

    double currentEntityLinetypeScale() const;
    void setCurrentEntityLinetypeScale(double);

    std::string menuFileName() const;
    void setMenuFileName(const std::string &);

    unsigned long long handleSeed() const;
    void setHandleSeed(unsigned long long);

    time_t createDateTime() const;
    void setCreateDateTime(time_t);

    time_t universalCreateDateTime() const;
    void setUniversalCreateDateTime(time_t);

    time_t updateDateTime() const;
    void setUpdateDateTime(time_t);

    time_t universalUpdateDateTime() const;
    void setUniversalUpdateDateTime(time_t);

    double totalEditingTime() const;
    void setTotalEditingTime(double);

    double userElapsedTimeSpan() const;
    void setUserElapsedTimeSpan(double);

    Color currentEntityColor() const;
    void setCurrentEntityColor(const Color &);

    double viewportDefaultViewScaleFactor() const;
    void setViewportDefaultViewScaleFactor(double);

    XYZ paperSpaceInsertionBase() const;
    void setPaperSpaceInsertionBase(const XYZ &);

    XYZ paperSpaceExtMin() const;
    void setPaperSpaceExtMin(const XYZ &);

    XYZ paperSpaceExtMax() const;
    void setPaperSpaceExtMax(const XYZ &);

    XY paperSpaceLimitsMin() const;
    void setPaperSpaceLimitsMin(const XYZ &);

    XY paperSpaceLimitsMax() const;
    void setPaperSpaceLimitsMax(const XY &);

    double paperSpaceElevation() const;
    void setPaperSpaceElevation(double);

    std::string paperSpaceBaseName() const;
    void setPaperSpaceBaseName(const std::string &);

    std::string paperSpaceName() const;
    void setPaperSpaceName(const std::string &);

    XYZ paperSpaceUcsOrigin() const;
    void setPaperSpaceUcsOrigin(const XYZ &);

    XYZ paperSpaceUcsXAxis() const;
    void setPaperSpaceUcsXAxis(const XYZ &);

    XYZ paperSpaceUcsYAxis() const;
    void setPaperSpaceUcsYAxis(const XYZ &);

    XYZ paperSpaceOrthographicTopDOrigin() const;
    void setPaperSpaceOrthographicTopDOrigin(const XYZ &);

    XYZ paperSpaceOrthographicBottomDOrigin() const;
    void setPaperSpaceOrthographicBottomDOrigin(const XYZ &);

    XYZ paperSpaceOrthographicLeftDOrigin() const;
    void setPaperSpaceOrthographicLeftDOrigin(const XYZ &);

    XYZ paperSpaceOrthographicRightDOrigin() const;
    void setPaperSpaceOrthographicRightDOrigin(const XYZ &);

    XYZ paperSpaceOrthographicFrontDOrigin() const;
    void setPaperSpaceOrthographicFrontDOrigin(const XYZ &);

    XYZ paperSpaceOrthographicBackDOrigin() const;
    void setPaperSpaceOrthographicBackDOrigin(const XYZ &);

    XYZ modelSpaceOrthographicTopDOrigin() const;
    void setModelSpaceOrthographicTopDOrigin(const XYZ &);

    XYZ modelSpaceOrthographicBottomDOrigin() const;
    void setModelSpaceOrthographicBottomDOrigin(const XYZ &);

    XYZ modelSpaceOrthographicLeftDOrigin() const;
    void setModelSpaceOrthographicLeftDOrigin(const XYZ &);

    XYZ modelSpaceOrthographicRightDOrigin() const;
    void setModelSpaceOrthographicRightDOrigin(const XYZ &);

    XYZ modelSpaceOrthographicFrontDOrigin() const;
    void setModelSpaceOrthographicFrontDOrigin(const XYZ &);

    XYZ modelSpaceOrthographicBackDOrigin() const;
    void setModelSpaceOrthographicBackDOrigin(const XYZ &);

    XYZ modelSpaceInsertionBase() const;
    void setModelSpaceInsertionBase(const XYZ &);

    XYZ modelSpaceExtMin() const;
    void setModelSpaceExtMin(const XYZ &);

    XYZ modelSpaceExtMax() const;
    void setModelSpaceExtMax(const XYZ &);

    XY modelSpaceLimitsMin() const;
    void setModelSpaceLimitsMin(const XY &);

    XY modelSpaceLimitsMax() const;
    void setModelSpaceLimitsMax(const XY &);

    std::string ucsBaseName() const;
    void setUcsBaseName(const std::string &);

    std::string ucsName() const;
    void setUcsName(const std::string &);

    double elevation() const;
    void setElevation(double);

    XYZ modelSpaceOrigin() const;
    void setModelSpaceOrigin(const XYZ &);

    XYZ modelSpaceXAxis() const;
    void setModelSpaceXAxis(const XYZ &);

    XYZ modelSpaceYAxis() const;
    void setModelSpaceYAxis(const XYZ &);

    std::string dimensionBlockName() const;
    void setDimensionBlockName(const std::string &);

    std::string arrowBlockName() const;
    void setArrowBlockName(const std::string &);

    std::string dimensionBlockNameFirst() const;
    void setDimensionBlockNameFirst(const std::string &);

    std::string dimensionBlockNameSecond() const;
    void setDimensionBlockNameSecond(const std::string &);

    short stackedTextAlignment() const;
    void setStackedTextAlignment(short);

    short stackedTextSizePercentage() const;
    void setStackedTextSizePercentage(short);

    std::string hyperLinkBase() const;
    void setHyperLinkBase(const std::string &);

    LineweightType currentEntityLineWeight() const;
    void setCurrentEntityLineWeight(LineweightType);

    short endCaps() const;
    void setEndCaps(short);

    short joinStyle() const;
    void setJoinStyle(short);

    bool displayLineWeight() const;
    void setDisplayLineWeight(bool);

    bool xEdit() const;
    void setXEdit(bool);

    bool extendedNames() const;
    void setExtendedNames(bool);

    short plotStyleMode() const;
    void setPlotStyleMode(short);

    bool loadOLEObject() const;
    void setLoadOLEObject(bool);

    UnitsType insUnits() const;
    void setInsUnits(UnitsType);

    EntityPlotStyleType currentEntityPlotStyle() const;
    void setCurrentEntityPlotStyle(EntityPlotStyleType);

    std::string fingerPrintGuid() const;
    void setFingerPrintGuid(const std::string &);

    std::string versionGuid() const;
    void setVersionGuid(const std::string &);

    ObjectSortingFlags entitySortingFlags() const;
    void setEntitySortingFlags(ObjectSortingFlags);

    IndexCreationFlags indexCreationFlags() const;
    void setIndexCreationFlags(IndexCreationFlags);

    unsigned char hideText() const;
    void setHideText(unsigned char);

    unsigned char externalReferenceClippingBoundaryType() const;
    void setExternalReferenceClippingBoundaryType(unsigned char);

    DimensionAssociation dimensionAssociativity() const;
    void setDimensionAssociativity(DimensionAssociation);

    unsigned char haloGapPercentage() const;
    void setHaloGapPercentage(unsigned char);

    Color obscuredColor() const;
    void setObscuredColor(const Color &);

    Color interfereColor() const;
    void setInterfereColor(const Color &);

    unsigned char obscuredType() const;
    void setObscuredType(unsigned char);

    unsigned char intersectionDisplay() const;
    void setIntersectionDisplay(unsigned char);

    std::string projectName() const;
    void setProjectName(const std::string &);

    bool cameraDisplayObjects() const;
    void setCameraDisplayObjects(bool);

    double stepsPerSecond() const;
    void setStepsPerSecond(double);

    double stepSize() const;
    void setStepSize(double);

    double dw3DPrecision() const;
    void setDw3DPrecision(double);

    double lensLength() const;
    void setLensLength(double);

    double cameraHeight() const;
    void setCameraHeight(double);

    char solidsRetainHistory() const;
    void setSolidsRetainHistory(char);

    char showSolidsHistory() const;
    void setShowSolidsHistory(char);

    double sweptSolidWidth() const;
    void setSweptSolidWidth(double);

    double sweptSolidHeight() const;
    void setSweptSolidHeight(double);

    double draftAngleFirstCrossSection() const;
    void setDraftAngleFirstCrossSection(double);

    double draftAngleSecondCrossSection() const;
    void setDraftAngleSecondCrossSection(double);

    double draftMagnitudeFirstCrossSection() const;
    void setDraftMagnitudeFirstCrossSection(double);

    double draftMagnitudeSecondCrossSection() const;
    void setDraftMagnitudeSecondCrossSection(double);

    short solidLoftedShape() const;
    void setSolidLoftedShape(short);

    char loftedObjectNormals() const;
    void setLoftedObjectNormals(char);

    double latitude() const;
    void setLatitude(double);

    double longitude() const;
    void setLongitude(double);

    double northDirection() const;
    void setNorthDirection(double);

    int timeZone() const;
    void setTimeZone(int);

    char displayLightGlyphs() const;
    void setDisplayLightGlyphs(char);

    char dwgUnderlayFramesVisibility() const;
    void setDwgUnderlayFramesVisibility(char);

    char dgnUnderlayFramesVisibility() const;
    void setDgnUnderlayFramesVisibility(char);

    ShadowMode shadowMode() const;
    void setShadowMode(ShadowMode);

    double shadowPlaneLocation() const;
    void setShadowPlaneLocation(double);

    std::string styleSheetName() const;
    void setStyleSheetName(const std::string &);

    std::string dimensionTextStyleName() const;
    void setDimensionTextStyleName(const std::string &);

    std::string dimensionStyleOverridesName() const;
    void setDimensionStyleOverridesName(const std::string &);

    short dimensionAngularDimensionDecimalPlaces() const;
    void setDimensionAngularDimensionDecimalPlaces(short);

    short dimensionDecimalPlaces() const;
    void setDimensionDecimalPlaces(short);

    short dimensionToleranceDecimalPlaces() const;
    void setDimensionToleranceDecimalPlaces(short);

    bool dimensionAlternateUnitDimensioning() const;
    void setDimensionAlternateUnitDimensioning(bool);

    LinearUnitFormat dimensionAlternateUnitFormat() const;
    void setDimensionAlternateUnitFormat(LinearUnitFormat);

    double dimensionAlternateUnitScaleFactor() const;
    void setDimensionAlternateUnitScaleFactor(double);

    double dimensionExtensionLineOffset() const;
    void setDimensionExtensionLineOffset(double);

    double dimensionScaleFactor() const;
    void setDimensionScaleFactor(double);

    short dimensionAlternateUnitDecimalPlaces() const;
    void setDimensionAlternateUnitDecimalPlaces(short);

    short dimensionAlternateUnitToleranceDecimalPlaces() const;
    void setDimensionAlternateUnitToleranceDecimalPlaces(short);

    AngularUnitFormat dimensionAngularUnit() const;
    void setDimensionAngularUnit(AngularUnitFormat);

    FractionFormat dimensionFractionFormat() const;
    void setDimensionFractionFormat(FractionFormat);

    LinearUnitFormat dimensionLinearUnitFormat() const;
    void setDimensionLinearUnitFormat(LinearUnitFormat);

    char dimensionDecimalSeparator() const;
    void setDimensionDecimalSeparator(char);

    TextMovement dimensionTextMovement() const;
    void setDimensionTextMovement(TextMovement);

    DimensionTextHorizontalAlignment dimensionTextHorizontalAlignment() const;
    void setDimensionTextHorizontalAlignment(DimensionTextHorizontalAlignment);

    bool dimensionSuppressFirstDimensionLine() const;
    void setDimensionSuppressFirstDimensionLine(bool);

    bool dimensionSuppressSecondDimensionLine() const;
    void setDimensionSuppressSecondDimensionLine(bool);

    bool dimensionGenerateTolerances() const;
    void setDimensionGenerateTolerances(bool);

    ToleranceAlignment dimensionToleranceAlignment() const;
    void setDimensionToleranceAlignment(ToleranceAlignment);

    ZeroHandling dimensionZeroHandling() const;
    void setDimensionZeroHandling(ZeroHandling);

    ZeroHandling dimensionToleranceZeroHandling() const;
    void setDimensionToleranceZeroHandling(ZeroHandling);

    short dimensionFit() const;
    void setDimensionFit(short);

    ZeroHandling dimensionAlternateUnitZeroHandling() const;
    void setDimensionAlternateUnitZeroHandling(ZeroHandling);

    ZeroHandling dimensionAlternateUnitToleranceZeroHandling() const;
    void setDimensionAlternateUnitToleranceZeroHandling(ZeroHandling);

    bool dimensionCursorUpdate() const;
    void setDimensionCursorUpdate(bool);

    TextArrowFitType dimensionDimensionTextArrowFit() const;
    void setDimensionDimensionTextArrowFit(TextArrowFitType);

    double dimensionAlternateUnitRounding() const;
    void setDimensionAlternateUnitRounding(double);

    std::string dimensionAlternateDimensioningSuffix() const;
    void setDimensionAlternateDimensioningSuffix(const std::string &);

    double dimensionArrowSize() const;
    void setDimensionArrowSize(double);

    ZeroHandling dimensionAngularZeroHandling() const;
    void setDimensionAngularZeroHandling(ZeroHandling);

    ArcLengthSymbolPosition dimensionArcLengthSymbolPosition() const;
    void setDimensionArcLengthSymbolPosition(ArcLengthSymbolPosition);

    bool dimensionSeparateArrowBlocks() const;
    void setDimensionSeparateArrowBlocks(bool);

    double dimensionCenterMarkSize() const;
    void setDimensionCenterMarkSize(double);

    double dimensionTickSize() const;
    void setDimensionTickSize(double);

    Color dimensionLineColor() const;
    void setDimensionLineColor(const Color &);

    Color dimensionExtensionLineColor() const;
    void setDimensionExtensionLineColor(const Color &);

    Color dimensionTextColor() const;
    void setDimensionTextColor(const Color &);

    double dimensionLineExtension() const;
    void setDimensionLineExtension(double);

    double dimensionLineIncrement() const;
    void setDimensionLineIncrement(double);

    double dimensionExtensionLineExtension() const;
    void setDimensionExtensionLineExtension(double);

    bool dimensionIsExtensionLineLengthFixed() const;
    void setDimensionIsExtensionLineLengthFixed(bool);

    double dimensionFixedExtensionLineLength() const;
    void setDimensionFixedExtensionLineLength(double);

    double dimensionJoggedRadiusDimensionTransverseSegmentAngle() const;
    void setDimensionJoggedRadiusDimensionTransverseSegmentAngle(double);

    DimensionTextBackgroundFillMode dimensionTextBackgroundFillMode() const;
    void setDimensionTextBackgroundFillMode(DimensionTextBackgroundFillMode);

    Color dimensionTextBackgroundColor() const;
    void setDimensionTextBackgroundColor(const Color &);

    double dimensionLineGap() const;
    void setDimensionLineGap(double);

    double dimensionLinearScaleFactor() const;
    void setDimensionLinearScaleFactor(double);

    double dimensionTextVerticalPosition() const;
    void setDimensionTextVerticalPosition(double);

    LineweightType dimensionLineWeight() const;
    void setDimensionLineWeight(LineweightType);

    LineweightType extensionLineWeight() const;
    void setExtensionLineWeight(LineweightType);

    std::string dimensionPostFix() const;
    void setDimensionPostFix(const std::string &);

    double dimensionRounding() const;
    void setDimensionRounding(double);

    bool dimensionSuppressFirstExtensionLine() const;
    void setDimensionSuppressFirstExtensionLine(bool);

    bool dimensionSuppressSecondExtensionLine() const;
    void setDimensionSuppressSecondExtensionLine(bool);

    bool dimensionSuppressOutsideExtensions() const;
    void setDimensionSuppressOutsideExtensions(bool);

    DimensionTextVerticalAlignment dimensionTextVerticalAlignment() const;
    void setDimensionTextVerticalAlignment(DimensionTextVerticalAlignment);

    short dimensionUnit() const;
    void setDimensionUnit(short);

    double dimensionToleranceScaleFactor() const;
    void setDimensionToleranceScaleFactor(double);

    bool dimensionTextInsideHorizontal() const;
    void setDimensionTextInsideHorizontal(bool);

    bool dimensionTextInsideExtensions() const;
    void setDimensionTextInsideExtensions(bool);

    double dimensionMinusTolerance() const;
    void setDimensionMinusTolerance(double);

    bool dimensionTextOutsideExtensions() const;
    void setDimensionTextOutsideExtensions(bool);

    bool dimensionTextOutsideHorizontal() const;
    void setDimensionTextOutsideHorizontal(bool);

    bool dimensionLimitsGeneration() const;
    void setDimensionLimitsGeneration();

    double dimensionPlusTolerance() const;
    void setDimensionPlusTolerance(double);

    double dimensionTextHeight() const;
    void setDimensionTextHeight(double);

    TextDirection dimensionTextDirection() const;
    void setDimensionTextDirection(TextDirection);

    double dimensionAltMzf() const;
    void setDimensionAltMzf(double);

    std::string dimensionAltMzs() const;
    void setDimensionAltMzs(const std::string &);

    double dimensionMzf() const;
    void setDimensionMzf(double);

    std::string dimensionMzs() const;
    void setDimensionMzs(const std::string &);

    std::string dimensionLineType() const;
    void setDimensionLineType(const std::string &);

    std::string dimensionTex1() const;
    void setDimensionTex1(const std::string &);

    std::string dimensionTex2() const;
    void setDimensionTex2(const std::string &);

    Layer *currentLayer() const;
    void setCurrentLayer(Layer *);

    LineType *currentLineType() const;
    void setCurrentLineType(LineType *);

    TextStyle *currentTextStyle() const;
    void setTextStyle(TextStyle *);

    TextStyle *dimensionTextStyle() const;
    void setDimensionTextStyle(TextStyle *);

    DimensionStyle *dimensionStyleOverrides() const;
    void setDimensionStyleOverrides(DimensionStyle *);

    UCS *modelSpaceUcs() const;
    void setModelSpaceUcs(UCS *);

    UCS *modelSpaceUcsBase() const;
    void setModelSpaceUcsBase(UCS *);

    UCS *paperSpaceUcs() const;
    void setPaperSpaceUcs(UCS *);

    UCS *paperSpaceUcsBase() const;
    void setPaperSpaceUcsBase(UCS *);
};

}// namespace dwg
