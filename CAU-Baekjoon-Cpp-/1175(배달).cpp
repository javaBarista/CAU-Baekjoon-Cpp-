#include <iostream>
#include <queue>
#pragma warning (disable : 4996)
using namespace std;

struct frame {
	int row;
	int col;
	int count;
	int dir;
	bool findC;
	bool findD;
};

int n, m;
static char map[50][50];
static bool visit[50][50][5][2][2];

frame init() {
	int row;
	int col;
	int cnt = 0;
	scanf(" %d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'S') {
				row = i;
				col = j;
			}
			if (map[i][j] == 'C') {
				cnt++;
				if (cnt == 2) map[i][j] = 'D';
			}
		}
	}

	return { row, col, 0, 4, false, false };
}

int bfs(frame start) {
	int dir[4] = { 0, 1, 0, -1 };
	queue<frame> q;
	q.push(start);
	visit[start.row][start.col][start.dir][start.findC][start.findD] = true;

	while (!q.empty()) {
		int row = q.front().row;
		int col = q.front().col;
		int count = q.front().count;
		int before_dir = q.front().dir;
		bool findC = q.front().findC;
		bool findD = q.front().findD;
		q.pop();

		if (findC && findD) return count;

		for (int i = 0; i < 4; i++) {
			if (i != before_dir) {
				int next_row = row + dir[i];
				int next_col = col + dir[3 - i];
				bool isFindC = findC;
				bool isFindD = findD;

				if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m && !visit[next_row][next_col][i][findC][findD] && map[next_row][next_col] != '#') {
					if (map[next_row][next_col] == 'C') isFindC = true;
					if (map[next_row][next_col] == 'D') isFindD = true;

					visit[next_row][next_col][i][isFindC][isFindD] = true;
					q.push({ next_row, next_col, count + 1, i, isFindC, isFindD });
				}
			}
		}
	}

	return -1;
}

int main() {
	printf("%d", bfs(init()));
}