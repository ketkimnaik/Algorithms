class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int left = 0, right = nums.size() - 1;
        int mid;
        
        while(left <= right) {

            mid = left + (right - left) / 2;

            if (target == nums[mid]) return true;

            if (nums[mid] > nums[left]) {

                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid;
                }
            } else if(nums[mid] < nums[left]){
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            } else {
                left++;
            }
        }  
        
        return false;
        
    }
};