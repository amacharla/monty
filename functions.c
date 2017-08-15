#include "monty.h"

void myexit(int code, int linenum, char *string)
{
	switch(code)
	{
		case 1:
			perror("USAGE: monty file");
		case 2:
			printf("Error: Cant't open file %s\n", string);
		case 3:
			printf("L%d: unknown instruction %s\n", linenum, string);
		case 4:
			perror("Error: malloc failed");

		exit(EXIT_FAILURE);
	}

}
