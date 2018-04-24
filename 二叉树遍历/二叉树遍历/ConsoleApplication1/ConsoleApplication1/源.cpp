#include<iostream>
using namespace std;
//A B D H 0 0 I 0 0 E J 0 0 K 0 0 C F L 0 0 M 0 0 G N 0 0 O 0 0

typedef struct Tree
{
	struct Tree *left;	//����
	struct Tree *right;	//�Һ���
	char value;		//������
}Node, *BitTree;	   //���Ľṹ�嶨��

#define EmptyTOS    -1  //��ջ
#define MinStackSize    5   //ջ����Сֵ
#define maxQueueSize 20		//�������ֵ

typedef struct stackRecord
{
	int capacity;//����
	int stackTop;//ջ��
	BitTree *array;	//�洢�����
}STACK;	  //��ջ�Ķ���

typedef struct
{
	int rear;	//��ָ��
	int front;	//βָ��
	BitTree *arr;	//�洢�����
}Queue;	  //���еĶ���


/*���еĺ���*/
void qMakeEmpty(Queue *q)	//ʹ���п�
{
	q->front = q->rear = 0;
}

Queue *initQueue()	//��ʼ������
{
	Queue *q;
	q = (Queue *)malloc(sizeof(Queue)*maxQueueSize);
	q->arr=(BitTree *)malloc(sizeof(Node)*maxQueueSize); //�ص㣨Ϊarrָ��������Ŀռ䣩
	q->front = 0;
	q->rear = 0;
	return q;
}

int qEmpty(Queue *q)	//�ж������Ƿ�Ϊ��
{
	return q->front == q->rear;
}

void qPush(Tree *T, Queue *q)	//��Ӳ���
{ 
	if (q->rear == maxQueueSize)	cout << "��������"<<endl;
	else
	{
		q->arr[q->rear++] = T;
		//cout << "Pushed!" << endl;
	}
}

void qPop(Queue *q)	//���Ӳ���
{
	if (qEmpty(q))	cout << "���пգ�" << endl;
	else
	{
		q->front++;
	}
}

BitTree qEle(Queue *q)	//ȡ����Ԫ��(frontָ����ָԪ��)
{
	if (qEmpty(q))
	{
		cout << "�пգ�" << endl;
		return 0;
	}
	else
	{
		return q->arr[q->front];
	}
}


/*��ջ�ĺ���*/
int isEmpty(STACK *s)	//�ж���ջ�Ƿ��
{
	//cout << s->stackTop;
	return (s->stackTop == EmptyTOS);
}

int isFull(STACK *s)	//�ж϶�ջ�Ƿ��
{
	//cout << s->stackTop;
	return (s->stackTop == s->capacity - 1);
}

void makeEmpty(STACK *s)	//ʹ��ջ���
{
	if (s != NULL) {
		s->stackTop = EmptyTOS;
	}
}

STACK *createStack(int maxElements)	//��ʼ����ջ
{
	STACK *s;

	if (maxElements < MinStackSize) {
		printf("Stack size si too small\n");
		return NULL;
	}
	s = (STACK *)malloc(sizeof(STACK));
	s->array = (BitTree *)malloc(sizeof(Node)*maxElements);	//�ص㣨Ϊ��ջ��arrayָ��������������Ա�洢��������㣩
	s->capacity = maxElements;
	makeEmpty(s);

	return s;

}

void disposeStack(STACK *s)		//����ջ
{
	if (s != NULL) {
		free(s->array);
		free(s);
	}
}

void push(Tree *T, STACK *s)	//��ջ
{
	if (!isFull(s)) {
		s->stackTop++;
		s->array[s->stackTop] = T;
	}
	else {
		printf("full stack\n");
	}
}

BitTree top(STACK *s)	//ȡջ��Ԫ��
{
	if (!isEmpty(s)) {
		return s->array[s->stackTop];
	}
	else {
		printf("empty stack\n");
		return 0;
	}
}

void pop(STACK *s)	//ɾ��ջ��Ԫ��
{
	if (!isEmpty(s))
		s->stackTop--;
	else
		printf("empty stack\n");
}

BitTree topAndPop(STACK *s)	//������˼������top��pop
{
	if (!isEmpty(s)) {
		return s->array[s->stackTop--];
	}
	else {
		printf("empty stack\n");
		return 0;
	}
}

int Depth(BitTree T)	//̽���������
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


/*�ݹ鷨*/
void preTraverse(BitTree T)//ǰ�����
{
	if (T)
	{
		cout << T->value;
		preTraverse(T->left);
		preTraverse(T->right);
	}
}

void midTraverse(BitTree T)//�������
{
		if (T->left)	midTraverse(T->left);
		cout << T->value;
		if (T->right)	midTraverse(T->right);
}

void backTraverse(BitTree T)//�������
{
		if (T->left)	backTraverse(T->left);
		if (T->right)	backTraverse(T->right);
		cout << T->value;
}


/*�ǵݹ鷨*/
void preTraverse_2(BitTree T,STACK *s) //�ǵݹ�ǰ�����
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

void midTraverse_2(BitTree T, STACK *s)	//�ǵݹ��������
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

void backTraverse_2(BitTree T, STACK *s)	 //�ǵݹ�������
{
	BitTree p=NULL;
	while (T || !isEmpty(s))
	{
		while (T)	//��������
		{
			push(T, s);
			T = T->left;
		}
		T = top(s);	//ȡջ��
		if ((!T->right) || (p == T->right))	 //������Һ��ӻ����Һ���û�б������Ļ�ִ��
		{
			cout << T->value;
			pop(s);
			p = T;	//����Һ����ѱ���
			T = NULL;	//ʹ�´�ѭ��ȡ����һ���ڵ�
		}
		else  T = T->right;

	}
	//cout << "!";
}

void stairwayTravere(BitTree T, Queue *q)
{
	qPush(T, q);	//�Ƚ����ڵ����
	while (!qEmpty(q))	//�����в���
	{
		T = qEle(q);	//ȡ����front
		cout << T->value;
		qPop(q);
		if (T->left)	qPush(T->left,q);    //��������
		if (T->right)	qPush(T->right,q);	 //�����Һ���
	}
	qMakeEmpty(q);
}

void init(BitTree &T)	//�ݹ鷨��ʼ��������
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
	cout << "�ݹ������" << endl << "ǰ��:";
	preTraverse(T1);
	cout << endl << "����:";
	midTraverse(T1);
	cout << endl << "����:";
	backTraverse(T1);	
	cout << endl;
	makeEmpty(s);
	cout << "�ǵݹ������" << endl << "ǰ��:";
	preTraverse_2(T1, s);
	cout << endl<<"����:";
	makeEmpty(s);
	midTraverse_2(T1, s);
	cout << endl<<"����:";
	makeEmpty(s);
	backTraverse_2(T1, s);
	cout << endl<<"��α���:";
	stairwayTravere(T1, q);

	
	return 0;
}