#include<iostream>
using namespace std;

int main()
{
	int num[50];
	int i, j;
	int sum, max = 0;

	for (i = 0;i < 8;i++)	cin >> num[i];

	for (i = 0;i < 8;i++)
	{
		sum = 0;
		for (j = i;j < 8;j++)
		{
			sum += num[j];
			if (sum < 0)	sum = 0;
			else if (sum > max)	max = sum;
		}

	}
	cout << max;
}