#pragma once
#define AES128 128
#define AES192 192
#define AES256 256

#define AESKEYSIZE AES128

#define BLOCKSIZE 16

#define ROUNDS (AESKEYSIZE+192)/32
#define Nk AESKEYSIZE/32
#define Nc 4

// keysize = 32*Rounds-192

typedef unsigned char byte;

#include <cstring>
#include <stdio.h>
#include <stdlib.h>

class AES {
public:
    byte** state;
    byte* encrypt(byte* plaintext, byte* cipherKey, int blocks);

private:
    byte** encryptBlock(byte** block, byte* cipherKey);
};