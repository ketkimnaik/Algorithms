class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        
        int maxdude = INT_MIN, mindude = INT_MAX;
        int leftindex, rightindex;
        bool issorted = true;
        for(int i = 0; i < nums.size() - 1; i++){
            if (nums[i] > nums[i + 1]){
                maxdude = max(maxdude, nums[i]);
                mindude = min(mindude, nums[i+1]);
                issorted = false;
            }
        }
        if(issorted) return 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > mindude){
                leftindex = i;
                break;
            }
        }
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] < maxdude){
                rightindex = i;
                break;
            }
        }
        return rightindex - leftindex + 1;
    }
};