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

#include <dwg/CadSystemVariables_p.h>

namespace dwg {


static std::vector<CadSystemVariableAttribute> _headerVariables = {
        {"$ANGBASE", {50}},
        {"$ANGDIR", {70}},
        {"$AUNITS", {70}},
        {"$AUPREC", {70}},
        {"$DIMLDRBLK", {1}},
        {"$DIMASO", {70}},
        {"$ATTMODE", {70}},
        {"$BLIPMODE", {70}},
        {"$CAMERADISPLAY", {290}},
        {"$CAMERAHEIGHT", {40}},
        {"$CHAMFERD", {40}},
        {"$CHAMFERA", {40}},
        {"$CHAMFERB", {40}},
        {"$CHAMFERC", {40}},
        {"$DWGCODEPAGE", {3}},
        {"$TDCREATE", {40}},
        {"$PELLIPSE", {70}},
        {"$CECOLOR", {62}},
        {"$CELTSCALE", {40}},
        {"$CELWEIGHT", {370}},
        {"$CEPSNTYPE", {380}},
        {"$CLAYER", true, {8}},
        {"$CELTYPE", true, {6}},
        {"$CMLJUST", {70}},
        {"$CMLSCALE", {40}},
        {"$CMLSTYLE", true, {2}},
        {"$DGNFRAME", {280}},
        {"$DIMAPOST", {1}},
        {"$DIMALTD", {70}},
        {"$DIMALT", {70}},
        {"$DIMALTU", {70}},
        {"$DIMALTRND", {40}},
        {"$DIMALTF", {40}},
        {"$DIMALTTD", {70}},
        {"$DIMALTTZ", {70}},
        {"$DIMALTZ", {70}},
        {"$DIMALTMZF", {40}},
        {"$DIMALTMZS", {6}},
        {"$DIMADEC", {70}},
        {"$DIMAUNIT", {70}},
        {"$DIMAZIN", {70}},
        {"$DIMARCSYM", {70}},
        {"$DIMASZ", {40}},
        {"$DIMASSOC", {280}},
        {"$DIMBLK", {1}},
        {"$DIMBLK1", {1}},
        {"$DIMBLK2", {1}},
        {"$DIMCEN", {40}},
        {"$DIMUPT", {70}},
        {"$DIMDEC", {70}},
        {"$DIMDSEP", {70}},
        {"$DIMATFIT", {70}},
        {"$DIMCLRE", {70}},
        {"$DIMEXE", {40}},
        {"$DIMEXO", {40}},
        {"$DIMFIT", {70}},
        {"$DIMFXL", {40}},
        {"$DIMFRAC", {70}},
        {"$DIMTOL", {70}},
        {"$DIMFXLON", {70}},
        {"$DIMJOGANG", {40}},
        {"$DIMLIM", {70}},
        {"$DIMLFAC", {40}},
        {"$DIMLUNIT", {70}},
        {"$DIMCLRD", {70}},
        {"$DIMDLE", {40}},
        {"$DIMGAP", {40}},
        {"$DIMDLI", {40}},
        {"$DIMLTYPE", {6}},
        {"$DIMLWD", {70}},
        {"$DIMTM", {40}},
        {"$DIMMZF", {40}},
        {"$DIMMZS", {6}},
        {"$DIMTP", {40}},
        {"$DIMPOST", {1}},
        {"$DIMRND", {40}},
        {"$DIMSCALE", {40}},
        {"$DIMSAH", {70}},
        {"$DIMSTYLE", true, {2}},
        {"$DIMSD1", {70}},
        {"$DIMSE1", {70}},
        {"$DIMSOXD", {70}},
        {"$DIMSD2", {70}},
        {"$DIMSE2", {70}},
        {"$DIMLTEX1", {6}},
        {"$DIMLTEX2", {6}},
        {DxfReferenceType::Ignored, "$DIMTFILLCLR", {62}},
        {"$DIMTFILL", {70}},
        {"$DIMCLRT", {70}},
        {"$DIMTXTDIRECTION", {70}},
        {"$DIMTXT", {40}},
        {"$DIMJUST", {70}},
        {"$DIMTIX", {70}},
        {"$DIMTIH", {70}},
        {"$DIMTMOVE", {70}},
        {"$DIMTOFL", {70}},
        {"$DIMTOH", {70}},
        {"$DIMTXSTY", true, {7}},
        {"$DIMTAD", {70}},
        {"$DIMTVP", {40}},
        {"$DIMTSZ", {40}},
        {"$DIMTOLJ", {70}},
        {"$DIMTDEC", {70}},
        {"$DIMTFAC", {40}},
        {"$DIMTZIN", {70}},
        {"$DIMUNIT", {70}},
        {"$DIMZIN", {70}},
        {"$LIGHTGLYPHDISPLAY", {280}},
        {"$LWDISPLAY", {290}},
        {"$DISPSILH", {70}},
        {"$LOFTANG1", {40}},
        {"$LOFTANG2", {40}},
        {"$LOFTMAG1", {40}},
        {"$LOFTMAG2", {40}},
        {"$3DDWFPREC", {40}},
        {"$DWFFRAME", {280}},
        {"$ELEVATION", {40}},
        {"$ENDCAPS", {280}},
        {"$SORTENTS", {280}},
        {"$EXTNAMES", {290}},
        {"$DIMLWE", {70}},
        {"$XCLIPFRAME", {280}},
        {"$FACETRES", {40}},
        {"$FILLETRAD", {40}},
        {"$FILLMODE", {70}},
        {"$FINGERPRINTGUID", {2}},
        {"$HALOGAP", {280}},
        {"$HANDSEED", {5}},
        {"$HIDETEXT", {280}},
        {"$HYPERLINKBASE", {1}},
        {"$INDEXCTL", {280}},
        {"$INSUNITS", {70}},
        {"$INTERFERECOLOR", {62}},
        {"$JOINSTYLE", {280}},
        {DxfReferenceType::Ignored, "$LASTSAVEDBY", {3}},
        {"$LATITUDE", {40}},
        {"$LENSLENGTH", {40}},
        {"$LIMCHECK", {70}},
        {"$LUNITS", {70}},
        {"$LUPREC", {70}},
        {"$LTSCALE", {40}},
        {"$LOFTNORMALS", {280}},
        {"$LONGITUDE", {40}},
        {DxfReferenceType::Ignored, "$ACADMAINTVER", {70}},
        {"$MAXACTVP", {70}},
        {"$MEASUREMENT", {70}},
        {"$MENU", {1}},
        {"$MIRRTEXT", {70}},
        {"$EXTMAX", {10, 20, 30}},
        {"$EXTMIN", {10, 20, 30}},
        {"$INSBASE", {10, 20, 30}},
        {"$LIMMAX", {10, 20}},
        {"$LIMMIN", {10, 20}},
        {"$UCSORG", {10, 20, 30}},
        {"$UCSORGBACK", {10, 20, 30}},
        {"$UCSORGBOTTOM", {10, 20, 30}},
        {"$UCSORGFRONT", {10, 20, 30}},
        {"$UCSORGLEFT", {10, 20, 30}},
        {"$UCSORGRIGHT", {10, 20, 30}},
        {"$UCSORGTOP", {10, 20, 30}},
        {"$UCSXDIR", {10, 20, 30}},
        {"$UCSYDIR", {10, 20, 30}},
        {"$NORTHDIRECTION", {40}},
        {"$SPLINESEGS", {70}},
        {"$OSMODE", {70}},
        {"$ORTHOMODE", {70}},
        {"$PUCSBASE", true, {2}},
        {"$PELEVATION", {40}},
        {"$PEXTMAX", {10, 20, 30}},
        {"$PEXTMIN", {10, 20, 30}},
        {"$PINSBASE", {10, 20, 30}},
        {"$PLIMCHECK", {70}},
        {"$PLIMMAX", {10, 20}},
        {"$PLIMMIN", {10, 20}},
        {"$PSLTSCALE", {70}},
        {"$PUCSNAME", true, {2}},
        {"$PUCSORGBACK", {10, 20, 30}},
        {"$PUCSORGBOTTOM", {10, 20, 30}},
        {"$PUCSORGFRONT", {10, 20, 30}},
        {"$PUCSORGLEFT", {10, 20, 30}},
        {"$PUCSORGRIGHT", {10, 20, 30}},
        {"$PUCSORGTOP", {10, 20, 30}},
        {"$PUCSORG", {10, 20, 30}},
        {"$PUCSXDIR", {10, 20, 30}},
        {"$PUCSYDIR", {10, 20, 30}},
        {"$PSTYLEMODE", {290}},
        {"$PDMODE", {70}},
        {"$PDSIZE", {40}},
        {"$PLINEGEN", {70}},
        {"$PLINEWID", {40}},
        {"$PROJECTNAME", {1}},
        {"$PROXYGRAPHICS", {70}},
        {"$QTEXTMODE", {70}},
        {"$REGENMODE", {70}},
        {DxfReferenceType::Ignored, "$REQUIREDVERSIONS", {70}},
        {"$VISRETAIN", {70}},
        {"$SHADEDIF", {70}},
        {"$SHADEDGE", {70}},
        {"$CSHADOW", {280}},
        {"$SHADOWPLANELOCATION", {40}},
        {"$TILEMODE", {70}},
        {"$SHOWHIST", {280}},
        {"$SPLFRAME", {70}},
        {"$SKETCHINC", {40}},
        {"$SKPOLY", {70}},
        {"$LOFTPARAM", {70}},
        {"$SOLIDHIST", {280}},
        {"$TREEDEPTH", {70}},
        {"$SPLINETYPE", {70}},
        {"$STEPSIZE", {40}},
        {"$STEPSPERSEC", {40}},
        {"$STYLESHEET", {1}},
        {"$SURFU", {70}},
        {"$SURFV", {70}},
        {"$SURFTAB1", {70}},
        {"$SURFTAB2", {70}},
        {"$SURFTYPE", {70}},
        {"$PSOLHEIGHT", {40}},
        {"$PSOLWIDTH", {40}},
        {"$TEXTSIZE", {40}},
        {"$TEXTSTYLE", true, {7}},
        {"$THICKNESS", {40}},
        {"$TIMEZONE", {70}},
        {"$TDINDWG", {40}},
        {"$TRACEWID", {40}},
        {"$UCSBASE", true, {2}},
        {"$UCSNAME", true, {2}},
        {"$UNITMODE", {70}},
        {"$TDUCREATE", {40}},
        {"$TDUUPDATE", {40}},
        {"$TDUPDATE", {40}},
        {"$DIMSHO", {70}},
        {"$USERR1", {40}},
        {"$USERR2", {40}},
        {"$USERR3", {40}},
        {"$USERR4", {40}},
        {"$USERR5", {40}},
        {"$TDUSRTIMER", {40}},
        {"$USERI1", {70}},
        {"$USERI2", {70}},
        {"$USERI3", {70}},
        {"$USERI4", {70}},
        {"$USERI5", {70}},
        {"$USRTIMER", {70}},
        {"$VERSIONGUID", {2}},
        {"$ACADVER", {DxfCode::Text}},
        {"$PSVPSCALE", {40}},
        {"$WORLDVIEW", {70}},
        {"$XEDIT", {290}},
};

std::vector<CadSystemVariableAttribute> CadSystemVariables::headerVariables() {}

}// namespace dwg