#include <cstdio>

bool is_prime(int x) {
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0)
			return false;
	
	return true;
}

int ans[25], n;

void print_answer() {
	for (int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	
	printf("\n");
}

bool used[25], isp[50];

void search(int now) {
	if (now > n) {
		if (isp[ans[1] + ans[20]])
			print_answer();
		
		return;
	}
	
	for (int i = 1; i <= n; ++i)
		if (used[i] == false && (now == 1 || isp[ans[now - 1] + i])) {
				ans[now] = i, used[i] = true;
				search(now + 1);
				ans[now] = 0, used[i] = false;
			}
}

int main() {
	for (int i = 2; i <= 40; ++i)
		isp[i] = is_prime(i);

	ans[1] = 1, used[1] = true;

	scanf("%d", &n);
	
	search(2);
}