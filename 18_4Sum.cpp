

class Solution {
public:
vector< vector<int> > fourSum(vector<int>& nums, int target) {
	vector<vector<int>> result;
    int n=nums.size();
    
    if(n<4)
    {
        return result;
    }
    
    sort(nums.begin(),nums.end()); // sort the numbers
    
    for(int i=0;i<n-3;++i)
    {
        if(target<=0 && nums[i]>0)
            break;
        if((nums[i]+nums[i+1]+nums[i+2]+nums[i+3])>target)//if smallest numbers of an array are greater than target then we wont get output
            break;
        
        if((nums[i]+nums[n-3]+nums[n-2]+nums[n-1])<target)// if highest num and lowest one is more than target then continue with next i
            continue;
        if(i>0 && nums[i]==nums[i-1])//avoid duplication
            continue;
        
        for(int j=i+1;j<n-2;++j)
        {
            if((nums[i]+nums[j+1]+nums[j+2]+nums[j])>target)//if smallest numbers of an array are greater than target then we wont get output
            break;
        
            if((nums[i]+nums[j]+nums[n-2]+nums[n-1])<target)// if highest num and lowest one is more than target then continue with next i
                continue;
            
            
            if(j>i+1 && nums[j]==nums[j-1]) //avoid duplication
                continue;
            
            int left=j+1, right=n-1;
            while(left<right)
            {
                int sum=nums[i]+nums[j]+nums[left]+nums[right];
                
            
                
                if(sum==target)
                {
                    int last_left=nums[left];
                int last_right=nums[right];
                    result.push_back({nums[i],nums[j],nums[left],nums[right]}) ;
                    while(left<right && nums[left]==last_left)
                    {
                        left++;
                    }
                    while(left<right && nums[right]==last_right)
                    {
                        --right;
                    }
                }
                else if(sum<target)
                {
                   left++; 
                }
                else
                {
                    right--;
                }
                
            }
        
            
            
            
            
        }
        
    }
    
    return result;
    
}
};