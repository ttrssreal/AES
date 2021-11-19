#pragma once
#include "aes.h"

// Byte array to block
byte** batb(byte bytes[BLOCKSIZE+1], int cols);

byte** allocateBlock(int rows, int cols);
void deAllocateBlock(byte** block, int cols);

byte*** allocateKeySchedule(int numKeys);
void deAllocateKeySchedule(byte*** sched, int cols);

void printBlock(byte** block, int cols);
void printWord(byte* word);

void rotWord(byte* word);
void subBytes(byte* word);
void doRcon(byte* word, int round);
byte* xorWords(byte* word1, byte* word2);