#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs(vector < vector<pair<int, int>> > & vecs, vector<bool> & visit, int i)
{
	queue<int> q;
	q.push(i);
	visit[i] = true;
	while (!q.empty())
	{
		int j = q.front();
		q.pop();
		cout << j << " ";

		for (pair<int, int> p : vecs[j])
		{
			if (!visit[p.first])
			{
				q.push(p.first);
				visit[p.first] = true;
			}
		}
	}
}

int main()
{
	vector< vector<pair<int,int>> > vecs;
	int nV = 6, nE = 8;
	vector<bool> visit;
	visit.resize(nV + 1);
	vecs.resize(nV + 1);
	fill(visit.begin(), visit.end(), false);
	for (int i = 0; i < nE; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;
		vecs[s].push_back(make_pair(e, w));
		vecs[e].push_back(make_pair(s, w));
	}
	

	bfs(vecs, visit, 1);
	return 0;
}