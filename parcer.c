#include "Assembler.h"

/**
  * @brief Converts decimal value to binary value
  * @param decimal - decimal value to convert
  * @return binary value
  * @note The function returns a string of 16 bits
  */
char* dectoBinary(int decimal)
{
	int tempDecimal;
	char binary[17] = "0000000000000000";
	int index = 0;

	/* Copies decimal value to temp variable */
	tempDecimal = decimal;

	while (tempDecimal != 0)
	{
		/* Finds decimal%2 and adds to the binary value */
		binary[index] = (tempDecimal % 2) + '0';

		tempDecimal /= 2;
		index++;
	}

	binary[16] = '\0';

	/* Reverse the binary value found */
	strrev(binary);

	return binary;
}

/**
  * @brief Parses the file and creates a temp file with the binary values
  * @param newPath - the path of the file to parse
  * @note  The function creates a temp file with the binary values
  */
void parse(char* newPath)
{
	FILE* srcFile;
	FILE* tempFile;
	char line[20];

	/* Try to open files */
	srcFile = fopen(newPath, "r");
	tempFile = fopen("parse.tmp", "w");

	/* Exit if file not opened successfully */
	if (srcFile == NULL || tempFile == NULL)
	{
		printf("Unable to open file.\n");
		printf("Please check you have read/write previleges.\n");

		exit(EXIT_FAILURE);
	}

	/* Move src file pointer to beginning */
	rewind(srcFile);

	char decimal[17] = { 00000000000000000 };  // Decimal value of the address string
	int dec = 0;       // Decimal value of the address integer
	char buffer[17];   // Binary value of the address

	// C instruction
	char headC[4];
	strcpy(headC, "111");
	// Destination part of the C instruction
	char dest[4] = { 0000 };
	dest[3] = '\0';
	int destVal = 0;
	int isDest = 0;
	// Computation part of the C instruction
	char comp[4];
	char binaryComp[8];
	// Jump part of the C instruction
	char jump[4];
	char binaryJump[4];

	// Indexes
	int i = 0; // Index for the dest loop
	int j = 0; // Index for the comp loop
	int z = 0;
	int k = 0; // Index for the jump loop

	// Read the file line by line
	while (fgets(line, sizeof(line), srcFile))
	{
		// A Instruction
		if (line[0] == '@')
		{
			// Get the address string
			for (int i = 0; i < 16; i++)
			{
				decimal[i + 1] = line[i + 1];
			}
			// Remove rubbish
			for (int i = 0; i < 16; i++)
			{
				decimal[i] = decimal[i + 1];
			}
			// Convert address string into integer
			dec = atoi(decimal);
			// Get the binary representation 
			strcpy(buffer, dectoBinary(dec));
			// Write the binary representation into the temp file
			fprintf(tempFile, "%s\n", buffer);
		}
		// C Instruction
		else
		{
			fprintf(tempFile, "%s", headC);

			// Get the destination part
			destVal = getDest(line, &i, &isDest);

			// Get the computation part
			strcpy(comp, getComp(line, i, &j, isDest, &destVal));


			// Get the jump part
			strcpy(jump, getJump(line, j));

			// Convert the computation part into binary 
			strcpy(binaryComp, compConvert(comp));
			binaryComp[7] = '\0';
			strcpy(comp, "   "); // Reset comp

			// Convert the destination part into binary
			strcpy(dest, destConvert(destVal));
			destVal = 0;

			// Convert the jump part into binary
			strcpy(binaryJump, jumpConvert(jump));
			strcpy(jump, "   "); // Reset comp

			// Write the binary representation into the temp file
			fprintf(tempFile, "%s", binaryComp);
			fprintf(tempFile, "%s", dest);
			fprintf(tempFile, "%s\n", binaryJump);

		}
	}


	/* Close all open files */
	fclose(srcFile);
	fclose(tempFile);

	/* Delete src file and rename temp file as src */
	remove(newPath);
	rename("parse.tmp", newPath);
}