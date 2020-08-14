#include <iostream>

using namespace std;


void swap(int &a, int &b) 
{ 
	int temp = a;
	a = b;
	b = temp; 
} 


int partition(int list[], int left, int right)
{
	int pivot = list[left];
	int low = left;
	int high = right + 1;

	do {
		do {
			low++;
		} while (list[low] < pivot && low <= right);

		do {
			high--;
		} while (list[high] > pivot && high >= left);
		
		if (low < high)
			swap(list[low], list[high]);

	} while (low < high);

	swap(list[left], list[high]);
	
	return high;
}

void quick_sort(int list[], int left, int right)
{
	if (left < right)
	{
		int q = partition(list, left, right);

		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}

}


int main()
{
	int arr[9] = { 5,3,2,4,9,1,6,8,7 };
	
	quick_sort(arr, 0, 8);

	for (int i = 0; i < 9; i++)
		cout << arr[i] << " ";
}