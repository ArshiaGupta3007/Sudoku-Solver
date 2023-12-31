#include<iostream>
#include<math.h>
using namespace std;

//to print the sudoku board
void PrintBoard(int board[][9],int n){
	for(int row=0;row<n;row++){
		for(int column=0;column<n;column++){
			cout<<board[row][column]<<" ";
		}
		cout<<endl;
	}
}

bool IsValid(int board[][9],int row,int column,int value,int n){
	for(int i=0;i<n;i++){
		//checking if the value already exists in the row
		if(board[row][i]==value){
			return false;
		}
		//checking if the value already exists in the column
		if(board[i][column]==value){
			return false;
		}
		
		
	}
	
	//SUBGRID
	
	int a=sqrt(n);
	int si=row-row%a;
	int sj=column-column%a;
	for(int i = si;i < si+a;i++){
		for(int j= sj;j<sj+a;j++){
			if(board[i][j]==value){
				return false;
			}
		}
	}
	return true;
}
bool SudokuSolver(int board[][9],int row,int column,int n){
	//BASE CASE- out of the board	
	if(row==n){
		PrintBoard(board,n);
		return true;
	}
	
	
	
	//to go to next row when we have reached the last column	
	if(column==n){
		return SudokuSolver(board,row+1,0,n);
	}
	
	
	
	//if the cell is already filled	
	if(board[row][column]!=0){
		return SudokuSolver(board,row,column+1,n);
	}
	
	
	
	for(int value=1;value<=9;value++){
		if(IsValid(board,row,column,value,n)){
			board[row][column]=value;
			
			//recursive call
			bool solvable=SudokuSolver(board,row,column+1,n);
			if(solvable){
				return true;
			}
			else{
				
				//backtracking
				board[row][column]=0;
			}
		}
	}
}
int main(){
	int n=9;
	int board[9][9]={
		{0,0,7,1,0,0,0,6,0},
		{1,0,5,2,0,8,0,0,0},
		{6,0,0,0,0,7,1,2,0},
		{3,1,2,4,0,5,0,0,8},
		{0,0,6,0,9,0,2,0,0},
		{0,0,0,0,0,3,0,0,1},
		{0,0,1,0,0,4,9,8,6},
		{8,0,3,9,0,6,0,0,0},
		{0,6,0,0,8,2,7,0,3},
	};
	cout<<" SOLVED SUDOKU : "<<endl;
	SudokuSolver(board,0,0,n);
	return 0;
}