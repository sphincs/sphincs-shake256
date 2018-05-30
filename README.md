## SPHINCS-SHAKE256 [![Build Status](https://travis-ci.org/sphincs/sphincs-shake256.svg?branch=master)](https://travis-ci.org/sphincs/sphincs-shake256)

This repository contains the [SPHINCS-256](https://sphincs.cr.yp.to) reference code, modified to use SHAKE256 as a hash function rather than the BLAKE and ChaCha-based construction as originally proposed. All other parameters and constructions are kept the same. This positions it somewhere between SPHINCS-256 and the recent SPHINCS+ submission to NIST's post-quantum cryptography project.

### License

The SPHINCS-256 code was placed in the public domain as per Section 1 of the [SPHINCS paper](https://eprint.iacr.org/2014/795.pdf). The FIPS202 code was placed in the public domain as part of the Keccak Code Package. All other modifications are available under the CC0 1.0 Universal Public Domain Dedication.
