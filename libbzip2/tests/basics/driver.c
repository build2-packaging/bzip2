#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <libbzip2/version.h>
#include <libbzip2/bzlib.h>

int starts_with(const char *pre, const char *str)
{
    size_t lenpre = strlen(pre),
           lenstr = strlen(str);
    return lenstr < lenpre ? 0 : memcmp(pre, str, lenpre) == 0;
}

int main ()
{
  const char* version = BZ2_bzlibVersion();
  puts(version);
  if(starts_with(version, LIBBZIP2_VERSION_FULL) != 0)
    return EXIT_FAILURE;
}
