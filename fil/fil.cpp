#include<stdlib.h>
#include<malloc.h>
#include<stdio.h>
#include<iostream>

using namespace std;

struct stack
{
	bool peek = false;
	int data;
	struct stack* next = NULL;
};

void push(stack* a, int value)
{
	if (a->peek == 0)
	{
		a->peek = 1;
		a->data = value;
		return;
	}

	stack* f = new stack;

	f->data = a->data;
	f->next = a->next;
	f->peek = 1;

	a->data = value;
	a->next = f;
}

int pop(stack* a)
{
	if (a->peek == 0)
	{
		printf_s("empty stack\n");
		return 0;
	}

	if (a->next == NULL)
	{
		a->peek = 0;
		int c = a->data;
		a->data = 0;
		return c;
	}

	int s = a->data;

	a->data = a->next->data;
	a->next = a->next->next;

	return s;
}


int main()
{

	stack* MyStack = new stack;

	int choise = 0;
	int val = 0;
	do
	{
		cout << "1)add element\n2)pop element\nenter ur choise: ";

		cin >> choise;
		cout << endl;

		if (choise == 1)
		{
			cout << "enter ur element: ";
			cin >> val;
			push(MyStack, val);
			cout << endl;
		}

		if (choise == 2)
		{
			cout << "ur element: ";
			cout << pop(MyStack);
			cout << endl;
			
		}

	} while (choise != 0);
}

