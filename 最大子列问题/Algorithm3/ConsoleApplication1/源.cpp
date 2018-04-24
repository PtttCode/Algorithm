/*递归解决最小子列问题*/

#include<iostream>
using namespace std;

int max = 0;

void Compare(int n[], int left, int right)
{
	int i;
	int sum = 0;
	for (i = left;i <= right;i++)
	{
		sum += n[i];
		if (sum < 0)	sum = 0;
		else if (sum>max)	max = sum;
	}
}

void digui(int n[], int left, int right)
{
	int mid = (left + right) / 2;
	if (left<right)
	{
		digui(n, left, mid);
		digui(n, mid + 1, right);
		Compare(n, left, right);
		
	}
}

int main()
{
	int num[1000];
	int i, n;
	cin >> n;

	for (i = 0;i < n;i++)
	{
		cin >> num[i];
	}

	digui(num, 0, n-1);
	cout << max;
	return 0;
}