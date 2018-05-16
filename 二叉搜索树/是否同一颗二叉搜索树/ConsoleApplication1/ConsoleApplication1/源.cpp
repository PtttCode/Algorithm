/*给定一个插入序列就可以唯一确定一棵二叉搜索树。然而，一棵给定的二叉搜索树却可以由多种不同的插入序列得到。例如分别按照序列{2, 1, 3}和{2, 3, 1}插入初始为空的二叉搜索树，都得到一样的结果。于是对于输入的各种插入序列，你需要判断它们是否能生成一样的二叉搜索树。

输入格式:

输入包含若干组测试数据。每组数据的第1行给出两个正整数N (≤10)和L，分别是每个序列插入元素的个数和需要检查的序列个数。第2行给出N个以空格分隔的正整数，作为初始插入序列。最后L行，每行给出N个插入的元素，属于L个需要检查的序列。

简单起见，我们保证每个插入序列都是1到N的一个排列。当读到N为0时，标志输入结束，这组数据不要处理。

输出格式:

对每一组需要检查的序列，如果其生成的二叉搜索树跟对应的初始序列生成的一样，输出“Yes”，否则输出“No”。

输入样例:

4 2
3 1 4 2
3 4 1 2
3 2 4 1
2 1
2 1
1 2
0
输出样例:

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