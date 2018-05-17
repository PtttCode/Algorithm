#include<iostream>
using namespace std;

typedef struct Edge
{
	int field;
	int value;	//±ßµÄÈ¨Öµ
	struct Edge *next;
}Edge,*tEdge;

typedef struct Node
{
	char data;
	tEdge firstEdge;
}Node,nList[10];

typedef struct
{
	nList vex;
	int ndeNum, edgNum;
}Arr;

int locateVex(Arr G, char v1);

void init(Arr &G)
{
	int i,j;
	char v1, v2;
	cin >> G.ndeNum >> G.edgNum;
	for (i = 0;i < G.ndeNum;i++)
	{
		cin >> G.vex[i].data;
		G.vex[i].firstEdge = NULL;
	}
	
	for (int k = 0;k < G.edgNum;k++)
	{
		cin >> v1 >> v2;
		i = locateVex(G, v1);
		j = locateVex(G, v2);

		tEdge p1 = (tEdge)malloc(sizeof(Edge));
		p1->field = j;
		p1->next = G.vex[i].firstEdge;
		G.vex[i].firstEdge = p1;

		tEdge p2 = (tEdge)malloc(sizeof(Edge));
		p2->field = i;
		p2->next = G.vex[j].firstEdge;
		G.vex[j].firstEdge = p2;
		cout<<i<<j;
	}
}

int locateVex(Arr G, char v1)
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
				cout<<G.vex[i].firstEdge->field;
				G.vex[i].firstEdge=G.vex[i].firstEdge->next;
			}
		}
		cout << endl;
	}
}

int main()
{
	Arr G;
	init(G);
	print(G);
}