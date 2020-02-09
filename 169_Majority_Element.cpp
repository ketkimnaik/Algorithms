class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        
         
        map<int,int> mp;
        
        for(auto i : nums)
        {
            mp[i]++;
        }
        
        int max=mp[nums[0]];
        
        int val=nums[0];
        
        for(auto it=mp.begin();it !=mp.end();++it)
        {
            if (it->second > max)
            {
                max =it->second;
                val=it->first;
            }
            
            
        }
        
        if(max>(nums.size()/2))
            return val;
        else 
            return 0;
        
    
        
    }
};