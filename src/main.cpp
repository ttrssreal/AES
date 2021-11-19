#include "aes.h"

int main(const int argc, const char** argv) {
    AES aes;
    byte plaintext[BLOCKSIZE+1] = "spaces and stuff";
    byte cipherKey[BLOCKSIZE+1] = "thisisnotgoodkey";
    aes.encrypt(plaintext, cipherKey);
    return 0;
}