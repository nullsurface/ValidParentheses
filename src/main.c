#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isValid(char*);
int correct_close(char*, int, char);
int isopen(char);

int main() {
    char* str = "";
    char* str1 = "[]";
    char* str2 = "({})";
    char* str3 = "{]";
    char* str4 = "([{})]";
    char* str5 = "[[";
    char* str6 = "{";
    char* str7 = "[][][]{()}{}()";
    char* str8 = "]";

    printf("%d\n", isValid(str));
    printf("%d\n", isValid(str1));
    printf("%d\n", isValid(str2));
    printf("%d\n", isValid(str3));
    printf("%d\n", isValid(str4));
    printf("%d\n", isValid(str5));
    printf("%d\n", isValid(str6));
    printf("%d\n", isValid(str7));
    printf("%d\n", isValid(str8));



    return 0;
}

int isValid(char* s) {
    char curr;
    int opened = 0;
    char* open = malloc(sizeof(char) * strlen(s));

    for (int i = 0; i < strlen(s); i++) {
	curr = s[i];
		
	if (isopen(curr)) {
	    open[opened] = curr;
	    opened++;
	} else {
	    if (correct_close(open, opened, curr))
		opened--;
	    else
		return 0;
	}
    }

    free (open);
    if (opened != 0)
	return 0;

    return 1;
}

int isopen(char c) {
    if (c == '(' || c == '[' || c == '{')
	return 1;

    return 0;
}

int correct_close(char* open, int opened, char curr) {
    if (opened < 1)
	return 0;

    switch (curr) {
	case ')':
	    return open[opened - 1] == '(';
	    break;
	case ']':
	    return open[opened - 1] == '[';
	    break;
	case '}':
	    return open[opened - 1] == '{';
	    break;
	}

    return 0;
}
