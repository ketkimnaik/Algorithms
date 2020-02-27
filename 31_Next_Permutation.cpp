class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)
            return;
        
        int pivot_ind=n-2;
        int suff_ind=n-1;
        //to get largest index for pivot
        while(pivot_ind>=0 && nums[pivot_ind]>=nums[pivot_ind+1])
        {
            --pivot_ind;
        }
        
        if(pivot_ind>=0 )
        {
            while(nums[pivot_ind]>=nums[suff_ind])
                --suff_ind;
            
            swap(nums[pivot_ind],nums[suff_ind]);
        }
      
        pivot_ind+=1;
        
        sort(nums.begin()+pivot_ind,nums.end());
        
    }
};