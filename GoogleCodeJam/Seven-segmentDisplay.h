#include <stdio.h>
#include <cmath>
#include <list>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stdint.h>
#include <algorithm>
#include <queue>
#include <functional>
#include <iostream>
using namespace std;
typedef unsigned int uint;
uint digits[10] = {1111011, 1111111, 1110000, 1011111, 1011011, 110011, 1111001, 1101101, 110000, 1111110};

uint convert10to2(uint a) {
	uint bit = 1;
	uint b = 0;
	while (a) {
		if (a%10 == 1)
			b |= bit;
		a /= 10;
		bit <<= 1;
	}
	return b;
}

uint convert2to10(uint a) {
	uint bit = 1;
	uint b = 0;
	while (a) {
		if (a%2 == 1)
			b += bit;
		a /= 2;
		bit *= 10;
	}
	return b;
}

int check(vector<uint> lights, uint mask, int start) {
	int ledoff = 0;
	for (int i = 0; i < lights.size(); ++i) {
		int a = lights[i] & mask;
		int b = digits[(start+i)%10] & mask;
		if (a != b)
			return -1;
		ledoff |= (lights[i] ^ digits[(start+i)%10]);
	}
	return ledoff;
}

int main() {
	for (int i = 0; i < 10; ++i) {
		digits[i] = convert10to2(digits[i]);
	}
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		printf("Case #%d: ", t);
		int n; scanf("%d", &n);
		vector<uint> lights(n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &lights[i]);
			lights[i] = convert10to2(lights[i]);
		}
		int ledon = 0;
		for(int i = 0; i < n; ++i)
			ledon |= lights[i];
		
		int start;
		int result = -1;
		for (start = 0; start < 10; ++start) {
			int ledoff = check(lights, ledon, start);
			if (ledoff == -1)
				continue;
			int next = (start + n) % 10;
			int show1 = digits[next] & (~ledoff);
			int show2 = digits[next] & ledon;
			if (show1 != show2)
				goto ERROR;
			if (result == -1)
				result = show1;
			else if (result != show1)
				goto ERROR;
		}

		printf("%07d\n", convert2to10(result));
		continue;

ERROR:
		printf("ERROR!\n");
	}
}