#include <iostream>

#pragma warning (disable : 4996)
using namespace std;

int r, c;
static int cnt;

void visit(int size, int curRow, int curCol) {
	if (size == 2) {
		if (curRow == r && curCol == c) {
			printf("%d", cnt);
			return;
		}
		cnt++;
		if (curRow == r && curCol + 1 == c) {
			printf("%d", cnt);
			return;
		}
		cnt++;
		if (curRow + 1 == r && curCol == c) {
			printf("%d", cnt);
			return;
		}
		cnt++;
		if (curRow + 1 == r && curCol + 1 == c) {
			printf("%d", cnt);
			return;
		}
		cnt++;
		return;
	}
	visit(size >> 1, curRow, curCol);
	visit(size >> 1, curRow, curCol + (size >> 1));
	visit(size >> 1, curRow + (size >> 1), curCol);
	visit(size >> 1, curRow + (size >> 1), curCol + (size >> 1));
}


int main() {
	int n;
	scanf(" %d %d %d", &n, &r, &c);

	visit(1 << n, 0, 0);
}