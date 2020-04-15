#include <iostream>
#include <queue>
#pragma warning(disable : 4996)
using namespace std;
#define max 100001

int dp[max];
static int k;

int bfs(int start) {
	queue<int> q;
	q.push(start);
	dp[start] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		
		if (cur == k) return dp[cur] - 1;

		int twice = cur << 1;
		if (twice < max && dp[twice] == 0) {
			dp[twice] = dp[cur] + 1;
			q.push(twice);
		}
		if (cur + 1 < max && dp[cur + 1] == 0) {
			dp[cur + 1] = dp[cur] + 1;
			q.push(cur + 1);
		}
		if (cur - 1 >= 0 && dp[cur - 1] == 0) {
			dp[cur - 1] = dp[cur] + 1;
			q.push(cur - 1);
		}
	}
}

int main() {
	int n;
	scanf(" %d %d", &n, &k);
	printf("%d", bfs(n));
}