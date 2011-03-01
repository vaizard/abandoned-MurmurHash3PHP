PHP_ARG_ENABLE(murmurhash3, whether to enable murmurhash3 support,[ --enable-murmurhash3   Enable murmurhash3 support])

if test "$PHP_MURMURHASH3" = "yes"; then
  PHP_REQUIRE_CXX
  AC_LANG_CPLUSPLUS
  PHP_ADD_LIBRARY(stdc++,,MURMURHASH3_SHARED_LIBADD)
  PHP_SUBST(MURMURHASH3_SHARED_LIBADD)
  AC_DEFINE(HAVE_MURMURHASH3, 1, [Whether you have murmurhash3])
  PHP_NEW_EXTENSION(murmurhash3, php_murmurhash3.cpp MurmurHash3.cpp, $ext_shared)
fi