#include <iostream>
#include <deque>
#pragma warning (disable : 4996)
using namespace std;

deque<bool> gear[1000];
static int t;

void init() {
	scanf(" %d", &t);
	for (int i = 0; i < t; i++) {
		char c;
		for (int j = 0; j < 8; j++) {
			scanf(" %c", &c);
			if (c == '1') gear[i].push_back(true);
			else gear[i].push_back(false);
		}
	}
}

void rotate(int i, int dir) {
	int tmp;
	if (dir == 1) {
		tmp = gear[i].back();
		gear[i].pop_back();
		gear[i].push_front(tmp);
	}
	else if (dir == -1) {
		tmp = gear[i].front();
		gear[i].pop_front();
		gear[i].push_back(tmp);
	}
	else return;
}

int main() {
	int m, index, d;
	init();
	scanf(" %d", &m);
	
	int dir[1000];
	while (m--) {
		scanf(" %d %d", &index, &d);
		dir[index - 1] = d;

		for (int i = index; i < t; i++) {
			dir[i] = gear[i - 1][2] ^ gear[i][6];
			if (dir[i] == 0) {
				for (int j = i + 1; j < t; j++) dir[j] = 0;
				break;
			}
			dir[i] = dir[i - 1] == 1 ? -1 : 1;
		}

		for (int i = index - 2; i >= 0; i--) {
			dir[i] = gear[i][2] ^ gear[i + 1][6];
			if (dir[i] == 0) {
				for (int j = i - 1; j >= 0; j--) dir[j] = 0;
				break;
			}
			dir[i] = dir[i + 1] == 1 ? -1 : 1;
		}

		for (int i = 0; i < t; i++) rotate(i, dir[i]);
	}

	int cnt = 0;
	for (int i = 0; i < t; i++) 
		if (gear[i][0]) cnt++;
	
	printf("%d", cnt);
}