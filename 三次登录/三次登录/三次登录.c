#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	for (int i = 1; i <= 3; i++){
		char password[20] = "159357";
		char input[20] = { 0 };
		printf("���������룺\n");
		scanf("%s", &input);
		if (strcmp(input, password) == 0){
			printf("��½�ɹ�\n");
			break;
		}
		else{
			printf("��½ʧ��\n");
		}
	}
	system("pasue");
	return 0;
}