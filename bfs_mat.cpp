#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs(vector<vector<int>> & vecs, vector<bool> & visit, int i)
{
	queue<int> q;
	q.push(i);
	while (!q.empty())
	{
		int j = q.front();
		q.pop();
		visit[j] = true;

		cout << j << " ";
		for (int k = 0; k < vecs[j].size(); k++)
		{
			if (!visit[k] && vecs[j][k] != 0)
			{
				q.push(k);
				visit[k] = true;
			}
		}
	}
}
int main()
{
	int nV = 6, nE = 8;
	vector<vector<int>> vecs;
	vector<bool> visit;
	vecs.resize(nV + 1);
	visit.resize(nV + 1);
	fill(visit.begin(), visit.end(), false);
	for (int i = 1; i <= nV; i++)
	{
		vecs[i].resize(nV + 1);
		fill(vecs[i].begin(), vecs[i].end(), 0);
	}
	for (int i = 0; i < nE; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;
		vecs[s][e] = vecs[e][s] = w;
	}
	bfs(vecs, visit, 1);
	return 0;
}