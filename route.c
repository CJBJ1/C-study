#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Point {
	int x;
	int y;
}Point;

typedef struct _Check {
	Point p;
	char dir;
}Check;

int setCheck(Check pc[],Point p, char dir,int n) {
	int i = 0;
	for (i = 0; i < n; i++) {
		if ((pc + i)->p.x == p.x && (pc + i)->p.y == p.y) {
			if ((pc + i)->dir == dir) {
				return 0;
			}
		}
	}
	(pc+n)->p = p;
	(pc + n)->dir = dir;
	return 1;
}

int solution(char* dirs)
{
	int i = 0;
	int answer = 0;
	Point p = { 0,0 };
	Check a[1000];

	while (*dirs != NULL) {
		switch (*dirs) {
		case 'U':
			if (p.y == 5)
				break;
			if (setCheck(a, p, 'U', i)) {
				i++;
				(p.y)++;
				setCheck(a, p, 'D', i++);
				answer++;
				break;
			}
			else {
				(p.y)++;
				break;
			}
		case 'D':
			if (p.y == -5)
				break;
			if (setCheck(a, p, 'D', i)) {
				i++;
				(p.y)--;
				setCheck(a, p, 'U', i++);
				answer++;
				break;
			}
			else {
				(p.y)--;
				break;
			}
		case 'R':
			if (p.x == 5)
				break;
			if (setCheck(a, p, 'R', i)) {
				i++;
				(p.x)++;
				setCheck(a, p, 'L', i++);
				answer++;
				break;
			}
			else {
				(p.x)++;
				break;
			}
		case 'L':
			if (p.x == -5)
				break;
			if (setCheck(a, p, 'L', i)) {
				i++;
				(p.x)--;
				setCheck(a, p, 'R', i++);
				answer++;
				break;
			}
			else {
				(p.x)--;
				break;
			}
		}

		*dirs++;
	}

	return answer;
}
