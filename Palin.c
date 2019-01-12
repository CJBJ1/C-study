#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(char* s) {
	int answer = 0;
	int i = 0, n = 0, j = 0;
	int p1, p2;
	bool jud= true;
	int max=0;

	
	n = strlen(s);
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	for (i = 0; i < n-1; i++) {
		if (answer >= n - 1)
			break;
		for (j = i+1; j <= n-1; j++) {
			if (s[i] == s [j]) {
				p1 = i;
				p2 = j;
				for (int k=0; k <= ((p2 - p1)-1 / 2) ; k++) {
					if (s[p1+k] != s[p2 -k]) {
						jud = false;
						break;
					}
				}
				if (jud == true) {
					answer = (answer > (p2 - p1) + 1) ? answer : (p2 - p1) + 1;
				}
				jud = true;
			}
		}
	}
	return answer;
}
