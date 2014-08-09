#include <stdio.h>

int main() {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		int n; scanf("%d", &n);
		int a = 1, b = 0;
		for (unsigned bit_flat = 1 << 31; bit_flat > 0; bit_flat >>= 1) {
			
			int a2 = a*a + 5*b*b;
			int b2 = 2*a*b;
			a = a2 % 1000, b = b2 % 1000;

			if (bit_flat & n) {
				int a2 = 3*a + 5*b;
				int b2 = a + 3*b;
				a = a2 % 1000, b = b2 % 1000;
			}
		}

		printf("Case #%d: %03d\n", t, (2*a-1)%1000);
	}
	return 0;
}