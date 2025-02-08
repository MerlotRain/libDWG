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

#include <dwg/objects/CadDictionaryWithDefault.h>

namespace dwg {

CadDictionaryWithDefault::CadDictionaryWithDefault() {}

ObjectType CadDictionaryWithDefault::ObjectType() const { return ObjectType::UNLISTED; }
std::string CadDictionaryWithDefault::ObjectName() const { return DxfFileToken::ObjectDictionaryWithDefault; }
std::string CadDictionaryWithDefault::SubclassMarker() const { return DxfSubclassMarker::DictionaryWithDefault; }

CadObjectPtr CadDictionaryWithDefault::DefaultEntry() const
{
    if (!_default_entry.Expired()) return _default_entry.Lock();

    return NULL;
}

void CadDictionaryWithDefault::DefaultEntry(CadObject *obj) { _default_entry = obj; }

}// namespace dwg