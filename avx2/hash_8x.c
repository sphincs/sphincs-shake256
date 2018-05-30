/*
These functions serve as an intermediate replacement towards hash_4x,
but transitioning via hash_8x makes more sense when coming from 8x ChaCha
*/

#include "hash.h"
#include "params.h"


int loop_hash_2n_n_mask_8x(unsigned char *out, const unsigned char *in,
                           unsigned long long blocks_8x, const unsigned char *mask)
{
    int i;

    for (i = 0; i < (blocks_8x >> 1); i += HASH_BYTES) {
        hash_2n_n_mask_8x(out + 8*i, in + 8*i*2,
                          HASH_BYTES, 2*HASH_BYTES, mask);
    }

    return 0;
}


int hash_2n_n_mask_8x(unsigned char *out, const unsigned char *in,
                      unsigned long long out_dist, unsigned long long in_dist,
                      const unsigned char *mask)
{
    int i;

    for (i = 0; i < 8; i++) {
        hash_2n_n_mask(out, in, mask);
        out += out_dist;
        in += in_dist;
    }

    return 0;
}

int hash_n_n_8x(unsigned char *out, const unsigned char *in)
{
    int i;

    for (i = 0; i < 8; i++) {
        hash_n_n(out, in);
        out += HASH_BYTES;
        in += HASH_BYTES;
    }

    return 0;
}

int hash_n_n_mask_8x(unsigned char *out, const unsigned char *in, const unsigned char *mask)
{
    int i;

    for (i = 0; i < 8; i++) {
        hash_n_n_mask(out, in, mask);
        out += HASH_BYTES;
        in += HASH_BYTES;
    }

    return 0;
}
