#include<iostream>
#include<string>
using namespace std;
#define MAXDIST 10000
#define MAXSIZE 20

typedef struct Edge
{
	int field;
	int value;	//�ߵ�Ȩֵ
	struct Edge *next;
}Edge, *tEdge;

typedef struct Node
{
	string data;
	tEdge firstEdge;
}Node, nList[12];

typedef struct
{
	nList vex;
	int ndeNum, edgNum;
}Arr;

typedef struct
{
	int rear;
	int front;
	int arr[MAXSIZE];
}Queue;

int locateVex(Arr G, char v1);

void makeEmpty(Queue &Q)
{
	Q.front = Q.rear = 0;
}

int isEmpty(Queue &Q)
{
	return Q.front == Q.rear;
}

Queue initQueue()
{
	Queue Q;
	Q.front = 0;
	Q.rear = 0;
	
	return Q;
}

void push(Queue &Q ,int num)
{
	if (Q.rear == MAXSIZE)	cout << "������" << endl;
	else
	{
		Q.arr[Q.rear++] = num;
	}
}


int pop(Queue &Q)
{
	if (Q.rear == 0)	cout << "���п�" << endl;
	else
	{
		return Q.arr[Q.front++];
	}
}

int locateVex(Arr G, char v1);

void recordEdge(Arr &G, int n1, int n2, int value)
{
	tEdge p1 = (tEdge)malloc(sizeof(Edge));
	p1->field = n2;
	p1->value = value;
	p1->next = G.vex[n1].firstEdge;
	G.vex[n1].firstEdge = p1;

	tEdge p2 = (tEdge)malloc(sizeof(Edge));
	p2->field = n1;
	p2->value = value;
	p2->next = G.vex[n2].firstEdge;
	G.vex[n2].firstEdge = p2;
}

void init(Arr &G) 
{
	int i;
	cin >> G.ndeNum >> G.edgNum;
	for (i = 0;i < G.ndeNum;i++)	G.vex[i].firstEdge = NULL;

	G.vex[0].data = "����";
	G.vex[1].data = "����";
	G.vex[2].data = "Ӿ��";
	G.vex[3].data = "ɳ��";
	G.vex[4].data = "����";
	G.vex[5].data = "�ɳ�";
	G.vex[6].data = "�³�";
	G.vex[7].data = "����¥";
	G.vex[8].data = "ͼ���";
	G.vex[9].data = "����¥";
	G.vex[10].data = "����¥";
	G.vex[11].data = "����¥";

	recordEdge(G, 0, 1, 20);
	recordEdge(G, 0, 2, 100);
	recordEdge(G, 0, 4, 280);
	recordEdge(G, 1, 3, 110);
	recordEdge(G, 1, 4, 120);
	recordEdge(G, 1, 7, 210);
	recordEdge(G, 1, 9, 280);
	recordEdge(G, 2, 7, 130);
	recordEdge(G, 3, 4, 20);
	recordEdge(G, 3, 6, 5);
	recordEdge(G, 4, 5, 5);
	recordEdge(G, 5, 8, 35);
	recordEdge(G, 6, 8, 50);
	recordEdge(G, 7, 9, 80);
	recordEdge(G, 8, 9, 200);
	recordEdge(G, 9, 10, 40);
	recordEdge(G, 10, 11, 20);


}

int locateVex(Arr G, string v1)
{
	int i;
	for (i = 0;i < G.ndeNum;i++)
	{
		if (G.vex[i].data == v1)	break;
	}
	return i;
}

void print(Arr G)
{
	for (int i = 0;i < G.ndeNum;i++)
	{
		if (G.vex[i].firstEdge)
		{
			cout << G.vex[i].data << ":";
			while (G.vex[i].firstEdge)
			{
				cout << G.vex[i].firstEdge->field;
				G.vex[i].firstEdge = G.vex[i].firstEdge->next;
			}
		}
		cout << endl;
	}
}

void djkstra(Arr G,int V)
{
	tEdge W;
	bool s[MAXSIZE] = { false };
	int dist[MAXSIZE] , path[MAXSIZE];
	int N;

	memset(dist, -1, sizeof(dist));	//���鸳ֵ
	Queue Q;
	Q = initQueue();
	dist[V] = 0;
	push(Q, V);

	while(!isEmpty(Q))
	{
		N = pop(Q);
		for (W = G.vex[N].firstEdge;W;W = W->next)
		{
			if (dist[W->field] == -1)	//���õ�δ���ʹ�
			{
				dist[W->field] = dist[N] + W->value;
				path[W->field] = N;
				push(Q, W->field);
			}
		}
	}

	for (int i = 0;i < G.ndeNum;i++)
	{
		cout << dist[i]<<endl;
	}
}


int main()
{
	Arr G;
	Node N;
	init(G);
	print(G);
	djkstra(G, 2);
}
