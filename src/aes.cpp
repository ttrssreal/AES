#include "aes.h"
#include "keySchedule.h"
#include "util.h"

byte* AES::encrypt(byte* plaintext, byte* cipherKey, int blocks) {
    byte*** output = allocateBlockArray(blocks);
    // encrypt and copy each block into the output
    for (int i = 0; i < blocks * 16; i += 16)
    {
        output[i/16] = this->encryptBlock(batb(plaintext + i), cipherKey);
    }
    // convert list of blocks into one byte array
    return blatba(output, blocks);
}

byte** AES::encryptBlock(byte** block, byte* cipherKey) {
    keySchedule ks(cipherKey);
    byte*** k = ks.generateKeySchedule();
    state = block;

    // add first round key
    state = xorBlocks(state, k[0]);

    for (int i = 1; i <= ROUNDS; i++)
    {
        subBytesBlock(state);
        // shift rows
        for (int k = 0; k < 4; k++) {
            byte word[4];
            for (int j = 0; j < Nc; j++) {
                word[j] = state[j][k];
            }
            rotWord(word, k);
            for (int j = 0; j < Nc; j++) {
                state[j][k] = word[j];
            }
        }
        // dont mix columns on the last round
        if (i != ROUNDS)
            mixColumns(state);
        // add round key
        state = xorBlocks(state, k[i]);
    }
    return state;
}