#include <iostream>
#include <vector>
#include <queue>
#pragma warning(disable : 4996)
using namespace std;

int m, x, y;
vector<vector<int>> adj;
static int visit[101];

void init() {
	int n;
	scanf(" %d", &n);
	adj.resize(n + 1);

	scanf(" %d %d", &x, &y);
	scanf(" %d", &m);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf(" %d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}

int bfs() {
	queue<int> q;
	q.push(x);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == y) return visit[cur];
		
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i];

			if (!visit[next]) {
				visit[next] = visit[cur] + 1;
				q.push(next);
			}
		}
	}
	return -1;
}

int main() {
	init();
	printf("%d", bfs());
}