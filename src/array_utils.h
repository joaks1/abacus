/**
 * @file        array_utils.h
 * @authors     Jamie Oaks
 * @package     msBayes
 * @brief       A collection of types and functions for array manipulations.
 * @copyright   Copyright (C) 2013 Jamie Oaks.
 *   This file is part of msBayes.  msBayes is free software; you can
 *   redistribute it and/or modify it under the terms of the GNU General Public
 *   License as published by the Free Software Foundation; either version 2 of
 *   the License, or (at your option) any later version.
 * 
 *   msBayes is distributed in the hope that it will be useful, but WITHOUT ANY
 *   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 *   FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 *   details.
 * 
 *   You should have received a copy of the GNU General Public License along
 *   with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct d_array_ {
    double * a;
    int length;
    int capacity;
} d_array;

typedef struct i_array_ {
    int * a;
    int length;
    int capacity;
} i_array;

typedef struct c_array_ {
    char * a;
    int capacity;
} c_array;

typedef struct s_array_ {
    c_array ** a;
    int length;
    int capacity;
} s_array;

d_array * init_d_array(int length);
void expand_d_array(d_array * v);
void append_d_array(d_array * v, double x);
void extend_d_array(d_array * dest, const d_array * to_add);
double get_d_array(const d_array * v, int index);
void set_d_array(d_array * v, int index, double x);
void write_d_array(const d_array * v);
void free_d_array(d_array * v);

c_array * init_c_array(int length);
void expand_c_array(c_array * v);
void assign_c_array(c_array * v, const char * s);
void free_c_array(c_array * v);

i_array * init_i_array(int length);
void expand_i_array(i_array * v);
void append_i_array(i_array * v, int x);
void extend_i_array(i_array * dest, const i_array * to_add);
int get_i_array(const i_array * v, int index);
void set_i_array(i_array * v, int index, int x);
void write_i_array(const i_array * v);
void free_i_array(i_array * v);

s_array * init_s_array(int length);
void expand_s_array(s_array * v);
void append_s_array(s_array * v, const char * x);
void extend_s_array(s_array * dest, const s_array * to_add);
char * get_s_array(const s_array * v, int index);
void set_s_array(s_array * v, int index, const char * s);
void write_s_array(const s_array * v);
void free_s_array(s_array * v);
int s_arrays_equal(const s_array * h1, const s_array * h2);

int split_str(char * string, s_array * words, int expected_num);
void get_matching_indices(const s_array * search_strings,
        const s_array * target_strings,
        i_array * indices);
int get_doubles(const s_array * strings, const i_array * indices,
        d_array * doubles_dest);

#endif /* ARRAY_UTILS_H */

