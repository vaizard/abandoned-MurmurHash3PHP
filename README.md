MurmurHash3PHP
==============

A C++ fork/rewrite of the smhasher project to bring Murmurhash3 to the Linux shell and to the PHP scripting language.


# Installation
```sh
git clone https://github.com/sgtsquiggs/MurmurHash3PHP.git
cd MurmurHash3PHP
phpize
./configure --enable-murmurhash3
make install
```

# Usage
MurmurHash is not cryptographically secure, so I am just using rand()
```php
int seed = rand();
// 681830476 for this example
```
### murmurhash3_128(key, seed)
Generates a 128 bit hash.
```php
echo murmurhash3_128('this is the key for my 128 bit hash', seed);
// 476d1835de8c85f3f6686e7f68ac515a
```

### murmurhash3_32(key, seed)
Generates a 32 bit hash.
```php
echo murmurhash3_32('this is the key for my 32 bit hash', seed);
// 9853e119
```

### murmurhash3(key, seed)
Alias of murmurhash3_128.
