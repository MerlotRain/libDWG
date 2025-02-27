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
#include <dwg/entities/LeaderCreationType.h>
#include <dwg/entities/LeaderPathType.h>

namespace dwg {

class DimensionStyle;

/**
 * @class Leader
 * @brief Represents a leader entity in a DWG/DXF drawing.
 *
 * A leader is an annotation object consisting of one or more line segments 
 * that visually connect text or symbols to a referenced location in the drawing.
 */
class LIBDWG_API Leader : public Entity
{
    DimensionStyle *_style;          ///< Dimension style associated with the leader.
    bool _arrowHeadEnabled;          ///< Indicates whether the arrowhead is enabled.
    LeaderPathType _pathType;        ///< Path type of the leader (e.g., straight or spline).
    LeaderCreationType _creationType;///< Creation type of the leader.
    bool _hookLineDirection;         ///< Direction of the hook line, if applicable.
    bool _hasHookline;               ///< Indicates whether the leader has a hook line.
    double _textHeight;              ///< Height of the text associated with the leader.
    double _textWidth;               ///< Width of the text associated with the leader.
    std::vector<XYZ> _vertices;      ///< List of vertex points defining the leader path.
    Entity *_associatedAnnotation;   ///< Associated annotation entity.
    XYZ _normal;                     ///< Normal vector defining the plane of the leader.
    XYZ _horizontalDirection;        ///< Horizontal direction vector.
    XYZ _blockOffset;                ///< Offset of the block reference.
    XYZ _annotationOffset;           ///< Offset of the annotation.

public:
    /**
     * @brief Constructs a Leader object.
     */
    Leader();

    /**
     * @brief Destroys the Leader object.
     */
    ~Leader();

    /**
     * @brief Returns the object type of the leader.
     * @return The object type as ObjectType.
     */
    virtual ObjectType objectType() const override;

    /**
     * @brief Returns the name of the object.
     * @return The name as a string.
     */
    virtual std::string objectName() const override;

    /**
     * @brief Returns the subclass marker associated with this object.
     * @return The subclass marker as a string.
     */
    virtual std::string subclassMarker() const override;

    /**
     * @brief Gets the dimension style of the leader.
     * @return Pointer to the DimensionStyle.
     */
    DimensionStyle *style() const;

    /**
     * @brief Sets the dimension style of the leader.
     * @param style Pointer to the DimensionStyle.
     */
    void setStyle(DimensionStyle *style);

    /**
     * @brief Checks whether the arrowhead is enabled.
     * @return True if the arrowhead is enabled, false otherwise.
     */
    bool arrowHeadEnabled() const;

    /**
     * @brief Enables or disables the arrowhead.
     * @param enabled True to enable, false to disable.
     */
    void setArrowHeadEnabled(bool enabled);

    /**
     * @brief Gets the path type of the leader.
     * @return The path type as LeaderPathType.
     */
    LeaderPathType pathType() const;

    /**
     * @brief Sets the path type of the leader.
     * @param type The path type as LeaderPathType.
     */
    void setPathType(LeaderPathType type);

    /**
     * @brief Gets the creation type of the leader.
     * @return The creation type as LeaderCreationType.
     */
    LeaderCreationType creationType() const;

    /**
     * @brief Sets the creation type of the leader.
     * @param type The creation type as LeaderCreationType.
     */
    void setCreationType(LeaderCreationType type);

    /**
     * @brief Checks the hook line direction.
     * @return True if the hook line is in the default direction, false otherwise.
     */
    bool hookLineDirection() const;

    /**
     * @brief Sets the hook line direction.
     * @param direction True for the default direction, false otherwise.
     */
    void setHookLineDirection(bool direction);

    /**
     * @brief Checks whether the leader has a hook line.
     * @return True if the leader has a hook line, false otherwise.
     */
    bool hasHookline() const;

    /**
     * @brief Sets whether the leader has a hook line.
     * @param hasHookline True to enable, false to disable.
     */
    void setHasHookline(bool hasHookline);

    /**
     * @brief Gets the text height associated with the leader.
     * @return The text height as a double.
     */
    double textHeight() const;

    /**
     * @brief Sets the text height associated with the leader.
     * @param height The text height as a double.
     */
    void setTextHeight(double height);

    /**
     * @brief Gets the text width associated with the leader.
     * @return The text width as a double.
     */
    double textWidth() const;

    /**
     * @brief Sets the text width associated with the leader.
     * @param width The text width as a double.
     */
    void setTextWidth(double width);

    /**
     * @brief Gets the vertices defining the leader path.
     * @return A vector of XYZ points.
     */
    std::vector<XYZ> vertices() const;

    /**
     * @brief Sets the vertices defining the leader path.
     * @param vertices A vector of XYZ points.
     */
    void setVertices(const std::vector<XYZ> &vertices);

    /**
     * @brief Gets the associated annotation entity.
     * @return Pointer to the associated Entity.
     */
    Entity *associatedAnnotation() const;

    /**
     * @brief Sets the associated annotation entity.
     * @param annotation Pointer to the Entity.
     */
    void setAssociatedAnnotation(Entity *annotation);

    /**
     * @brief Gets the normal vector defining the leader's plane.
     * @return The normal vector as XYZ.
     */
    XYZ normal() const;

    /**
     * @brief Sets the normal vector defining the leader's plane.
     * @param normal The normal vector as XYZ.
     */
    void setNormal(const XYZ &normal);

    /**
     * @brief Gets the horizontal direction of the leader.
     * @return The horizontal direction as XYZ.
     */
    XYZ horizontalDirection() const;

    /**
     * @brief Sets the horizontal direction of the leader.
     * @param direction The horizontal direction as XYZ.
     */
    void setHorizontalDirection(const XYZ &direction);

    /**
     * @brief Gets the block offset of the leader.
     * @return The block offset as XYZ.
     */
    XYZ blockOffset() const;

    /**
     * @brief Sets the block offset of the leader.
     * @param offset The block offset as XYZ.
     */
    void setBlockOffset(const XYZ &offset);

    /**
     * @brief Gets the annotation offset of the leader.
     * @return The annotation offset as XYZ.
     */
    XYZ annotationOffset() const;

    /**
     * @brief Sets the annotation offset of the leader.
     * @param offset The annotation offset as XYZ.
     */
    void setAnnotationOffset(const XYZ &offset);
};

}// namespace dwg
