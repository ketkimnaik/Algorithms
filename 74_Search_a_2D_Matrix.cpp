class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        if (!m) return false; 
        int n = matrix[0].size();
        
        int left = 0, right = m * n - 1, mid;
        
        while (left <=right) {
            mid = (left + (right - left) / 2); 
            int middleElement = (matrix[mid / n][mid % n]); 
            if (middleElement == target) {
                return true;
            } else if (middleElement > target) {
                right = mid - 1;
            } else {
                left= mid + 1;
            }
        } 
        return false;
    }
};