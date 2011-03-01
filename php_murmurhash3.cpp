/*
 *  MurmurHash3PHP - php extension for MurmurHash3
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

extern "C" {
  #ifdef HAVE_CONFIG_H
    #include "config.h"
  #endif

  #include "php.h"
  #include "php_murmurhash3.h"
}

#include "MurmurHash3.hpp"


static function_entry murmurhash3_functions[] = {
    PHP_FE(murmurhash3, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry murmurhash3_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_MURMURHASH3_EXTNAME,
    murmurhash3_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
#if ZEND_MODULE_API_NO >= 20010901
    PHP_MURMURHASH3_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

extern "C" {
  #ifdef COMPILE_DL_MURMURHASH3
    ZEND_GET_MODULE(murmurhash3)
  #endif
}


// Convert uint8 to hex representation (2 characters)
void c2h(uint8_t c, char *r)
{
  const char *hex = "0123456789abcdef";
  r[0] = hex[c / 16];
  r[1] = hex[c % 16];
}

PHP_FUNCTION(murmurhash3)
{
    char *key;
    int key_len;
    long seed;
    char output[MURMURHASH3_OUTPUT_LENGTH + 1];
    char result[MURMURHASH3_OUTPUT_LENGTH * 2 + 1];

    // Parse the input parameters
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sl", &key, &key_len, &seed) == FAILURE) {
        RETURN_NULL();
    }

    // Calculate the hash
    MurmurHash3_x64_128 ( key, key_len, (uint32_t)seed, output );
    output[MURMURHASH3_OUTPUT_LENGTH] = 0;

    // Convert to HEX
    for (int i=0; i<MURMURHASH3_OUTPUT_LENGTH; i++) {
      c2h(output[i], &result[i*2]);
    }
    result[MURMURHASH3_OUTPUT_LENGTH * 2] = 0;

    // Return the result
    RETURN_STRING(result, 1);
}
