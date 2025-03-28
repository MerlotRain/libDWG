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

#include <dwg/entities/UnderlayEntity.h>

namespace dwg {

/**
 * @class PdfUnderlay
 * @brief Represents a PDF underlay entity in a DWG/DXF drawing.
 *
 * A PDF underlay allows embedding a PDF document as a reference within a drawing.
 * It inherits from UnderlayEntity, sharing common underlay properties.
 */
class LIBDWG_API PdfUnderlay : public UnderlayEntity
{
public:
    /**
     * @brief Constructs a PdfUnderlay object.
     */
    PdfUnderlay();

    /**
     * @brief Destroys the PdfUnderlay object.
     */
    ~PdfUnderlay();

    /**
     * @brief Gets the object type of the PDF underlay.
     * @return The object type as ObjectType.
     */
    virtual ObjectType objectType() const override;

    /**
     * @brief Gets the name of the PDF underlay object.
     * @return The object name as a string.
     */
    virtual std::string objectName() const override;
};

}// namespace dwg
