#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#define INF 2e9
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
	vector<vector<pair<int, int>>> graph(nV);
	vector<int> parent(nV, -1);
	vector<bool> visited(nV, false);
	vector<int> dist(nV, INF);


	for (int i = 0; i < nE; i++)
	{
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);
		s--; e--;
		graph[s].push_back(make_pair(e, w));
	}

	dist[src] = 0;
	bool isCycle = false;
	for (int i = 0; i < nV; i++)
	{
		for (int j = 0; j < nV; j++)
		{
			for (pair<int, int> & p : graph[j])
			{
				int next = p.first;
				int nextd = p.second;
				if (dist[next] > dist[j] + nextd)
				{
					dist[next] = dist[j] + nextd;
					parent[next] = j;
					if (i == nV - 1) isCycle = true;
				}
			}
		}
	}
	if (isCycle) puts("negative cycle");
	else
	{
		int idx = dst;
		vector<int> res;
		printf("%d\n", dist[idx]);
		while (parent[idx] != -1)
		{
			res.push_back(idx);
			idx = parent[idx];
		}
		res.push_back(idx);
		for (int i = res.size() - 1; i >= 0; i--)
			printf("%d ", res[i] + 1);
		puts("");
	}
	return 0;
}
