#include<iostream>
using namespace std;

typedef struct Node *Pnode;
typedef struct Node {
	int xi;
	int zhi;
	Pnode next;
}Node,*LinkedList;

LinkedList init()
{
	int a, b;
	LinkedList L;
	L = (Node *)malloc(sizeof(Node));
	L->next = NULL;
	Pnode r;
	r = L;

	for (int i = 0;i < 3;i++)
	{
		cin >> a >> b;
		Pnode p;
		p = (Node *)malloc(sizeof(Node));
		p->xi = a;
		p->zhi = b;
		r->next = p;
		r = p;
	}
	r->next = NULL;
	return L;
}

void print(LinkedList L) 
{
	Pnode r;
	r = L->next;
	while (r)
	{
		cout << r->xi << " " << r->zhi << endl;
		r = r->next;
	}
}

LinkedList cal(LinkedList L1, LinkedList L2)
{
	LinkedList L;
	L = (Node *)malloc(sizeof(Node));
	L->next = NULL;
	Pnode r = L;
	Pnode a = L1->next, b = L2->next;

	while (L1 || L2)
	{
		Pnode p = (Node *)malloc(sizeof(Node));
		if (a->zhi > b->zhi)
		{
			p->xi = a->xi;
			p->zhi = a->zhi;
			r->next = p;
			r = p;
			a = a->next;
		}
		else if (a->zhi == b->zhi)
		{
			p->xi = a->xi + b->xi;
			p->zhi = a->zhi;
			r->next = p;
			r = p;
			a = a->next;
			b = b->next;
		}
		else
		{
			p->xi = b->xi;
			p->zhi = b->zhi;
			r->next = p;
			r = p;
			b = b->next;
		}
		if (a == NULL&&b)
		{
			while (b)
			{
				Pnode p = (Node *)malloc(sizeof(Node));
				p->xi = b->xi;
				p->zhi = b->zhi;
				r->next = p;
				r = p;
				b = b->next;
			}
			break;
		}
		else if(b==NULL&&a)
		{
			while (a)
			{
				Pnode p = (Node *)malloc(sizeof(Node));
				p->xi = a->xi;
				p->zhi = a->zhi;
				r->next = p;
				r = p;
				a = a->next;
			}
			break;
		}
	}
	r->next = NULL;
	return L;
}

int main()
{
	LinkedList L1, L2;
	L1 = init();
	L2 = init();
	LinkedList L = cal(L1, L2);
	print(L);
}