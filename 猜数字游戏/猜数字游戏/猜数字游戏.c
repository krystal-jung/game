#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int menu(){
	printf("-------------------------\n");
	printf("1.��ʼ��Ϸ\n");
	printf("0.�˳���Ϸ\n");
	printf("-------------------------\n");
	int choice = 0;
	printf("���������ѡ��");
	scanf("%d", &choice);
	return choice;
}

void game(){
	int toGuess = rand() % 100 + 1;
	while (1){
		int input = 0;
		printf("����������:");
		scanf("%d", &input);
		if (input > toGuess){
			printf("����\n");
		}
		else if (input < toGuess){
			printf("С��\n");
		}
		else{
			printf("�¶���\n");
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
			printf("�˳���Ϸ\n");
			break;
		}
		else{
			printf("�������\n");
		}  
	}
	system("pause");
	return 0;
}