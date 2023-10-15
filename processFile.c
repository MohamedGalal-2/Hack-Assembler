#include "Assembler.h"

#define BUFFER_SIZE 1000

/**
  * @brief  Removes comments from a file.
  * @param  srcFile: Pointer to source file.
  * @param  tempFile: Pointer to temporary file.
  * @return void
  */
void removeComments(FILE* srcFile, FILE* tempFile) {

	int c;
	int prevChar = '\0';

	while ((c = fgetc(srcFile)) != EOF) {
		if (prevChar == '/') {
			/* Remove rest of the line */
			while ((c = fgetc(srcFile)) != EOF && c != '\n')
			{
				// Do nothing
			}
		}
		else {
			if (prevChar != '\0') {
				fputc(prevChar, tempFile);
			}
		}
		prevChar = c;
	}

	/* Write the last character if it is not a comment */
	if (prevChar != '\0') {
		fputc(prevChar, tempFile);
	}
}

/**
  * @brief  Check if given string is empty or not.
  * @param  str: Pointer to string.
  * @return 1 if string is empty, 0 otherwise.
  * @note   A string is empty if it only contains white space characters.
  */
int isEmpty(const char* str)
{
	char ch;

	do
	{
		ch = *(str++);

		/* Check non whitespace character */
		if (ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r' && ch != '\0' && ch != '/')
		{
			return 0;
		}

	} while (ch != '\0');

	return 1;
}

/**
  * @brief  Removes empty lines from a file.
  * @param  srcFile: Pointer to source file.
  * @param  tempFile: Pointer to temporary file.
  * @return void
  */
void removeEmptyLines(FILE* srcFile, FILE* tempFile)
{
	char buffer[BUFFER_SIZE];

	while ((fgets(buffer, BUFFER_SIZE, srcFile)) != NULL)
	{
		/* If current line is not empty then write to temporary file */
		if (!isEmpty(buffer))
		{
			fputs(buffer, tempFile);
		}
	}
}

/**
  * @brief  Process files to remove empty lines and comments.
  * @return void
  */
void processFiles(char* path)
{
	FILE* srcFile;
	FILE* tempFile;
	char* newPath = NULL;
	newPath = (char*)calloc(100, sizeof(char));
	newPath = getFileName(path);
	// Remove Comments

	/* Try to open files */
	srcFile = fopen(path, "r");
	tempFile = fopen("remove-comments.tmp", "w");

	/* Exit if file not opened successfully */
	if (srcFile == NULL || tempFile == NULL)
	{
		printf("Unable to open file.\n");
		printf("Please check you have read/write previleges.\n");

		exit(EXIT_FAILURE);
	}

	/* Move src file pointer to beginning */
	rewind(srcFile);

	/* Remove comments from file. */
	removeComments(srcFile, tempFile);

	/* Close all open files */
	fclose(srcFile);
	fclose(tempFile);

	/*Rename temp file as *.hack */
	rename("remove-comments.tmp", newPath);

	// Remove Blank Spaces

	/* Try to open files */
	srcFile = fopen(newPath, "r");
	tempFile = fopen("remove-comments.tmp", "w");

	/* Exit if file not opened successfully */
	if (srcFile == NULL || tempFile == NULL)
	{
		printf("Unable to open file.\n");
		printf("Please check you have read/write previleges.\n");

		exit(EXIT_FAILURE);
	}

	/* Move src file pointer to beginning */
	rewind(srcFile);

	/* Remove comments from file. */
	removeEmptyLines(srcFile, tempFile);

	/* Close all open files */
	fclose(srcFile);
	fclose(tempFile);

	/* Delete src file and rename temp file as src */
	remove(newPath);
	rename("remove-comments.tmp", newPath);

}

/**
  * @brief  Gets the file name from the path.
  * @param  path: Pointer to path.
  * @return file name.
  */
char* getFileName(char* path)
{
	char* name;
	int length = 0;
	char* hack = ".hack";
	int j = 0;

	while (path[length] != '.')
	{
		length++;
	}

	name = (char*)calloc((length + 5), sizeof(char*));

	for (int i = 0; i < length; i++)
	{
		name[i] = path[i];
	}

	for (int i = length; i < (length + 5); i++)
	{
		name[i] = hack[j];
		j++;
	}

	return name;
}