#include<iostream>
using namespace std;

int main()
{
	int n;
	int num[100];
	int i;
	int sum = 0, max = 0;

	cin >> n;
	for (i = 0;i < n;i++)
	{
		cin >> num[i];
	}

	for (i = 0;i < n;i++)
	{
		sum += num[i];
		if (sum < 0)	sum = 0;
		else if (sum>max)	max = sum;
	}
	cout << max;
}