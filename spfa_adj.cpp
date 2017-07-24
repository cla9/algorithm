#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;
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

int main()
{
	vector<vector<pair<int, int>>> graph;
	vector<int> parent;
	vector<int> dist;
	vector<int> uptCnt;
	vector<bool> isInQueue;
	
	int nV, nE;
	int src, dst;
	scanf("%d %d", &nV, &nE);
	scanf("%d %d", &src, &dst);
	graph.resize(nV);
	uptCnt.resize(nV);
	dist.resize(nV);
	parent.resize(nV);
	isInQueue.resize(nV);

	fill(dist.begin(), dist.end(), INF);
	fill(parent.begin(), parent.end(), -1);
	fill(isInQueue.begin(), isInQueue.end(), false);
	fill(uptCnt.begin(), uptCnt.end(), 0);
	
	for (int i = 0; i < nE; i++)
	{
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);
		s--; e--;
		graph[s].push_back(make_pair(e, w));
	}


	src--;
	dist[src] = 0;

	queue<int> q;
	q.push(src);
	isInQueue[src] = true;

	bool mCycle = false;
	int qCnt = 0;
	
	while (!q.empty() && !mCycle)
	{
		int curr = q.front(); q.pop();
		isInQueue[curr] = false;

		for (int i = 0; i < graph[curr].size(); i++)
		{
			int next = graph[curr][i].first;
			int nextd = graph[curr][i].second;
			if (dist[next] > dist[curr] + nextd)
			{
				dist[next] = dist[curr] + nextd;
				parent[next] = curr;
				uptCnt[next]++;
				if (uptCnt[next] == nV)
				{
					mCycle = true;
					break;
				}
				if (!isInQueue[next])
				{
					isInQueue[next] = true;
					q.push(next);
				}
			}
		}
	}
	
	if (mCycle) puts("negative cycle");
	else
	{
		int idx = dst - 1;
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
