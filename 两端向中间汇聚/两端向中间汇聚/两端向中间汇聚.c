#include <stdio.h>
#include <string.h>
#include <windows.h>
int main()
{
	char arr1[] = "Hello Hidden.Blue";
	char arr2[] = "*****************";
	printf("%s\n", arr2);
	int left = 0;
	int right = strlen(arr2)-1;
	while (left <= right){
		Sleep(1000);
		system("cls");
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		left++;
		right--;
		printf("%s\n", arr2);
	}
	system("pause");
	return 0;
}