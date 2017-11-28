#include <cstdio>

int n, m, val[20][20], max_sum;

void search(int now, int sum, int used) {
	if (max_sum < sum)
		max_sum = sum;
	
	if (now > n)
		return;

	for (int i = 1; i <= m; ++i)
		if (!((used >> i) & 1))
			search(now + 1, sum + val[now][i], used | (1 << i));
}

int main() {
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf("%d", &val[i][j]);

	search(1, 0, 0);

	printf("%d\n", max_sum);
}