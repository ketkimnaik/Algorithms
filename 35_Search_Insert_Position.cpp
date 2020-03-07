class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        auto it=lower_bound(nums.begin(), nums.end(), target); 
        
        return it-nums.begin();
        
    }
};

Approch 2 using binary search:
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            if (nums[middle] == target)
            {
                return middle;
            } 
			else if (nums[middle] < target)
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }
		
        return left;
    }
};
