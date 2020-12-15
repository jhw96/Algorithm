#include <iostream>

using namespace std;

class queue
{
private:
	int *arr;
	int capacity, front, rear;


public:
	queue() { capacity = 10, front = 0, rear = 0; arr = new int[capacity]; };
	bool isEmpty() { if (rear == front) return true; return false; }
	void push(int num);
	void pop();
	void display();
};

void queue::push(int num)
{
	if (((rear + 1) % capacity) == front) // Queue is Full
	{
		cout << "Queue is Full!\n";
		int *temp = new int[2 * capacity];

		if (rear == capacity - 1) // 큐가 그냥 순차대로 찬 경우
		{
			for (int i = front; i <= rear; i++)
				temp[i] = arr[i];

			rear++;
			arr[rear] = num;
			capacity *= 2;
		}
		else // 큐가 순차대로 차지 않은 경우
		{
			int index = 0;

			for (int i = front + 1; i < capacity; i++) // front 뒤쪽 옮기기
			{
				temp[index] = arr[i];
				index++;
			}

			for (int i = 0; i <= rear; i++) // rear 옮기기
			{
				temp[index] = arr[i];
				index++;
			}

			rear = index;
			front = 2 * capacity - 1;
			arr = temp;
			capacity *= 2;
			arr[rear] = num;
		}

	}
	else
	{
		rear = (rear + 1) % capacity;
		arr[rear] = num;
	}
}

void queue::pop()
{
	if (isEmpty())
		cout << "Queue is Empty!\n";
	else
	{
		front = (front + 1) % capacity;
		cout << arr[front] << " is Deleted\n";
		arr[front] = -9999;
	}
}

void queue::display()
{
	if (isEmpty())
		cout << "Queue is Empty!\n";
	else
	{
		int index = (front + 1) % capacity;
		cout << "front [ ";

		while (index <= rear)
		{
			cout << " " << arr[index] << " ";
			if (index != rear)
				cout << " | ";

			index = (index + 1) % capacity;
		}

		cout << " ] rear\n";
	}
}

int main() {
	queue a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);
	a.push(6);
	a.display();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();

	a.display();

	a.push(7);
	a.push(8);
	a.push(9);
	a.push(10);
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);
	a.push(6);

	a.display();


	return 0;
}