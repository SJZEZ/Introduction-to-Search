
#include <cstdio>

int n, m;

int steps;
int path_x[50];
int path_y[50];

void print_answer() {
	printf("%d ", steps);

	for (int i = 1; i <= steps; ++i)
		printf("(%d,%d) ", path_x[i], path_y[i]);

	printf("\n");
}

const int move[4][2] = {
	{ +1, +2 },
	{ +1, -2 },
	{ +2, +1 },
	{ +2, -1 }
};

void search(int x, int y) {
	++steps;
	path_x[steps] = x;
	path_y[steps] = y;

	if (x == n && y == m)
		print_answer();
	else {
		for (int i = 0; i < 4; ++i) {
			int a = x + move[i][0];
			int b = y + move[i][1];

			if (a < 1 || a > n)continue;
			if (b < 1 || b > m)continue;

			search(a, b);
		}
	}

	path_x[steps] = 0;
	path_y[steps] = 0;
	--steps;
}

int main() {
	scanf("%d%d", &n, &m);

	search(1, 1);
}
