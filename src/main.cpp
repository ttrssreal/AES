#include <stdio.h>
#include "aes.h"

int main(const int argc, const char** argv) {
    // if (argc < 2) {
    //     printf("Usage: usage\n");
    //     return 1;
    // }
    int blockSize = 16;
    AES aes;
    unsigned char plaintext[blockSize+1] = "spaces and stuff";
    unsigned char cipherKey[blockSize+1] = "1234567891234567";

    printf("%s\n", aes.encrypt(plaintext, cipherKey));
    return 0;
}