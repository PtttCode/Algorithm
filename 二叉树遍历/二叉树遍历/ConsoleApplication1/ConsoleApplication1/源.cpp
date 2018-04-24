#include<iostream>
using namespace std;
//A B D H 0 0 I 0 0 E J 0 0 K 0 0 C F L 0 0 M 0 0 G N 0 0 O 0 0

typedef struct Tree
{
	struct Tree *left;	//左孩子
	struct Tree *right;	//右孩子
	char value;		//数据域
}Node, *BitTree;	   //树的结构体定义

#define EmptyTOS    -1  //空栈
#define MinStackSize    5   //栈的最小值
#define maxQueueSize 20		//队列最大值

typedef struct stackRecord
{
	int capacity;//容量
	int stackTop;//栈顶
	BitTree *array;	//存储树结点
}STACK;	  //堆栈的定义

typedef struct
{
	int rear;	//首指针
	int front;	//尾指针
	BitTree *arr;	//存储树结点
}Queue;	  //队列的定义


/*队列的函数*/
void qMakeEmpty(Queue *q)	//使队列空
{
	q->front = q->rear = 0;
}

Queue *initQueue()	//初始化队列
{
	Queue *q;
	q = (Queue *)malloc(sizeof(Queue)*maxQueueSize);
	q->arr=(BitTree *)malloc(sizeof(Node)*maxQueueSize); //重点（为arr指针分配树的空间）
	q->front = 0;
	q->rear = 0;
	return q;
}

int qEmpty(Queue *q)	//判定队列是否为空
{
	return q->front == q->rear;
}

void qPush(Tree *T, Queue *q)	//入队操作
{ 
	if (q->rear == maxQueueSize)	cout << "队列满！"<<endl;
	else
	{
		q->arr[q->rear++] = T;
		//cout << "Pushed!" << endl;
	}
}

void qPop(Queue *q)	//出队操作
{
	if (qEmpty(q))	cout << "队列空！" << endl;
	else
	{
		q->front++;
	}
}

BitTree qEle(Queue *q)	//取队列元素(front指针所指元素)
{
	if (qEmpty(q))
	{
		cout << "列空！" << endl;
		return 0;
	}
	else
	{
		return q->arr[q->front];
	}
}


/*堆栈的函数*/
int isEmpty(STACK *s)	//判定堆栈是否空
{
	//cout << s->stackTop;
	return (s->stackTop == EmptyTOS);
}

int isFull(STACK *s)	//判断堆栈是否空
{
	//cout << s->stackTop;
	return (s->stackTop == s->capacity - 1);
}

void makeEmpty(STACK *s)	//使堆栈变空
{
	if (s != NULL) {
		s->stackTop = EmptyTOS;
	}
}

STACK *createStack(int maxElements)	//初始化堆栈
{
	STACK *s;

	if (maxElements < MinStackSize) {
		printf("Stack size si too small\n");
		return NULL;
	}
	s = (STACK *)malloc(sizeof(STACK));
	s->array = (BitTree *)malloc(sizeof(Node)*maxElements);	//重点（为堆栈的array指针分配树的类型以便存储二叉树结点）
	s->capacity = maxElements;
	makeEmpty(s);

	return s;

}

void disposeStack(STACK *s)		//销毁栈
{
	if (s != NULL) {
		free(s->array);
		free(s);
	}
}

void push(Tree *T, STACK *s)	//入栈
{
	if (!isFull(s)) {
		s->stackTop++;
		s->array[s->stackTop] = T;
	}
	else {
		printf("full stack\n");
	}
}

BitTree top(STACK *s)	//取栈顶元素
{
	if (!isEmpty(s)) {
		return s->array[s->stackTop];
	}
	else {
		printf("empty stack\n");
		return 0;
	}
}

void pop(STACK *s)	//删除栈顶元素
{
	if (!isEmpty(s))
		s->stackTop--;
	else
		printf("empty stack\n");
}

