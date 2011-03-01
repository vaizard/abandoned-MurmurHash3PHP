#!/bin/bash
phpize
./configure --enable-murmurhash3
make install
cp 06_murmurhash3.ini /etc/php.d/