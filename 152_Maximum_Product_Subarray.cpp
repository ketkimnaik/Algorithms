class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int> maximum(n);
        vector<int> minimum(n);
        
        minimum[0]=nums[0];
        maximum[0]=nums[0];
        int max_product=nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
           if(nums[i]>0)
           {
               maximum[i]=max(maximum[i-1]*nums[i],nums[i]); //save the product
               minimum[i]=min(minimum[i-1]*nums[i],nums[i]); // save the previous element
               
           }
            
            else
           {
               maximum[i]=max(minimum[i-1]*nums[i],nums[i]); //save the product
               minimum[i]=min(maximum[i-1]*nums[i],nums[i]); // save the previous element
               
           }
            
            max_product=max(max_product,maximum[i]);
        }
        
        return max_product;
    }
};