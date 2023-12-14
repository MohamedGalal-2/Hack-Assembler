#include "Assembler.h"

/**
  * @brief Converts the dest part of the line to machine code
  * @param dest - the dest part of the line
  * @return the machine code of the dest part
  * @note The function returns a string of 3 bits
  */
char* destConvert(int dest)
{
	char destString[4];
	if (dest == 1)
	{
		strcpy(destString, "001"); // M
	}
	else if (dest == 2)
	{
		strcpy(destString, "010"); // D
	}
	else if (dest == 3)
	{
		strcpy(destString, "011"); // DM
	}
	else if (dest == 4)
	{
		strcpy(destString, "100"); // A
	}
	else if (dest == 5)
	{
		strcpy(destString, "101"); // AM
	}
	else if (dest == 6)
	{
		strcpy(destString, "110"); // AD
	}
	else if (dest == 7)
	{
		strcpy(destString, "111"); // ADM
	}
	else
	{
		strcpy(destString, "000"); // Null
	}

	return destString;
}

/**
  * @brief Converts the comp part of the line to machine code
  * @param comp - the comp part of the line
  * @return the machine code of the comp part
  * @note The function returns a string of 7 bits
  */
char* compConvert(char* comp)
{
	char binaryComp[8] = { 00000000 };
	binaryComp[7] = '\0';

	if (comp[0] == '0')
	{
		strcpy(binaryComp, "0101010"); // 0
	}
	else if (comp[0] == '1')
	{
		strcpy(binaryComp, "0111111"); // 1
	}
	else if (comp[0] == '-')
	{
		if (comp[1] == '1')
		{
			strcpy(binaryComp, "0111010"); // -1
		}
		else if (comp[1] == 'D')
		{
			strcpy(binaryComp, "0001111"); // -D
		}
		else if (comp[1] == 'A')
		{
			strcpy(binaryComp, "0110011"); // -A
		}
		else if (comp[1] == 'M')
		{
			strcpy(binaryComp, "1110011"); // -M
		}
	}
	else if (comp[0] == 'D')
	{
		strcpy(binaryComp, "0001100"); // D
		if (comp[1] == '+')
		{
			if (comp[2] == '1')
			{
				strcpy(binaryComp, "0011111"); // D+1
			}
			else if (comp[2] == 'A')
			{
				strcpy(binaryComp, "0000010"); // D+A
			}
			else if (comp[2] == 'M')
			{
				strcpy(binaryComp, "1000010"); // D+M
			}
		}
		else if (comp[1] == '&')
		{
			if (comp[2] == 'A')
			{
				strcpy(binaryComp, "0000000"); // D&A
			}
			else if (comp[2] == 'M')
			{
				strcpy(binaryComp, "1000000"); // D&M
			}
		}
		else if (comp[1] == '-')
		{
			if (comp[2] == '1')
			{
				strcpy(binaryComp, "0001110"); // D-1
			}
			else if (comp[2] == 'A')
			{
				strcpy(binaryComp, "0010011"); // D-A
			}
			else if (comp[2] == 'M')
			{
				strcpy(binaryComp, "1010011"); // D-M
			}
		}
		else if (comp[1] == '|')
		{
			if (comp[2] == 'A')
			{
				strcpy(binaryComp, "0010101"); // D|A
			}
			else if (comp[2] == 'M')
			{
				strcpy(binaryComp, "1010101"); // D|M
			}
		}
	}
	else if (comp[0] == 'A')
	{
		strcpy(binaryComp, "0110000"); // A
		if (comp[1] == '+')
		{
			strcpy(binaryComp, "0110111"); // A+1
		}
		else if (comp[1] == '-')
		{
			if (comp[2] == '1')
			{
				strcpy(binaryComp, "0110010"); // A-1
			}
			else if (comp[2] == 'D')
			{
				strcpy(binaryComp, "0000111"); // A-D
			}
		}
	}
	else if (comp[0] == '!')
	{
		if (comp[1] == 'A')
		{
			strcpy(binaryComp, "0110001"); // !A
		}
		else if (comp[1] == 'M')
		{
			strcpy(binaryComp, "1110001"); // !M
		}
		else if (comp[1] == 'D')
		{
			strcpy(binaryComp, "0001101"); // !D
		}
	}
	else if (comp[0] == 'M')
	{
		strcpy(binaryComp, "1110000"); // M
		if (comp[1] == '+')
		{
			strcpy(binaryComp, "1110111"); // M+1
		}
		else if (comp[1] == '-')
		{
			if (comp[2] == '1')
			{
				strcpy(binaryComp, "1110010"); // M-1
			}
			else if (comp[2] == 'D')
			{
				strcpy(binaryComp, "1000111"); // M-D
			}
		}
	}

	return binaryComp;
}

/**
  * @brief Converts the jump part of the line to machine code
  * @param jump - the jump part of the line
  * @return the machine code of the jump part
  * @note The function returns a string of 3 bits
  */
char* jumpConvert(char* jump)
{
	char jumpBinary[4] = { 0000 };
	jumpBinary[3] = '\0';
	strcpy(jumpBinary, "000"); // Null

	if (jump[1] == 'G')
	{
		if (jump[2] == 'T')
		{
			strcpy(jumpBinary, "001"); // JGT
		}
		else if (jump[2] == 'E')
		{
			strcpy(jumpBinary, "011"); // JGE
		}
	}
	else if (jump[1] == 'L')
	{
		if (jump[2] == 'T')
		{
			strcpy(jumpBinary, "100"); // JLT
		}
		else if (jump[2] == 'E')
		{
			strcpy(jumpBinary, "110"); // JLE
		}
	}
	else if (jump[1] == 'E')
	{
		strcpy(jumpBinary, "010"); // JEQ
	}
	else if (jump[1] == 'N')
	{
		strcpy(jumpBinary, "101"); // JNE
	}
	else if (jump[1] == 'M')
	{
		strcpy(jumpBinary, "111"); // JMP
	}

	return jumpBinary;
}