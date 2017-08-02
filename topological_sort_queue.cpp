#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<queue>
/*
3 2
1 3
2 3

ans) 
1 2 3
2 1 3

4 2
4 2
3 1

ans)
4 2 3 1
4 3 2 1

3 3
1 2
2 3
3 1

ans)
cycle
*/
using namespace std;
int main()
{
	int nV, nE;
	scanf("%d %d", &nV, &nE);
	vector<vector<pair<int, int>>> graph(nV);
	vector<int> inDegree(nV,0);
	vector<int> res(nV,0);
	queue<int> q;

	for (int i = 0; i < nE; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		s--; e--;
		graph[s].push_back(make_pair(e, 1));
		inDegree[e]++;
	}
	
	for (int i = 0; i < nV; i++)
		if (!inDegree[i])
			q.push(i);
	
	bool isCycle = false;
	for (int i = 0; i < nV; i++)
	{
		if (q.empty())
		{
			isCycle = true;
			break;
		}
		int curr = q.front(); 
		q.pop();
		res[i] = curr;
		for (pair<int, int> p : graph[curr])
		{
			int next = p.first;
			--inDegree[next];
			if (!inDegree[next])
				q.push(next);
		}
	}
	if (isCycle)
		puts("cycle");
	else
	{
		for (int i = 0; i < nV; i++)
			printf("%d ", res[i] + 1);
		puts("");
	}
	return 0;
}