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

#include <dwg/enums/ACadVersion.h>
#include <dwg/exports.h>
#include <dwg/enums/header/MeasurementUnits.h>
#include <dwg/enums/units/AngularDirection.h>
#include <dwg/enums/units/LinearUnitFormat.h>
#include <dwg/enums/units/AngularUnitFormat.h>
#include <dwg/enums/header/ObjectSnapMode.h>
#include <dwg/enums/header/AttributeVisibilityMode.h>
#include <dwg/enums/header/SplineType.h>
#include <dwg/enums/header/ShadeEdgeType.h>
#include <dwg/enums/entities/VerticalAlignmentType.h>

namespace dwg {
class CadDocument;
}// namespace dwg


namespace dwg {
namespace header {

class LIBDWG_API CadHeader
{

public:
    CadHeader(CadDocument *document);
    CadHeader(ACadVersion version);

    std::string VersionString;

    ACadVersion Version;

    // "$ACADMAINTVER", 70
    short maintenanceVersion;
    // "$DWGCODEPAGE", 3
    std::string CodePage; // "ANSI_1252"
    // "$LASTSAVEDBY", 3
    std::string LastSavedBy; // "libDWG"
    // "$REQUIREDVERSIONS", 70
    bool associatedDimensions;
    // "$DIMSHO", 70
    bool updateDimensionsWhileDragging;

    bool DIMSAV;

    // "$MEASUREMENT", 70
    header::MeasurementUnits measurementUnits;
    // "$PLINEGEN", 70
    bool polylineLineTypeGeneration;
    // "$ORTHOMODE", 70
    bool orthoMode;
    // "$REGENMODE", 70
    bool regenerationMode;
    // "$FILLMODE", 70
    bool fillMode;
    // "$QTEXTMODE", 70
    bool quickTextMode;
    // "$PSLTSCALE", 70
    bool limitCheckingOn;
    // "$BLIPMODE", 70
    bool blipMode;
    // "$USRTIMER", 70
    bool userTimer;
    // "$SKPOLY", 70
    bool sketchPolylines;
    // "$ANGDIR", 70
    AngularDirection angularDirection;
    // "$SPLFRAME", 70
    bool showSplineControlPoints;
    // "$MIRRTEXT", 70
    bool mirrorText;
    // "$WORLDVIEW", 70
    bool worldView;
    // "$TILEMODE", 70
    bool showModelSpace;  
    // "$PLIMCHECK", 70
    bool paperSpaceLimitsChecking;
    // "$VISRETAIN", 70
    bool retainXRefDependentVisibilitySettings;
    // "$DISPSILH", 70
    bool displaySilhouetteCurves;


    bool CreateEllipseAsPolyline;

    // "$PROXYGRAPHICS", 70
    bool proxyGraphics;
    // "$TREEDEPTH", 70
    short spatialIndexMaxTreeDepth;
    // "$LUNITS", 70
    LinearUnitFormat linearUnitFormat;
    // "$LUPREC", 70
    short linearUnitPrecision;
    // "$AUNITS", 70
    AngularUnitFormat angularUnit;
    // "$AUPREC", 70
    short AngularUnitPrecision;


    ObjectSnapMode objectSnapMode;
    // "$ATTMODE", 70
    AttributeVisibilityMode attributeVisibility;
    // "$PDMODE", 70
    short ointDisplayMode;
    // "$USERI1", 70
    short userShort1;
    // "$USERI2", 70
    short userShort2;
    // "$USERI3", 70
    short userShort3;
    // "$USERI4", 70
    short userShort4;
    // "$USERI5", 70
    short userShort5;
    // "$SPLINESEGS", 70
    short NumberOfSplineSegments = 8;
    // "$SURFU", 70
    short surfaceDensityU;
    // "$SURFV", 70
    short SurfaceDensityV;
    // "$SURFTYPE", 70
    short surfaceType;
    // "$SURFTAB1", 70
    short surfaceMeshTabulationCount1;
    // "$SURFTAB2", 70
    short surfaceMeshTabulationCount2;
    // "$SPLINETYPE", 70
    SplineType splineType;
    // "$SHADEDGE", 70
    ShadeEdgeType shadeEdgeType;
    // "$SHADEDIF", 70
    short shadeDiffuseToAmbientPercentage;
    // "$UNITMODE", 70
    short unitMode;
    // "$MAXACTVP", 70
    short maxViewportCount;
    
