#include <iostream>

#pragma warning (disable : 4996)
using namespace std;

static int n, cnt;
static bool pipe[16][16];

void init() {
	scanf(" %d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) scanf(" %d", &pipe[i][j]);
	}
}

void dfs(int row, int col, int before_dir) {
	if (row == n - 1 && col == n - 1) {
		cnt++;
		return;
	}
	if (row >= n || col >= n) return;

	if (!pipe[row + 1][col + 1] && !pipe[row + 1][col] && !pipe[row][col + 1]) dfs(row + 1, col + 1, 0);
	if (before_dir == -1 || before_dir == 0) {
		if (!pipe[row][col + 1]) dfs(row, col + 1, -1);
	}
	if (before_dir == 0 || before_dir == 1) {
		if (!pipe[row + 1][col]) dfs(row + 1, col, 1);
	}
}

int main() {
	init();
	dfs(0, 1, -1);
	printf("%d", cnt);
}