#include <iostream>
#include <queue>
#pragma warning (disable : 4996)
using namespace std;

struct frame {
	int row;
	int col;
};

int n, m;
int dirRow[4] = { 0, 1, 0, -1 };
int dirCol[4] = { 1, 0, -1 ,0 };
static int iceberg[301][301];
static int meltberg[301][301];
static bool visit[301][301];

void input() {
	scanf(" %d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) 
			scanf(" %d", &iceberg[i][j]);
	}
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			meltberg[i][j] = 0;
			visit[i][j] = false;
		}
	}
}

void bfs(int sRow, int sCol) {
	queue<frame> q;
	q.push({sRow, sCol});
	visit[sRow][sCol] = true;

	while (!q.empty()) {
		int row = q.front().row;
		int col = q.front().col;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nextRow = row + dirRow[i];
			int nextCol = col + dirCol[i];

			if (!visit[nextRow][nextCol] && nextRow >= 0 && nextCol >= 0 && nextRow < n && nextCol < m && iceberg[nextRow][nextCol] > 0) {
				visit[nextRow][nextCol] = true;
				q.push({ nextRow, nextCol });
			}
		}
	}
}

int melting(int row, int col) {
	int count = 0;
	for (int i = 0; i < 4; i++) 
		if (iceberg[row + dirRow[i]][col + dirCol[i]] == 0) count++;

	return count;
}

void after_year() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (iceberg[i][j] > 0) {
				meltberg[i][j] = iceberg[i][j] - melting(i, j);
				meltberg[i][j] = meltberg[i][j] < 0 ? 0 : meltberg[i][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			iceberg[i][j] = meltberg[i][j];
	}
}

int main() {
	input();
	
	int year = 0;
	int land = 0;
	while (1) {
		init();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (iceberg[i][j] > 0 && !visit[i][j]) {
					land++;
					bfs(i, j);
				}
			}
		}
		if (land >= 2) break;
		if (land == 0) {
			putchar('0');
			return 0;
		}

		after_year();
		year++;
		land = 0;
	}
	printf("%d", year);
}