#include <stdio.h>
#include "monty.h"
int main(void)
{
	run_opcode("push  1");
	run_opcode("   pall");
	run_opcode("   pop	");
	run_opcode("push  1ll");
}
