#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int menu(){
	printf("-------------------------\n");
	printf("1.开始游戏\n");
	printf("0.退出游戏\n");
	printf("-------------------------\n");
	int choice = 0;
	printf("请输入你的选择：");
	scanf("%d", &choice);
	return choice;
}

void game(){
	int toGuess = rand() % 100 + 1;
	while (1){
		int input = 0;
		printf("请输入数字:");
		scanf("%d", &input);
		if (input > toGuess){
			printf("大了\n");
		}
		else if (input < toGuess){
			printf("小了\n");
		}
		else{
			printf("猜对了\n");
			break;
		}
	}
}

int main()
{
	srand(time(0));
	int choice = menu();
	while (1){
		if (choice == 1){
			game();
		}
		else if (choice == 0){
			printf("退出游戏\n");
			break;
		}
		else{
			printf("输入错误\n");
		}  
	}
	system("pause");
	return 0;
}