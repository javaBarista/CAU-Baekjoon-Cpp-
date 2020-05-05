#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable : 4996)
using namespace std;

int n;
vector<int> v;

void init() {
	scanf(" %d", &n);
	v.resize(n);
	for (int i = 0; i < n; i++) 
		scanf(" %d", &v[i]);
	
	sort(v.begin(), v.end());

	for (int i = 1; i < n; i++)
		v[i] += v[i - 1];
}

int main() {
	init();
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += v[i];
	printf("%d", sum);
}