/**
 * Copyright 2013 Felix Schmitt
 *
 * This file is part of libSplash. 
 * 
 * libSplash is free software: you can redistribute it and/or modify 
 * it under the terms of of either the GNU General Public License or 
 * the GNU Lesser General Public License as published by 
 * the Free Software Foundation, either version 3 of the License, or 
 * (at your option) any later version. 
 * libSplash is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 * GNU General Public License and the GNU Lesser General Public License 
 * for more details. 
 * 
 * You should have received a copy of the GNU General Public License 
 * and the GNU Lesser General Public License along with libSplash. 
 * If not, see <http://www.gnu.org/licenses/>. 
 */

#ifndef BASETYPES_COMPOUND_HPP
#define	BASETYPES_COMPOUND_HPP

#include <stdint.h>

#include "CollectionType.hpp"

namespace splash
{

    static const char* COMPOUND_ELEMENTS[] = {"x", "y", "z", "u", "v", "w"};

#define TYPE_COMPOUND(_name, _h5_type, _real_type, _size) \
    class ColType##_name : public CollectionType \
    { \
    public: \
 \
        ColType##_name() \
        { \
            this->type = H5Tcreate(H5T_COMPOUND, sizeof (_real_type) * _size); \
            for (size_t i = 0; i < _size; ++i) \
                H5Tinsert(this->type, COMPOUND_ELEMENTS[i], i * sizeof(_real_type), _h5_type); \
        } \
 \
        ~ColType##_name() \
        { H5Tclose(this->type); } \
 \
        size_t getSize() const \
        { return _size * sizeof (_real_type); } \
    };

TYPE_COMPOUND(Float2, H5T_NATIVE_FLOAT, float, 2);
TYPE_COMPOUND(Float3, H5T_NATIVE_FLOAT, float, 3);
TYPE_COMPOUND(Float4, H5T_NATIVE_FLOAT, float, 4);

TYPE_COMPOUND(Double2, H5T_NATIVE_DOUBLE, double, 2);
TYPE_COMPOUND(Double3, H5T_NATIVE_DOUBLE, double, 3);
TYPE_COMPOUND(Double4, H5T_NATIVE_DOUBLE, double, 4);

TYPE_COMPOUND(Int2, H5T_NATIVE_INT, int, 2);
TYPE_COMPOUND(Int3, H5T_NATIVE_INT, int, 3);
TYPE_COMPOUND(Int4, H5T_NATIVE_INT, int, 4);

}

#endif	/* BASETYPES_COMPOUND_HPP */

