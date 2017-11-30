#include <cstdio>

int n, m, val[20][20], max_sum, max_val[20];

bool used[20];

void search(int now, int sum) {
	if (max_sum < sum)
		max_sum = sum;
	
	if (now > n)
		return;

	if (max_sum >= sum + max_val[now])
		return;

	for (int i = 1; i <= m; ++i)
		if (used[i] == false) {
			used[i] = true;
			search(now + 1, sum + val[now][i]);
			used[i] = false;
		}

	search(now + 1, sum);
}

int main() {
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &val[i][j]);

			if (max_val[i] < val[i][j])
				max_val[i] = val[i][j];
		}

	search(1, 0);

	printf("%d\n", max_sum);
}
