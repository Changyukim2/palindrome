
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct Stacktype {
	char stack[MAX_SIZE];
	int top;
}Stacktype;

void Stack_init(Stacktype* s) {
	s->top = -1;
}

void Stack_push(Stacktype* s, char item) {
	s->stack[++(s->top)] = item;
	return;
}

bool is_empty(Stacktype* s) {
	return s->top == -1;
}

char Stack_pop(Stacktype* s) {
	char t = s->stack[s->top];
	s->stack[s->top] = 0;
	s->top--;
	return t;
}

int main(void) {

	printf("문자열을 입력하시오 : ");
	char input[MAX_SIZE];
	scanf_s("%[^\n]s", input,sizeof(input));

	Stacktype s;
	Stack_init(&s);
	int i = 0;
	while (1) {
		while (input[i] != NULL) {
			if ('a' <= input[i] && input[i] <= 'z')
				Stack_push(&s, input[i]);
			else if ('A' <= input[i] && input[i] <= 'Z')
				Stack_push(&s, input[i] - ('A' - 'a'));
			i++;
		}
		bool flag = true;
		i = 0;
		while (input[i] != NULL) {
			if ('a' <= input[i] && input[i] <= 'z') {
				if (Stack_pop(&s) != input[i]) {
					flag = false;
					break;
				}
			}
			else if ('A' <= input[i] && input[i] <= 'Z') {
				if (Stack_pop(&s) != (input[i] - ('A' - 'a'))) {
					flag = false;
					break;
				}
			}
			i++;
		}
		if (flag)
			printf("회문입니다.\n\n");
		else
			printf("회문이아닙니다.\n\n");
		printf("계속 입력하시겠습니까? yes/no: ");
		char a[3];
		scanf_s("%s",a,sizeof(a));
		if (a == 'yes')
		{
			continue;
		}
		else
			break;
	}
	
}