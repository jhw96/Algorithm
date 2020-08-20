#include <iostream>

using namespace std;

int sorted[8];

void merge(int list[], int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) // 맨 왼쪽에서 시작하는 애가 중간보다 작고 중간부터 시작하는 애가 오른쪽보다 작을때까지만
	{
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	
	// 위에서 루프돌고 남은 애들 넣어주기
	if (i <= mid)
	{
		for (int m = i; m <= mid; m++)
			sorted[k++] = list[m];
	}
	else
	{
		for (int m = j; m <= right; m++)
			sorted[k++] = list[m];
	}

	// 원래의 배열로 복사해넣기
	for (int m = left; m <= right; m++)
		list[m] = sorted[m];

}

void merge_sort(int list[], int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}

int main()
{
	int list[8] = { 21, 10, 12, 20, 25, 13, 15, 22 };

	merge_sort(list, 0, 7);

	for (int i = 0; i < 8; i++)
		cout << list[i] << " ";

}