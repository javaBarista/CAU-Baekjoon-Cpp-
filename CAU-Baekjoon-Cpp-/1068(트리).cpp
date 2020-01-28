#include <iostream>
#include <vector>
#include <queue>

#pragma warning (disable : 4996)
using namespace std;

vector<int> tree[51];
queue<int> q;
int res;
bool visit[51];

void bfs(int root) {
	visit[root] = true;
	q.push(root);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		int child = 0;
		for (int i = 0; i < tree[cur].size(); i++) {
			int next = tree[cur][i];
			if (!visit[next]) {
				q.push(next);
				visit[next] = true;
				child++;
			}
		}

		if (child == 0) res++;
	}
}

int main() {
	int n, root, del;
	scanf(" %d", &n);

	for (int i = 0; i < n; i++) {
		int parent;
		scanf(" %d", &parent);
		if (parent == -1) root = i;
		else {
			tree[i].push_back(parent);
			tree[parent].push_back(i);
		}
	}
	scanf(" %d", &del);
	visit[del] = true;

	if (!visit[root]) bfs(root);

	printf("%d", res);
}