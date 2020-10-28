#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	for (int i = 1; i <= 3; i++){
		char password[20] = "159357";
		char input[20] = { 0 };
		printf("ÇëÊäÈëÃÜÂë£º\n");
		scanf("%s", &input);
		if (strcmp(input, password) == 0){
			printf("µÇÂ½³É¹¦\n");
			break;
		}
		else{
			printf("µÇÂ½Ê§°Ü\n");
		}
	}
	system("pasue");
	return 0;
}