#include <cstdio>

int n, m, like[20][20], total;

bool used[20];

void search(int now) {
	if (now > n) {
		++total;
		return;
	}

	for (int i = 1; i <= m; ++i)
		if (like[now][i] && used[i] == false) {
			used[i] = true;
			search(now + 1);
			used[i] = false;
		}
}

int main() {
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf("%d", &like[i][j]);

	search(1);

	printf("%d\n", total);
}