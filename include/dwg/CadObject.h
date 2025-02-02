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

// clang-format off
#include <dwg/IHandledCadObject.h>
#include <dwg/ObjectType.h>
#include <dwg/exports.h>
#include <dwg/objects/CadDictionary.h>
#include <dwg/tables/TableEntry.h>
#include <dwg/CadObjectCollection.h>
// clang-format on

namespace dwg {

class DG_CadDocument;

/**
 * @class DG_CadObject
 * @brief Base class representing a CAD object with handle-based identification and ownership hierarchy.
 *
 * This class serves as the foundation for all CAD entities, providing support for unique
 * identification through handles and ownership relationships within a CAD document.
 */
class LIBDWG_API DG_CadObject : public DG_IHandledCadObject
{
protected:
    /// @brief Unique handle identifying the CAD object.
    unsigned long long _handle;

    /// @brief Pointer to the owning CAD object.
    DG_CadObject *_owner;

    /// @brief Pointer to the CAD document this object belongs to.
    DG_CadDocument *_document;

public:
    /**
     * @brief Default constructor.
     */
    DG_CadObject() = default;

    /**
     * @brief Virtual destructor.
     */
    virtual ~DG_CadObject() override;

    /**
     * @brief Get the type of the CAD object.
     * @details This method must be implemented by derived classes to return the specific
     * type of the object.
     * @return The type of the object as a value from the `DG_ObjectType` enumeration.
     */
    virtual DG_ObjectType ObjectType() const = 0;

    /**
     * @brief Get the name of the CAD object.
     * @details This method must be implemented by derived classes to return the name
     * associated with the object.
     * @return A string representing the object's name.
     */
    virtual std::string ObjectName() const = 0;

    /**
     * @brief Get the subclass marker of the CAD object.
     * @details This method must be implemented by derived classes to return a marker
     * indicating the object's subclass.
     * @return A string representing the subclass marker.
     */
    virtual std::string SubclassMarker() const = 0;

    /**
     * @brief Get the unique handle of the CAD object.
     * @return The handle of the object as an unsigned long long value.
     */
    unsigned long long Handle() const;

    /**
     * @brief Get the owning CAD object of this object.
     * @details The ownership establishes a hierarchical relationship between CAD objects.
     * @return A pointer to the owning CAD object, or nullptr if no owner is set.
     */
    DG_CadObject *Owner() const;

    /**
     * @brief Get the CAD document that contains this object.
     * @return A pointer to the owning CAD document.
     */
    DG_CadDocument *Document() const;

    /**
     * @brief Set the CAD document that contains this object.
     * @param doc Pointer to the CAD document.
     */
    void Document(DG_CadDocument *doc);

    /**
     * @brief Clone this CAD object.
     * @return A pointer to the newly created copy of this object.
     * @note Derived classes should override this method to provide proper deep copy behavior.
     */
    virtual DG_CadObject *Clone();

protected:
    /**
     * @brief Set the unique handle of the CAD object.
     * @param value The handle value to assign.
     */
    void Handle(unsigned long long value);

    /**
     * @brief Set the owning CAD object for this object.
     * @param obj Pointer to the new owning CAD object.
     */
    void Owner(DG_CadObject *obj);

private:
    /// @brief Deleted copy constructor to prevent copying.
    DG_CadObject(const DG_CadObject &) = delete;

    /// @brief Deleted assignment operator to prevent copying.
    DG_CadObject &operator=(const DG_CadObject &) = delete;
};

}// namespace dwg