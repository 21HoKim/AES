#include <stdio.h>

#include "aes.h"

int main() {

	uint8_t i;
	 
	/* 128 bits */
	uint8_t key[] = {
		0x2b, 0x7e, 0x15, 0x16,
		0x28, 0xae, 0xd2, 0xa6,
		0xab, 0xf7, 0x15, 0x88,
		0x09, 0xcf, 0x4f, 0x3c};
	
	
	uint8_t in[] = {
		0x32, 0x43, 0xf6, 0xa8,
		0x88, 0x5a, 0x30, 0x8d,
		0x31, 0x31, 0x98, 0xa2,
		0xe0, 0x37, 0x07, 0x34}; // 128

	
	uint8_t out[16]; // 128

	uint8_t *w; // expanded key

	w = aes_init(sizeof(key));

	aes_key_expansion(key, w);

	printf("Plaintext message:\n");
	for (i = 0; i < 4; i++) {
		printf("%02x %02x %02x %02x ", in[4*i+0], in[4*i+1], in[4*i+2], in[4*i+3]);
	}

	printf("\n");

	aes_cipher(in, out, w);

	printf("Ciphered message:\n");
	for (i = 0; i < 4; i++) {
		printf("%02x %02x %02x %02x ", out[4*i+0], out[4*i+1], out[4*i+2], out[4*i+3]);
	}

	printf("\n");

	aes_inv_cipher(out, in, w);

	printf("Original message (after inv cipher):\n");
	for (i = 0; i < 4; i++) {
		printf("%02x %02x %02x %02x ", in[4*i+0], in[4*i+1], in[4*i+2], in[4*i+3]);
	}

	printf("\n");

	free(w);

	return 0;
}
