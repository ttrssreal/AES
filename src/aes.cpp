#include "aes.h"
#include "keySchedule.h"
#include "util.h"

byte* AES::encrypt(byte plaintext[], byte cipherKey[]) {
    keySchedule ks(cipherKey);
    // So far just derive the keys
    byte*** k = ks.generateKeySchedule(ROUNDS+1);
    return cipherKey;
}

byte** AES::encryptBlock(byte block[16], byte cipherKey[16]) {
    return 0;
}