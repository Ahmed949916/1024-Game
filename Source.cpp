#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<ctime>
#include"mygraphics.h"
#include"myconsole.h"
#include<conio.h>

using namespace std;
const int row = 4;
const int col = 4;


void numbers(int number, int x, int y, int ht)
{
	COLORREF random = RGB(255, 255, 255);
	switch (number)
	{
	case 0:
		myEllipse(x, y, x + ht, y + ht, random, random);
		break;

	case 1:
		myLine(x, y, x, y + ht, random);
		break;

	case 2:
		myLine(x, y, x + ht, y, random);
		myLine(x + ht, y, x + ht, y + ht / 2, random);
		myLine(x + ht, y + ht / 2, x, y + ht / 2, random);
		myLine(x, y + ht / 2, x, y + ht / 2 + 5, random);
		myLine(x, y + ht + ht / 5, x + ht, y + ht + ht / 5, random);
		break;

	case 3:
		myLine(x, y, x + ht, y, random);
		myLine(x + ht, y, x + ht, y + 3 * ht / 5, random);
		myLine(x + ht, y + 3 * ht / 5, x, y + 3 * ht / 5, random);
		myLine(x + ht, y + 3 * ht / 5, x + ht, y + 4 * ht / 5 + 2, random);
		myLine(x, y + ht + ht / 4, x + ht, y + ht + ht / 4, random);
		break;

	case 4:
		myLine(x, y, x, y + 3 * ht / 5, random);
		myLine(x, y + 3 * ht / 5, x + ht, y + 3 * ht / 5, random);
		myLine(x + 2 * ht / 5, y + ht / 4, x + 2 * ht / 5, y + 4 * ht / 5 + 3, random);
		break;

	case 5:
		myLine(x, y, x + ht, y, random);
		myLine(x, y, x, y + 3 * ht / 5, random);
		myLine(x + ht, y + 3 * ht / 5, x, y + 3 * ht / 5, random);
		myLine(x + ht, y + 3 * ht / 5, x + ht, y + 4 * ht / 5, random);
		myLine(x, y + ht + ht / 4, x + ht, y + ht + ht / 4, random);
		break;

	case 6:
		myLine(x, y, x + ht, y, random);
		myLine(x, y, x, y + ht + ht / 5, random);
		myLine(x, y + ht + ht / 5, x + ht, y + ht + ht / 5, random);
		myLine(x + ht, y + ht + ht / 5, x + ht, y + ht / 2, random);
		myLine(x + ht, y + ht / 2, x, y + ht / 2, random);
		break;

	case 7:
		myLine(x, y, x + ht, y, random);
		myLine(x + ht, y, x + 4 * ht / 5, y + ht, random);
		break;

	case 8:
		myLine(x, y, x + ht, y, random);
		myLine(x, y, x, y + ht + ht / 4, random);
		myLine(x + ht, y, x + ht, y + ht + ht / 4, random);
		myLine(x, y + ht + ht / 4, x + ht, y + ht + ht / 4, random);
		myLine(x, y + 3 * ht / 5, x + ht, y + 3 + ht / 4, random);
		break;

	case 9:
		myLine(x, y, x + ht, y, random);
		myLine(x, y, x, y + ht / 2, random);
		myLine(x + ht, y, x + ht, y + ht + ht / 5, random);
		myLine(x, y + ht + ht / 5, x + ht, y + ht + ht / 5, random);
		myLine(x, y + ht / 2, x + ht, y + 3 + ht / 5, random);
		break;
	}
}
void printNumber(int number,int x,int y,int ht){
	int printable = number;
	int i = 0;
	while (printable > 10) {
		numbers(printable % 10, x - ((i++ * ht)-20), y, ht);
		printable /= 10;
	}
	numbers(printable, x-(i++ * ht), y, ht);
}
void drawGrid(int nums[][4], int row)
{
	int x1, x2, y1, y2,size;
	size = 120;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			x1 = (i * size) + 55;
			y1 = (j * size) + 55;
			x2 = ((i + 1) * size) + 55;
			y2 = ((j + 1) * size) + 55;
			myRect(x1, y1, x2, y2, COLORREF(RGB(130,130,130)), COLORREF(RGB(100, 100, 100)));
			if (nums[i][j] != 0)
			{
				printNumber(nums[i][j], x1 + 50, y1 + 40, 10);
			}
		}
	}

}
void placeRandomly(int nums[][col],int r) {
	int ri = rand() % r;
	int rj = rand() % col;
	while (nums[ri][rj] != 0) {
		ri = rand() % r;
		rj = rand() % col;
	}
	nums[ri][rj] = (rand() % 2) + 1;
}
void swap(int& left,int& right) {
	int temp = left;
	left = right;
	right = temp;
}
void shiftDown(int nums[][col],int ri,int ci) {
	for (int j = ci; j > 0; j--) {
		swap(nums[ri][j], nums[ri][j - 1]);
	}
}
bool checkIfAllZero(int nums[][col],int r,int col) {
	bool skip = true;
	for (int j = 0; j < col; j++) {
		skip = skip && (nums[r][j] == 0);
	}
	return skip;
}
bool checkIfRemainingRowZero(int nums[][col], int r, int ci,int col) {
	bool skip = true;
	for (int j = ci; j >=0; j--) {
		skip = skip && (nums[r][j] == 0);
	}
	return skip;
}
bool checkIfUpSideZero(int nums[][col], int r, int ci, int col) {
	bool skip = true;
	for (int j = ci; j < col; j++) {
		skip = skip && (nums[r][j] == 0);
	}
	return skip;
}
void shiftUp(int nums[][col], int ri, int ci) {
	for (int j = ci; j < col-1; j++) {
		swap(nums[ri][j], nums[ri][j + 1]);
	}
}
void handleShiftDown(int nums[][col], int ri,int col) {
	for (int j = col-1; j > 0; j--) {
		while (nums[ri][j] == 0 && !checkIfRemainingRowZero(nums,ri,j,col)) {
			shiftDown(nums, ri, j);
		}
	}
}
void handleShiftUp(int nums[][col], int ri, int col) {
	for (int j = 0; j < col; j++) {
		while (nums[ri][j] == 0 && !checkIfUpSideZero(nums, ri, j, col)) {
			shiftUp(nums, ri, j);
		}
	}
}
bool checkIfAllColumnZero(int nums[][col], int row, int c) {
	bool skip = true;
	for (int i = 0; i < row; i++) {
		skip = skip && (nums[i][c] == 0);
	}
	return skip;
}
bool checkIfLeftSideZero(int nums[][col], int ri, int c, int row) {
	bool skip = true;
	for (int i = ri; i < row; i++) {
		skip = skip && (nums[i][c] == 0);
	}
	return skip;
}
bool checkIfRightSideZero(int nums[][col], int ri, int c, int row) {
	bool skip = true;
	for (int i = ri; i >=0; i--) {
		skip = skip && (nums[i][c] == 0);
	}
	return skip;
}
void shiftLeft(int nums[][col], int ri, int ci) {
	for (int i = ri; i < row - 1; i++) {
		swap(nums[i][ci], nums[i + 1][ci]);
	}
}
void shiftRight(int nums[][col], int ri, int ci) {
	for (int i = ri; i >0; i--) {
		swap(nums[i][ci], nums[i - 1][ci]);
	}
}

