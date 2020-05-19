class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        
        for(auto& n:nums)
        {
            
            
            nums[abs(n)-1]*=-1;
            
            if(nums[abs(n)-1]>0)
            
                return abs(n);
                
        }
        
        return -1;
    }
};