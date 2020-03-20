class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> result{};
        if(n==0)
            return result;
        sort(nums.begin(),nums.end());
        vector<int> previous_index(n,-1);
        vector<int> size(n,1);
        
        int result_index=0;
        int max_size=0;
        
        for(int i=1;i<n;++i)
        {
            int current_index=-1;
            int current_maxsize=1;
            
            for(int j=0;j<i;++j)
            {
                if(nums[i]%nums[j]==0)
                {
                    if(size[j]+1>current_maxsize)
                    {
                    current_maxsize=size[j]+1;
                    current_index=j;
                    }
                }
            }
            
            previous_index[i]=current_index;
            size[i]=current_maxsize;
            
            if(current_maxsize>max_size)
            {
                max_size=current_maxsize;
                result_index=i;
            }
        }
        
        
        while(result_index>=0)
        {
            result.push_back(nums[result_index]);
            result_index=previous_index[result_index];
        }
        
        reverse(result.begin(),result.end());
        return result;
        
    }
};