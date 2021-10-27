/*
SEARCH IN A 2D MATRIX
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104

Problem link : https://leetcode.com/problems/search-a-2d-matrix/

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.size()==0){
            return false;
        }
        
        int lower = 0;
        int higher = (matrix.size() * matrix[0].size())-1;
        int mid =0;
        int midEle=0;
        
        while(lower<=higher){
            mid = (lower+higher)/2;
            midEle = matrix[mid/matrix[0].size()][mid%matrix[0].size()];
            if(midEle == target){
                return true;
            }else if(midEle > target){
                higher = mid-1;
            }else{
                lower = mid+1;
            }
        }
        return false;
    }
};
//Binary search
//O(log(m*n))  O(1)
