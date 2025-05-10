/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1: 
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Example 2:
Input: n = 1
Output: [["Q"]]

*/

/*
Solution approach: 
https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/

The idea is to use backtracking to check all possible combinations of n queens in a chessboard of order n*n. To do so, first create an auxiliary matrix mat[][] of order n*n to mark the cellsoccupied by queens. Start from the first row and for each row  place queen at different columns and check for clashes with other queens. To check for clashes, iterate through all the rows of current column and both the diagonals. If it is safe to place queen in current column, mark the cell occupied in matrix mat[][] and move to the next row. If at any row, there is no safe column to place the queen, backtrack to previous row and place the queen in other safe column and again check for the next row.


*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        //Initializes an n x n chessboard filled with '.', representing empty cells.
        vector<string> board(n, string(n, '.'));
        //Starts the backtracking algorithm at row 0.
        backtrack(board, 0, solutions);
        return solutions;
    }
private:
    void backtrack(vector<string> &board, int row, vector<vector<string>>& solutions){
        //end the backtracking 
        if(row == board.size()){
            solutions.push_back(board);
            return;
        }
        //Try placing a queen in each column of the current row.
        int n = board.size();
        for(int col = 0; col < n; col++){
            // if Q is not causing any conflict, Check if placing a queen at (row, col) is safe.
            if(is_safe(board, row, col)){
                // Place the queen
                board[row][col] = 'Q';
                // go to the next row and place a . 
                backtrack(board, row + 1, solutions);
                board[row][col] = '.';
            }
        }
    }

    bool is_safe(const vector<string>& board, int row, int col){
        int n = board.size();
        //Check for queens in the same column, Scan all rows above the current one in the same column for a queen.
        for(int i = 0; i < row; i++){
            if(board[i][col] == 'Q'){
                return false;
            }                    
        }

        // Check for queens in the upper-left diagonal
        //int i = row - 1 : checks the row above the current one
        //j = col - 1: checks the left column
        //i--, j-- : moves columns to the left size, and moves rows up
        //i>= 0 && j>=0: Keep moving diagonally up-left until you're out of the board's top or left boundaries
        for(int i = row - 1, j = col - 1; i>= 0 && j>=0; i--, j--){
            if(board[i][j] == 'Q'){
                return false; 
            }
        }

        // Check for queens in the upper-right diagonal
        //int i = row - 1 : checks the row above the current one
        //j = col + 1: checks the right column
        //i--, j++ : moves columns to the right size, and moves rows up
        //i>= 0 && j < n: Keep moving diagonally up-left until you're out of the board's top or right boundaries
        for(int i = row - 1, j = col + 1; i>= 0 && j < n; i--, j++){
            if(board[i][j] == 'Q'){
                return false; 
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    int n = 4; // You can change this to any n >= 1
    vector<vector<string>> solutions = sol.solveNQueens(n);

    cout << "Total solutions for " << n << "-Queens: " << solutions.size() << "\n";
    for (const auto& board : solutions) {
        for (const auto& row : board) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}