void handleShiftLeft(int nums[][col], int ci, int col) {
	for (int i = 0; i < row; i++) {
		while (nums[i][ci] == 0 && !checkIfLeftSideZero(nums, i, ci, col)) {
			shiftLeft(nums, i, ci);
		}
	}
}
void handleShiftRight(int nums[][col], int ci, int col) {
	for (int i = row-1; i >0; i--) {
		while (nums[i][ci] == 0 && !checkIfRightSideZero(nums, i, ci, col)) {
			shiftRight(nums, i, ci);
		}
	}
}
void move(int nums[][col],int r)
{
	int begin = true;
	while (begin)
	{
		COLORREF white = RGB(255, 255, 255);
		COLORREF black = RGB(0, 0, 0);
		myDrawTextWithFont(25, 25, 25, (char*)"Play 1024 game\n", white, black);
		switch (_getch())
		{
		case 72:
		{
			for (int i = 0; i < 4; i++)
			{
				if (!checkIfAllZero(nums, i, col))
				{
					handleShiftUp(nums, i, col);
				}
				for (int j = 0; j < col - 1; j++)
				{
					if (nums[i][j] == nums[i][j + 1] && nums[i][j] != 0) 
					{
						nums[i][j] += nums[i][j + 1];
						nums[i][j + 1] = 0;
					}
				}
				if (!checkIfAllZero(nums, i, col))
				{
					handleShiftUp(nums, i, col);
				}
			}
			placeRandomly(nums, 4);
			break;
		}
		case 80:
		{
			for (int i = 0; i < 4; i++)
			{
				if (!checkIfAllZero(nums, i, col)) {
					handleShiftDown(nums, i, col);
				}
				for (int j = 3; j > 0; j--)
				{
					if (nums[i][j] == nums[i][j - 1] && nums[i][j] != 0) {
						nums[i][j] += nums[i][j - 1];
						nums[i][j - 1] = 0;
					}
				}
				if (!checkIfAllZero(nums, i, col)) {
					handleShiftDown(nums, i, col);
				}
			}
			placeRandomly(nums, 4);
			break;
		}
		case 75:
		{
			for (int j = 0; j < col; j++)
			{
				if (!checkIfAllColumnZero(nums, row, j)) {
					handleShiftLeft(nums, j, row);
				}
				for (int i = 0; i < row - 1; i++)
				{
					if (nums[i][j] == nums[i + 1][j] && nums[i][j] != 0) {
						nums[i][j] += nums[i + 1][j];
						nums[i + 1][j] = 0;
					}
				}
				if (!checkIfAllColumnZero(nums, row, j)) {
					handleShiftLeft(nums, j, row);
				}
			}
			placeRandomly(nums, 4);
			break;
		}
		case 77:
		{
			for (int j = 0; j < col; j++)
			{
				if (!checkIfAllColumnZero(nums, row, j)) {
					handleShiftRight(nums, j, row);
				}
				for (int i = row - 1; i > 0; i--)
				{
					if (nums[i][j] == nums[i - 1][j] && nums[i][j] != 0) {
						nums[i][j] += nums[i - 1][j];
						nums[i - 1][j] = 0;
					}
				}
				if (!checkIfAllColumnZero(nums, row, j)) {
					handleShiftRight(nums, j, row);
				}
			}
			placeRandomly(nums, 4);
			break;
		}
		case 'e':
			begin = false;
			break;
		case 'd':
		{
			for (int j = 0; j < col; j++)
			{
				if (!checkIfAllColumnZero(nums, row, j)) {
					handleShiftRight(nums, j, row);
				}
				for (int i = row-1; i >0; i--)
				{
					if (nums[i][j] == nums[i - 1][j] && nums[i][j] != 0) {
						nums[i][j] += nums[i - 1][j];
						nums[i - 1][j] = 0;
					}
				}
				if (!checkIfAllColumnZero(nums, row, j)) {
					handleShiftRight(nums, j, row);
				}
			}
			placeRandomly(nums, 4);
			break;
		}
		case 's':
		{
			for (int i = 0; i < 4; i++)
			{
				if (!checkIfAllZero(nums, i, col)) {
					handleShiftDown(nums, i, col);
				}
				for (int j = 3; j > 0 ; j--)
				{
					if (nums[i][j] == nums[i][j - 1] && nums[i][j]!=0) {
						nums[i][j] += nums[i][j - 1];
						nums[i][j - 1] = 0;
					}
				}
				if (!checkIfAllZero(nums, i, col)) {
					handleShiftDown(nums, i, col);
				}
			}
			placeRandomly(nums, 4);
			break;
		}
		case 'a':
		{
			for (int j = 0; j < col; j++)
			{
				if (!checkIfAllColumnZero(nums, row, j)) {
					handleShiftLeft(nums, j, row);
				}
				for (int i = 0; i < row - 1; i++)
				{
					if (nums[i][j] == nums[i + 1][j] && nums[i][j] != 0) {
						nums[i][j] += nums[i + 1][j];
						nums[i + 1][j] = 0;
					}
				}
				if (!checkIfAllColumnZero(nums, row, j)) {
					handleShiftLeft(nums, j, row);
				}
			}
			placeRandomly(nums, 4);
			break;
		}
		case 'w':
		{
			for (int i = 0; i < 4; i++)
			{
				if (!checkIfAllZero(nums, i, col)) {
					handleShiftUp(nums, i, col);
				}
				for (int j = 0; j < col-1; j++)
				{
					if (nums[i][j] == nums[i][j + 1] && nums[i][j] != 0) {
						nums[i][j] += nums[i][j + 1];
						nums[i][j + 1] = 0;
					}
				}
				if (!checkIfAllZero(nums, i, col)) {
					handleShiftUp(nums, i, col);
				}
			}
			placeRandomly(nums, 4);
			break;
		}
		default:
			break;
		}
		
		drawGrid(nums, 4);
	}
	
}

int main()
{
	srand(time(0));
	int nums[4][4];
	int x1, x2, y1, y2;
	bool begin = true;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			nums[i][j] = 0;
		}
	}
	int ri = rand() % 4;
	int rj = rand() % 4;
	nums[ri][rj] = (rand() %2)+1;

	ri = rand() % 4;
	rj = rand() % 4;
	nums[ri][rj] = (rand() % 2) + 1;

	drawGrid(nums, 4);
	move(nums, 4);
	return 0;
}