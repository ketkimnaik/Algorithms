class Solution {
    
    
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> index(nums.size(),0);
        vector<int> result(nums.size(),0);
        
        iota(index.begin(),index.end(),0);//arrange index from 0 to size-1
        
        //sort index in descending order
        
        sort(index.begin(),index.end(),[&](int a,int b)
             {return nums[a]<nums[b];}
            );
        
        for(int i=1;i<nums.size();++i)
        {
            if(nums[index[i]]==nums[index[i-1]])
                result[index[i]]=result[index[i-1]];
            else
                result[index[i]]=i;
        }
        
        return result;
        
    }
};