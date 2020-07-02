class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0 , right = n - 1, mid = 0;
        
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(mid > 0 && mid < nums.size() - 1 && nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                break;
            } else if(mid < nums.size() - 1 && nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        
        }
        
        return mid;
    }
};