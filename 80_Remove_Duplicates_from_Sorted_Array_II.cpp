class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
            return n;
        
        int out=0,count=0,curr=-1;
        
        for(int i=0;i<n;++i)
        {
            if(curr !=nums[i] || count<=1 )
            {
                if(curr !=nums[i])
                {
                    
                    count=0;
                }
                
                nums[out]=nums[i];
                count++;
                out++;
                
                
            }
            
            curr=nums[i];
        }
        
        return out;
    }
};