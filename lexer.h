/* File Guard */
#pragma once
#ifndef _LEXER_H
#define _LEXER_H

/* Includes Section */
#include "Assembler.h"

/* Functions Prototype Section */
int getDest(char* line, int* i, int* isDe);
char* getComp(char* line, int i, int* j, int isDest, int* destVal);
char* getJump(char* line, int j);

#endif // _CODE_H_