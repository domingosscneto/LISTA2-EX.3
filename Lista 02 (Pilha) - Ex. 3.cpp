#ifndef __STATIC_STACK_H__
#define __STATIC_STACK_H__
#define E 9

// Define uma pilha usando um vetor (array).
const int STATIC_STACK_CAPACITY = E;

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


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int simbolo(char bracket, char brackets[])
{
	int idx, i;

	for (i = 0; i < E; i++)
		if (bracket == brackets[i])
			idx = i;

	return idx;
}
int main()
{
	setlocale(LC_ALL, "pt_BR");
	char brackets[E]{ '{', '[', '<', '(',
						'}', ']', '>', ')' };
	string s;
	int index[E], i, j, x;
	cout << "Digite uma STRING: ";
	cin >> s;

	StaticStack symbols = Create();
	for (i = 0; i < s.size(); i++)
		for (j = 0; j < E; j++)
			if (s[i] == brackets[j])
				Push(symbols, (char)s[i]);

	for (i = 0; i < symbols.count; i++)
		index[i] = simbolo(symbols.values[i], brackets);

	i = 0;
	j = i + 4;
	x = E - 1;
	while (i < 4)
		if (brackets[index[i]] == brackets[index[x] - 4])
		{
			i++;
			j++;
			x--;
		}
		else
		{
			cout << "Error";
			return 0;
		}
	cout << "OK";
}