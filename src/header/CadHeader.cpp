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

#include <dwg/header/CadHeader.h>

namespace dwg {

/* --------------------------- CadHeaderPrivate -------------------------- */

class CadHeaderPrivate
{
public:
    CadHeaderPrivate();
    ~CadHeaderPrivate();

    std::string _versionString;
    ACadVersion _version;
    short _maintenanceVersion;
    std::string _codePage;
    std::string _lastSavedBy;
    bool _associatedDimensions;
    bool _updateDimensionsWhileDragging;
    bool _DIMSAV;
    MeasurementUnits _measurementUnits;
    bool _polylineLineTypeGeneration;
    bool _orthoMode;
    bool _regenerationMode;
    bool _fillMode;
    bool _quickTextMode;
    SpaceLineTypeScaling _paperSpaceLineTypeScaling;
    bool _limitCheckingOn;
    bool _blipMode;
    bool _userTimer;
    bool _sketchPolylines;
    AngularDirection _angularDirection;
    bool _showSplineControlPoints;
    bool _mirrorText;
    bool _worldView;
    bool _showModelSpace;
    bool _paperSpaceLimitsChecking;
    bool _retainXRefDependentVisibilitySettings;
    bool _displaySilhouetteCurves;
    bool _createEllipseAsPolyline;
    bool _proxyGraphics;
    short _spatialIndexMaxTreeDepth;
    LinearUnitFormat _linearUnitFormat;
    short _linearUnitPrecision;
    AngularUnitFormat _angularUnit;
    short _angularUnitPrecision;
    ObjectSnapMode _objectSnapMode;
    AttributeVisibilityMode _attributeVisibility;
    short _pointDisplayMode;
    short _userShort1;
    short _userShort2;
    short _userShort3;
    short _userShort4;
    short _userShort5;
    short _numberOfSplineSegments;
    short _surfaceDensityU;
    short _surfaceDensityV;
    short _surfaceType;
    short _surfaceMeshTabulationCount1;
    short _surfaceMeshTabulationCount2;
    SplineType _splineType;
    ShadeEdgeType _shadeEdge;
    short _shadeDiffuseToAmbientPercentage;
    short _unitMode;
    short _maxViewportCount;
    short _surfaceIsolineCount;
    VerticalAlignmentType _currentMultilineJustification;
    short _textQuality;
    double _lineTypeScale;
    double _textHeightDefault;
    std::string _textStyleName;
    std::string _currentLayerName;
    std::string _currentLineTypeName;
    std::string _multiLineStyleName;
    double _traceWidthDefault;
    double _sketchIncrement;
    double _filletRadius;
    double _thicknessDefault;
    double _angleBase;
    double _pointDisplaySize;
    double _polylineWidthDefault;
    double _userDouble1;
    double _userDouble2;
    double _userDouble3;
    double _userDouble4;
    double _userDouble5;
    double _chamferDistance1;
    double _chamferDistance2;
    double _chamferLength;
    double _chamferAngle;
    double _facetResolution;
    double _currentMultilineScale;
    double _currentEntityLinetypeScale;
    std::string _menuFileName;
    unsigned long long _handleSeed;
    time_t _createDateTime;
    time_t _universalCreateDateTime;
    time_t _updateDateTime;
    time_t _universalUpdateDateTime;
    double _totalEditingTime;
    double _userElapsedTimeSpan;
    Color _currentEntityColor;
    double _viewportDefaultViewScaleFactor;
    XYZ _paperSpaceInsertionBase;
    XYZ _paperSpaceExtMin;
    XYZ _paperSpaceExtMax;
    XY _paperSpaceLimitsMin;
    XY _paperSpaceLimitsMax;
    double _paperSpaceElevation;
    std::string _paperSpaceBaseName;
    std::string _paperSpaceName;
    XYZ _paperSpaceUcsOrigin;
    XYZ _paperSpaceUcsXAxis;
    XYZ _paperSpaceUcsYAxis;
    XYZ _paperSpaceOrthographicTopDOrigin;
    XYZ _paperSpaceOrthographicBottomDOrigin;
    XYZ _paperSpaceOrthographicLeftDOrigin;
    XYZ _paperSpaceOrthographicRightDOrigin;
    XYZ _paperSpaceOrthographicFrontDOrigin;
    XYZ _paperSpaceOrthographicBackDOrigin;
    XYZ _modelSpaceOrthographicTopDOrigin;
    XYZ _modelSpaceOrthographicBottomDOrigin;
    XYZ _modelSpaceOrthographicLeftDOrigin;
    XYZ _modelSpaceOrthographicRightDOrigin;
    XYZ _modelSpaceOrthographicFrontDOrigin;
    XYZ _modelSpaceOrthographicBackDOrigin;
    XYZ _modelSpaceInsertionBase;
    XYZ _modelSpaceExtMin;
    XYZ _modelSpaceExtMax;
    XY _modelSpaceLimitsMin;
    XY _modelSpaceLimitsMax;
    std::string _ucsBaseName;
    std::string _ucsName;
    double _elevation;
    XYZ _modelSpaceOrigin;
    XYZ _modelSpaceXAxis;
    XYZ _modelSpaceYAxis;
    std::string _dimensionBlockName;
    std::string _arrowBlockName;
    std::string _dimensionBlockNameFirst;
    std::string _dimensionBlockNameSecond;
    short _stackedTextAlignment;
    short _stackedTextSizePercentage;
    std::string _hyperLinkBase;
    LineweightType _currentEntityLineWeight;
    short _endCaps;
    short _joinStyle;
    bool _displayLineWeight;
    bool _xedit;
    bool _extendedNames;
    short _plotStyleMode;
    bool _loadOLEObject;
    UnitsType _dinsUnits;
    EntityPlotStyleType _currentEntityPlotStyle;
    std::string _fingerPrintGuid;
    std::string _versionGuid;
    ObjectSortingFlags _entitySortingFlags;
    IndexCreationFlags _indexCreationFlags;
    unsigned char _hideText;
    unsigned char _externalReferenceClippingBoundaryType;
    DimensionAssociation _dimensionAssociativity;
    unsigned char _haloGapPercentage;
    Color _obscuredColor;
    Color _interfereColor;
    unsigned char _obscuredType;
    unsigned char _intersectionDisplay;
    std::string _projectName;
    bool _cameraDisplayObjects;
    double _stepsPerSecond;
    double _stepSize;
    double _dw3DPrecision;
    double _lensLength;
    double _cameraHeight;
    char _solidsRetainHistory;
    char _showSolidsHistory;
    double _sweptSolidWidth;
    double _sweptSolidHeight;
    double _draftAngleFirstCrossSection;
    double _draftAngleSecondCrossSection;
    double _draftMagnitudeFirstCrossSection;
    double _draftMagnitudeSecondCrossSection;
    short _solidLoftedShape;
    char _loftedObjectNormals;
    double _latitude;
    double _longitude;
    double _northDirection;
    int _timeZone;
    char _displayLightGlyphs;
    char _dwgUnderlayFramesVisibility;
    char _dgnUnderlayFramesVisibility;
    ShadowMode _shadowMode;
    double _shadowPlaneLocation;
    std::string _styleSheetName;
    std::string _dimensionTextStyleName;
    std::string _dimensionStyleOverridesName;
    short _dimensionAngularDimensionDecimalPlaces;
    short _dimensionDecimalPlaces;
    short _dimensionToleranceDecimalPlaces;
    bool _dimensionAlternateUnitDimensioning;
    LinearUnitFormat _dimensionAlternateUnitFormat;
    double _dimensionAlternateUnitScaleFactor;
    double _dimensionExtensionLineOffset;
    double _dimensionScaleFactor;
    short _dimensionAlternateUnitDecimalPlaces;
    short _dimensionAlternateUnitToleranceDecimalPlaces;
    AngularUnitFormat _dimensionAngularUnit;
    FractionFormat _dimensionFractionFormat;
    LinearUnitFormat _dimensionLinearUnitFormat;
    char _dimensionDecimalSeparator;
    TextMovement _dimensionTextMovement;
    DimensionTextHorizontalAlignment _dimensionTextHorizontalAlignment;
    bool _dimensionSuppressFirstDimensionLine;
    bool _dimensionSuppressSecondDimensionLine;
    bool _dimensionGenerateTolerances;
    ToleranceAlignment _dimensionToleranceAlignment;
    ZeroHandling _dimensionZeroHandling;
    ZeroHandling _dimensionToleranceZeroHandling;
    short _dimensionFit;
    ZeroHandling _dimensionAlternateUnitZeroHandling;
    ZeroHandling _dimensionAlternateUnitToleranceZeroHandling;
    bool _dimensionCursorUpdate;
    TextArrowFitType _dimensionDimensionTextArrowFit;
    double _dimensionAlternateUnitRounding;
    std::string _dimensionAlternateDimensioningSuffix;
    double _dimensionArrowSize;
    ZeroHandling _dimensionAngularZeroHandling;
    ArcLengthSymbolPosition _dimensionArcLengthSymbolPosition;
    bool _dimensionSeparateArrowBlocks;
    double _dimensionCenterMarkSize;
    double _dimensionTickSize;
    Color _dimensionLineColor;
    Color _dimensionExtensionLineColor;
    Color _dimensionTextColor;
    double _dimensionLineExtension;
    double _dimensionLineIncrement;
    double _dimensionExtensionLineExtension;
    bool _dimensionIsExtensionLineLengthFixed;
    double _dimensionFixedExtensionLineLength;
    double _dimensionJoggedRadiusDimensionTransverseSegmentAngle;
    DimensionTextBackgroundFillMode _dimensionTextBackgroundFillMode;
    Color _dimensionTextBackgroundColor;
    double _dimensionLineGap;
    double _dimensionLinearScaleFactor;
    double _dimensionTextVerticalPosition;
    LineweightType _dimensionLineWeight;
    LineweightType _extensionLineWeight;
    std::string _dimensionPostFix;
    double _dimensionRounding;
    bool _dimensionSuppressFirstExtensionLine;
    bool _dimensionSuppressSecondExtensionLine;
    bool _dimensionSuppressOutsideExtensions;
    DimensionTextVerticalAlignment _dimensionTextVerticalAlignment;
    short _dimensionUnit;
    double _dimensionToleranceScaleFactor;
    bool _dimensionTextInsideHorizontal;
    bool _dimensionTextInsideExtensions;
    double _dimensionMinusTolerance;
    bool _dimensionTextOutsideExtensions;
    bool _dimensionTextOutsideHorizontal;
    bool _dimensionLimitsGeneration;
    double _dimensionPlusTolerance;
    double _dimensionTextHeight;
    TextDirection _dimensionTextDirection;
    double _dimensionAltMzf;
    std::string _dimensionAltMzs;
    double _dimensionMzf;
    std::string _dimensionMzs;
    std::string _dimensionLineType;
    std::string _dimensionTex1;
    std::string _dimensionTex2;

