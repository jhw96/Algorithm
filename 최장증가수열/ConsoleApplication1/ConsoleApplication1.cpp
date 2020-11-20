#include <iostream>
#include <stack>

using namespace std;

//LIS(Longest Increasing Subsequence)

int main()
{
	stack<int> result;
	int N = 0;
	cin >> N;
	
	int *arr = new int[N];
	int *dp = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		dp[i] = 0;
	}
	
	int findMax = -1;
	int findIndex = 0;

	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
	cout << "\n";

	for (int i = 0; i < N; i++)
	{
		if (dp[i] == 0) dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j]) // 맨 뒤의 비교당하는 수가 앞의 수보다 크면
			{
				if (dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1;
			}
		}
		if (findMax < dp[i])
		{
			findMax = dp[i];
			findIndex = i;
		}
	}

	int checkIndex = findIndex;
	int flow = checkIndex - 1;

	while (true)
	{
		if (arr[checkIndex] > arr[flow]) // 비교하는 수가 앞의 수보다 크면 
		{
			result.push(arr[checkIndex]);
			checkIndex = flow;
		}
		else // 비교하는 수가 앞의 수보다 크지 않으면
		{
			flow--;
		}
		if (checkIndex == 0)
			break;
	}

	if (arr[checkIndex] < arr[checkIndex + 1])
		result.push(arr[checkIndex]);

	while (!result.empty())
	{
		int top = result.top();
		result.pop();
		cout << top << " ";
	}
	
	
}