    short surfaceIsolineCount;

    // "$CMLJUST", 70
    VerticalAlignmentType CurrentMultilineJustification;

    short TextQuality;

    // "$LTSCALE", 40
    double LineTypeScale = 1.0;

    // "$TEXTSIZE", 40
    double TextHeightDefault = 2.5;

    // "$TEXTSTYLE", true, 7
    std::string TextStyleName;

    // "$CLAYER", true, 8
    std::string CurrentLayerName;

    // "$CELTYPE", true, 6
    std::string CurrentLineTypeName;

    // "$CMLSTYLE", true, 2
    std::string MultiLineStyleName = "Standard";

    // "$TRACEWID", 40
    double TraceWidthDefault = 0;

    // "$SKETCHINC", 40
    double SketchIncrement;
    // "$FILLETRAD", 40
    double FilletRadius;
    // "$THICKNESS", 40
    double ThicknessDefault;
    // "$ANGBASE", 50
    double AngleBase = 0.0;
    // "$PDSIZE", 40
    double PointDisplaySize = 0.0;
    // "$PLINEWID", 40
    double PolylineWidthDefault;
    // "$USERR1", 40
    double UserDouble1;
    // "$USERR2", 40
    double UserDouble2;
    // "$USERR3", 40
    double UserDouble3;
    // "$USERR4", 40
    double UserDouble4;
    // "$USERR5", 40
    double UserDouble5;
    // "$CHAMFERA", 40
    double ChamferDistance1;
    // "$CHAMFERB", 40
    double ChamferDistance2;
    // "$CHAMFERC", 40
    double ChamferLength;
    // "$CHAMFERD", 40
    double ChamferAngle;
    
    double FacetResolution;

    // "$CMLSCALE", 40
    double CurrentMultilineScale = 20.0;
    // "$CELTSCALE", 40
    double CurrentEntityLinetypeScale = 1.0;
    // "$MENU", 1
    std::string MenuFileName = ".";
    // "$HANDSEED", 5
    ulong HandleSeed = 0x0;
    // "$TDCREATE", 40
    DateTime CreateDateTime;