    Layer *_currentLayer;
    LineType *_currentLineType;
    TextStyle *_currentTextStyle;
    TextStyle *_dimensionTextStyle;
    DimensionStyle *_dimensionStyleOverrides;
    UCS *_modelSpaceUcs;
    UCS *_modelSpaceUcsBase;
    UCS *_paperSpaceUcs;
    UCS *_paperSpaceUcsBase;
};


/* --------------------------- CadHeader impls --------------------------- */

CadHeader::CadHeader() {}

CadHeader::CadHeader(CadDocument *document) {}

CadHeader::CadHeader(ACadVersion version) {}

std::string CadHeader::VersionString() const {}

void CadHeader::VersionString(const std::string &value) {}

ACadVersion CadHeader::Version() const {}

void CadHeader::Version(ACadVersion) {}

short CadHeader::MaintenanceVersion() const {}

void CadHeader::MaintenanceVersion(short) {}

std::string CadHeader::CodePage() const {}

void CadHeader::CodePage(const std::string &value) {}

std::string CadHeader::LastSavedBy() const {}

void CadHeader::LastSavedBy(const std::string &value) {}

bool CadHeader::AssociatedDimensions() const {}

void CadHeader::AssociatedDimensions(bool) {}

bool CadHeader::UpdateDimensionsWhileDragging() const {}

void CadHeader::UpdateDimensionsWhileDragging(bool) {}

bool CadHeader::DIMSAV() const {}

void CadHeader::DIMSAV(bool) {}

MeasurementUnits CadHeader::MeasurementUnits() const {}

void CadHeader::MeasurementUnits(MeasurementUnits) {}

bool CadHeader::PolylineLineTypeGeneration() const {}

void CadHeader::PolylineLineTypeGeneration(bool) {}

bool CadHeader::OrthoMode() const {}

void CadHeader::OrthoMode(bool) {}

bool CadHeader::RegenerationMode() const {}

void CadHeader::RegenerationMode(bool) {}

bool CadHeader::FillMode() const {}

void CadHeader::FillMode(bool) {}

bool CadHeader::QuickTextMode() const {}

void CadHeader::QuickTextMode(bool) {}

SpaceLineTypeScaling CadHeader::PaperSpaceLineTypeScaling() const {}

void CadHeader::PaperSpaceLineTypeScaling(SpaceLineTypeScaling) {}

bool CadHeader::LimitCheckingOn() const {}

void CadHeader::LimitCheckingOn(bool) {}

bool CadHeader::BlipMode() const {}

void CadHeader::BlipMode(bool) {}

bool CadHeader::UserTimer() const {}

void CadHeader::UserTimer(bool) {}

bool CadHeader::SketchPolylines() const {}

void CadHeader::SketchPolylines(bool) {}

AngularDirection CadHeader::AngularDirection() const {}

void CadHeader::AngularDirection(AngularDirection) {}

bool CadHeader::ShowSplineControlPoints() const {}

void CadHeader::ShowSplineControlPoints(bool) {}

bool CadHeader::MirrorText() const {}

void CadHeader::MirrorText(bool) {}

bool CadHeader::WorldView() const {}

void CadHeader::WorldView(bool) {}

bool CadHeader::ShowModelSpace() const {}

void CadHeader::ShowModelSpace(bool) {}

bool CadHeader::PaperSpaceLimitsChecking() const {}

void CadHeader::PaperSpaceLimitsChecking(bool) {}

bool CadHeader::RetainXRefDependentVisibilitySettings() const {}

void CadHeader::RetainXRefDependentVisibilitySettings(bool) {}

bool CadHeader::DisplaySilhouetteCurves() const {}

void CadHeader::DisplaySilhouetteCurves(bool) {}

bool CadHeader::CreateEllipseAsPolyline() const {}

void CadHeader::CreateEllipseAsPolyline(bool) {}

bool CadHeader::ProxyGraphics() const {}

void CadHeader::ProxyGraphics(bool) {}

short CadHeader::SpatialIndexMaxTreeDepth() const {}

void CadHeader::SpatialIndexMaxTreeDepth(short) {}

LinearUnitFormat CadHeader::LinearUnitFormat() const {}

void CadHeader::LinearUnitFormat(LinearUnitFormat) {}

short CadHeader::LinearUnitPrecision() const {}

void CadHeader::LinearUnitPrecision(short) {}

AngularUnitFormat CadHeader::AngularUnit() const {}

void CadHeader::AngularUnit(AngularUnitFormat) {}

short CadHeader::AngularUnitPrecision() const {}

void CadHeader::AngularUnitPrecision(short) {}

ObjectSnapMode CadHeader::ObjectSnapMode() const {}

void CadHeader::ObjectSnapMode(ObjectSnapMode) {}

AttributeVisibilityMode CadHeader::AttributeVisibility() const {}

void CadHeader::AttributeVisibility(AttributeVisibilityMode) {}

short CadHeader::PointDisplayMode() const {}

void CadHeader::PointDisplayMode(short) {}

short CadHeader::UserShort1() const {}

void CadHeader::UserShort1(short) {}

short CadHeader::UserShort2() const {}

void CadHeader::UserShort2(short) {}

short CadHeader::UserShort3() const {}

void CadHeader::UserShort3(short) {}

short CadHeader::UserShort4() const {}

void CadHeader::UserShort4(short) {}

short CadHeader::UserShort5() const {}

void CadHeader::UserShort5(short) {}

short CadHeader::NumberOfSplineSegments() const {}

void CadHeader::NumberOfSplineSegments(short) {}

short CadHeader::SurfaceDensityU() const {}

void CadHeader::SurfaceDensityU(short) {}

short CadHeader::SurfaceDensityV() const {}

void CadHeader::SurfaceDensityV(short) {}

short CadHeader::SurfaceType() const {}

void CadHeader::SurfaceType(short) {}

short CadHeader::SurfaceMeshTabulationCount1() const {}

void CadHeader::SurfaceMeshTabulationCount1(short) {}

short CadHeader::SurfaceMeshTabulationCount2() const {}

void CadHeader::SurfaceMeshTabulationCount2(short) {}

SplineType CadHeader::SplineType() const {}

void CadHeader::SplineType(SplineType) {}

ShadeEdgeType CadHeader::ShadeEdge() const {}

void CadHeader::ShadeEdge(ShadeEdgeType) {}

short CadHeader::ShadeDiffuseToAmbientPercentage() const {}

void CadHeader::ShadeDiffuseToAmbientPercentage(short) {}

short CadHeader::UnitMode() const {}

void CadHeader::UnitMode(short) {}

short CadHeader::MaxViewportCount() const {}

void CadHeader::MaxViewportCount(short) {}

short CadHeader::SurfaceIsolineCount() const {}

void CadHeader::SurfaceIsolineCount(short) {}

VerticalAlignmentType CadHeader::CurrentMultilineJustification() const {}

void CadHeader::CurrentMultilineJustification(VerticalAlignmentType) {}

short CadHeader::TextQuality() const {}

void CadHeader::TextQuality(short) {}

double CadHeader::LineTypeScale() const {}

void CadHeader::LineTypeScale(double) {}

double CadHeader::TextHeightDefault() const {}

void CadHeader::TextHeightDefault(double) {}

std::string CadHeader::TextStyleName() const {}

void CadHeader::TextStyleName(const std::string &value) {}

std::string CadHeader::CurrentLayerName() const {}

void CadHeader::CurrentLayerName(const std::string &value) {}

std::string CadHeader::CurrentLineTypeName() const {}

void CadHeader::CurrentLineTypeName(const std::string &value) {}

std::string CadHeader::MultiLineStyleName() const {}

void CadHeader::MultiLineStyleName(const std::string &value) {}

double CadHeader::TraceWidthDefault() const {}

void CadHeader::TraceWidthDefault(double) {}

double CadHeader::SketchIncrement() const {}

void CadHeader::SketchIncrement(double) {}

double CadHeader::FilletRadius() const {}

void CadHeader::FilletRadius(double) {}

double CadHeader::ThicknessDefault() const {}

void CadHeader::ThicknessDefault(double) {}

double CadHeader::AngleBase() const {}

void CadHeader::AngleBase(double) {}

double CadHeader::PointDisplaySize() const {}

void CadHeader::PointDisplaySize(double) {}

double CadHeader::PolylineWidthDefault() const {}

void CadHeader::PolylineWidthDefault(double) {}

double CadHeader::UserDouble1() const {}

void CadHeader::UserDouble1(double) {}

double CadHeader::UserDouble2() const {}

void CadHeader::UserDouble2(double) {}

double CadHeader::UserDouble3() const {}

void CadHeader::UserDouble3(double) {}

double CadHeader::UserDouble4() const {}

void CadHeader::UserDouble4(double) {}

double CadHeader::UserDouble5() const {}

void CadHeader::UserDouble5(double) {}

double CadHeader::ChamferDistance1() const {}

void CadHeader::ChamferDistance1(double) {}

double CadHeader::ChamferDistance2() const {}

void CadHeader::ChamferDistance2(double) {}

double CadHeader::ChamferLength() const {}

void CadHeader::ChamferLength(double) {}

double CadHeader::ChamferAngle() const {}

void CadHeader::ChamferAngle(double) {}

double CadHeader::FacetResolution() const {}

void CadHeader::FacetResolution(double) {}

double CadHeader::CurrentMultilineScale() const {}

void CadHeader::CurrentMultilineScale(double) {}

double CadHeader::CurrentEntityLinetypeScale() const {}

void CadHeader::CurrentEntityLinetypeScale(double) {}

std::string CadHeader::MenuFileName() const {}

void CadHeader::MenuFileName(const std::string &value) {}

unsigned long long CadHeader::HandleSeed() const {}

void CadHeader::HandleSeed(unsigned long long) {}

time_t CadHeader::CreateDateTime() const {}

void CadHeader::CreateDateTime(time_t) {}

time_t CadHeader::UniversalCreateDateTime() const {}

void CadHeader::UniversalCreateDateTime(time_t) {}

time_t CadHeader::UpdateDateTime() const {}

void CadHeader::UpdateDateTime(time_t) {}

time_t CadHeader::UniversalUpdateDateTime() const {}

void CadHeader::UniversalUpdateDateTime(time_t) {}

double CadHeader::TotalEditingTime() const {}

void CadHeader::TotalEditingTime(double) {}

double CadHeader::UserElapsedTimeSpan() const {}

void CadHeader::UserElapsedTimeSpan(double) {}

Color CadHeader::CurrentEntityColor() const {}

void CadHeader::CurrentEntityColor(const Color &) {}

double CadHeader::ViewportDefaultViewScaleFactor() const {}

void CadHeader::ViewportDefaultViewScaleFactor(double) {}

XYZ CadHeader::PaperSpaceInsertionBase() const {}

void CadHeader::PaperSpaceInsertionBase(const XYZ &) {}

XYZ CadHeader::PaperSpaceExtMin() const {}

void CadHeader::PaperSpaceExtMin(const XYZ &) {}

XYZ CadHeader::PaperSpaceExtMax() const {}

void CadHeader::PaperSpaceExtMax(const XYZ &) {}

XY CadHeader::PaperSpaceLimitsMin() const {}

void CadHeader::PaperSpaceLimitsMin(const XYZ &) {}

XY CadHeader::PaperSpaceLimitsMax() const {}

void CadHeader::PaperSpaceLimitsMax(const XY &) {}

double CadHeader::PaperSpaceElevation() const {}

void CadHeader::PaperSpaceElevation(double) {}

std::string CadHeader::PaperSpaceBaseName() const {}

void CadHeader::PaperSpaceBaseName(const std::string &value) {}

std::string CadHeader::PaperSpaceName() const {}

void CadHeader::PaperSpaceName(const std::string &value) {}

XYZ CadHeader::PaperSpaceUcsOrigin() const {}

void CadHeader::PaperSpaceUcsOrigin(const XYZ &) {}

XYZ CadHeader::PaperSpaceUcsXAxis() const {}

void CadHeader::PaperSpaceUcsXAxis(const XYZ &) {}

XYZ CadHeader::PaperSpaceUcsYAxis() const {}

void CadHeader::PaperSpaceUcsYAxis(const XYZ &) {}

XYZ CadHeader::PaperSpaceOrthographicTopDOrigin() const {}

void CadHeader::PaperSpaceOrthographicTopDOrigin(const XYZ &) {}

XYZ CadHeader::PaperSpaceOrthographicBottomDOrigin() const {}

void CadHeader::PaperSpaceOrthographicBottomDOrigin(const XYZ &) {}

XYZ CadHeader::PaperSpaceOrthographicLeftDOrigin() const {}

void CadHeader::PaperSpaceOrthographicLeftDOrigin(const XYZ &) {}

XYZ CadHeader::PaperSpaceOrthographicRightDOrigin() const {}

void CadHeader::PaperSpaceOrthographicRightDOrigin(const XYZ &) {}

XYZ CadHeader::PaperSpaceOrthographicFrontDOrigin() const {}

void CadHeader::PaperSpaceOrthographicFrontDOrigin(const XYZ &) {}

XYZ CadHeader::PaperSpaceOrthographicBackDOrigin() const {}

void CadHeader::PaperSpaceOrthographicBackDOrigin(const XYZ &) {}

XYZ CadHeader::ModelSpaceOrthographicTopDOrigin() const {}

void CadHeader::ModelSpaceOrthographicTopDOrigin(const XYZ &) {}

XYZ CadHeader::ModelSpaceOrthographicBottomDOrigin() const {}

void CadHeader::ModelSpaceOrthographicBottomDOrigin(const XYZ &) {}

XYZ CadHeader::ModelSpaceOrthographicLeftDOrigin() const {}

void CadHeader::ModelSpaceOrthographicLeftDOrigin(const XYZ &) {}

XYZ CadHeader::ModelSpaceOrthographicRightDOrigin() const {}

void CadHeader::ModelSpaceOrthographicRightDOrigin(const XYZ &) {}

XYZ CadHeader::ModelSpaceOrthographicFrontDOrigin() const {}

void CadHeader::ModelSpaceOrthographicFrontDOrigin(const XYZ &) {}

XYZ CadHeader::ModelSpaceOrthographicBackDOrigin() const {}

void CadHeader::ModelSpaceOrthographicBackDOrigin(const XYZ &) {}

XYZ CadHeader::ModelSpaceInsertionBase() const {}

void CadHeader::ModelSpaceInsertionBase(const XYZ &) {}

XYZ CadHeader::ModelSpaceExtMin() const {}

void CadHeader::ModelSpaceExtMin(const XYZ &) {}

XYZ CadHeader::ModelSpaceExtMax() const {}

void CadHeader::ModelSpaceExtMax(const XYZ &) {}

XY CadHeader::ModelSpaceLimitsMin() const {}

void CadHeader::ModelSpaceLimitsMin(const XY &) {}

XY CadHeader::ModelSpaceLimitsMax() const {}

void CadHeader::ModelSpaceLimitsMax(const XY &) {}

std::string CadHeader::UcsBaseName() const {}

void CadHeader::UcsBaseName(const std::string &value) {}

std::string CadHeader::UcsName() const {}

void CadHeader::UcsName(const std::string &value) {}

double CadHeader::Elevation() const {}

void CadHeader::Elevation(double) {}

XYZ CadHeader::ModelSpaceOrigin() const {}

void CadHeader::ModelSpaceOrigin(const XYZ &) {}

XYZ CadHeader::ModelSpaceXAxis() const {}

void CadHeader::ModelSpaceXAxis(const XYZ &) {}

XYZ CadHeader::ModelSpaceYAxis() const {}

void CadHeader::ModelSpaceYAxis(const XYZ &) {}

std::string CadHeader::DimensionBlockName() const {}

void CadHeader::DimensionBlockName(const std::string &value) {}

std::string CadHeader::ArrowBlockName() const {}

void CadHeader::ArrowBlockName(const std::string &value) {}

std::string CadHeader::DimensionBlockNameFirst() const {}

void CadHeader::DimensionBlockNameFirst(const std::string &value) {}

std::string CadHeader::DimensionBlockNameSecond() const {}

void CadHeader::DimensionBlockNameSecond(const std::string &value) {}

short CadHeader::StackedTextAlignment() const {}

void CadHeader::StackedTextAlignment(short) {}

short CadHeader::StackedTextSizePercentage() const {}

void CadHeader::StackedTextSizePercentage(short) {}

std::string CadHeader::HyperLinkBase() const {}

void CadHeader::HyperLinkBase(const std::string &value) {}

LineweightType CadHeader::CurrentEntityLineWeight() const {}

void CadHeader::CurrentEntityLineWeight(LineweightType) {}

short CadHeader::EndCaps() const {}

void CadHeader::EndCaps(short) {}

short CadHeader::JoinStyle() const {}

void CadHeader::JoinStyle(short) {}

bool CadHeader::DisplayLineWeight() const {}

void CadHeader::DisplayLineWeight(bool) {}

bool CadHeader::XEdit() const {}

void CadHeader::XEdit(bool) {}

bool CadHeader::ExtendedNames() const {}

void CadHeader::ExtendedNames(bool) {}

short CadHeader::PlotStyleMode() const {}

void CadHeader::PlotStyleMode(short) {}

bool CadHeader::LoadOLEObject() const {}

void CadHeader::LoadOLEObject(bool) {}

UnitsType CadHeader::InsUnits() const {}

void CadHeader::InsUnits(UnitsType) {}

EntityPlotStyleType CadHeader::CurrentEntityPlotStyle() const {}

void CadHeader::CurrentEntityPlotStyle(EntityPlotStyleType) {}

std::string CadHeader::FingerPrintGuid() const {}

void CadHeader::FingerPrintGuid(const std::string &value) {}

std::string CadHeader::VersionGuid() const {}

void CadHeader::VersionGuid(const std::string &value) {}

ObjectSortingFlags CadHeader::EntitySortingFlags() const {}

void CadHeader::EntitySortingFlags(ObjectSortingFlags) {}

IndexCreationFlags CadHeader::IndexCreationFlags() const {}

void CadHeader::IndexCreationFlags(IndexCreationFlags) {}

unsigned char CadHeader::HideText() const {}

void CadHeader::HideText(unsigned char) {}

unsigned char CadHeader::ExternalReferenceClippingBoundaryType() const {}

void CadHeader::ExternalReferenceClippingBoundaryType(unsigned char) {}

DimensionAssociation CadHeader::DimensionAssociativity() const {}

void CadHeader::DimensionAssociativity(DimensionAssociation) {}

unsigned char CadHeader::HaloGapPercentage() const {}

void CadHeader::HaloGapPercentage(unsigned char) {}

Color CadHeader::ObscuredColor() const {}

void CadHeader::ObscuredColor(const Color &) {}

Color CadHeader::InterfereColor() const {}

void CadHeader::InterfereColor(const Color &) {}

unsigned char CadHeader::ObscuredType() const {}

void CadHeader::ObscuredType(unsigned char) {}

unsigned char CadHeader::IntersectionDisplay() const {}

void CadHeader::IntersectionDisplay(unsigned char) {}

std::string CadHeader::ProjectName() const {}

void CadHeader::ProjectName(const std::string &value) {}

bool CadHeader::CameraDisplayObjects() const {}

void CadHeader::CameraDisplayObjects(bool) {}

double CadHeader::StepsPerSecond() const {}

void CadHeader::StepsPerSecond(double) {}

double CadHeader::StepSize() const {}

void CadHeader::StepSize(double) {}

double CadHeader::Dw3DPrecision() const {}

void CadHeader::Dw3DPrecision(double) {}

double CadHeader::LensLength() const {}

void CadHeader::LensLength(double) {}

double CadHeader::CameraHeight() const {}

void CadHeader::CameraHeight(double) {}

char CadHeader::SolidsRetainHistory() const {}

void CadHeader::SolidsRetainHistory(char) {}

char CadHeader::ShowSolidsHistory() const {}

void CadHeader::ShowSolidsHistory(char) {}

double CadHeader::SweptSolidWidth() const {}

void CadHeader::SweptSolidWidth(double) {}

double CadHeader::SweptSolidHeight() const {}

void CadHeader::SweptSolidHeight(double) {}

double CadHeader::DraftAngleFirstCrossSection() const {}

void CadHeader::DraftAngleFirstCrossSection(double) {}

double CadHeader::DraftAngleSecondCrossSection() const {}

void CadHeader::DraftAngleSecondCrossSection(double) {}

double CadHeader::DraftMagnitudeFirstCrossSection() const {}

void CadHeader::DraftMagnitudeFirstCrossSection(double) {}

double CadHeader::DraftMagnitudeSecondCrossSection() const {}

void CadHeader::DraftMagnitudeSecondCrossSection(double) {}

short CadHeader::SolidLoftedShape() const {}

void CadHeader::SolidLoftedShape(short) {}

char CadHeader::LoftedObjectNormals() const {}

void CadHeader::LoftedObjectNormals(char) {}

double CadHeader::Latitude() const {}

void CadHeader::Latitude(double) {}

double CadHeader::Longitude() const {}

void CadHeader::Longitude(double) {}

double CadHeader::NorthDirection() const {}

void CadHeader::NorthDirection(double) {}

int CadHeader::TimeZone() const {}

void CadHeader::TimeZone(int) {}

char CadHeader::DisplayLightGlyphs() const {}

void CadHeader::DisplayLightGlyphs(char) {}

char CadHeader::DwgUnderlayFramesVisibility() const {}

void CadHeader::DwgUnderlayFramesVisibility(char) {}

char CadHeader::DgnUnderlayFramesVisibility() const {}

void CadHeader::DgnUnderlayFramesVisibility(char) {}

ShadowMode CadHeader::ShadowMode() const {}

void CadHeader::ShadowMode(ShadowMode) {}

double CadHeader::ShadowPlaneLocation() const {}

void CadHeader::ShadowPlaneLocation(double) {}

std::string CadHeader::StyleSheetName() const {}

void CadHeader::StyleSheetName(const std::string &value) {}

std::string CadHeader::DimensionTextStyleName() const {}

void CadHeader::DimensionTextStyleName(const std::string &value) {}

std::string CadHeader::DimensionStyleOverridesName() const {}

void CadHeader::DimensionStyleOverridesName(const std::string &value) {}

short CadHeader::DimensionAngularDimensionDecimalPlaces() const {}

void CadHeader::DimensionAngularDimensionDecimalPlaces(short) {}

short CadHeader::DimensionDecimalPlaces() const {}

void CadHeader::DimensionDecimalPlaces(short) {}

short CadHeader::DimensionToleranceDecimalPlaces() const {}

void CadHeader::DimensionToleranceDecimalPlaces(short) {}

bool CadHeader::DimensionAlternateUnitDimensioning() const {}

void CadHeader::DimensionAlternateUnitDimensioning(bool) {}

LinearUnitFormat CadHeader::DimensionAlternateUnitFormat() const {}

void CadHeader::DimensionAlternateUnitFormat(LinearUnitFormat) {}

double CadHeader::DimensionAlternateUnitScaleFactor() const {}

void CadHeader::DimensionAlternateUnitScaleFactor(double) {}

double CadHeader::DimensionExtensionLineOffset() const {}

void CadHeader::DimensionExtensionLineOffset(double) {}

double CadHeader::DimensionScaleFactor() const {}

void CadHeader::DimensionScaleFactor(double) {}

short CadHeader::DimensionAlternateUnitDecimalPlaces() const {}

void CadHeader::DimensionAlternateUnitDecimalPlaces(short) {}

short CadHeader::DimensionAlternateUnitToleranceDecimalPlaces() const {}

void CadHeader::DimensionAlternateUnitToleranceDecimalPlaces(short) {}

AngularUnitFormat CadHeader::DimensionAngularUnit() const {}

void CadHeader::DimensionAngularUnit(AngularUnitFormat) {}

FractionFormat CadHeader::DimensionFractionFormat() const {}

void CadHeader::DimensionFractionFormat(FractionFormat) {}

LinearUnitFormat CadHeader::DimensionLinearUnitFormat() const {}

void CadHeader::DimensionLinearUnitFormat(LinearUnitFormat) {}

char CadHeader::DimensionDecimalSeparator() const {}

void CadHeader::DimensionDecimalSeparator(char) {}

TextMovement CadHeader::DimensionTextMovement() const {}

void CadHeader::DimensionTextMovement(TextMovement) {}

DimensionTextHorizontalAlignment CadHeader::DimensionTextHorizontalAlignment() const {}

void CadHeader::DimensionTextHorizontalAlignment(DimensionTextHorizontalAlignment) {}

bool CadHeader::DimensionSuppressFirstDimensionLine() const {}

void CadHeader::DimensionSuppressFirstDimensionLine(bool) {}

bool CadHeader::DimensionSuppressSecondDimensionLine() const {}

void CadHeader::DimensionSuppressSecondDimensionLine(bool) {}

bool CadHeader::DimensionGenerateTolerances() const {}

void CadHeader::DimensionGenerateTolerances(bool) {}

ToleranceAlignment CadHeader::DimensionToleranceAlignment() const {}

void CadHeader::DimensionToleranceAlignment(ToleranceAlignment) {}

ZeroHandling CadHeader::DimensionZeroHandling() const {}

void CadHeader::DimensionZeroHandling(ZeroHandling) {}

ZeroHandling CadHeader::DimensionToleranceZeroHandling() const {}

void CadHeader::DimensionToleranceZeroHandling(ZeroHandling) {}

short CadHeader::DimensionFit() const {}

void CadHeader::DimensionFit(short) {}

ZeroHandling CadHeader::DimensionAlternateUnitZeroHandling() const {}

void CadHeader::DimensionAlternateUnitZeroHandling(ZeroHandling) {}

ZeroHandling CadHeader::DimensionAlternateUnitToleranceZeroHandling() const {}

void CadHeader::DimensionAlternateUnitToleranceZeroHandling(ZeroHandling) {}

bool CadHeader::DimensionCursorUpdate() const {}

void CadHeader::DimensionCursorUpdate(bool) {}

TextArrowFitType CadHeader::DimensionDimensionTextArrowFit() const {}

void CadHeader::DimensionDimensionTextArrowFit(TextArrowFitType) {}

double CadHeader::DimensionAlternateUnitRounding() const {}

void CadHeader::DimensionAlternateUnitRounding(double) {}

std::string CadHeader::DimensionAlternateDimensioningSuffix() const {}

void CadHeader::DimensionAlternateDimensioningSuffix(const std::string &value) {}

double CadHeader::DimensionArrowSize() const {}

void CadHeader::DimensionArrowSize(double) {}

ZeroHandling CadHeader::DimensionAngularZeroHandling() const {}

void CadHeader::DimensionAngularZeroHandling(ZeroHandling) {}

ArcLengthSymbolPosition CadHeader::DimensionArcLengthSymbolPosition() const {}

void CadHeader::DimensionArcLengthSymbolPosition(ArcLengthSymbolPosition) {}

bool CadHeader::DimensionSeparateArrowBlocks() const {}

void CadHeader::DimensionSeparateArrowBlocks(bool) {}

double CadHeader::DimensionCenterMarkSize() const {}

void CadHeader::DimensionCenterMarkSize(double) {}

double CadHeader::DimensionTickSize() const {}

void CadHeader::DimensionTickSize(double) {}

Color CadHeader::DimensionLineColor() const {}

void CadHeader::DimensionLineColor(const Color &) {}

Color CadHeader::DimensionExtensionLineColor() const {}

void CadHeader::DimensionExtensionLineColor(const Color &) {}

Color CadHeader::DimensionTextColor() const {}

void CadHeader::DimensionTextColor(const Color &) {}

double CadHeader::DimensionLineExtension() const {}

void CadHeader::DimensionLineExtension(double) {}

double CadHeader::DimensionLineIncrement() const {}

void CadHeader::DimensionLineIncrement(double) {}

double CadHeader::DimensionExtensionLineExtension() const {}

void CadHeader::DimensionExtensionLineExtension(double) {}

bool CadHeader::DimensionIsExtensionLineLengthFixed() const {}

void CadHeader::DimensionIsExtensionLineLengthFixed(bool) {}

double CadHeader::DimensionFixedExtensionLineLength() const {}

void CadHeader::DimensionFixedExtensionLineLength(double) {}

double CadHeader::DimensionJoggedRadiusDimensionTransverseSegmentAngle() const {}

void CadHeader::DimensionJoggedRadiusDimensionTransverseSegmentAngle(double) {}

DimensionTextBackgroundFillMode CadHeader::DimensionTextBackgroundFillMode() const {}

void CadHeader::DimensionTextBackgroundFillMode(DimensionTextBackgroundFillMode) {}

Color CadHeader::DimensionTextBackgroundColor() const {}

void CadHeader::DimensionTextBackgroundColor(const Color &) {}

double CadHeader::DimensionLineGap() const {}

void CadHeader::DimensionLineGap(double) {}

double CadHeader::DimensionLinearScaleFactor() const {}

void CadHeader::DimensionLinearScaleFactor(double) {}

double CadHeader::DimensionTextVerticalPosition() const {}

void CadHeader::DimensionTextVerticalPosition(double) {}

LineweightType CadHeader::DimensionLineWeight() const {}

void CadHeader::DimensionLineWeight(LineweightType) {}

LineweightType CadHeader::ExtensionLineWeight() const {}

void CadHeader::ExtensionLineWeight(LineweightType) {}

std::string CadHeader::DimensionPostFix() const {}

void CadHeader::DimensionPostFix(const std::string &value) {}

double CadHeader::DimensionRounding() const {}

void CadHeader::DimensionRounding(double) {}

bool CadHeader::DimensionSuppressFirstExtensionLine() const {}

void CadHeader::DimensionSuppressFirstExtensionLine(bool) {}

bool CadHeader::DimensionSuppressSecondExtensionLine() const {}

void CadHeader::DimensionSuppressSecondExtensionLine(bool) {}

bool CadHeader::DimensionSuppressOutsideExtensions() const {}

void CadHeader::DimensionSuppressOutsideExtensions(bool) {}

DimensionTextVerticalAlignment CadHeader::DimensionTextVerticalAlignment() const {}

void CadHeader::DimensionTextVerticalAlignment(DimensionTextVerticalAlignment) {}

short CadHeader::DimensionUnit() const {}

void CadHeader::DimensionUnit(short) {}

double CadHeader::DimensionToleranceScaleFactor() const {}

void CadHeader::DimensionToleranceScaleFactor(double) {}

bool CadHeader::DimensionTextInsideHorizontal() const {}

void CadHeader::DimensionTextInsideHorizontal(bool) {}

bool CadHeader::DimensionTextInsideExtensions() const {}

void CadHeader::DimensionTextInsideExtensions(bool) {}

double CadHeader::DimensionMinusTolerance() const {}

void CadHeader::DimensionMinusTolerance(double) {}

bool CadHeader::DimensionTextOutsideExtensions() const {}

void CadHeader::DimensionTextOutsideExtensions(bool) {}

bool CadHeader::DimensionTextOutsideHorizontal() const {}

void CadHeader::DimensionTextOutsideHorizontal(bool) {}

bool CadHeader::DimensionLimitsGeneration() const {}

void CadHeader::DimensionLimitsGeneration() {}

double CadHeader::DimensionPlusTolerance() const {}

void CadHeader::DimensionPlusTolerance(double) {}

double CadHeader::DimensionTextHeight() const {}

void CadHeader::DimensionTextHeight(double) {}

TextDirection CadHeader::DimensionTextDirection() const {}

void CadHeader::DimensionTextDirection(TextDirection) {}

double CadHeader::DimensionAltMzf() const {}

void CadHeader::DimensionAltMzf(double) {}

std::string CadHeader::DimensionAltMzs() const {}

void CadHeader::DimensionAltMzs(const std::string &value) {}

double CadHeader::DimensionMzf() const {}

void CadHeader::DimensionMzf(double) {}

std::string CadHeader::DimensionMzs() const {}

void CadHeader::DimensionMzs(const std::string &value) {}

std::string CadHeader::DimensionLineType() const {}

void CadHeader::DimensionLineType(const std::string &value) {}

std::string CadHeader::DimensionTex1() const {}

void CadHeader::DimensionTex1(const std::string &value) {}

std::string CadHeader::DimensionTex2() const {}

void CadHeader::DimensionTex2(const std::string &value) {}

Layer *CadHeader::CurrentLayer() const {}

void CadHeader::CurrentLayer(Layer *) {}

LineType *CadHeader::CurrentLineType() const {}

void CadHeader::CurrentLineType(LineType *) {}

TextStyle *CadHeader::CurrentTextStyle() const {}

void CadHeader::TextStyle(TextStyle *) {}

TextStyle *CadHeader::DimensionTextStyle() const {}

void CadHeader::DimensionTextStyle(TextStyle *) {}

DimensionStyle *CadHeader::DimensionStyleOverrides() const {}

void CadHeader::DimensionStyleOverrides(DimensionStyle *) {}

UCS *CadHeader::ModelSpaceUcs() const {}

void CadHeader::ModelSpaceUcs(UCS *) {}

UCS *CadHeader::ModelSpaceUcsBase() const {}

void CadHeader::ModelSpaceUcsBase(UCS *) {}

UCS *CadHeader::PaperSpaceUcs() const {}

void CadHeader::PaperSpaceUcs(UCS *) {}

UCS *CadHeader::PaperSpaceUcsBase() const {}

void CadHeader::PaperSpaceUcsBase(UCS *) {}

}// namespace dwg