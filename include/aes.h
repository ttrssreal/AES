#pragma once
#define CIPHERKEYSIZE 128
#define BLOCKSIZE CIPHERKEYSIZE/8
#define ROUNDS 11
#define Nc 4

typedef unsigned char byte;

#include <cstring>
#include <stdio.h>
#include <stdlib.h>

class AES {
public:
    byte** state;
    byte* encrypt(byte plaintext[], byte cipherKey[]);

private:
    byte** encryptBlock(byte block[BLOCKSIZE], byte cipherKey[BLOCKSIZE]);
};