class Solution {
public:
    int Binary_Search(vector<int> nums, int num, string occur) {
        int left = 0, right = nums.size() - 1, mid;
        int result = -1;

        while (left <= right) {
            mid = (left + right) / 2;

            if (nums[mid] == num) {
                result = mid;
                (occur == "F") ? right = mid - 1 : left = mid + 1;
            }
            else if (nums[mid] > num) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return result;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = Binary_Search(nums, target, "F");
		int last = Binary_Search(nums, target, "L");
        
        return {first, lastO};
    }
    
    
};