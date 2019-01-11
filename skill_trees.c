#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(char* skill, char* skill_trees[], size_t skill_trees_len) {
	int i = 0,j = 0, k = 0;
	int sk = 0;
	int answer = 0;
	char conv[26];
	bool exitOuterLoop = false;
	while (k!=skill_trees_len) {
		for (i = 0; i < strlen(skill_trees[k]); i++) {
			for (j = 0; j<strlen(skill); j++) {
				if (*(skill_trees[k] + i) == skill[j]) {
					if (sk == j) {
						sk++;
						continue;
					}
					else {
						printf("%s: 잘못된 스킬트리 입니다 %c보다 %c를 먼저 배워야 합니다.\n", skill_trees[k], skill[j],skill[j-1]);
						exitOuterLoop = true;
						break;
					}
				}
			}
			if (exitOuterLoop == true)
				break;
		}
		if (exitOuterLoop == false) {
			printf("%s: 올바른 스킬트리 입니다.\n", skill_trees[k]);
			answer++;
		}
		exitOuterLoop = false;
		sk = 0;
		k++;
	}
	return answer;
}