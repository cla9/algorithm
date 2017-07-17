#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long dfs(vector<vector<int>> & graph, vector<bool> & isVisited, int idx)
{
	long res = 1;
	isVisited[idx] = true;
	cout << idx << " ";
	for (int i = 0; i < graph.size(); i++)
	{
		if (graph[idx][i] && !isVisited[i])
			res += dfs(graph, isVisited, i);
	}
	return res;
}

int main()
{
	vector<vector<int>> graph;
	vector<bool> isVisited;
	int nV, nE;
	scanf("%d %d", &nV, &nE);
	graph.resize(nV + 1);
	for (int i = 1; i < nV + 1; i++)
	{
		graph[i].resize(nV + 1);
		fill(graph[i].begin(), graph[i].end(), 0);
	}
	isVisited.resize(nV + 1);
	fill(isVisited.begin(), isVisited.end(), false);
	for (int i = 0; i < nE; i++)
	{
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);
		graph[s][e] = graph[e][s] = w;
	}
	int cnt = 0;
	for (int i = 1; i <= nV; i++)
	{
		if (!isVisited[i])
		{
			int res = dfs(graph, isVisited, i);
			printf("\n %d\n", res);
			cnt++;
		}
	}
	printf("%d\n", cnt)
		return 0;
}