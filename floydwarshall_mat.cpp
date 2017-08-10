#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#define INF static_cast<int>(2e9)
/*
5 10
1 5
1 2 2
1 3 2
1 4 5
1 5 9
2 3 3
2 4 4
2 5 8
3 4 7
3 5 6
4 5 5
답
8
1 3 5

음수 사이클 존재 경우
5 5
1 5
1 2 2
3 2 -1
4 3 -4
2 4 3
2 5 1
*/
using namespace std;

int main()
{
	int nV, nE, src, dst;
	scanf("%d %d %d %d", &nV, &nE, &src, &dst);
	src--; dst--;

	vector<vector<int>> graph(nV);
	vector<vector<int>> parent(nV);
	for (int i = 0; i < nV; i++)
	{
		graph[i].resize(nV);
		parent[i].resize(nV);
		fill(graph[i].begin(), graph[i].end(), INF);
		fill(parent[i].begin(), parent[i].end(), -1);
		graph[i][i] = 0;
	}
	for (int i = 0; i < nE; i++)
	{
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);
		s--; e--;
		graph[s][e] = w;
		parent[s][e] = s;
	}

	for (int i = 0; i < nV; i++)
	{
		for (int j = 0; j < nV; j++)
		{
			for (int k = 0; k < nV; k++)
			{
				if (graph[i][k] > graph[i][j] + graph[j][k])
				{
					graph[i][k] = graph[i][j] + graph[j][k];
					parent[i][k] = parent[j][k];
				}
			}
		}
	}
	bool isCycle = false;
	for (int i = 0; i < nV; i++)
	if (graph[i][i]<0)
		isCycle = true;

	if (isCycle)
		puts("negative cycle");
	else
	{
		int idx = dst;
		vector<int> res;
		printf("%d\n", graph[src][idx]);
		while (parent[src][idx] != -1)
		{
			res.push_back(idx);
			idx = parent[src][idx];
		}
		res.push_back(idx);
		for (int i = res.size() - 1; i >= 0; i--)
			printf("%d ", res[i] + 1);
		puts("");
	}
}