    // "$TDUCREATE", 40
    DateTime UniversalCreateDateTime;
    // "$TDUPDATE", 40
    DateTime UpdateDateTime;
    // "$TDUUPDATE", 40
    DateTime UniversalUpdateDateTime;
    // "$TDINDWG", 40
    TimeSpan TotalEditingTime;
    // "$TDUSRTIMER", 40
    TimeSpan UserElapsedTimeSpan;
    // "$CECOLOR", 62
    Color CurrentEntityColor = Color.ByLayer;
    // "$PSVPSCALE", 40
    double ViewportDefaultViewScaleFactor;
    // "$PINSBASE", 10, 20, 30
    XYZ PaperSpaceInsertionBase = XYZ.Zero;
    // "$PEXTMIN", 10, 20, 30
    XYZ PaperSpaceExtMin;
    // "$PEXTMAX", 10, 20, 30
    XYZ PaperSpaceExtMax;
    // "$PLIMMIN", 10, 20
    XY PaperSpaceLimitsMin;
    // "$PLIMMAX", 10, 20
    XY PaperSpaceLimitsMax;
    // "$PELEVATION", 40
    double PaperSpaceElevation;
    // "$PUCSBASE", true, 2
    std::string PaperSpaceBaseName;
    // "$PUCSNAME", true, 2
    std::string PaperSpaceName;
    // "$PUCSORG", 10, 20, 30
    XYZ PaperSpaceUcsOrigin;
    // "$PUCSXDIR", 10, 20, 30
    XYZ PaperSpaceUcsXAxis;
    // "$PUCSYDIR", 10, 20, 30
    XYZ PaperSpaceUcsYAxis;
    // "$PUCSORGTOP", 10, 20, 30
    XYZ PaperSpaceOrthographicTopDOrigin;
    // "$PUCSORGBOTTOM", 10, 20, 30
    XYZ PaperSpaceOrthographicBottomDOrigin;
    // "$PUCSORGLEFT", 10, 20, 30
    XYZ PaperSpaceOrthographicLeftDOrigin;
    // "$PUCSORGRIGHT", 10, 20, 30
    XYZ PaperSpaceOrthographicRightDOrigin;
    // "$PUCSORGFRONT", 10, 20, 30
    XYZ PaperSpaceOrthographicFrontDOrigin;
    // "$PUCSORGBACK", 10, 20, 30
    XYZ PaperSpaceOrthographicBackDOrigin;
    // "$UCSORGTOP", 10, 20, 30
    XYZ ModelSpaceOrthographicTopDOrigin;
    // "$UCSORGBOTTOM", 10, 20, 30
    XYZ ModelSpaceOrthographicBottomDOrigin;
    // "$UCSORGLEFT", 10, 20, 30
    XYZ ModelSpaceOrthographicLeftDOrigin;
    // "$UCSORGRIGHT", 10, 20, 30
    XYZ ModelSpaceOrthographicRightDOrigin;
    // "$UCSORGFRONT", 10, 20, 30
    XYZ ModelSpaceOrthographicFrontDOrigin;
    // "$UCSORGBACK", 10, 20, 30
    XYZ ModelSpaceOrthographicBackDOrigin;
    // "$INSBASE", 10, 20, 30
    XYZ ModelSpaceInsertionBase = XYZ.Zero;
    // "$EXTMIN", 10, 20, 30
    XYZ ModelSpaceExtMin;
    // "$EXTMAX", 10, 20, 30
    XYZ ModelSpaceExtMax;
    // "$LIMMIN", 10, 20
    XY ModelSpaceLimitsMin;
    // "$LIMMAX", 10, 20
    XY ModelSpaceLimitsMax;
    // "$UCSBASE", true, 2
    std::string UcsBaseName;
    // "$UCSNAME", true, 2
    std::string UcsName;
    // "$ELEVATION", 40
    double Elevation;
    // "$UCSORG", 10, 20, 30
    XYZ ModelSpaceOrigin;
    // "$UCSXDIR", 10, 20, 30
    XYZ ModelSpaceXAxis;
    // "$UCSYDIR", 10, 20, 30
    XYZ ModelSpaceYAxis;
    // "$DIMBLK", 1
    std::string DimensionBlockName;
    // "$DIMLDRBLK", 1
    std::string ArrowBlockName;
    // "$DIMBLK1", 1
    std::string DimensionBlockNameFirst;
    // "$DIMBLK2", 1
    std::string DimensionBlockNameSecon;
    

    short StackedTextAlignment = 1;
    short StackedTextSizePercentage = 70;


    // "$HYPERLINKBASE", 1
    std::string HyperLinkBase;
    // "$CELWEIGHT", 370
    LineweightType CurrentEntityLineWeight = LineweightType.ByLayer;
    // "$ENDCAPS", 280
    short EndCaps;
    // "$JOINSTYLE", 280
    short JoinStyle;
    // "$LWDISPLAY", 290
    bool DisplayLineWeight = false;
    // "$XEDIT", 290
    bool XEdit;
    // "$EXTNAMES", 290
    bool ExtendedNames = true;
    // "$PSTYLEMODE", 290
    short PlotStyleMode;
	//[CadSystemVariable("$OLESTARTUP", 290
    bool LoadOLEObject;
    // "$INSUNITS", 70
    UnitsType InsUnits = UnitsType.Unitless;
    // "$CEPSNTYPE", 380
    EntityPlotStyleType CurrentEntityPlotStyle;
    // "$FINGERPRINTGUID", 2
    std::string FingerPrintGuid { get; internal set; } = Guid.NewGuid().ToString();

    // "$VERSIONGUID", 2
    std::string VersionGuid { get; internal set; } = Guid.NewGuid().ToString();

    // "$SORTENTS", 280
    ObjectSortingFlags EntitySortingFlags;
    // "$INDEXCTL", 280
    IndexCreationFlags IndexCreationFlags;
    // "$HIDETEXT", 280   //note: mismatch with docs, code 290
    unsigned char HideText;
    // "$XCLIPFRAME", 280 //note: mismatch with docs, code 290
    unsigned char ExternalReferenceClippingBoundaryType;
    // "$DIMASSOC", 280
    DimensionAssociation DimensionAssociativity;
    // "$HALOGAP", 280
    unsigned char HaloGapPercentage;

