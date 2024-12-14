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

namespace dwg {

enum ACadVersion : short
{
    Unknown = -1,
    /// Release 1.1
    MC0_0,
    /// Release 1.2
    AC1_2,
    /// Release 1.4
    AC1_4,
    /// Release 2.0
    AC1_50,
    /// Release 2.10
    AC2_10,
    /// Release 2.5
    AC1002,
    /// Release 2.6
    AC1003,
    /// Release 9
    AC1004,
    /// Release 10
    AC1006,
    /// Release 11/12 (LT R1/R2)
    AC1009,
    /// Release 13 (LT95)
    AC1012 = 19,
    /// Release 14, 14.01 (LT97/LT98)
    AC1014 = 21,
    /// Release 2000/2000i/2002
    AC1015 = 23,
    /// Release 2004/2005/2006
    AC1018 = 25,
    /// Release 2007/2008/2009
    AC1021 = 27,
    /// Release 2010/2011/2012
    AC1024 = 29,
    /// Release 2013/2014/2015/2016/2017
    AC1027 = 31,
    /// Release 2018/2019/2020
    AC1032 = 33
};

}// namespace dwg