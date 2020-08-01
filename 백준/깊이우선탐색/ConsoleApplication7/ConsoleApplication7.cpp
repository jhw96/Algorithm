#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<int> *graph,bool *visit, int start) // 시작 정점부터 깊이 탐색
{
	visit[start] = true; // 노드 방문 체크
	cout << start << " "; // 방문한 노드 바로 출력
	
	for (int i = 0; i < graph[start].size(); i++) // 방금 방문한 정점의 연결된 정점들 탐색
	{
		int next = graph[start][i];
		if (visit[next] == false) // 방문하지 않았으면 깊이우선 탐색
			DFS(graph, visit, next);
	}
	
}

int main()
{
	int vertex = 0, arc = 0, start = 0; // 노드 수, 간선 수, 시작정점
	cin >> vertex >> arc >> start;
	
	vector<int> * graph = new vector<int>[vertex + 1];
	bool *visit = new bool[vertex + 1]; // 방문 여부 체크

	for (int i = 0; i < vertex + 1; i++)
		visit[i] = false;
	
	for (int i = 0; i < arc; i++) // 그래프 만들기
	{
		int num1, num2;
		cin >> num1 >> num2;
		graph[num1].push_back(num2);
		graph[num2].push_back(num1);
	}

	/*for (int i = 1; i < vertex + 1; i++) // 그래프 출력
	{
		cout << i << "번 정점과 연결된 정점들 : ";
		for (int j = 0; j < graph[i].size(); j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}*/

	DFS(graph, visit, start);

	return 0;
}