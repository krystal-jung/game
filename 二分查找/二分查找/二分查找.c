#include <stdio.h>
int main()
{
	char arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int tofind = 7;
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	while (left <= right){
		int mid = (left + right) / 2;
		if (tofind > arr[mid]){
			left = arr[mid] + 1;
		}
		else if (tofind < arr[mid]){
			right = arr[mid] - 1;
		}
		else{
			printf("�ҵ��ˣ��±��ǣ�%d\n", mid);
			break;
		}
	}
	if (left>right){
		printf("�Ҳ���");
	}
	system("pause");
	return 0;
}