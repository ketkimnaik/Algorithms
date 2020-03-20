class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        
        bool flag=true;
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i] != nums[i-1])
                flag=false;
            nums[i-1]=nums[i]-nums[i-1];
        }
        
        if(flag)
            return 1;
        
        nums.pop_back();
        while(nums.size()>0 && nums[0]==0)
            nums.erase(nums.begin());
        
        int count=0;
        int current=nums[0];
        for(int i=1;i<nums.size();++i)
        {
            if((current>0 && nums[i]<0) || (current<0 && nums[i]>0))
            {
                count++;
                current=nums[i];
            }
        }
            
        return count+2;
    }
};