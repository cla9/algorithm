#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#define MAX 1e9
using namespace std;
/*
5 10
5
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
5
1 2 2
3 2 -1
4 3 -4
2 4 3
2 5 1
*/
int main()
{
	vector<vector<int>> graph;
	vector<vector<int>> parent;
	int nV, nE, dst;
	scanf("%d %d", &nV, &nE);
	scanf("%d", &dst);

	graph.resize(nV);
	parent.resize(nV);
	for (int i = 0; i < nV; i++)
	{
		graph[i].resize(nV);
		fill(graph[i].begin(), graph[i].end(), MAX);
		graph[i][i] = 0;

		parent[i].resize(nV);
		fill(parent[i].begin(), parent[i].end(), -1);
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
	
	bool mCycle = false;
	for (int i = 0; i < nV; i++)
	{
		if (graph[i][i]<0)
		{
			mCycle = true;
			break;
		}
	}

	if (mCycle) printf("minus cycle\n");
	else
	{
		int idx = dst - 1;
		printf("%d\n", graph[0][idx]);
		vector<int> res;
		while (parent[0][idx] != -1)
		{
			res.push_back(idx);
			idx = parent[0][idx];
		}
		res.push_back(idx);
		for (int i = res.size() - 1; i >= 0; i--)
			printf("%d ",res[i]+1);
		printf("\n");
	}
}