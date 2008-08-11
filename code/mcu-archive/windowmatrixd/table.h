/*
   windowmatrixd - receives blinkenframes from the network

   Copyright (C) 2001, 2002 Sebastian Klemke

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

*/


#ifndef _TABLE_H_
#define _TABLE_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#include "common.h"


static const table_t remap_table[HEIGHT][WIDTH] = {
  {{ 0, 0}, { 0, 1}, { 0, 2}, { 0, 3}, { 0, 4}, { 0, 5}, { 0, 6}, { 0, 7},
   { 1, 0}, { 1, 1}, { 1, 2}, { 1, 3}, { 1, 4}, { 1, 5}, { 1, 6}, { 1, 7},
   { 2, 0}, { 2, 1}},
  {{ 2, 2}, { 2, 3}, { 2, 4}, { 2, 5}, { 2, 6}, { 2, 7}, { 3, 0}, { 3, 1},
   { 3, 2}, { 3, 3}, { 3, 4}, { 3, 5}, { 3, 6}, { 3, 7}, { 4, 0}, { 4, 1},
   { 4, 2}, { 4, 3}},
  {{ 4, 4}, { 4, 5}, { 4, 6}, { 4, 7}, { 5, 0}, { 5, 1}, { 5, 2}, { 5, 3},
   { 5, 4}, { 5, 5}, { 5, 6}, { 5, 7}, { 6, 0}, { 6, 1}, { 6, 2}, { 6, 3},
   { 6, 4}, { 6, 5}},
  {{ 6, 6}, { 6, 7}, { 7, 0}, { 7, 1}, { 7, 2}, { 7, 3}, { 7, 4}, { 7, 5},
   { 7, 6}, { 7, 7}, { 8, 0}, { 8, 1}, { 8, 2}, { 8, 3}, { 8, 4}, { 8, 5},
   { 8, 6}, { 8, 7}},
  {{ 9, 0}, { 9, 1}, { 9, 2}, { 9, 3}, { 9, 4}, { 9, 5}, { 9, 6}, { 9, 7},
   {10, 0}, {10, 1}, {10, 2}, {10, 3}, {10, 4}, {10, 5}, {10, 6}, {10, 7},
   {11, 0}, {11, 1}},
  {{11, 2}, {11, 3}, {11, 4}, {11, 5}, {11, 6}, {11, 7}, {12, 0}, {12, 1},
   {12, 2}, {12, 3}, {12, 4}, {12, 5}, {12, 6}, {12, 7}, {13, 0}, {13, 1},
   {13, 2}, {13, 3}},
  {{13, 4}, {13, 5}, {13, 6}, {13, 7}, {14, 0}, {14, 1}, {14, 2}, {14, 3},
   {14, 4}, {14, 5}, {14, 6}, {14, 7}, {15, 0}, {15, 1}, {15, 2}, {15, 3},
   {15, 4}, {15, 5}},
  {{15, 6}, {15, 7}, {16, 0}, {16, 1}, {16, 2}, {16, 3}, {16, 4}, {16, 5},
   {16, 6}, {16, 7}, {17, 0}, {17, 1}, {17, 2}, {17, 3}, {17, 4}, {17, 5},
   {17, 6}, {17, 7}}
};


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _TABLE_H_ */


