#ifndef SPX_FIPS202X4_H
#define SPX_FIPS202X4_H

#include <immintrin.h>

void shake128x4(unsigned char *out0,
                unsigned char *out1,
                unsigned char *out2,
                unsigned char *out3, unsigned long long outlen,
                const unsigned char *in0,
                const unsigned char *in1,
                const unsigned char *in2,
                const unsigned char *in3, unsigned long long inlen);

void shake256x4(unsigned char *out0,
                unsigned char *out1,
                unsigned char *out2,
                unsigned char *out3, unsigned long long outlen,
                const unsigned char *in0,
                const unsigned char *in1,
                const unsigned char *in2,
                const unsigned char *in3, unsigned long long inlen);

#endif
