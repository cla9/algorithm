#include<iostream>
#include<deque>
#include<queue>
#include<functional>

using namespace std;
/*
3 3
1 2 1
2 3 2
1 3 3


->3
*/
template<typename T>
class Node
{
public:
	T v1;
	T v2;
	int w;
public:
	Node(T _v1 = 0, T _v2 = 0, int _w = 0) : v1(_v1), v2(_v2), w(_w){}
	bool operator>(const Node<T> & n)const { return w > n.w; }
};

class Set{
private:
	int * p;
	int n;
public:
	Set(int _n) :n(_n)
	{
		p = new int[n];
		fill(p, p + n, -1);
	}
	~Set(){ delete[] p; }
public:
	int Find(int _v)
	{
		if (p[_v] < 0) return _v;
		p[_v] = Find(p[_v]);
		return p[_v];
	}
	void Merge(int _v1, int _v2)
	{
		_v1 = Find(_v1);
		_v2 = Find(_v2);
		if (_v1 == _v2) return;
		p[_v1] += p[_v2];
		p[_v2] = _v1;
	}
};


int main()
{
	vector< vector<pair<int,int> > > vecs;
	priority_queue< Node<int>, deque< Node<int> >, greater< Node<int> > > pq;
	int nV, nE;

	cin >> nV >> nE;
	Set set(nV + 1);
	vecs.resize(nV + 1);

	int s, e, w;
	for (int i = 0; i < nE; i++)
	{
		cin >> s >> e >> w;
		vecs[s].push_back(make_pair(e, w));
	}

	for (int i = 0; i < vecs.size(); i++)
		for (pair<int, int> p : vecs[i])
			pq.push(Node<int>(i, p.first, p.second));	
	
	Node<int> p;
	int nEdge = 0;
	int sum = 0;
	while (!pq.empty() && nEdge < nV)
	{
		p = pq.top(); pq.pop();
		int i1 = set.Find(p.v1);
		int i2 = set.Find(p.v2);
		if (i1 != i2)
		{
			sum += p.w;
			nEdge++;
			set.Merge(i1, i2);
		}
	}
	cout << sum << endl;
	return 0;
}