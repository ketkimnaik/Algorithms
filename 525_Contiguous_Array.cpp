class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 0;
        unsigned int sum=0;
        unordered_map<int,int> mp;
        int result=0;
        for(int i=0;i<n;++i)
        {
            if(nums[i]==0)
                sum+=-1;
            else
                sum+=1;
            
            auto it=mp.find(sum);
            
            if(sum==0)
                result=max(result,i+1);
            
            else if(it != mp.end())//if sum exist in map
            {
                if(result<i-it->second)
                    result=i-it->second;
            }
            
            else if(it == mp.end())
                mp.insert({sum,i});
                
              
            
        }
       
        return result;
    }
};