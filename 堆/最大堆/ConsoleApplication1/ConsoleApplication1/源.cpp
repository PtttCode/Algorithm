#include <iostream>
using namespace std;

typedef struct
{
	int *data;
	int size;
	int capacity;
}Heap,*MaxHeap;

MaxHeap init(int maxSize)
{
	MaxHeap H = (MaxHeap)malloc(sizeof(Heap));
	H->data = (int *)malloc(sizeof(int)*(maxSize + 1));
	H->size = 0;
	H->capacity = maxSize;
	H->data[0] = 99999;
	return H;
}

void Insert(MaxHeap H, int item)
{
	if (H->size == H->capacity)
	{
		cout << "¶ÑÂú£¡";
		return;
	}
	int i = ++H->size;
	for (;item > H->data[i/2];i /= 2)
	{
		H->data[i] = H->data[i / 2];
	}
	H->data[i] = item;
}

int deleteData(MaxHeap H)
{
	int p, c;
	if (H->size == 1)
	{
		cout << "¶Ñ¿Õ£¡";
		return;
	}
	int temp = H->data[1];
	int flag = H->data[H->size--];
	for (p = 1;p * 2 <= H->size;p = c)
	{
		c = p * 2;
		if (c != H->size && (H->data[c] < H->data[c + 1]))
		{
			c++;
		}
		if (flag >= H->data[c]) break;
		else  H->data[p] = H->data[c];
	}
	H->data[p] = flag;
	return temp;
}

int main()
{

}