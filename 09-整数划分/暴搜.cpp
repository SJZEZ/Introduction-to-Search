#include <cstdio>

int n, m, total;

void search(int rem, int num, int lmt) {	// remain, number, limit
	if (rem == 0 && num == 0)
		++total;

	if (rem == 0 || num == 0)
		return;

	for (int i = lmt; i > 0; --i)
		if (i <= rem)
			search(rem - i, num - 1, i);
}

int main() {
	scanf("%d%d", &n, &m);

	search(n, m, n);

	printf("%d\n", total);
}