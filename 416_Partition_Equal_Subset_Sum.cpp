class Solution {
public:
    bool backtrack(vector<int> &nums,int ind,int sum)
    {
        if(ind>=nums.size())
            return false;
        if(sum==nums[ind])
            return true;
        if(sum<nums[ind])
            return false;
        
        return backtrack(nums,ind+1,sum-nums[ind]) || backtrack(nums,ind+1,sum);
    }
    
    bool canPartition(vector<int>& nums) {
        if(nums.size()<2)
            return false;
        int sum=accumulate(nums.begin(),nums.end(),0);
         if(sum % 2 !=0)
             return false;//can not divide odd sum in 2 equal parts
        
        //sort numbers in reverse order
        sort(nums.rbegin(),nums.rend());
        return backtrack(nums,0,sum/2);
    }
};