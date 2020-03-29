class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        
        if(nums.size()<3)
            return true;
        
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),0));
        
        for(int i=0;i<nums.size();++i)
            dp[i][i]=nums[i];
        
        for(int n=1;n<nums.size();++n)
        {
            for(int i=0;i+n<nums.size();++i)
            {
                int j=i+n;
                
                dp[i][j]=max(nums[i]-dp[i+1][j],nums[j]-dp[i][j-1]);
            }
        }
        
       return dp[0][nums.size()-1]>=0?true:false ;
    }
};