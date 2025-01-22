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

#include <dwg/exports.h>

namespace dwg {

// The Transparency struct represents the transparency properties of an object in LIBDWG.
// It provides methods to manage and convert transparency values.
struct LIBDWG_API Transparency
{
    // Member variable to store the transparency value.
    short Value;

    // Constructor to initialize the transparency with a given value.
    Transparency(short value);

    // Checks if the transparency is set to "ByLayer".
    bool IsByLayer() const;

    // Checks if the transparency is set to "ByBlock".
    bool IsByBlock() const;

    // Getter method to retrieve the transparency value.
    short Value() const;

    // Setter method to update the transparency value.
    void Value(short value);

    // Converts a Transparency object to an alpha value (integer).
    static int ToAlphaValue(Transparency transparency);

    // Creates a Transparency object from an alpha value (integer).
    static Transparency FromAlphaValue(int value);

    // Predefined Transparency object representing "ByLayer" transparency.
    static Transparency ByLayer;

    // Predefined Transparency object representing "ByBlock" transparency.
    static Transparency ByBlock;

    // Predefined Transparency object representing fully opaque transparency.
    static Transparency Opaque;
};

}// namespace dwg
