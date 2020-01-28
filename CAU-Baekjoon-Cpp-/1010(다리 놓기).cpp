#include <iostream>
#include <vector>
#include <cstring>

#pragma warning (disable : 4996)
using namespace std;

long long arr[30][30];
vector <int> ans;

int dp(int n, int k) {
	if (k == 0 || k == n) return 1;

	long long& ret = arr[n][k];

	if (ret != -1) return ret;

	ret = (dp(n - 1, k - 1) + dp(n - 1, k));
	return ret;
}

int main() {
	int m;
	scanf(" %d", &m);
	memset(arr, -1, sizeof(arr));
	int i = 0;
	while (m-- > 0) {
		int k, n;
		scanf(" %d %d", &k, &n);

		ans.push_back(dp(n, k));
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("%d\n", ans[i]);
	}
}