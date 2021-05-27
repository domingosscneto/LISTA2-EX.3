#ifndef __STATIC_STACK_H__
#define __STATIC_STACK_H__
#define MAX 9

// Define uma pilha usando um vetor (array).
const int STATIC_STACK_CAPACITY = MAX;

struct StaticStack
{
	int count; // Quantidade de elementos empilhados (índice do elemento no topo da pilha = count - 1).
	char values[STATIC_STACK_CAPACITY]; // Dados da pilha.
};

StaticStack Create();

bool Push(StaticStack& stack, char elem);

char Pop(StaticStack& stack);

char Top(const StaticStack& stack);

int Size(const StaticStack& stack);

int Count(const StaticStack& stack);

bool IsEmpty(const StaticStack& stack);

bool Clear(StaticStack& stack);

#endif