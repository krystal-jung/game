#define _CRT_SECURE_NO_WARNINGS
#define MAX_ROW 9
#define MAX_COL 9
#define DIFFICULTY 10
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int menu(){
	printf("----------------------\n");
	printf("------1.开始游戏------\n");
	printf("------0.退出游戏------\n");
	printf("----------------------\n");
	int choice = 0;
	printf("请输入你的选择:");
	scanf("%d", &choice);
	return choice;
}
void init(char show[MAX_ROW][MAX_COL], char mine[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			show[row][col] = '*';
			mine[row][col] = '0';
		}
	}
	int n = DIFFICULTY;
	while (n>0){
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mine[row][col] == '1'){
			continue;
		}
		mine[row][col] = '1';
		n--;
	}
}
void printShow(char show[MAX_ROW][MAX_COL]){
	printf("  |");
	for (int col = 0; col < MAX_COL; col++) {
		printf("%d ", col);
	}
	printf("\n");
	printf("--+------------------\n");
	for (int row = 0; row < MAX_ROW; row++) {
		printf(" %d|", row);
		for (int col = 0; col < MAX_COL; col++) {
			printf("%c ", show[row][col]);
		}
		printf("\n");
	}
}
void updateShow(char show[MAX_ROW][MAX_COL], char mine[MAX_ROW][MAX_COL], int row, int col){
	int count = 0;
	for (int r = row - 1; r <= row + 1; r++) {
		for (int c = col - 1; c <= col + 1; c++) {
			if (r < 0 || r >= MAX_ROW
				|| c < 0 || c >= MAX_COL) {
				continue;
			}
			if (mine[r][c] == '1') {
				count++;
			}
		}
	}
	show[row][col] = count + '0';

}
void play(char show[MAX_ROW][MAX_COL], char mine[MAX_ROW][MAX_COL]){
	int row = 0;
	int col = 0;
	int safe = 0;
	while (safe < MAX_ROW*MAX_COL - DIFFICULTY){
		printf("请输入翻开的坐标（row col）:");
		scanf("%d %d", &row, &col);
		if (row >= 0 && row < MAX_ROW&&col >= 0 && col < MAX_COL){
			if (mine[row][col] == '1'){
				printf("你已经被炸死了！！！\n");
				printShow(mine);
				break;
			}
			else{
				updateShow(show, mine, row, col);
				printShow(show);
				safe++;
			}
		}
		else{
			printf("输入的坐标有误，重新输入：\n");
			continue;                                                                                                                                                                                                                                                                       
		}
	}
	if (safe == MAX_ROW*MAX_COL - DIFFICULTY)
	{
		printf("恭喜你排雷成功！请联系作者领取奖励\n");
	}
}
void game(){
	char show[MAX_ROW][MAX_COL] = { 0 };
	char mine[MAX_ROW][MAX_COL] = { 0 };
	init(show, mine);
	printShow(show);
	play(show,mine);
}
int main()
{
	srand((unsigned int)time(0));
	while (1){
		int choice = menu();
		if (choice == 1){
			game();
		}
		else if (choice == 0){
			printf("退出游戏，byebye!");
			break;
		}
		else{
			printf("输入错误，请重新输入：");
			continue;
		}

	}
}