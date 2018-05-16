#include<iostream>
using namespace std;

#define Lack '-'


typedef struct Tree {
	char data;
	int left;
	int right;
}Tree, BiTree[11];

struct Arr
{
	BiTree arr;
	int ndeNum;
};

void init(Arr &T)
{
	int i;
	char l, r;
	char nde;
	cin >> T.ndeNum;

	for (i = 0;i < T.ndeNum;i++)
	{
		cin >> nde >> l >> r;
		T.arr[i].data = nde;
		if (l !=Lack)	T.arr[i].left = l-'0';
		else    T.arr[i].left = -1;
		if (r != Lack)	T.arr[i].right = r-'0';
		else    T.arr[i].right = -1;
	}
}

int locate(Arr T,char data)
{
	int i;
	for (i = 0;i < T.ndeNum;i++)
	{
		if (T.arr[i].data == data)	break;
	}
	return i;
}


void cmp(Arr T, Arr T1)
{
	int i;
	int pos;
	char tleft=NULL, tright= NULL;
	char t1left= NULL, t1right= NULL;

	for (i = 0;i < T.ndeNum;i++)
	{
		pos = locate(T, T1.arr[i].data);
		if (T.arr[pos].left >= 0)  tleft = T.arr[T.arr[pos].left].data; 
		if (T.arr[pos].right >= 0)	tright = T.arr[T.arr[pos].right].data;
		if (T1.arr[i].left >= 0)
		{
			t1left = T1.arr[T1.arr[i].left].data;
			if (t1left == tleft || t1left == tright);
			else
			{
				cout << "No";
				return;
			}
		}
		if (T1.arr[i].right >= 0)
		{
			t1right = T1.arr[T1.arr[i].right].data;
			if (t1right == tleft || t1right == tright);
			else
			{
				cout << "No";
				return;
			}
		}
	}
		cout << "Yes";
		
}


int main()
{
	Arr T, T1;
	init(T);
	init(T1);
	cmp(T, T1);
}