#include <iostream>
#pragma warning (disable : 4996)
using namespace std;

int n, s, cnt;
static int num[21];

void init() {
	scanf(" %d %d", &n, &s);
	for (int i = 0; i < n; i++) scanf(" %d", &num[i]);
}

void dfs(int i, int sum) {
	if (i == n) return;
	if (sum + num[i] == s) cnt++;

	dfs(i + 1, sum);
	dfs(i + 1, sum + num[i]);
}

int main() {
	init();
	dfs(0, 0);
	printf("%d", cnt);
}