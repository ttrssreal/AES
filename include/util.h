#pragma once
#include "aes.h"

// byte array to block
byte** batb(byte bytes[]);

// block to byte array
byte* btba(byte** block);

// block array to byte array
byte* blatba(byte*** block, int blocks);

byte** allocateBlock(int rows, int cols);
void deAllocateBlock(byte** block);

byte*** allocateBlockArray(int blocks);
void deAllocateBlockArray(byte*** blockArray, int blocks);

void printBlock(byte** block);
void printWord(byte* word);

void rotWord(byte* word, int n);
void doRcon(byte* word, int round);

void subBytesWord(byte* word);
void subBytesBlock(byte** block);

void mixColumns(byte** block);

byte* xorWords(byte* word1, byte* word2);
byte** xorBlocks(byte** block1, byte** block2);

byte* padPkcs7(byte* bytes);