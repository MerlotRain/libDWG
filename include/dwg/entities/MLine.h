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
#include <dwg/entities/MLineFlags.h>
#include <dwg/entities/MLineJustification.h>
#include <dwg/entities/Vertex.h>

namespace dwg {

class MLineStyle;

/**
 * @class MLine
 * @brief Represents a multiline entity in a DWG/DXF drawing.
 *
 * A multiline consists of multiple parallel lines, typically used for architectural 
 * and engineering drawings. It supports justification, scaling, and various styles.
 */
class LIBDWG_API MLine : public Entity
{
    MLineStyle *_style;               ///< Pointer to the multiline style.
    double _scaleFactor;              ///< Scale factor for the multiline.
    MLineJustification _justification;///< Justification of the multiline.
    MLineFlags _flags;                ///< Flags indicating properties of the multiline.
    XYZ _startPoint;                  ///< Start point of the multiline.
    XYZ _normal;                      ///< Normal vector defining the plane of the multiline.

public:
    /**
     * @struct Segment
     * @brief Represents a segment within a multiline vertex.
     *
     * Each segment contains parameter values defining its position 
     * and optional area fill parameters.
     */
    struct Segment
    {
        std::vector<double> Parameters;        ///< Parameters defining segment positions.
        std::vector<double> AreaFillParameters;///< Parameters for area fill.
    };

    /**
     * @struct Vertex
     * @brief Represents a vertex in a multiline.
     *
     * A vertex consists of a position, direction, mitering data, 
     * and multiple segments that define multiline components.
     */
    struct Vertex
    {
        XYZ Position;                 ///< Position of the vertex.
        XYZ Direction;                ///< Direction vector at the vertex.
        XYZ Miter;                    ///< Mitering vector for joint handling.
        std::vector<Segment> Segments;///< Segments associated with the vertex.
    };

public:
    /**
     * @brief Constructs a MLine object.
     */
    MLine();

    /**
     * @brief Destroys the MLine object.
     */
    ~MLine();

    /**
     * @brief Returns the object type of the multiline.
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
     * @brief Gets the multiline style.
     * @return Pointer to the MLineStyle.
     */
    MLineStyle *style() const;

    /**
     * @brief Sets the multiline style.
     * @param style Pointer to the MLineStyle.
     */
    void setStyle(MLineStyle *style);

    /**
     * @brief Gets the scale factor of the multiline.
     * @return The scale factor as a double.
     */
    double scaleFactor() const;

    /**
     * @brief Sets the scale factor of the multiline.
     * @param scale The scale factor as a double.
     */
    void setScaleFactor(double scale);

    /**
     * @brief Gets the justification of the multiline.
     * @return The justification as MLineJustification.
     */
    MLineJustification justification() const;

    /**
     * @brief Sets the justification of the multiline.
     * @param justification The justification as MLineJustification.
     */
    void setJustification(MLineJustification justification);

    /**
     * @brief Gets the flags of the multiline.
     * @return The flags as MLineFlags.
     */
    MLineFlags flags() const;

    /**
     * @brief Sets the flags of the multiline.
     * @param flags The flags as MLineFlags.
     */
    void setFlags(MLineFlags flags);

    /**
     * @brief Gets the start point of the multiline.
     * @return The start point as XYZ.
     */
    XYZ startPoint() const;

    /**
     * @brief Sets the start point of the multiline.
     * @param point The start point as XYZ.
     */
    void setStartPoint(const XYZ &point);

    /**
     * @brief Gets the normal vector of the multiline.
     * @return The normal vector as XYZ.
     */
    XYZ normal() const;

    /**
     * @brief Sets the normal vector of the multiline.
     * @param normal The normal vector as XYZ.
     */
    void setNormal(const XYZ &normal);

    /**
     * @brief Gets the vertices defining the multiline.
     * @return A vector of Vertex objects.
     */
    std::vector<Vertex> vertices() const;

    /**
     * @brief Sets the vertices defining the multiline.
     * @param vertices A vector of Vertex objects.
     */
    void setVertices(const std::vector<Vertex> &vertices);

private:
    std::vector<Vertex> _vertices;///< List of vertices defining the multiline.
};

}// namespace dwg
