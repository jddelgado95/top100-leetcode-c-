/*
Given an mxn integer matrix matrix, if an element is 0, set its entire row and column to 0s. 
You must do it in place
For example: 
Input matrix = [[1,1,1],[1,0,1],[1,1,1]]

1     1      1

1     0      1

1     1      1

Output = [[1,0,1],[0,0,0],[1,0,1]]

1    0     1

0    0     0

1    0     1

Could you devise a constant space solution?
*/

/*
Solution approach: Using First Row and Column – O(n*m) Time and O(1) Space
So if the first cell of a row is set to 0, then all cells of that row should be updated with 0. Similarly, if the first cell of a column is set to 0, then all cells of that column should be updated to 0. Since cell (0, 0) is first cell of the first row as well as the first column, so maintain another variable, say c0 to store the status of the first column and cell(0, 0) will store the status of the first row.

https://www.geeksforgeeks.org/set-matrix-rows-and-columns-to-zeroes/

Remeber a little theory of matrix using vector in C++

vector[row][colum]

*/

#include<vector>
#include<iostream>
using namespace std;

class Solution{
    public:
        void SetZeroes(vector<vector<int>>& matrix){
            // We are going to use the 1st row and 1st column as extra space
            bool firstRow = false, firstCol = false;
            int m = matrix.size(); // Number of rows
            int n = matrix[0].size(); // Numbers of columns

            // Check columns for zero values
            for(int j = 0; j < n; j++){
                if(matrix[0][j] == 0){
                    firstRow = true;
                    break;
                }
            }
            
            // Check rows for zero values
            for(int i = 0; i < m; i++){
                if(matrix[i][0] == 0){
                    firstCol = true;
                    break;
                }            
            }
            /* Mark rows and columns that need to be zeroed:
            Indicates which columns and which rows must be converted to zero. 
            For each inner cell (excluding first row and column), if the value is 0, mark its row and column for zeroing using the first row and column as flags.*/
            //Loop through all rows
            for(int i = 1; i < m; i++){
                //Loop through all columns
                for(int j = 1; j < n; j++){
                    //if this element is 0, it means its entire row i and column j should be set to 0
                    if(matrix[i][j] == 0){
                        //Mark down with a zero the first element of the column: Use the first column of that row to remember this row must be zeroed later.
                        matrix[i][0] = 0;
                        //Mark down with a zero the first element of the row: Use the first row of that column to remember this column must be zeroed later.
                        matrix[0][j] = 0;
                    }
                }
            }

            // Check if a corresponding cell correspond to zero. Uses the markers from previous step to set appropriate inner cells to zero.
            for(int i = 1; i < m; i++){
                for(int j = 1; j < n; j++){
                    if(matrix[i][0] == 0 || matrix[0][j] == 0 ){
                        matrix[i][j] = 0;
                    }
                }
            }

            //If the first row originally had a 0, zero out the whole first row.
            if(firstRow){
                for(int j = 1; j < n; j++){
                    matrix[0][j];
                }
            }
            //If the first column originally had a 0, zero out the whole first column.
            if(firstCol){
                for (int i = 0; i < m; i++){
                    matrix[i][0] = 0;
                }
            }    
        }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    Solution sol;
    sol.SetZeroes(matrix);
//It prints a 2D matrix (output) in a formatted table-like layout. The outer loop goes over each row. The inner loop prints each value in that row. After each row, it prints a newline ("\n"), so it appears like a grid.
    cout << "Resulting matrix:\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
