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

#include <dwg/CadDocument.h>
#include <dwg/CadObject.h>
#include <dwg/objects/CadDictionary.h>
#include <dwg/objects/collections/ObjectDictionaryCollection.h>
#include <dwg/tables/AppId.h>
#include <dwg/tables/TableEntry.h>
#include <dwg/tables/collections/Table.h>
#include <dwg/xdata/ExtendedDataDictionary.h>

namespace dwg {

CadObject::CadObject()
{
    _extendedData = new ExtendedDataDictionary(this);
}

CadObject::~CadObject() {}

ExtendedDataDictionary *CadObject::extendedData() const
{
    return _extendedData;
}

unsigned long long CadObject::handle() const
{
    return _handle;
}

IHandledCadObject *CadObject::owner() const
{
    return _owner;
}

CadDictionary *CadObject::xdictionary() const
{
    return _xdictionary;
}

CadDocument *CadObject::document() const
{
    return _document;
}

void CadObject::setDocument(CadDocument *doc)
{
    _document = doc;
}

CadObject *CadObject::clone()
{
    return nullptr;
}

bool CadObject::hasDynamicSubclass() const
{
    return false;
}

std::vector<CadObject *> CadObject::reactors() const
{
    return _reactors;
}

std::vector<CadObject *> &CadObject::reactors()
{
    return _reactors;
}

void CadObject::clearReactors() {}

void CadObject::addReactor(CadObject *reactor)
{
    _reactors.push_back(reactor);
}

bool CadObject::removeReactor(CadObject *reactor)
{
    for (auto it = _reactors.begin(); it != _reactors.end(); ++it)
    {
        if (*it == reactor)
        {
            _reactors.erase(it);
            return true;
        }
    }
    return false;
}

void CadObject::setHandle(unsigned long long value)
{
    _handle = value;
}

void CadObject::setOwner(IHandledCadObject *obj)
{
    _owner = obj;
}

void CadObject::setExtendedData(ExtendedDataDictionary *value)
{
    _extendedData = value;
}

void CadObject::setXDictionary(CadDictionary *value)
{
    _xdictionary = value;
}

void CadObject::assignDocument(CadDocument *doc)
{
    _document = doc;
    if (_xdictionary)
    {
        doc->registerCollection(_xdictionary);
    }

    if (!_extendedData->data().empty())
    {
        auto &&entries = _extendedData->data();
        _extendedData->clear();

        for (auto &&[key, value]: entries)
        {
            _extendedData->add(dynamic_cast<AppId *>(key->clone()), value);
        }
    }
}

void CadObject::unassignDocument() {}

NonGraphicalObject *CadObject::updateCollection(NonGraphicalObject *entry, ObjectDictionaryCollection *collection)
{
    if (!entry || !collection)
    {
        return entry;
    }

    NonGraphicalObject *existing = collection->value(entry->name());
    if (existing)
    {
        return existing;
    }
    else
    {
        collection->add(entry);
        return entry;
    }
}

TableEntry *CadObject::updateTable(TableEntry *entry, Table *table)
{
    if (!table || !entry)
    {
        return entry;
    }

    TableEntry *existing = table->value(entry->name());
    if (existing)
    {
        return existing;
    }
    else
    {
        table->add(entry);
        return entry;
    }
}

}// namespace dwg