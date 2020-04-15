#include <iostream>
#include <queue>
#pragma warning (disable : 4996)
using namespace std;

struct frame {
	int row;
	int col;
};
int dir_row[4] = { 1, 0, -1, 0 };
int dir_col[4] = { 0, 1, 0 ,-1 };
queue<frame> q;
int m, n;
static int box[1001][1001];
static int dp[1001][1001];

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %d", &box[i][j]);
			dp[i][j] = -1;
			if (box[i][j] == 1) {
				q.push({ i,j });
				dp[i][j] = 0;
			}
		}
	}
}

int bfs() {
	while (!q.empty()) {
		int row = q.front().row;
		int col = q.front().col;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nRow = row + dir_row[i];
			int nCol = col + dir_col[i];
			
			if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && box[nRow][nCol] == 0 && dp[nRow][nCol] == -1) {
				dp[nRow][nCol] = dp[row][col] + 1;
				q.push({ nRow, nCol });
			}
		}
	}

	int day = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			day = dp[i][j] > day ? dp[i][j] : day;
			if (box[i][j] == 0 && dp[i][j] == -1) return - 1;
		}
	}
	return day;
}

int main() {
	scanf(" %d %d", &m, &n);
	init();
	printf("%d", bfs());
}