#include <iostream>

using namespace std;

class Node {
private:
	int data;
	Node *next;
public:
	Node(int num) 
	{
		this->data = num;
		next = NULL;
	}
	// 읽기접근
	int GetData() { return data; } 
	Node *GetNext() { return next; }

	// 쓰기접근
	void setNext(Node *ptr) { next = ptr; }
};


class Deque {
private:
	Node *front;
	Node *back;
	int DataCount;

public:
	Deque()
	{
		front = NULL;
		back = NULL;
		DataCount = 0;
	}
	
	void pushFront(int num);
	void pushBack(int num);
	void popFront();
	void popBack();
	void Display();
	bool isEmpty() { if (DataCount == 0) return true; return false; }
	void Front();
	void Back();
	void Size() { cout << DataCount << "\n"; }
};

void Deque::pushFront(int num)
{
	if (isEmpty()) // 비어있으면
	{
		Node *newNode = new Node(num);
		front = back = newNode;
		DataCount++;
	}
	else
	{
		Node *newNode = new Node(num);
		newNode->setNext(front);
		front = newNode;
		DataCount++;
	}
}

void Deque::pushBack(int num)
{
	if (isEmpty()) // 비어있으면
	{
		Node *newNode = new Node(num);
		front = back = newNode;
		DataCount++;
	}
	else
	{
		Node *newNode = new Node(num);
		back->setNext(newNode);
		back = newNode;
		DataCount++;
	}
}

void Deque::popFront()
{
	if (isEmpty())
		cout << "-1\n";
	
	else
	{
		cout << front->GetData() << "\n";
		front = front->GetNext();
		DataCount--;
	}
}

void Deque::popBack()
{
	if (isEmpty())
		cout << "-1\n";
	else
	{
		cout << back->GetData() << "\n";
		Node *temp = front;
		while (temp->GetNext() != back) // back 직전 노드까지 이동
			temp = temp->GetNext();
		temp->setNext(NULL);
		back = temp;
		DataCount--;
	}
}




void Deque::Front() // 맨 앞의 정수 보기
{
	if (!isEmpty())
		cout << front->GetData() << "\n";
	else
		cout << "-1\n";
}

void Deque::Back() // 맨 뒤의 정수 보기
{
	if (!isEmpty())
		cout << back->GetData() << "\n";
	else
		cout << "-1\n";
}

void Deque::Display()
{
	if (!isEmpty())
	{
		Node *temp = front;
		while (temp->GetNext() != NULL)
		{
			cout << temp->GetData();
			cout << " -> ";

			temp = temp->GetNext();
		}
		cout << back->GetData() << "\n";
	}
	else
		cout << "Deque is Empty!\n";
}


int main()
{
	Deque dq;
	dq.pushFront(1);
	dq.pushFront(0);
	dq.pushBack(2);
	dq.Display();
	dq.pushFront(4);
	dq.pushBack(7);
	dq.Display();
	dq.popFront();
	dq.popBack();
	dq.Display();
}