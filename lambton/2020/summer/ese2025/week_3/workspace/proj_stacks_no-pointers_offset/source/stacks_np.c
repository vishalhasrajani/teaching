/*
 * stacks_np.c
 *
 * a simple, non-pointer stack implementation for the storage of integers
 *
 * In this slightly modified version, we reduce the computational burden
 * of the push and pop algorithms by eliminating the "-1"... to do this,
 * we use -1 to designate an empty stack. The code looks cleaner, too!
 *
 *  Created on: Jun. 8, 2020
 *      Author: takis
 */

/************************************************************************
 * PRELIMINARIES
 ************************************************************************
 */
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define L	1024	// size of integer data structure

/************************************************************************
 * GLOBAL VARIABLES
 ************************************************************************
 */
int s[L]; // stack storage
long s_top = -1;	// the stack "pointer", s.top, valid from 1 to L;
// a value of zero means the stack is empty

/************************************************************************
 * FUNCTIONS
 ************************************************************************
 */

/*
 * stack_empty(s) implementation
 */
bool stack_empty(void)
{
	bool result;

	if (s_top == -1)
	{
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}

/*
 * push(s) implementation
 */
void push(int x)
{
	s[++s_top] = x; // increment s_top, then place value at this new location

	// can you check for stack overflow? if so, how? And what to do about it?

	return;
}

/*
 * pop(s) implementation
 */
int pop(void)
{
	if (stack_empty())
	{
		printf("underflow error\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		return s[s_top--]; // return value at s_top location, decrement s_top
	}
}

/************************************************************************
 * MAIN CODE
 ************************************************************************
 */
int main()
{
	int loadarr[] =
	{ 52, -29, 36, -821, 790, -650, 1125, 72, 0, 68, 33, 59 };
	size_t N = sizeof(loadarr) / sizeof(int);

	/* print out contents of arra */
	printf("data to be loaded on to the stack:\n");
	for (size_t i = 0; i != N; ++i)
	{
		printf("%d ", loadarr[i]);
	}
	printf("\n");

	/* load stack */
	printf("pushing data onto stack...\n");
	for (size_t i = 0; i != N; ++i)
	{
		push(loadarr[i]);
	}

	/* pop stack */
	printf("popping data off of stack...\n");
	while (stack_empty() == false)
	{
		printf("%d ", pop());
	}

	// exit normally
	return EXIT_SUCCESS;
}

