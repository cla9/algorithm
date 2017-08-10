#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<queue>
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

´ä
8
1 3 5
*/
#define INF static_cast<int>(2e9)
using namespace std;
typedef pair<int, int> P;
int main()
{
	int nV, nE, src, dst;
	scanf("%d %d %d %d", &nV, &nE, &src, &dst);
	src--; dst--;
	vector<vector<P>> graph(nV);
	vector<bool> visited(nV, false);
	vector<int> parent(nV, -1);
	vector<int> dist(nV, INF);

	for (int i = 0; i < nE; i++)
	{
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);
		s--; e--;
		graph[s].push_back(make_pair(e, w));
	}
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push(make_pair(0, src));
	dist[src] = 0;
	while (!pq.empty())
	{
		int curr = pq.top().second;
		pq.pop();
		if (visited[curr]) continue;
		visited[curr] = true;
		for (P & p : graph[curr])
		{
			int next = p.first;
			int nextd = p.second;
			if (!visited[next] && dist[next] > dist[curr] + nextd)
			{
				dist[next] = dist[curr] + nextd;
				parent[next] = curr;
				pq.push(make_pair(dist[next], next));
			}
		}
	}
	int idx = dst;
	printf("%d\n", dist[idx]);
	vector<int> res;
	while (parent[idx] != -1)
	{
		res.push_back(idx);
		idx = parent[idx];
	}
	res.push_back(idx);
	for (int i = res.size() - 1; i >= 0; i--)
		printf("%d ", res[i] + 1);
	puts("");
	return 0;
}