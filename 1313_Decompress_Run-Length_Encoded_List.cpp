class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        
        vector<int> result{};
        for(int i=1;i<nums.size();i=i+2)
        {
            while(nums[i-1] !=0)
            {
                result.push_back(nums[i]);
                nums[i-1]--;
            }
        }
        
        return result;
    }
};