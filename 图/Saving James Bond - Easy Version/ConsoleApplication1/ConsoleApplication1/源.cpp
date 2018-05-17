/*
This time let us consider the situation in the movie "Live and Let Die" in which James Bond, the world's most famous spy, was captured by a group of drug dealers. He was sent to a small piece of land at the center of a lake filled with crocodiles. There he performed the most daring action to escape -- he jumped onto the head of the nearest crocodile! Before the animal realized what was happening, James jumped again onto the next big head... Finally he reached the bank before the last crocodile could bite him (actually the stunt man was caught by the big mouth and barely escaped with his extra thick boot).

Assume that the lake is a 100 by 100 square one. Assume that the center of the lake is at (0,0) and the northeast corner at (50,50). The central island is a disk centered at (0,0) with the diameter of 15. A number of crocodiles are in the lake at various positions. Given the coordinates of each crocodile and the distance that James could jump, you must tell him whether or not he can escape.

Input Specification:
Each input file contains one test case. Each case starts with a line containing two positive integers N (¡Ü100), the number of crocodiles, and D, the maximum distance that James could jump. Then N lines follow, each containing the (x,y) location of a crocodile. Note that no two crocodiles are staying at the same position.

Output Specification:
For each test case, print in a line "Yes" if James can escape, or "No" if not.

Sample Input 1:
14 20
25 -15
-25 28
8 49
29 15
-35 -2
5 28
27 -29
-8 -28
-20 -35
-25 -20
-13 29
-30 15
-35 40
12 12
Sample Output 1:
Yes
Sample Input 2:
4 13
-12 12
12 12
-12 -12
12 -12
Sample Output 2:
No
*/

#include <iostream>
using namespace std;

typedef struct Edge 
{
	int field;
	struct Edge *next;
}Edge,*tEdge;

typedef struct Node
{
	int data;
	int x;
	int y;
	tEdge firstEdge;
}Node,nList[100];

struct Arr
{
	nList vex;
	int ndeNum;
	int minNum[100];
};

bool mark = false;
bool Visited[100] = { false };
int locateVex(Arr G, char v1)
{
	int i;
	for (i = 0;i < G.ndeNum;i++)
	{
		if (G.vex[i].data == v1)	break;
	}
	return i;
}

int init(Arr &G)
{
	double dist;
	int count = 0;
	int i, j;
	cin >> G.ndeNum >> dist;

	for (i = 0;i < G.ndeNum;i++)
	{
		G.vex[i].data = i;
		cin >> G.vex[i].x >> G.vex[i].y;
		G.vex[i].firstEdge = NULL;
	}

	for (i = 0;i < G.ndeNum;i++)
	{
		double fromZero = sqrt(pow(G.vex[i].x, 2) + pow(G.vex[i].y, 2));
		if (fromZero <= dist)
		{
			G.minNum[count++] = i;
		}
		for (j = i + 1;j < G.ndeNum;j++)
		{
			double res = sqrt(pow(G.vex[i].x - G.vex[j].x, 2) + pow(G.vex[i].y - G.vex[j].y, 2));
			if (res <= dist)
			{
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
	}
	return count;

}

void DFSTraverse(Arr G,int V)
{
	tEdge E;
	Visited[V] = true;
	if (50 - abs(G.vex[V].x) <= 20 || 50 - abs(G.vex[V].y) <= 20)
	{
		mark = true;
		return;
	}
	for (E = G.vex[V].firstEdge;E;E = E->next)
	{
		if (!Visited[E->field])
		{
			DFSTraverse(G, E->field);
		}
	}	
}

void print(Arr G)
{
	for (int i = 0;i < G.ndeNum;i++)
	{
		cout << i << ":";
		while (G.vex[i].firstEdge)
		{
			cout << G.vex[i].firstEdge->field;
			G.vex[i].firstEdge = G.vex[i].firstEdge->next;
		}
		cout << endl;
	}
}


int main()
{
	int count;
	Arr G;
	count = init(G);
	for (int i = 0;i < count;i++)
	{
		DFSTraverse(G, G.minNum[i]);
	}
	if (mark)	cout << "Yes";
	else  cout << "No";
}