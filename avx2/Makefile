CC = /usr/bin/gcc
CFLAGS = -Wall -g -O3 -mavx2 -no-pie

TESTS = test/test_horst \
		test/test_sign \
		test/test_wots \

.PHONY: clean test

tests: $(TESTS)

test: $(TESTS:=.exec)

test/test_horst: prg.c consts.c horst.c hash.c hash_4x.c fips202.c fips202x4.c keccak4x/KeccakP-1600-times4-SIMD256.o permute.c randombytes.c test/test_horst.c api.h hash.h randombytes.h params.h cpucycles.h cpucycles.c
	$(CC) $(CFLAGS) prg.c consts.c horst.c hash.c hash_4x.c fips202.c fips202x4.c keccak4x/KeccakP-1600-times4-SIMD256.o permute.c randombytes.c cpucycles.c test/test_horst.c -o $@

test/test_wots: prg.c wots.c consts.c hash.c hash_4x.c fips202.c fips202x4.c keccak4x/KeccakP-1600-times4-SIMD256.o permute.c randombytes.c test/test_wots.c api.h hash.h randombytes.h params.h cpucycles.h cpucycles.c
	$(CC) $(CFLAGS) prg.c wots.c consts.c hash.c hash_4x.c fips202.c fips202x4.c keccak4x/KeccakP-1600-times4-SIMD256.o permute.c randombytes.c cpucycles.c test/test_wots.c -o $@

test/speed: prg.c consts.c horst.c horst.h wots.c sign.c zerobytes.c zerobytes.h hash.c hash_4x.c fips202.c fips202x4.c keccak4x/KeccakP-1600-times4-SIMD256.o permute.c randombytes.c test/speed.c api.h crypto_sign.h hash.h randombytes.h params.h cpucycles.h cpucycles.c
	$(CC) $(CFLAGS) prg.c consts.c horst.c wots.c sign.c zerobytes.c hash.c hash_4x.c fips202.c fips202x4.c keccak4x/KeccakP-1600-times4-SIMD256.o permute.c cpucycles.c randombytes.c test/speed.c -o $@

test/test_sign: prg.c consts.c horst.c horst.h wots.c sign.c zerobytes.c zerobytes.h hash.c hash_4x.c fips202.c fips202x4.c keccak4x/KeccakP-1600-times4-SIMD256.o permute.c randombytes.c test/test_sign.c api.h crypto_sign.h hash.h randombytes.h params.h cpucycles.h cpucycles.c
	$(CC) $(CFLAGS) prg.c consts.c horst.c wots.c sign.c zerobytes.c hash.c hash_4x.c fips202.c fips202x4.c keccak4x/KeccakP-1600-times4-SIMD256.o permute.c cpucycles.c randombytes.c test/test_sign.c -o $@

test/gen_testvectors: prg.c consts.c horst.c horst.h wots.c sign.c zerobytes.c zerobytes.h hash.c hash_4x.c fips202.c fips202x4.c keccak4x/KeccakP-1600-times4-SIMD256.o permute.c test/gen_testvectors.c api.h crypto_sign.h hash.h randombytes.h params.h cpucycles.h cpucycles.c
	$(CC) $(CFLAGS) prg.c consts.c horst.c wots.c sign.c zerobytes.c hash.c hash_4x.c fips202.c fips202x4.c keccak4x/KeccakP-1600-times4-SIMD256.o permute.c cpucycles.c test/gen_testvectors.c -o $@

test/%.exec: test/%
	@$<

keccak4x/KeccakP-1600-times4-SIMD256.o: keccak4x/align.h \
										keccak4x/brg_endian.h \
										keccak4x/KeccakP-1600-times4-SIMD256.c \
										keccak4x/KeccakP-1600-times4-SnP.h \
										keccak4x/KeccakP-1600-unrolling.macros \
										keccak4x/SIMD256-config.h
	$(CC) $(CFLAGS) -c keccak4x/KeccakP-1600-times4-SIMD256.c -o $@


clean:
	-$(RM) $(TESTS)
	-$(RM) keccak4x/KeccakP-1600-times4-SIMD256.o
