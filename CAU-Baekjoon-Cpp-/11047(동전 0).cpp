#include <iostream>
#include <vector>
#pragma warning (disable : 4996)
using namespace std;

int n, k;
bool isclear = false;
static int coin[10];

void init() {
	scanf(" %d %d", &n, &k);
	for (int i = 0; i < n; i++) scanf(" %d", &coin[i]);
}

int main() {
	init();
	int count = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (k >= coin[i]) {
			count += (k / coin[i]);
			k %= coin[i];
		}
	}
	printf("%d", count);
}