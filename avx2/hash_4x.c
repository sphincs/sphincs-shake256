#include "hash.h"
#include "params.h"
#include "fips202x4.h"

int loop_hash_2n_n_mask_4x(unsigned char *out, const unsigned char *in,
                           unsigned long long blocks_4x, const unsigned char *mask)
{
    int i;

    for (i = 0; i < (blocks_4x >> 1); i += HASH_BYTES) {
        hash_2n_n_mask_4x(out + 4*i, in + 4*i*2,
                          HASH_BYTES, 2*HASH_BYTES, mask);
    }

    return 0;
}


int hash_2n_n_mask_4x(unsigned char *out, const unsigned char *in,
                      unsigned long long out_dist, unsigned long long in_dist,
                      const unsigned char *mask)
{
    unsigned char buf[2*4*HASH_BYTES];
    int i;

    for(i=0;i<2*HASH_BYTES;i++) {
        buf[i+0*2*HASH_BYTES] = in[i+0*in_dist] ^ mask[i];
        buf[i+1*2*HASH_BYTES] = in[i+1*in_dist] ^ mask[i];
        buf[i+2*2*HASH_BYTES] = in[i+2*in_dist] ^ mask[i];
        buf[i+3*2*HASH_BYTES] = in[i+3*in_dist] ^ mask[i];
    }
    shake256x4(out + 0*out_dist,
               out + 1*out_dist,
               out + 2*out_dist,
               out + 3*out_dist, HASH_BYTES,
               buf + 0*2*HASH_BYTES,
               buf + 1*2*HASH_BYTES,
               buf + 2*2*HASH_BYTES,
               buf + 3*2*HASH_BYTES, 2*HASH_BYTES);

    return 0;
}

int hash_n_n_4x(unsigned char *out, const unsigned char *in)
{
    shake256x4(out + 0*HASH_BYTES,
               out + 1*HASH_BYTES,
               out + 2*HASH_BYTES,
               out + 3*HASH_BYTES, HASH_BYTES,
               in + 0*HASH_BYTES,
               in + 1*HASH_BYTES,
               in + 2*HASH_BYTES,
               in + 3*HASH_BYTES, HASH_BYTES);
    return 0;
}

int hash_n_n_mask_4x(unsigned char *out, const unsigned char *in, const unsigned char *mask)
{
    unsigned char buf[4*HASH_BYTES];
    int i;

    for(i=0;i<HASH_BYTES;i++) {
        buf[i+0*HASH_BYTES] = in[i+0*HASH_BYTES] ^ mask[i];
        buf[i+1*HASH_BYTES] = in[i+1*HASH_BYTES] ^ mask[i];
        buf[i+2*HASH_BYTES] = in[i+2*HASH_BYTES] ^ mask[i];
        buf[i+3*HASH_BYTES] = in[i+3*HASH_BYTES] ^ mask[i];
    }
    shake256x4(out + 0*HASH_BYTES,
               out + 1*HASH_BYTES,
               out + 2*HASH_BYTES,
               out + 3*HASH_BYTES, HASH_BYTES,
               buf + 0*HASH_BYTES,
               buf + 1*HASH_BYTES,
               buf + 2*HASH_BYTES,
               buf + 3*HASH_BYTES, HASH_BYTES);

    return 0;
}
