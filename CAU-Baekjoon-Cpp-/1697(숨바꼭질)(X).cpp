#include <iostream>

#pragma warning(disable : 4996)
using namespace std;

int min_cnt = 987654321;
static int k;

void dfs(int cur, int cnt) {
	if (min_cnt < cnt) return;
	if (cur == k) {
		min_cnt = min_cnt > cnt ? cnt : min_cnt;
		return;
	}
	if(cur <= k / 2 && cur > 0) dfs(cur << 1, cnt + 1);
	dfs(cur + 1, cnt + 1);
	if(cur > 0) dfs(cur - 1, cnt + 1);
}

int main() {
	int n;
	scanf(" %d %d", &n, &k);

	dfs(n, 0);
	printf("%d", min_cnt);
}