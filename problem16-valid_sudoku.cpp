/*
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
1. Each row must contain the digits 1-9 without repetition. 
2. Each column must contain the digits 1-9 without repetition/ 
3. Each of the nine 3x3 sub boxes of the grid must containt the digits 1-9 without repetition. 

Notes: 
- A sudoku board partially filled 
*/

/* Solution approach: 
if we want to validate it efficiently, we need to check every row and every columns sets for repetive numbers. 
Using Array of Fixed Length
Instead of using any hash table for keeping track of seen/visited elements, We can use auxiliary arrays to track the seen/visited of each number in rows, columns, and sub-matrix. By using arrays, we can eliminate the overhead of hashing.

Step-by-step approach:

We use three 2D arrays (rows, cols, subMat) to track which numbers have already appeared in each row, column, and sub-matrix, respectively.
For each cell, we skip if it contains 0 (empty). Otherwise, we check if the number has already appeared in the corresponding row, column, or sub-matrix. If so, the matrix is invalid.
The sub-matrix index is calculated as (i / 3) * 3 + j / 3 where i and j are the row and column indices.
If the current number is not visited before in the current row, column, or sub-matrix then marked as seen/visited.

https://www.geeksforgeeks.org/check-if-given-sudoku-board-configuration-is-valid-or-not/
*/

/*
This is  a valid question that I did when I was trying to solve this problem? It may help you. 
Why char and not int?
Even though Sudoku uses numbers, the board usually comes as a character grid because:
Empty cells are represented by '.', not a number.
The input format (often from LeetCode or similar platforms) uses characters to represent '1' through '9'.
So each cell contains either:
'1', '2', ..., '9' (as characters)
or '.' to represent an empty spot
*/

#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution{
    public:
        bool isValidSudoku(vector<vector<char>>& board){
            /*
            vector<unordered_set<char>>: This declares a vector (a dynamic array) where each element is an unordered_set<char>.  
            unordered_set<char> is a container that stores unique characters with fast lookup (average O(1) time).
            rowSet(9)
            Initializes the vector with 9 elements. 
            Each of these 9 elements is an empty unordered set of characters.
            So, you're effectively creating 9 empty sets.
            This would be used to store the set of characters (digits) already seen in each of the 9 rows, so you can check for duplicates quickly.
            */
           //Creates 3 vectors of 9 unordered_set<char>, one for each row, column, and 3x3 subgrid respectively. These sets will store the characters that have already appeared to detect duplicates.
            vector<unordered_set<char>> rowSet(9);
            vector<unordered_set<char>> colSet(9);
            vector<unordered_set<char>> gridSet(9);

            /*
            for(int i=0; i<9; i++){
                rowSet[i] = unordered_set<char>();
                colSet[i] = unordered_set<char>();
                gridSet[i] = unordered_set<char>();
            }*/
            //Nested loop to iterate over every cell in the 9x9 Sudoku board.
            for(int i=0; i<9; i++){
                for(int j=0; j<9; j++){
                    //Retrieves the current cell's value.
                    char value = board[i][j];
                    //Skips empty cells ('.') — standard for partially filled Sudoku boards.
                    if(value == '.'){
                        continue;
                    }
                    //Calculates which of the 9 3x3 subgrids this cell belongs to.
                    int gridNumber = (i/3) * 3 + (j/3);
                    //Checks if the current value already exists in the current row, column, or subgrid.
                    /*
                    Breaking it down:
                    rowSet[i]: This accesses the unordered_set<char> corresponding to row i. It stores the characters that have already been seen in that row.
                    .count(value): This checks how many times value appears in that set. For unordered_set, this will be either 0 (not present) or 1 (present).
                    > 0: Returns true if value is present (i.e., count is 1), or false if it is not.
                    Purpose:
                    This helps detect duplicate values in a row, which would violate Sudoku rules.
                    */
                    bool isPresentinRow = rowSet[i].count(value) > 0;
                    bool isPresentinCol = colSet[i].count(value) > 0;
                    bool isPresentinGrid = gridSet[gridNumber].count(value) > 0;

                    //If the number is already in any of these sets, the Sudoku board is invalid — return false.
                    if(isPresentinRow || isPresentinCol || isPresentinGrid){
                        return false;
                    }
                    // /If it wasn’t a duplicate, insert the value into the corresponding row, column, and grid sets.
                    rowSet[i].insert(value);
                    colSet[i].insert(value);
                    gridSet[gridNumber].insert(value);
                }
            }
            //If the whole board is traversed without conflicts, return true.
            return true;
        }
};

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution sol;
    if (sol.isValidSudoku(board)) {
        cout << "The Sudoku board is valid." << endl;
    } else {
        cout << "The Sudoku board is invalid." << endl;
    }

    return 0;
}