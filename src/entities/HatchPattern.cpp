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

#include <dwg/entities/HatchPattern.h>

namespace dwg {

HatchPattern::HatchPattern() {}

HatchPattern::HatchPattern(const std::string &name) : _name(name) {}

HatchPattern::~HatchPattern() {}

HatchPattern HatchPattern::Solid()
{
    return HatchPattern("SOLID");
}

std::string HatchPattern::name() const
{
    return _name;
}

std::vector<HatchPattern> HatchPattern::LoadFrom(const std::string &filepath)
{
    return std::vector<HatchPattern>();
}

void HatchPattern::SavePatterns(const std::string &filepath, const std::vector<HatchPattern> &patterns) {}

void HatchPattern::setName(const std::string &name)
{
    _name = name;
}

std::string HatchPattern::description() const
{
    return _description;
}

void HatchPattern::setDescription(const std::string &description)
{
    _description = description;
}

std::vector<HatchPattern::Line> HatchPattern::lines() const
{
    return _lines;
}

void HatchPattern::setLines(const std::vector<HatchPattern::Line> &lines)
{
    _lines = lines;
}

}// namespace dwg