#include<iostream>
using namespace std;

int main()
{
	int num[50];
	int mid, left, right;
	int i, count = 0;

	for (i = 0;i < 11;i++)
	{
		cin >> num[i];
	}

	left = 1;
	right = 11;

	while (left <= right)
	{
		count++;
		mid = (left + right) / 2;
		if (num[mid] == 27)
		{
			cout << mid<<endl;
			break;
		}
		else if (num[mid] < 27)	left = mid + 1;
		else  right = mid - 1;
	}
	cout << count;

	return 0;
}
