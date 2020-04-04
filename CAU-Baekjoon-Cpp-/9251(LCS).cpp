#include <iostream>
#include <string>
#pragma warning (disable : 4996)
using namespace std;

static int lcs[1001][1001];

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	string str1 = '0' + s1;
	string str2 = '0' + s2;

	for (int i = 0; i < str1.size(); i++) {
		for (int j = 0; j < str2.size(); j++) {
			if (i == 0 || j == 0) {
				lcs[i][j] = 0;
				continue;
			}
			if (str1[i] == str2[j]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else lcs[i][j] = lcs[i - 1][j] > lcs[i][j - 1] ? lcs[i - 1][j] : lcs[i][j - 1];
		}
	}

	printf("%d", lcs[s1.size()][s2.size()]);
}