/****************************************************
 *		@author  - Mohamed Ahmed Galal				*
 *		@program - Hack Assembler					*
 *		@version - V1.2.0							*
 ****************************************************/
 
 /* Include Section*/
#include "Assembler.h"

int main()
{
	char path[100];

	/* Input file path */
	printf("Enter file path: ");
	scanf("%s", path);

	processFiles(path);

	// Get new file name
	char* newPath = NULL;
	newPath = (char*)calloc(100, sizeof(char));
	newPath = getFileName(path);

	// Convert to binary
	parse(newPath);


	return 0;
}

