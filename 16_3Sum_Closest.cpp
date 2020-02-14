class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size()<3)
            return 0;
        int result;
        int diff=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
          int left=i+1;
          int right=nums.size()-1;
            
            while(left<right)
            {
                int sum=nums[i]+nums[left]+nums[right];
                if(sum-target==0)
                    return target;
                diff=min(diff,abs(sum-target));
                
                    if(diff==abs(sum-target))
                    {
                        result=sum;
                        
                    }
                
                if(sum<target)
                    left++;
                if(sum>target)
                    right--;
                
                
            }
             
            
            
        }
        return result;
        
    }
};