BitTree topAndPop(STACK *s)	//字面意思函数先top再pop
{
	if (!isEmpty(s)) {
		return s->array[s->stackTop--];
	}
	else {
		printf("empty stack\n");
		return 0;
	}
}

int Depth(BitTree T)	//探测树的深度
{
	if (T == NULL)	return 0;
	else
	{
		int m = Depth(T->left);
		int n = Depth(T->right);
		if (m > n)	return m + 1;
		else  return n + 1;
	}
}


/*递归法*/
void preTraverse(BitTree T)//前序遍历
{
	if (T)
	{
		cout << T->value;
		preTraverse(T->left);
		preTraverse(T->right);
	}
}

void midTraverse(BitTree T)//中序遍历
{
		if (T->left)	midTraverse(T->left);
		cout << T->value;
		if (T->right)	midTraverse(T->right);
}

void backTraverse(BitTree T)//后序遍历
{
		if (T->left)	backTraverse(T->left);
		if (T->right)	backTraverse(T->right);
		cout << T->value;
}


/*非递归法*/
void preTraverse_2(BitTree T,STACK *s) //非递归前序遍历
{
	while (T || !isEmpty(s))
	{
		while (T)
		{
			cout << T->value;
			push(T, s);
			T = T->left;
		}
		if (!isEmpty(s))
		{
			T = topAndPop(s);
			T = T->right;
		}
	}
}

void midTraverse_2(BitTree T, STACK *s)	//非递归中序遍历
{
	while (T || !isEmpty(s))
	{
		while (T)
		{
			push(T, s);
			T = T->left;
		}
		if (!isEmpty(s))
		{
			T = topAndPop(s);
			cout << T->value;
			T = T->right;
		}
	}
}

void backTraverse_2(BitTree T, STACK *s)	 //非递归后序遍历
{
	BitTree p=NULL;
	while (T || !isEmpty(s))
	{
		while (T)	//遍历左孩子
		{
			push(T, s);
			T = T->left;
		}
		T = top(s);	//取栈顶
		if ((!T->right) || (p == T->right))	 //如果有右孩子或者右孩子没有遍历过的话执行
		{
			cout << T->value;
			pop(s);
			p = T;	//标记右孩子已遍历
			T = NULL;	//使下次循环取出下一个节点
		}
		else  T = T->right;

	}
	//cout << "!";
}

void stairwayTravere(BitTree T, Queue *q)
{
	qPush(T, q);	//先将根节点入队
	while (!qEmpty(q))	//当队列不空
	{
		T = qEle(q);	//取队列front
		cout << T->value;
		qPop(q);
		if (T->left)	qPush(T->left,q);    //放入左孩子
		if (T->right)	qPush(T->right,q);	 //放入右孩子
	}
	qMakeEmpty(q);
}

void init(BitTree &T)	//递归法初始化二叉树
{
	char str;
	cin >> str;
	if (str == '0')
	{
		T = NULL;
	}
	else
	{
		T = (Node *)malloc(sizeof(Node));
		T->value = str;
		init(T->left);
		init(T->right);
	}
}

int main()
{
	BitTree T1;
	STACK *s;
	Queue *q;
	q = initQueue();
	s = createStack(20);
	init(T1);
	cout << "递归遍历：" << endl << "前序:";
	preTraverse(T1);
	cout << endl << "中序:";
	midTraverse(T1);
	cout << endl << "后序:";
	backTraverse(T1);	
	cout << endl;
	makeEmpty(s);
	cout << "非递归遍历：" << endl << "前序:";
	preTraverse_2(T1, s);
	cout << endl<<"中序:";
	makeEmpty(s);
	midTraverse_2(T1, s);
	cout << endl<<"后序:";
	makeEmpty(s);
	backTraverse_2(T1, s);
	cout << endl<<"层次遍历:";
	stairwayTravere(T1, q);

	
	return 0;
}