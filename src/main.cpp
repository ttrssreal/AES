#include "aes.h"
#include "util.h"

int main(const int argc, const char** argv) {
    if (argc != 4) {
        printf("Usage:\n");
        printf("%s encrypt <text> <key>\n", argv[0]);
        return 1;
    }
    AES aes;
    if (!strncmp(argv[1], "encrypt", 7)) {
        // pad input to blocksize
        byte* plaintext = padPkcs7((byte*)argv[2]);
        byte* cipherKey = (byte*)argv[3];
        // encrypt
        byte* output = aes.encrypt(plaintext, cipherKey, strlen((const char*)plaintext)/16);
        // print out the cyphertext
        for (int i = 0; i < (int)strlen((const char*)output); i++)
        {
            printf("%02x", output[i]);
        }
        printf("\n");
    }
    return 0;
}