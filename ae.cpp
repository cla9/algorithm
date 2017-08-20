#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<algorithm>
/*
DFS ���д� Ʈ���� �̿��Ͽ� A��° �������� �θ�� ���� ������ �����ϰ� ������ �������� ���� �湮���� ��忡�� ���� discover ��ȣ�� ���� discover ��ȣ���� Ŭ ��� �������� �˴ϴ�.
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