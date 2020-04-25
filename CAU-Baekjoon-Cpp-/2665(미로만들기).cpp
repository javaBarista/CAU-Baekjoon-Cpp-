#include <iostream>
#include <queue>
#pragma warning (disable : 4996)
using namespace std;

struct frame {
	int row;
	int col;
};
int n;
static bool maze[50][50];
static int visit[50][50];

void init() {
	scanf(" %d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			scanf(" %c", &c);
			maze[i][j] = c == '1' ? true : false;
			visit[i][j] = 987654321;
		}
	}
}

void bfs() {
	int dir[4] = {1, 0, -1 ,0};

	queue<frame> q;
	q.push({ 0, 0 });
	visit[0][0] = 0;

	while (!q.empty()) {
		int row = q.front().row;
		int col = q.front().col;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_row = row + dir[i];
			int next_col = col + dir[3 - i];
			if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < n) {
				if (maze[next_row][next_col]) {
					if (visit[next_row][next_col] > visit[row][col]) {
						visit[next_row][next_col] = visit[row][col];
						q.push({ next_row, next_col });
					}
				}
				else {
					if (visit[next_row][next_col] > visit[row][col] + 1) {
						visit[next_row][next_col] = visit[row][col] + 1;
						q.push({ next_row, next_col });
					}
				}
			}
		}
	}
}

int main() {
	init();
	bfs();
	printf("%d", visit[n - 1][n - 1]);
}