class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        if(nums.size()<2)
            return false;
        
        k=abs(k);
        
        unordered_map<int,int> rem;//to store remainders;
        
        rem[0]=-1;
        int sum=0;
        for(int i=0;i<nums.size();++i)
        {
            sum+=nums[i];
            
            if(k!=0)
            {
                sum=sum %k;
            }
            
            auto it=rem.find(sum);
            if(it != rem.end())
            {
                 if(it->second<i-1)
                    return true;
            }
            else
            {
               rem[sum]=i;
            }
        }
        return false;
    }
};