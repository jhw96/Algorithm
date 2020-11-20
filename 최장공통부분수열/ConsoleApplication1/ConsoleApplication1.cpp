#include <iostream>
#include <string>
#include <stack>

using namespace std;

// LCS(Longest Common Subsqence)
int main(void)
{
	string str1, str2;
	cin >> str1 >> str2;

	int strLength = str1.length();
	char *sample1 = new char[strLength + 1];
	char *sample2 = new char[strLength + 1];
	int **cLength = new int*[strLength + 1];

	for (int i = 0; i < strLength + 1; i++)
		cLength[i] = new int[strLength + 1];

	// 테이블 초기화
	for (int i = 0; i < strLength + 1; i++)
	{
		cLength[0][i] = 0;
		cLength[i][0] = 0;
	}

	sample1[0] = 0, sample2[0] = 0;

	for (int i = 0; i < strLength; i++)
	{
		sample1[i + 1] = str1[i];
		sample2[i + 1] = str2[i];
	}

	
	for (int i = 1; i < strLength + 1; i++)
	{
		for (int j = 1; j < strLength + 1; j++) // Sample1의 표본에 대해 검사
		{
			if (sample1[j] != sample2[i]) // 비교하는 문자가 서로 다르면
			{
				if (cLength[j][i - 1] > cLength[j - 1][i])
					cLength[j][i] = cLength[j][i - 1];
				else
					cLength[j][i] = cLength[j - 1][i];
			}
			else
			{
				cLength[j][i] = cLength[j - 1][i - 1] + 1;
			}
		}
	}

	int i = strLength; // Sample1의 길이
	int j = strLength; // Sample2의 길이

	stack<int> result;

	while (cLength[i][j] != 0)
	{
		// 경로 추적

		// 테이블이 같은 넘버링이라면
		// 왼쪽으로 이동
		if (cLength[i][j] == cLength[i][j - 1])
			j--;

		// 위쪽으로 이동
		else if (cLength[i][j] == cLength[i - 1][j])
			i--;

		// 왼쪽 위쪽 모두 다른 넘버링이라면 대각선 방향으로 이동
		else if (cLength[i][j] - 1 == cLength[i - 1][j - 1])
		{
			result.push(i);
			i--;
			j--;
		}
	}


	while (!result.empty())
	{
		cout << sample1[result.top()] << " ";
		result.pop();
	}

}
