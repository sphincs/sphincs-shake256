#include "params.h"
#include "permute.h"
#include "fips202.h"

#include <stddef.h>

int varlen_hash(unsigned char *out,const unsigned char *in,unsigned long long inlen)
{
  shake256(out, 32, in, inlen);
  return 0;
}

int msg_hash(unsigned char *out,const unsigned char *in,unsigned long long inlen)
{
  shake256(out, 64, in, inlen);
  return 0;
}

int hash_2n_n(unsigned char *out,const unsigned char *in)
{
  shake256(out, HASH_BYTES, in, 2*HASH_BYTES);
  return 0;
}

int hash_2n_n_mask(unsigned char *out,const unsigned char *in, const unsigned char *mask)
{
  unsigned char buf[2*HASH_BYTES];
  int i;
  for(i=0;i<2*HASH_BYTES;i++)
    buf[i] = in[i] ^ mask[i];
  return hash_2n_n(out, buf);
}

int hash_n_n(unsigned char *out,const unsigned char *in)
{
  shake256(out, HASH_BYTES, in, HASH_BYTES);
  return 0;
}

int hash_n_n_mask(unsigned char *out,const unsigned char *in, const unsigned char *mask)
{
  unsigned char buf[HASH_BYTES];
  int i;
  for(i=0;i<HASH_BYTES;i++)
    buf[i] = in[i] ^ mask[i];
  return hash_n_n(out, buf);
}

