#define _CRT_SECURE_NO_WARNINGS
#define MAX_ROW 9
#define MAX_COL 9
#define DEGAULT_SWEEP 10
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void init(char sweep[MAX_ROW][MAX_COL], char mineSweep[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			sweep[row][col] = '*';
			mineSweep[row][col] = '0';
		}
	}
	int n = DEGAULT_SWEEP;
	while (n>0){
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mineSweep[row][col] == '1'){
			continue;
		}
		mineSweep[row][col] = '1';
		n--;
	}
}
void printSweep(char sweep[MAX_ROW][MAX_COL]){
	printf("  |");
	for (int col = 0; col < MAX_COL; col++) {
		printf("%d ", col);
	}
	printf("\n");
	printf("--+------------------\n");
	for (int row = 0; row < MAX_ROW; row++) {
		printf(" %d|", row);
		for (int col = 0; col < MAX_COL; col++) {
			printf("%c ", sweep[row][col]);
		}
		printf("\n");
	}
}
void updatesweep(char sweep[MAX_ROW][MAX_COL],
	char mineSweep[MAX_ROW][MAX_COL], int row, int col) {
	int count = 0;
	for (int r = row - 1; r <= row + 1; r++) {
		for (int c = col - 1; c <= col + 1; c++) {
			if (r < 0 || r >= MAX_ROW
				|| c < 0 || c >= MAX_COL) {
				continue;
			}
			if (mineSweep[r][c] == '1') {
				count++;
			}
		}
	}
	
	sweep[row][col] = count + '0';
	printSweep(sweep);
}

char palyer(char sweep[MAX_ROW][MAX_COL], char mineSweep[MAX_ROW][MAX_COL]){
	
		int row = 0;
		int col = 0;
		while (1){
		printf("请输入地皮的坐标(row col):");
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL){
			printf("越界重输");
			continue;
		}
		if (sweep[row][col] != '*'){
			printf("翻开了重输入");
			continue;
		}
		if (mineSweep[row][col] == '1'){
			printf("游戏结束,你死了.\n");
			printSweep(mineSweep);
			break;
			return '0';
		}
			updatesweep(sweep, mineSweep, row, col);
	}
}

void game(){
	srand((unsigned int)time(0));
	int openedBlockCount = 0;
	char sweep[MAX_ROW][MAX_COL] = { 0 };
	char mineSweep[MAX_ROW][MAX_COL] = { 0 };
	init(sweep, mineSweep);
	while (1){
		printSweep(sweep);
		palyer(sweep, mineSweep);
		if (palyer(sweep, mineSweep) == '0'){
			break;
		}
		openedBlockCount++;
		if (openedBlockCount == MAX_ROW * MAX_COL - DEGAULT_SWEEP) {
			printf("游戏胜利!\n");
			printSweep(mineSweep);
			break;
		}
	}

}
int menu(){
	printf("--------------------------\n");
	printf("--------1.开始游戏--------\n");
	printf("--------0.结束游戏--------\n");
	printf("--------------------------\n");
	printf("请输入你的选择：");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
int main()
{
	while (1){
		int choice = menu();
		if (choice == 1){
			game();
			break;
		}
		else if (choice == 0){
			printf("已退出,byebye!\n");
			break;
		}
		else{
			printf("输入错误!");
			continue;
		}
	}
	system("pause");
	return 0;
}