    Color ObscuredColor;
    // "$INTERFERECOLOR", 62
    Color InterfereColor;

    unsigned char ObscuredType;

    unsigned char IntersectionDisplay;
    // "$PROJECTNAME", 1
    std::string ProjectName;

    bool CameraDisplayObjects;
    double StepsPerSecon;
    double StepSize;
    double Dw3DPrecision;
    double LensLength;
    double CameraHeight;
    char SolidsRetainHistory;
    char ShowSolidsHistory;
    double SweptSolidWidth;
    double SweptSolidHeight;
    double DraftAngleFirstCrossSection;
    double DraftAngleSecondCrossSection;
    double DraftMagnitudeFirstCrossSection;
    double DraftMagnitudeSecondCrossSection;
    short SolidLoftedShape;
    char LoftedObjectNormals;
    
    // "$LATITUDE", 40
    double Latitude = 37.7950;
    // "$LONGITUDE", 40
    double Longitude = -122.394;
    // "$NORTHDIRECTION", 40
    double NorthDirection;
    // "$TIMEZONE", 70
    int TimeZone;

    char DisplayLightGlyphs;
    // "$DWFFRAME", 280
    char DwgUnderlayFramesVisibility;;
    // "$DGNFRAME", 280
    char DgnUnderlayFramesVisibility;;
    // "$CSHADOW", 280
    ShadowMode ShadowMode;;
    // "$SHADOWPLANELOCATION", 40
    double ShadowPlaneLocation;

