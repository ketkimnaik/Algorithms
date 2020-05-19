class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        
        sort(nums.rbegin(),nums.rend());
        int sum=0;
        sum=accumulate(nums.begin(),nums.end(),0);
        
        int subsum=0;
        vector<int> result{};
        for(int i=0;i<nums.size();++i)
        {
            subsum+=nums[i];
            sum-=nums[i];
            result.push_back(nums[i]);
            
            if(sum<subsum)
                break;
            
        }
        
        return result;
    }
};