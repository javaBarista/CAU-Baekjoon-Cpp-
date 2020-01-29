#include <iostream>

#pragma warning (disable : 4996)
using namespace std;

static char input[51][51];
static bool compare[51][51];
int n, m, res;

int main() {
	scanf(" %d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &input[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char temp;
			scanf(" %c", &temp);
			compare[i][j] = input[i][j] != temp ? true : false;
		}
	}

	if (n < 3 || m < 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (compare[i][j]) {
					printf("-1");
					return 0;
				}
			}
		}
		printf("0");
		return 0;
	}

	for (int i = 0; i <= n - 3; i++) {
		for (int j = 0; j <= m - 3; j++) {
			if (compare[i][j]) {
				for (int y = 0; y < 3; y++) {
					for (int x = 0; x < 3; x++) {
						compare[i + y][j + x] = !compare[i + y][j + x];
					}
				}
				res++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (compare[i][j]) {
				printf("-1");
				return 0;
			}
		}
	}

	printf("%d", res);
}