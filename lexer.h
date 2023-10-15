/* File Guard */
#pragma once
#ifndef _LEXER_H
#define _LEXER_H

/* Includes Section */
#include "Assembler.h"

/* Functions Prototype Section */

/**
  * @brief  Gets the destination part of the line.
  * @param  line: Pointer to line.
  * @param  i: Pointer to index of line.
  * @param  isDe: Pointer to isDest.
  * @return destination part of the line.
  * @note   The function returns the destination part of the line and updates the index and isDest.
  */
int getDest(char* line, int* i, int* isDe);

/**
  * @brief  Gets the computation part of the line.
  * @param  line: Pointer to line.
  * @param  i: Pointer to index of line.
  * @param  isDest: Pointer to isDest.
  * @param  destVal: Pointer to destVal.
  * @return computation part of the line.
  * @note   The function returns the computation part of the line and updates the index, isDest and destVal.
  */
char* getComp(char* line, int i, int* j, int isDest, int* destVal);

/**
* @brief  Gets the jump part of the line.
* @param  line: Pointer to line.
* @param  j: index of line.
* @return jump part of the line.
*/
char* getJump(char* line, int j);

#endif // _CODE_H_