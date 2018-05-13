#include<iostream>
using namespace std;

typedef struct haffman
{
	int weight;
	struct haffman *left, *right;
}haffMan,*hTree;

typedef struct
{
	int *data;
	int size;
	int capacity;
}Heap, *MinHeap;

MinHeap init(int maxSize)
{
	MinHeap H = (MinHeap)malloc(sizeof(Heap));
	H->data = (int *)malloc(sizeof(int)*(maxSize + 1));
	H->size = 0;
	H->capacity = maxSize;
	H->data[0] = 0;
	return H;
}

void Insert(MinHeap H, int item)
{
	if (H->size == H->capacity)
	{
		cout << "¶ÑÂú£¡";
		return;
	}
	int i = ++H->size;
	for (;item < H->data[i / 2];i /= 2)
	{
		H->data[i] = H->data[i / 2];
	}
	H->data[i] = item;
}

int deleteData(MinHeap H)
{
	int p, c;
	if (H->size == 1)
	{
		cout << "¶Ñ¿Õ£¡";
		return 0;
	}
	int temp = H->data[1];
	int flag = H->data[H->size--];
	for (p = 1;p * 2 <= H->size;p = c)
	{
		c = p * 2;
		if (c != H->size && (H->data[c] > H->data[c + 1]))
		{
			c++;
		}
		if (flag < H->data[c]) break;
		else  H->data[p] = H->data[c];
	}
	H->data[p] = flag;
	return temp;
}

void print(MinHeap H)
{
	for (int i = 1;i <= H->size;i++)
	{
		cout << H->data[i];
	}
}


/*hTree init(MinHeap H)
{
	int i;
	hTree HT;
}*/

int main()
{
	MinHeap H;
	H = init(20);
	int num;

	for (int i = 0;i < 5;i++)
	{
		cin >> num;
		Insert(H, num);
	}
	print(H);
}