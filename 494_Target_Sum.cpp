class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(S>1000)
            return 0;
        int sum=accumulate(nums.begin(),nums.end(),0);
        int targetsumdouble=sum+S;
        
        if(targetsumdouble % 2)
            return 0;//if odd sum then return 0
        
        int target=targetsumdouble/2;
        
        if(target>sum)
            return 0;
        
        vector<int> dp(sum+1,0);
        dp[0]=1;
        for(int i=0;i<nums.size();++i)
        {
            for(int j=sum-nums[i];j>=0;--j)
            {
                dp[j+nums[i]]+=dp[j];
            }
        }
        
        return dp[target];
    }
};