// **************************** Sudoku Solver ***********************************

#include<bits/stdc++.h>
using namespace std;


// TC = O(9^m), m = no. of empty cell
// SC = O(1)

bool isSafe(int row, int col, vector<vector<int>> &board, int val){
    
    for(int i=0; i<board.size(); i++){
//         row check
        if(board[row][i] == val) return false;
        
//         col check
        if(board[i][col] == val)  return false;
        
//         3*3 matrix check
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val)  return false;
    }
    
    return true;
}

bool solve(vector<vector<int>>& board){
    int n = board[0].size();
    
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            
//             check cell is empty
            if(board[row][col] == 0){
                for(int val=1; val<=9; val++){
                    if(isSafe(row, col, board, val)){
                        board[row][col] = val;
//                         recursive call
                        bool nextSolutionIsPossible = solve(board);
                        if(nextSolutionIsPossible){
                            return true;
                        }
                        else{
//                             backtrack
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
	// Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix
    solve(sudoku);
}