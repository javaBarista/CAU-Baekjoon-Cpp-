#include <iostream>
#include <vector>
#include <queue>
#pragma warning (disable : 4996)
using namespace std;

int n, m;
bool visit[101];
vector<vector<int>> adj;

void init() {
	int n, m;
	scanf(" %d", &n);
	adj.resize(n + 1);
	scanf(" %d", &m);

	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf(" %d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}

int bfs() {
	queue<int> q;
	q.push(1);
	visit[1] = true;
	
	int count = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < adj[cur].size(); i++) {
			int node = adj[cur][i];

			if (!visit[node]) {
				visit[node] = true;
				q.push(node);
				count++;
			}
		}
	}

	return count;
}

int main() {
	init();
	printf("%d", bfs());
}