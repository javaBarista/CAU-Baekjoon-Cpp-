#include <iostream>
#include <string>
#include <stack>
#pragma warning (disable : 4996)
using namespace std;

static int lcs[1001][1001];

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	string str1 = '0' + s1;
	string str2 = '0' + s2;

	int len1 = s1.size();
	int len2 = s2.size();

	for (int i = 0; i <= len1; i++) {
		for (int j = 0; j <= len2; j++) {
			if (i == 0 || j == 0) {
				lcs[i][j] = 0;
				continue;
			}
			if (str1[i] == str2[j]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else lcs[i][j] = lcs[i - 1][j] > lcs[i][j - 1] ? lcs[i - 1][j] : lcs[i][j - 1];
		}
	}
	printf("%d\n", lcs[len1][len2]);

	stack<int> stk;
	while (lcs[len1][len2]) {
		int &cur = lcs[len1][len2];
	
		if (cur == lcs[len1 - 1][len2]) len1--;
		else if (cur == lcs[len1][len2 - 1]) len2--;
		else if (cur - 1 == lcs[len1 - 1][len2 - 1]) {
			stk.push(len1--);
			len2--;
		}
	}
	
	while (!stk.empty()) {
		putchar(str1[stk.top()]);
		stk.pop();
	}
}