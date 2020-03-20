Optimized and iterative approach:

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        if(nums.size()==0)
            return 0;
        
        if(target==0)
            return 1;//empty set
        
        vector<unsigned long long> dp(target+1,0);
        dp[0]=1;
        
        for(int i=1;i<=target;++i)
        {
            for(int j=0;j<nums.size();++j)
            {
                if(i-nums[j]>=0)
                {
                    dp[i]+=dp[i-nums[j]];
                }
            }
        }
        
        
        return dp[target];
    }
};

Resursive approach:

class Solution {
    unordered_map<int,int> mp;
public:
    int combinationSum4(vector<int>& nums, int target) {
         
        if(target==0)//base case
            return 1;
        
        if(mp.count(target)>0)// for memoization
            return mp[target];
        int sum=0;
        for(auto  n: nums)
        {
            
            if(target>=n)
            {
               
                
                sum+=combinationSum4(nums,target-n);//inductive case
            }
        }
        
        mp[target]=sum;
        
        return sum;
    }
};