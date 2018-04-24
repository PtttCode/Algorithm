#include<iostream>
using namespace std;

int main()
{
	int num[50];
	int i, j, k;
	int n;
	int sum = 0, max = 0;

	cin >> n;
	for (i = 0;i < n;i++)	cin >> num[i];

	for (i = 0;i < n;i++)
	{
		for (j = i;j < n;j++)
		{
			sum = 0;
			for (k = i;k <= j;k++)	sum += num[k];
			if (sum > max)	max = sum;
		
		}
	}

	cout << max;
	return 0;
}