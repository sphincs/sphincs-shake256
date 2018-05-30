#include "fips202.h"
#include "params.h"
#include "prg.h"

void prg(unsigned char *r, unsigned long long rlen, const unsigned char key[SEED_BYTES])
{
  shake256(r, rlen, key, SEED_BYTES);
}
