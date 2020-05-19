Solution 1:

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int prod=1;
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            if(nums[i]==0)
            {
                
                count++;
                
            }
            else
                prod*=nums[i];
            
        }
        
        
        
        
        for(int i=0;i<n;++i)
        {
            if(count>1)
                nums[i]=0;
            else if(count==1)
            {
                if(nums[i]==0)
                    nums[i]=prod;
                else
                    nums[i]=0;
                
            }
            
            else
                nums[i]=prod/nums[i];
                
                
        }
        
        return nums;
        
    }
};



Solution 2:

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> v(nums.size(),1);
        int pre=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            v[i]=pre;
            pre=pre*nums[i];
        }
        int post=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--)
        {
            v[i]=v[i]*post;
            post=post*nums[i];
        }
        return v;
    }
};