#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<algorithm>
/*
DFS 스패닝 트리를 이용하여 A번째 정점에서 부모로 가는 간선을 제외하고 나머지 간선에서 아직 방문안한 노드에서 얻어온 discover 번호가 나의 discover 번호보다 클 경우 단절선이 됩니다.
http://jason9319.tistory.com/119

7 8
1 4
4 5
5 1
1 6
6 7
2 7
7 3
2 3

2
1 6
6 7
*/
using namespace std;

vector<vector<int>> graph;
vector<pair<int, int>> bridge;
vector<int> order;
int num;

int dfs(int curr, int par)
{
	int ret, m;
	ret = order[curr] = ++num;
	for (int next : graph[curr])
	{
		if (next == par) continue;
		if (!order[next])
		{
			m = dfs(next, curr);
			ret = min(ret, m);
			if (m > order[curr]) bridge.push_back(make_pair(min(curr, next), max(curr, next)));
		}
		else
			ret = min(ret, order[next]);
	}
	return ret;
}
int main()
{
	int nV, nE;
	scanf("%d %d", &nV, &nE);
	graph.resize(nV);
	order.resize(nV);
	fill(order.begin(), order.end(), 0);
	for (int i = 0; i < nE; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		s--; e--;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	for (int i = 0; i < nV; i++)
	if (!order[i])
		dfs(i, i);
	sort(bridge.begin(), bridge.end());
	printf("%d\n", bridge.size());
	for (int i = 0; i < bridge.size(); i++)
		printf("%d %d\n", bridge[i].first + 1, bridge[i].second + 1);
	puts("");
	return 0;
}