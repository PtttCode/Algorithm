/*
We have a network of computers and a list of bi-directional connections. Each of these connections allows a file transfer from one computer to another. Is it possible to send a file from any computer on the network to any other?

Input Specification:
Each input file contains one test case. For each test case, the first line contains NN (2N1042¡ÜN¡Ü10
?4
?? ), the total number of computers in a network. Each computer in the network is then represented by a positive integer between 1 and NN. Then in the following lines, the input is given in the format:

I c1 c2
where I stands for inputting a connection between c1 and c2; or

C c1 c2
where C stands for checking if it is possible to transfer files between c1and c2; or

S
where S stands for stopping this case.

Output Specification:
For each C case, print in one line the word "yes" or "no" if it is possible or impossible to transfer files between c1 and c2, respectively. At the end of each case, print in one line "The network is connected." if there is a path between any pair of computers; or "There are k components." where kis the number of connected components in this network.

Sample Input 1:
5
C 3 2
I 3 2
C 1 5
I 4 5
I 2 4
C 3 5
S
Sample Output 1:
no
no
yes
There are 2 components.
Sample Input 2:
5
C 3 2
I 3 2
C 1 5
I 4 5
I 2 4
C 3 5
I 1 3
C 1 5
S
Sample Output 2:
no
no
yes
yes
The network is connected.
*/

#include <iostream>
using namespace std;

struct Set
{
	int parent;
	int value;
};

void Insert(Set S[],int value,int parent)
{
	int mark;
	if (S[value - 1].parent < 0)	mark = S[value - 1].parent;
	S[value - 1].parent = parent;
	if (S[parent - 1].parent < 0)	S[parent - 1].parent+=mark;
	else
	{
		while (S[parent - 1].parent > 0)
		{
			parent = S[parent - 1].parent;
		}
		S[parent - 1].parent +=mark;
	}
}

void init(Set S[], int size)
{
	for (int i = 0;i < size;i++)
	{
		S[i].parent = -1;
		S[i].value = i+1;
	}
}

void print(Set S[], int size)
{
	for (int i = 0;i < size;i++)
	{
		cout << S[i].value << " " << S[i].parent << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	int v, p;
	Set S[11];

	init(S, n);
	for (int i = 0;i < n-2;i++)
	{
		cin >> v >> p;
		Insert(S, v, p);
	}
	print(S, n);

	return 0;
}