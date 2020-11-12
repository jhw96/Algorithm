#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void LowerBound(int left, int right, int target, vector<int> arr)
{
	while (left < right)
	{
		int mid = (left + right) / 2;

		if (arr[mid] >= target)
			right = mid;
		else
			left = mid + 1;

	}

	cout << "LowerBound is arr[" << right << "]\n";
}

void UpperBound(int left, int right, int target, vector<int> arr)
{
	while (left < right)
	{
		int mid = (left + right) / 2;

		if (arr[mid] > target)
			right = mid;
		else
			left = mid + 1;
	}
	cout << "UpperBound is arr[" << left << "]\n";
}

int main(void)
{
	int count = 0;
	int num = 0;
	vector<int> arr;

	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());
	LowerBound(0, arr.size(), 3, arr);
	UpperBound(0, arr.size(), 5, arr);
}