/* File Guard */
#pragma once
#ifndef _PROCESSFILE_H_
#define _PROCESSFILE_H_

/* Includes Section */
#include "Assembler.h"

/* Marcos Definition Section */
#define BUFFER_SIZE 1000

/* Functions Declaration Section */

/**
  * @brief  Removes comments from a file.
  * @param  srcFile: Pointer to source file.
  * @param  tempFile: Pointer to temporary file.
  * @return void
  */
void removeComments(FILE* srcFile, FILE* tempFile);

/**
  * @brief  Check if given string is empty or not.
  * @param  str: Pointer to string.
  * @return 1 if string is empty, 0 otherwise.
  * @note   A string is empty if it only contains white space characters.
  */
int isEmpty(const char* str);

/**
  * @brief  Removes empty lines from a file.
  * @param  srcFile: Pointer to source file.
  * @param  tempFile: Pointer to temporary file.
  * @return void
  */
void removeEmptyLines(FILE* srcFile, FILE* tempFile);

/**
  * @brief  Process all files in the current directory.
  * @param  void
  * @return void
  */
void processFiles(char* path);

/**
  * @brief  Gets the file name from the path.
  * @param  path: Pointer to path.
  * @return file name.
  */
char* getFileName(char* path);

#endif // _PROCESSFILE_H_ 