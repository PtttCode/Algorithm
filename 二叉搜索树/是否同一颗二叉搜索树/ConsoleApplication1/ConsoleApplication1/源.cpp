/*����һ���������оͿ���Ψһȷ��һ�ö�����������Ȼ����һ�ø����Ķ���������ȴ�����ɶ��ֲ�ͬ�Ĳ������еõ�������ֱ�������{2, 1, 3}��{2, 3, 1}�����ʼΪ�յĶ��������������õ�һ���Ľ�������Ƕ�������ĸ��ֲ������У�����Ҫ�ж������Ƿ�������һ���Ķ�����������

�����ʽ:

�������������������ݡ�ÿ�����ݵĵ�1�и�������������N (��10)��L���ֱ���ÿ�����в���Ԫ�صĸ�������Ҫ�������и�������2�и���N���Կո�ָ�������������Ϊ��ʼ�������С����L�У�ÿ�и���N�������Ԫ�أ�����L����Ҫ�������С�

����������Ǳ�֤ÿ���������ж���1��N��һ�����С�������NΪ0ʱ����־����������������ݲ�Ҫ����

�����ʽ:

��ÿһ����Ҫ�������У���������ɵĶ�������������Ӧ�ĳ�ʼ�������ɵ�һ���������Yes�������������No����

��������:

4 2
3 1 4 2
3 4 1 2
3 2 4 1
2 1
2 1
1 2
0
�������:

Yes
No
No*/

#include<iostream>
using namespace std;
int Count;

typedef struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
}Tree,*BiTree;


BiTree insert(BiTree &T, int num)
{
	if (!T)
	{
		T = (BiTree)malloc(sizeof(Tree));
		T->data = num;
		T->left = T->right = NULL;
	}
	else
	{
		if (num < T->data)	insert(T->left, num);
		else  insert(T->right, num);
	}

	return T;
}

BiTree init(int size)
{
	BiTree T;
	int num;

	cin >> num;
	T = (BiTree)malloc(sizeof(Tree)*(2*size+1));
	T->data = num;
	T->left = T->right = NULL;
	for (int i = 0;i < size-1;i++)
	{
		cin >> num;
		T= insert(T, num);
	}
	return T;
}

int  preTraverse(BiTree T,BiTree T1)
{
	if (T && T1)
	{
		if (T->data == T1->data)
		{
			Count++;
			preTraverse(T->left, T1->left);
			preTraverse(T->right, T1->right);
		}
	}
	return Count;
}

int main()
{
	BiTree T,T1;
	int N, L;
	int i, judge;
	cin >> N;

	while (N != 0)
	{
		cin >> L;
		T = init(N);
		for (i = 0;i < L;i++)
		{
			T1 = init(N);
			judge = preTraverse(T, T1);
			if (judge == N)	cout << "Yes" << endl;
			else  cout << "No" << endl;
			free(T1);
		}
		cin >> N;
	}
	
	return 0;
}