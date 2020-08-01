#include <iostream>
#include <vector>
#include <queue>

using namespace std;


void BFS(vector<int> *graph, bool *visit, int start)
{
	queue<int> q;
	q.push(start);

	visit[start] = true; // 시작정점 방문

	while (!q.empty()) // 큐가 빌 때까지
	{
		int first = q.front(); // 큐의 첫번째 정점

		cout << first << " ";

		q.pop();

		for (int i = 0; i < graph[first].size(); i++) // 큐에서 한 정점을 빼내면서 인근 접점을 큐에 다 넣는다
		{
			int next = graph[first][i];

			if (visit[next] != true)
			{
				q.push(next);
				visit[next] = true;
			}
		}
	}

}

int main()
{
	int vertex, arc, start; // 정점 수, 간선 수, 시작정점

	cin >> vertex >> arc >> start;

	vector<int> * graph = new vector<int>[vertex + 1]; // 그래프
	bool *visit = new bool[vertex + 1]; // 방문 여부 확인

	int num1 = 0, num2 = 0;

	for (int i = 0; i < arc; i++) // 간선 입력
	{
		cin >> num1 >> num2;
		graph[num1].push_back(num2);
		graph[num2].push_back(num1);
	}
	
	for (int i = 0; i < vertex + 1; i++)
		visit[i] = false;
	 
	BFS(graph, visit, start);

}