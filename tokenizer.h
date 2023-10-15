/* File Guard */
#pragma once
#ifndef _TOKENIZER_H
#define _TOKENIZER_H

/* Includes Section */
#include "Assembler.h"

/* Functions Prototype Section */

/**
  * @brief Converts the dest part of the line to machine code
  * @param dest - the dest part of the line
  * @return the machine code of the dest part
  * @note The function returns a string of 3 bits
  */
char* destConvert(int dest);

/**
  * @brief Converts the comp part of the line to machine code
  * @param comp - the comp part of the line
  * @return the machine code of the comp part
  * @note The function returns a string of 7 bits
  */
char* compConvert(char* comp);

/**
  * @brief Converts the jump part of the line to machine code
  * @param jump - the jump part of the line
  * @return the machine code of the jump part
  * @note The function returns a string of 3 bits
  */
char* jumpConvert(char* jump);

#endif // _TOKENIZER_H