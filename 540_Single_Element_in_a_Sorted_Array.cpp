class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int left=0,right=nums.size()-1;
        
       /* if(nums.size()==1)
            return nums[0];*/
        
        int mid=0;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(mid==0 or mid==nums.size()-1)
                break;
            if(nums[mid]==nums[mid-1])
            {
                if(mid%2==0)
                {
                    //left half
                    right=mid-2;
                }
                else
                {
                    //right half
                    left=mid+1;
                }
            }
            
            else if(nums[mid]==nums[mid+1])
            {
                if(mid%2==0)
                {
                    //right half
                    left=mid+2;
                }
                else
                {
                    right=mid-1;
                }
            }
            else
                break;
        }
        
        return nums[mid];
        
    }
};