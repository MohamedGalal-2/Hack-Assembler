/* File Guard */
#pragma once
#ifndef _PARCER_H_
#define _PARCER_H_

/* Includes Section */
#include "Assembler.h"

/* Functions Prototype Section */

/**
  * @brief  Converts decimal value to binary value
  * @param  decimal - decimal value to convert
  * @return binary value
  * @note   The function returns a string of 16 bits
  */
char* dectoBinary(int decimal);

/**
  * @brief Parses the file and creates a temp file with the binary values
  * @param newPath - the path of the file to parse
  * @note  The function creates a temp file with the binary values
  */
void parse(char* newPath);

#endif // _PARCER_H_