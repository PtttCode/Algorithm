/*
给定一个有N个顶点和E条边的无向图，请用DFS和BFS分别列出其所有的连通集。假设顶点从0到N?1编号。进行搜索时，假设我们总是从编号最小的顶点出发，按编号递增的顺序访问邻接点。

输入格式:
输入第1行给出2个整数N(0<N≤10)和E，分别是图的顶点数和边数。随后E行，每行给出一条边的两个端点。每行中的数字之间用1空格分隔。

输出格式:
按照"{ v?1?? v?2?? ... v?k?? }"的格式，每行输出一个连通集。先输出DFS的结果，再输出BFS的结果。

输入样例:
8 6
0 7
0 1
2 0
4 1
2 4
3 5
输出样例:
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
	int value;	//边的权值
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