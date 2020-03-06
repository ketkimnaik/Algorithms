
Approach 1:

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        
        set<int>s;
        
        for(auto n: nums)
        {
            auto it=s.lower_bound(n);
            
            if(it ==s.end())//if any value eual to or smaller than n is not present then insert that in set
                s.insert(n);
            
            else
            {
                if(*it !=n)//remove value bigger than that value from set
                {
                    s.erase(*it);
                    s.insert(n);
                }
            }
        }
        
        return s.size();
    }
};

DP Approach:

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        
        if(n==0)
            return 0;
        vector<int> dp(n,1);
        
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                if(nums[j]<nums[i])
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
            
            return *max_element(dp.begin(),dp.end());
        
    }
};