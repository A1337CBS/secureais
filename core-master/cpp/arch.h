/*
   Copyright (C) 2019 MIRACL UK Ltd.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.


    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

     https://www.gnu.org/licenses/agpl-3.0.en.html

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

   You can be released from the requirements of the license by purchasing
   a commercial license. Buying such a license is mandatory as soon as you
   develop commercial activities involving the MIRACL Core Crypto SDK
   without disclosing the source code of your own applications, or shipping
   the MIRACL Core Crypto SDK with a closed source product.
*/

/* Architecture definition header file */

/**
 * @file arch.h
 * @author Mike Scott
 * @date 23rd February 2016
 * @brief Architecture Header File
 *
 * Specify Processor Architecture
 *
 */

/* NOTE: There is only one user configurable section in this header - see below */

#ifndef ARCH_H
#define ARCH_H
#include <stdint.h>

namespace core {

/*** START OF USER CONFIGURABLE SECTION - set architecture ***/

#define CHUNK 64      /**< size of chunk in bits = wordlength of computer = 16, 32 or 64. Note not all curve options are supported on 16-bit processors - see rom.c */

/*** END OF USER CONFIGURABLE SECTION ***/

/* Create Integer types */
/* Support for C99?  Note for GCC need to explicitly include -std=c99 in command line */


#define byte uint8_t            /**< 8-bit unsigned integer */
#define sign8 int8_t            /**< 8-bit signed integer */
#define sign16 int16_t          /**< 16-bit signed integer */
#define sign32 int32_t          /**< 32-bit signed integer */
#define sign64 int64_t          /**< 64-bit signed integer */
#define unsign32 uint32_t       /**< 32-bit unsigned integer */
#define unsign64 uint64_t       /**< 64-bit unsigned integer */

#define uchar unsigned char  /**<  Unsigned char */

/* Don't mess with anything below this line unless you know what you are doing */
/* This next is probably OK, but may need changing for non-C99-standard environments */

/* This next is probably OK, but may need changing for non-C99-standard environments */

#if CHUNK==16

#define chunk int16_t       /**< C type corresponding to word length */
#define dchunk int32_t      /**< Always define double length chunk type if available */

#endif

#if CHUNK == 32

#define chunk int32_t       /**< C type corresponding to word length */
#define dchunk int64_t      /**< Always define double length chunk type if available */

#endif

#if CHUNK == 64

#define chunk int64_t       /**< C type corresponding to word length */
//    #ifdef __GNUC__
//       #define dchunk __int128        /**< Always define double length chunk type if available - GCC supports 128 bit type  ??? */
//    #endif

//    #ifdef __clang__
//       #define dchunk __int128
#if defined(__SIZEOF_INT128__) && __SIZEOF_INT128__ == 16
#define dchunk __int128
#endif

#endif

#ifdef dchunk
#define COMBA      /**< Use COMBA method for faster muls, sqrs and reductions */
#endif

}

#endif
