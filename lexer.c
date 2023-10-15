#include "Assembler.h"

/**
  * @brief  Gets the destination part of the line.
  * @param  line: Pointer to line.
  * @param  i: Pointer to index of line.
  * @param  isDe: Pointer to isDest.
  * @return destination part of the line.
  * @note   The function returns the destination part of the line and updates the index and isDest.
  */
int getDest(char* line, int* i, int* isDe)
{
	int it = 0;
	int destVal = 0;
	int isDest = 0;
	for (it = 0; it < 3; it++)
	{
		if (line[it] != '=')
		{
			if (line[it] == 'A')
			{
				destVal += 4;
			}
			else if (line[it] == 'D')
			{
				destVal += 2;
			}
			else if (line[it] == 'M')
			{
				destVal += 1;
			}
		}
		else
		{
			break;
		}
	}
	for (int x = 0; x <= 3; x++)
	{
		if (line[x] == '=')
		{
			isDest = 1;
			break;
		}
		else
		{
			isDest = 0;
		}
	}

	*i = it;
	*isDe = isDest;

	return destVal;
}

/**
  * @brief  Gets the computation part of the line.
  * @param  line: Pointer to line.
  * @param  i: Pointer to index of line.
  * @param  isDest: Pointer to isDest.
  * @param  destVal: Pointer to destVal.
  * @return computation part of the line.
  * @note   The function returns the computation part of the line and updates the index, isDest and destVal.
  */
char* getComp(char* line, int i, int* j, int isDest, int* destVal)
{
	int z = 0;
	char comp[4];

	if (isDest == 1)
	{
		*j = (i + 1);
	}
	else
	{
		*j = 0;
		*destVal = 0;
	}
	while (line[*j] != ';')
	{
		if (line[*j] == '\0')
		{
			break;
		}
		else
		{
			comp[z] = line[*j];
			z++;
			*j += 1;
		}
	}
	comp[3] = '\0'; // Null terminator

	return comp;
}

/**
* @brief  Gets the jump part of the line.
* @param  line: Pointer to line.
* @param  j: index of line.
* @return jump part of the line.
*/
char* getJump(char* line, int j)
{
	int z = 0;
	int k = 0;
	char jump[4];

	k = j + 1;
	while ((line[k] != '\0'))
	{
		jump[z] = line[k];
		z++;
		k++;
	}
	jump[3] = '\0';
	z = 0; // Reset z

	return jump;
}