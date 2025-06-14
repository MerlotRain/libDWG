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
#include <dwg/LineWeightType.h>
#include <dwg/TextAlignmentType.h>
#include <dwg/TextAngleType.h>
#include <dwg/TextAttachmentDirectionType.h>
#include <dwg/TextAttachmentPointType.h>
#include <dwg/TextAttachmentType.h>
#include <dwg/entities/BlockContentConnectionType.h>
#include <dwg/entities/Entity.h>
#include <dwg/entities/MultiLeaderPathType.h>
#include <dwg/entities/MultiLeaderPropertyOverrideFlags.h>
#include <dwg/objects/LeaderContentType.h>

namespace dwg {

class AttributeDefinition;
class MultiLeaderStyle;
class MultiLeaderAnnotContext;
class BlockRecord;
class TextStyle;

class LIBDWG_API MultiLeader : public Entity
{
public:
    struct BlockAttribute
    {
        AttributeDefinition *attributeDefinition;///< Pointer to the attribute definition.
        short index;                             ///< Index of the attribute within the block.
        double width;                            ///< Width of the attribute text.
        std::string text;                        ///< The actual text content of the attribute.
        bool operator==(const BlockAttribute &other) const;
        bool operator<(const BlockAttribute &other) const;
    };

public:
    MultiLeader();
    virtual ~MultiLeader();

    virtual ObjectType objectType() const override;
    virtual std::string objectName() const override;
    virtual std::string subclassMarker() const override;

    BlockRecord *arrowhead() const;
    void setArrowhead(BlockRecord *);

    double arrowheadSize() const;
    void setArrowheadSize(double size);

    std::vector<BlockAttribute> blockAttributes() const;
    void setBlockAttributes(const std::vector<BlockAttribute> &);

    LeaderContentType contentType() const;
    void setContentType(LeaderContentType);

    MultiLeaderAnnotContext *contextData() const;
    void setContextData(MultiLeaderAnnotContext *);

    bool enableAnnotationScale() const;
    void setEnableAnnotationScale(bool);

    bool enableDogleg() const;
    void setEnableDogleg(bool);

    bool enableLanding() const;
    void setEnableLanding(bool);

    bool extendedToText() const;
    void setExtendedToText(bool);

    double landingDistance() const;
    void setLandingDistance(double);

    LineType *leaderLineType() const;
    void setLeaderLineType(LineType *);

    LineweightType leaderLineWeight() const;
    void setLeaderLineWeight(LineweightType);

    Color lineColor() const;
    void setLineColor(const Color &);

    MultiLeaderPathType pathType() const;
    void setPathType(MultiLeaderPathType);

    MultiLeaderPropertyOverrideFlags propertyOverrideFlags() const;
    void setPropertyOverrideFlags(MultiLeaderPropertyOverrideFlags);

    double scaleFactor() const;
    void setScaleFactor(double);

    MultiLeaderStyle *style() const;
    void setStyle(MultiLeaderStyle *);

#pragma region Text Menu Properties
    TextAlignmentType textAlignment() const;
    void setTextAlignment(TextAlignmentType);

    TextAngleType textAngle() const;
    void setTextAngle(TextAngleType);

    Color textColor() const;
    void setTextColor(const Color &);

    bool textFrame() const;
    void setTextFrame(bool);

    TextAttachmentType textLeftAttachment() const;
    void setTextLeftAttachment(TextAttachmentType);

    TextAttachmentType textRightAttachment() const;
    void setTextRightAttachment(TextAttachmentType);

    TextStyle *textStyle() const;
    void setTextStyle(TextStyle *);

    LineweightType leaderLineLength() const;
    void setLeaderLineLength(LineweightType);

#pragma endregion Text Menu Properties

#pragma region Block Content Properties
    BlockRecord *blockContent() const;
    void setBlockContent(BlockRecord *);

    Color blockContentColor() const;
    void setBlockContentColor(const Color &);

    BlockContentConnectionType blockContentConnection() const;
    void setBlockContentConnection(BlockContentConnectionType);

    double blockContentRotation() const;
    void setBlockContentRotation(double);

    XYZ blockContentScale() const;
    void setBlockContentScale(const XYZ &);

#pragma endregion Block Content Properties

    short textAligninIPE() const;
    void setTextAligninIPE(short);

    TextAttachmentDirectionType textAttachmentDirection() const;
    void setTextAttachmentDirection(TextAttachmentDirectionType);

    TextAttachmentPointType textAttachmentPoint() const;
    void setTextAttachmentPoint(TextAttachmentPointType);

    TextAttachmentType textBottomAttachment() const;
    void setTextBottomAttachment(TextAttachmentType);

    bool textDirectionNegative() const;
    void setTextDirectionNegative(bool);

    TextAttachmentType textTopAttachment() const;
    void setTextTopAttachment(TextAttachmentType);

private:
    void assignDocument(CadDocument *document) override;
    void unassignDocument() override;

private:
    void tableOnRemove(CadObject *object);

private:
    BlockRecord *_arrowhead;
    double _arrowheadSize;
    std::vector<BlockAttribute> _blockAttributes;
    LeaderContentType _contentType;
    MultiLeaderAnnotContext *_contextData;
    bool _enableAnnotationScale;
    bool _enableDogleg;
    bool _enableLanding;
    bool _extendedToText;
    double _landingDistance;
    LineType *_leaderLineType;
    LineweightType _leaderLineWeight;
    Color _lineColor;
    MultiLeaderPathType _pathType;
    MultiLeaderPropertyOverrideFlags _propertyOverrideFlags;
    double _scaleFactor;
    MultiLeaderStyle *_style;
    TextAlignmentType _textAlignment;
    TextAngleType _textAngle;
    Color _textColor;
    bool _textFrame;
    TextAttachmentType _textLeftAttachment;
    TextAttachmentType _textRightAttachment;
    TextStyle *_textStyle;
    LineweightType _leaderLineLength;
    BlockRecord *_blockContent;
    Color _blockContentColor;
    BlockContentConnectionType _blockContentConnection;
    double _blockContentRotation;
    XYZ _blockContentScale;
    short _textAligninIPE;
    TextAttachmentDirectionType _textAttachmentDirection;
    TextAttachmentPointType _textAttachmentPoint;
    TextAttachmentType _textBottomAttachment;
    bool _textDirectionNegative;
    TextAttachmentType _textTopAttachment;
};

}// namespace dwg