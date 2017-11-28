#include <cstdio>

int total;

bool visit[10][10];

const int move[8][2] = {
	{ +1, +2 },
	{ +1, -2 },
	{ -1, +2 },
	{ -1, -2 },
	{ +2, +1 },
	{ +2, -1 },
	{ -2, +1 },
	{ -2, -1 },
};

void search(int x, int y, int now) {
	if (now == 25) {
		++total;
		return;
	}

	for (int i = 0; i < 8; ++i) {
		int a = x + move[i][0];
		int b = y + move[i][1];

		if (a < 1 || a > 5)continue;
		if (b < 1 || b > 5)continue;
		
		if (visit[a][b] == false) {
			visit[a][b] = true;
			search(a, b, now + 1);
			visit[a][b] = false;
		}
	}
}

int main() {
	visit[1][1] = true;

	search(1, 1, 1);

	printf("%d\n", total);
}