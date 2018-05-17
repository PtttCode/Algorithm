/*
����һ����N�������E���ߵ�����ͼ������DFS��BFS�ֱ��г������е���ͨ�������趥���0��N?1��š���������ʱ�������������Ǵӱ����С�Ķ������������ŵ�����˳������ڽӵ㡣

�����ʽ:
�����1�и���2������N(0<N��10)��E���ֱ���ͼ�Ķ������ͱ��������E�У�ÿ�и���һ���ߵ������˵㡣ÿ���е�����֮����1�ո�ָ���

�����ʽ:
����"{ v?1?? v?2?? ... v?k?? }"�ĸ�ʽ��ÿ�����һ����ͨ���������DFS�Ľ���������BFS�Ľ����

��������:
8 6
0 7
0 1
2 0
4 1
2 4
3 5
�������:
{ 0 1 4 2 7 }
{ 3 5 }
{ 6 }
{ 0 1 2 7 4 }
{ 3 5 }
{ 6 }

*/


#include<iostream>
#include<algorithm>
using namespace std;

typedef struct Edge
{
	int field;
	int value;	//�ߵ�Ȩֵ
	struct Edge *next;
}Edge, *tEdge;

typedef struct Node
{
	int data;
	tEdge firstEdge;
}Node, nList[10];

typedef struct
{
	nList vex;
	int ndeNum, edgNum;
}Arr;

bool Visited[10] = { false };
bool BVisited[10] = { false };
int locateVex(Arr G, char v1);

void init(Arr &G)
{
	int i, j;
	int v1, v2;
	cin >> G.ndeNum >> G.edgNum;
	for (i = 0;i < G.ndeNum;i++)
	{
		G.vex[i].data = i;
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


void DFSTraverse(Arr G,int V)
{
	tEdge N;

	cout << G.vex[V].data;
	Visited[V] = true;
	for (N = G.vex[V].firstEdge;N;N = N->next)
	{
		if (!Visited[N->field])
		{
			DFSTraverse(G, N->field);
		}
	}
}


void BFSTraverse(Arr G, int V)
{
	int mark[10];
	int count = 0, k = count, j = 1;
	mark[count] = V;
	BVisited[mark[k]] = true;

	for (int i = 0;i < G.ndeNum;i++)
	{
		cout << G.vex[mark[k]].data;
		j--;
		while (G.vex[mark[k]].firstEdge)
		{
			//G.vex[mark[k]].firstEdge->field;
			if (BVisited[G.vex[mark[k]].firstEdge->field]==false)
			{
				//cout << G.vex[mark[k]].firstEdge->field << endl;
				BVisited[G.vex[mark[k]].firstEdge->field] = true;
				j++;
				mark[++count] = G.vex[mark[k]].firstEdge->field;
			}
			G.vex[mark[k]].firstEdge = G.vex[mark[k]].firstEdge->next;
			//cout << G.vex[mark[k]].firstEdge->field;
		}
		k = count - j+1;
		if (k > count)	break;
	}
	
}


void sortArr(Arr G)
{
	int num[10], count = 0, k = 0;
	Arr A = G;
	for (int i = 0;i < G.ndeNum;i++)
	{
		while (G.vex[i].firstEdge)
		{
			num[count++] = G.vex[i].firstEdge->field;
			G.vex[i].firstEdge = G.vex[i].firstEdge->next;
		}
		sort(num,num+count);
		int k = 0;
		while (A.vex[i].firstEdge)
		{
			A.vex[i].firstEdge->field = num[k++];
			A.vex[i].firstEdge = A.vex[i].firstEdge->next;
		}
		count = 0;
	}
	G = A;
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
		else  cout << G.vex[i].data << ":NULL";
		cout << endl;
	}
}

int main()
{
	Arr G;
	init(G);
	sortArr(G);
	print(G);
	for (int i = 0;i < G.ndeNum;i++)
	{
		if (!Visited[i])
		{
			DFSTraverse(G, i);
			cout << endl;
		}
	}

	cout << endl;
	for (int i = 0;i < G.ndeNum;i++)
	{
		if (!BVisited[i])
		{
			BFSTraverse(G, i);
			cout << endl;
		}
	}
}