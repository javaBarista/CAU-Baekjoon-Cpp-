#include <iostream>
#include <deque>
#pragma warning (disable : 4996)
using namespace std;

deque<bool> gear[4];

void init() {
	for (int i = 0; i < 4; i++) {
		char c;
		for (int j = 0; j < 8; j++) {
			scanf(" %c", &c);
			if (c == '1') gear[i].push_back(true);
			else gear[i].push_back(false);
		}
	}
}

void rolling(int i, int dir) {
	int tmp;
	if (dir == -1) {
		tmp = gear[i].front();
		gear[i].pop_front();
		gear[i].push_back(tmp);
	}
	else if (dir == 1){
		tmp = gear[i].back();
		gear[i].pop_back();
		gear[i].push_front(tmp);
	}
	else return;
}

int main() {
	init();
	int k;
	scanf(" %d", &k);

	while (k--) {
		int i, d;
		scanf(" %d %d", &i, &d);

		int dir[4];
		dir[i - 1] = d;

		for (int z = i; z < 4; z++) {
			dir[z] = (gear[z - 1][2] ^ gear[z][6]);
			if (dir[z] == 0) {
				for (int a = z + 1; a < 4; a++) dir[a] = 0;
				break;
			}
			dir[z] = dir[z - 1] == 1 ? -1 : 1;
		}
		for (int z = i - 2; z >= 0; z--) {
			dir[z] = (gear[z][2] ^ gear[z + 1][6]);
			if (dir[z] == 0) {
				for (int a = z - 1; a >= 0; a--) dir[a] = 0;
				break;
			}
			dir[z] = dir[z + 1] == 1 ? -1 : 1;
		}

		for (int z = 0; z < 4; z++) rolling(z, dir[z]);
	}

	int sum = 0;
	for (int i = 0; i < 4; i++) 
		if (gear[i][0]) sum += (1 << i);
	
	printf("%d", sum);
}