    std::string StyleSheetName;
    // "$DIMTXSTY", true, 7
    std::string DimensionTextStyleName;
    // "$DIMSTYLE", true, 2
    std::string DimensionStyleOverridesName;
    // "$DIMADEC", 70
    short DimensionAngularDimensionDecimalPlaces;
    // "$DIMDEC", 70
    short DimensionDecimalPlaces;
    // "$DIMTDEC", 70
    short DimensionToleranceDecimalPlaces;
    // "$DIMALT", 70
    bool DimensionAlternateUnitDimensioning;
    // "$DIMALTU", 70
    LinearUnitFormat DimensionAlternateUnitFormat;
    // "$DIMALTF", 40
    double DimensionAlternateUnitScaleFactor;
    // "$DIMEXO", 40
    double DimensionExtensionLineOffset;
    // "$DIMSCALE", 40
    double DimensionScaleFactor;
    // "$DIMALTD", 70
    short DimensionAlternateUnitDecimalPlaces;
    // "$DIMALTTD", 70
    short DimensionAlternateUnitToleranceDecimalPlaces;
    // "$DIMAUNIT", 70
    AngularUnitFormat DimensionAngularUnit;
    // "$DIMFRAC", 70
    FractionFormat DimensionFractionFormat;
    // "$DIMLUNIT", 70
    LinearUnitFormat DimensionLinearUnitFormat;
    // "$DIMDSEP", 70
    char DimensionDecimalSeparator;
    // "$DIMTMOVE", 70
    TextMovement DimensionTextMovement;
    // "$DIMJUST", 70
    DimensionTextHorizontalAlignment DimensionTextHorizontalAlignment;
    // "$DIMSD1", 70
    bool DimensionSuppressFirstDimensionLine;
    // "$DIMSD2", 70
    bool DimensionSuppressSecondDimensionLine;
    // "$DIMTOL", 70
    bool DimensionGenerateTolerances;
    // "$DIMTOLJ", 70
    ToleranceAlignment DimensionToleranceAlignment;
    // "$DIMZIN", 70
    ZeroHandling DimensionZeroHandling;
    // "$DIMTZIN", 70
    ZeroHandling DimensionToleranceZeroHandling;
    // "$DIMFIT", 70
    short DimensionFit;
    // "$DIMALTZ", 70
    ZeroHandling DimensionAlternateUnitZeroHandling;
    // "$DIMALTTZ", 70
    ZeroHandling DimensionAlternateUnitToleranceZeroHandling;
    // "$DIMUPT", 70
    bool DimensionCursorUpdate;
    // "$DIMATFIT", 70
    TextArrowFitType DimensionDimensionTextArrowFit;
    // "$DIMALTRND", 40
    double DimensionAlternateUnitRounding;
    // "$DIMAPOST", 1
    std::string DimensionAlternateDimensioningSuffix;
    // "$DIMASZ", 40
    double DimensionArrowSize;
    // "$DIMAZIN", 70
    ZeroHandling DimensionAngularZeroHandling;
    // "$DIMARCSYM", 70
    ArcLengthSymbolPosition DimensionArcLengthSymbolPosition;
    // "$DIMSAH", 70
    bool DimensionSeparateArrowBlocks;
    // "$DIMCEN", 40
    double DimensionCenterMarkSize;
    // "$DIMTSZ", 40
    double DimensionTickSize;
    // "$DIMCLRD", 70
    Color DimensionLineColor;
    // "$DIMCLRE", 70
    Color DimensionExtensionLineColor;
    // "$DIMCLRT", 70
    Color DimensionTextColor;
    // "$DIMDLE", 40
    double DimensionLineExtension;
    // "$DIMDLI", 40
    double DimensionLineIncrement;
    // "$DIMEXE", 40
    double DimensionExtensionLineExtension;
    // "$DIMFXLON", 70
    bool DimensionIsExtensionLineLengthFixe;
    // "$DIMFXL", 40
    double DimensionFixedExtensionLineLength;
    // "$DIMJOGANG", 40
    double DimensionJoggedRadiusDimensionTransverseSegmentAngle;
    // "$DIMTFILL", 70
    DimensionTextBackgroundFillMode DimensionTextBackgroundFillMode;
    // DxfReferenceType.Ignored, "$DIMTFILLCLR", 62
    Color DimensionTextBackgroundColor;
    // "$DIMGAP", 40
    double DimensionLineGap;
    // "$DIMLFAC", 40
    double DimensionLinearScaleFactor;
    // "$DIMTVP", 40
    double DimensionTextVerticalPosition;
    // "$DIMLWD", 70
    LineweightType DimensionLineWeight;
    // "$DIMLWE", 70
    LineweightType ExtensionLineWeight;
    // "$DIMPOST", 1
    std::string DimensionPostFix;
    // "$DIMRND", 40
    double DimensionRounding;
    // "$DIMSE1", 70
    bool DimensionSuppressFirstExtensionLine;
    // "$DIMSE2", 70
    bool DimensionSuppressSecondExtensionLine;
    // "$DIMSOXD", 70
    bool DimensionSuppressOutsideExtensions;
    // "$DIMTAD", 70
    DimensionTextVerticalAlignment DimensionTextVerticalAlignment;
    // "$DIMUNIT", 70
    short DimensionUnit;
    // "$DIMTFAC", 40
    double DimensionToleranceScaleFactor;
    // "$DIMTIH", 70
    bool DimensionTextInsideHorizontal;
    // "$DIMTIX", 70
    bool DimensionTextInsideExtensions;
    // "$DIMTM", 40
    double DimensionMinusTolerance;
    // "$DIMTOFL", 70
    bool DimensionTextOutsideExtensions;
    // "$DIMTOH", 70
    bool DimensionTextOutsideHorizontal;
    // "$DIMLIM", 70
    bool DimensionLimitsGeneration;
    // "$DIMTP", 40
    double DimensionPlusTolerance;
    // "$DIMTXT", 40
    double DimensionTextHeight;
    // "$DIMTXTDIRECTION", 70
    TextDirection DimensionTextDirection;
    // "$DIMALTMZF", 40
    double DimensionAltMzf;
    // "$DIMALTMZS", 6
    std::string DimensionAltMzs;
    // "$DIMMZF", 40
    double DimensionMzf;
    // "$DIMMZS", 6
    std::string DimensionMzs;
    // "$DIMLTYPE", 6
    std::string DimensionLineType = "ByBlock";
    // "$DIMLTEX1", 6
    std::string DimensionTex1 = "ByBlock";
    // "$DIMLTEX2", 6
    std::string DimensionTex2 = "ByBlock";

		//TODO: How header UCS work??
    UCS ModelSpaceUcs;

    UCS ModelSpaceUcsBase ;
    UCS PaperSpaceUcs ;

    UCS PaperSpaceUcsBase ;



};

}// namespace header
}// namespace dwg
