#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long

void prims(vector<pair<int, int>> graph[], int source, int node)
{
	int cost = 0; bool f = false;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<bool> vis(node, false);
	pq.push({0, source});
	while (!pq.empty())
	{
		auto top = pq.top();
		pq.pop();
		int a = top.first;
		int b = top.second;
		if (!vis[b])
		{
			vis[b] = true;
			cost += a;
			for (auto u : graph[b])
			{
				int x = u.first;
				int y = u.second;
				if (!vis[x])
					pq.push({y, x});
			}
		}
	}
	for (int i = 1; i <= node; i++)
	{
		if (vis[i] == false)
		{
			cout << "IMPOSSIBLE";
			return;
		}
	}
	cout << cost;
}

main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

	int node, edge;
	cin >> node >> edge;
	vector<pair<int, int>> graph[node + 1];
	for (int i = 0; i < edge; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].pb({v, w});
		graph[v].pb({u, w});
	}
	prims(graph, 1, node);


	return 0;
}