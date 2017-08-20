#pragma warning(disable:4996)
#include<vector>
#include<iostream>
#include<algorithm>
/*
3 3
1 2 1
2 3 2
1 3 3


->3
*/

using namespace std;

vector<int> set;

int find(int _v)
{
	if (set[_v] < 0) return _v;
	else return set[_v] = find(set[_v]);
}

bool merge(int v1, int v2)
{
	v1 = find(v1);
	v2 = find(v2);
	if (v1 == v2) return false;
	set[v1] += set[v2];
	set[v2] = v1;
	return true;
}

class Edge
{
public:
	int s, e, w;
public:
	Edge(int _s = 0, int _e = 0, int _w = 0) :s(_s), e(_e), w(_w){}
	bool operator<(const Edge & e) const{ return w < e.w; }
};

int main()
{
	vector<Edge> graph;
	int nV, nE;
	scanf("%d %d", &nV, &nE);
	graph.resize(nV);
	set.resize(nV);
	fill(set.begin(), set.end(), -1);
	for (int i = 0; i < nE; i++)
	{
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);
		s--; e--;
		graph[i] = Edge(s, e, w);
	}

	sort(graph.begin(), graph.end());
	int numEdges = 0, sum = 0;
	for (int i = 0; i < nE; i++)
	{
		if (merge(graph[i].s, graph[i].e))
		{
			sum += graph[i].w;
			if (++numEdges == nV - 1) break;
		}
	}
	printf("%d\n", sum);
	return 0;
}