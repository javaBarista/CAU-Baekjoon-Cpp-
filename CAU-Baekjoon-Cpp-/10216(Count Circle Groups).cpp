#include <iostream>
#include <vector>
#include <cmath> //백준에서 sqrt 쓸때
#include <cstring> //백준에서 memset쓸때 string은 안됨 ㅉ
#pragma warning (disable : 4996)
using namespace std;

vector<vector <int>> v;
int n;
static bool visit[3001];
static int camp[3001][3];

void dfs(int start) {
	visit[start] = true;

	for (int i = 0; i < v[start].size(); i++) {
		int cur = v[start][i];
		if (!visit[cur]) dfs(cur);
	}
}

int main() {
	int t;
	scanf(" %d", &t);

	while (t--) {
		scanf(" %d", &n);
		v.clear();
		v.resize(n);
		memset(visit, false, sizeof(visit));

		for (int i = 0; i < n; i++) 
			scanf(" %d %d %d", &camp[i][0], &camp[i][1], &camp[i][2]);
		
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int x = camp[i][0] - camp[j][0];
				int y = camp[i][1] - camp[j][1];
				double r = (double)(camp[i][2] + camp[j][2]);
				double d = sqrt((x * x) + (y * y));

				if (d <= r) {
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}

		int count = 0;
		for (int i = 0; i < n; i++) {
			if (!visit[i]) {
				count++;
				for (int j = 0; j < v[i].size(); j++) 
					dfs(v[i][j]);	
			}
		}

		printf("%d\n", count);
	}
}