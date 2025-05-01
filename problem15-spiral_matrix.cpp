/*
Give an mxn matrix, return all elements of the matrix in spiral order.
Example: 
input matrix = [[1,2,3],[4,5,6],[7,8,9]]
1   2    3
4   5    6
7   8    9
Output: [1,2,3,6,9,8,7,4,5]
*/

/*
Solution approach: 
We can print the matrix in a spiral order by dividing it into loops or boundaries. We print the elements of the outer boundary first, then move inward to print the elements of the inner boundaries.

Define the boundaries of the matrix with variables top, bottom, left, and right.
Print the top row from left to right and increment top.
Print the right column from top to bottom and decrement right.
Check if boundaries have crossed; if not, print the bottom row from right to left and decrement bottom.
Print the left column from bottom to top and increment left.
Repeat until all boundaries are crossed.

top = 0
bottom = rows - 1
left = 0
right = cols - 1
direction = 0(left to right), 1 (top to bottom), 2(right to left), 3(bottom to top)

for the above matrix: 
rows = 3
cols = 3
top = 0
bottom = 2
left = 0
right = 2
direction = 0 (left to right)
print(1,2,3)
top = 1
bottom =2
left = 0
right = 2
direction = 1 (top to bottom)
print(6,9)

top = 1, bottom =2 left = 0 right = 1 direction 2
print(8,7)
top = 1, bottom =1, left = 0, right = 1 direction =3
print(4)
top = 1, bottom =1 , left =1 rigth = 1 direction 0
print(5)
*/

/*
matrix[0].size()
matrix is a 2D vector, so it's essentially a vector of vectors: vector<vector<int>>.
matrix[0] accesses the first row, which is itself a vector<int>.
.size() on that first row returns the number of elements in that row, which is the number of
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public: 
        vector<int> spiralOrder(vector<vector<int>>& matrix){
            int m = matrix.size(); // number of rows
            int n = matrix[0].size(); //Numbers of columns
            int top = 0, bottom = m - 1, left = 0, right = n - 1, direction = 0;
            vector<int> output;
            while(top <= bottom && left <= right){
                // Print top row from left to right
                if(direction == 0){
                    for(int j = left; j <= right; j++){
                        output.push_back(matrix[top][j]);
                    }
                    top++;
                    direction =1; 
                }
                // print most right column, from top to bottom
                else if (direction == 1){
                    for(int i = top; i <= bottom; i++){
                        output.push_back(matrix[i][right]);
                    }
                    right--;
                    direction = 2;
                }
                //Printing the most bottom row  of the matrix from right to left
                else if(direction == 2){
                    for(int j = right; j >= left; j--){
                        output.push_back(matrix[bottom][j]);
                    }
                    bottom--;
                    direction = 3;
                }
                // Print the most left column from bottom to top
                else{
                    for(int i = bottom; i >= top; i--){
                        output.push_back(matrix[i][left]);
                    }
                    left++;
                    direction = 0;
                }
            }
            return output;
        }
};

int main(){
    vector<vector<int>> input = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    Solution sol;
    vector<int> output = sol.spiralOrder(input);
    //This is a range-based for loop (introduced in C++11).It iterates over every element in the result vector (which contains the spiral order of the matrix). Each element is assigned to the variable val during each iteration. cout << val << " "; prints each value followed by a space, so all values are printed on the same line.
    cout << "Spiral order of the matrix is: ";
    for (int val : output) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}