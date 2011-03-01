/*
 *  MurmurHash3CLI - command line interface for MurmurHash3
 *  Copyright (C) 2011 Jaromir Capik <tavvva@email.cz>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef __MURMURHASH3_HPP__

  #define __MURMURHASH3_HPP__

  #include <stdint.h>

  #define MURMURHASH3_OUTPUT_LENGTH	16

  typedef uint8_t MurmurHash3_output_t[MURMURHASH3_OUTPUT_LENGTH];
  typedef uint32_t MurmurHash3_seed_t;

  void MurmurHash3_x86_32  ( const void * key, int len, uint32_t seed, void * out );
  void MurmurHash3_x86_64  ( const void * key, int len, uint32_t seed, void * out );
  void MurmurHash3_x86_128 ( const void * key, int len, uint32_t seed, void * out );

  void MurmurHash3_x64_32  ( const void * key, int len, uint32_t seed, void * out );
  void MurmurHash3_x64_64  ( const void * key, int len, uint32_t seed, void * out );
  void MurmurHash3_x64_128 ( const void * key, int len, uint32_t seed, void * out );

#endif
