#include<iostream>
using namespace std;


typedef struct Node *Guide;
typedef struct Node {
	int data;
	Guide next;
}Node, *LinkedList;

LinkedList LinkedListCreatH()
{
	int i;
	Guide L;
	L = (Node *)malloc(sizeof(Node));   //申请头结点空间  
	L->next = NULL;                      //初始化一个空链表  
	Guide r;
	r = L;
                       
	for (i = 0;i < 10;i++)
	{
		Node *p;
		p = (Node *)malloc(sizeof(Node));  //申请新的结点   
		p->data = i;                     //结点数据域赋值   
		r->next =p;                    //将结点插入到表头L-->|2|-->|1|-->NULL   
		r = p;
	}
	r->next = NULL;
	return L;
}

void print(LinkedList L)
{
	Guide p = L->next;
	while (p)
	{
		cout << p->data;
		p = p->next;
	}
}

void Paste(LinkedList L1, LinkedList L2)
{
	LinkedList L3;
	Guide a, b;
	Guide r;
	a = L1->next;
	b = L2->next;
	L3 = (Node *)malloc(sizeof(Node));
	L3->next = NULL;

	r = L3;

	while(a)
	{
		Node *p;
		p = (Node *)malloc(sizeof(Node));  //申请新的结点   
		p->data = a->data;                     //结点数据域赋值   
		r->next = p;                    //将结点插入到表头L-->|2|-->|1|-->NULL   
		r = p;
		a = a->next;
	}
	
	while(b)
	{
		Node *p;
		p = (Node *)malloc(sizeof(Node));  //申请新的结点   
		p->data = b->data;                     //结点数据域赋值   
		r->next = p;                    //将结点插入到表头L-->|2|-->|1|-->NULL   
		r = p;
		b = b->next;
	}
	r ->next = NULL;
	print(L3);
}

int main()
{
	Guide l1, l2;
	l1 = LinkedListCreatH();
	l2 = LinkedListCreatH();
	 
	Paste(l1, l2);
	return 0;
}