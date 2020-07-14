Optimized Approach:

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int r = row - 1, c = 0;
        
        while(r >= 0 && c < col) {
            if (matrix[r][c] == target) {
                return true;
            } else if (matrix[r][c] > target) {
                r--;
            } else {
                c++;
            }
        }
        
        return false;
    }
};


class Solution {
public:
    bool BinarySearch(vector<int> &nums, int target, int col) {
        int left = 0, right = col -1;
        int mid;
        
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                return true;
            } else if(nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col;
        if(row) col = matrix[0].size();
        if(row * col == 0) return false;
        
        for(int i = 0; i < row; ++i) {
            if(target >= matrix[i][0] && target <= matrix[i][col - 1]) {
                if (BinarySearch(matrix[i], target, col)) return true;
            }
        }
        
        return false;
    }
};