class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        result=[]
        a=len(nums)
        next_new=0
        
        for i in range(a):
            
            if i ==0 or nums[i] !=nums[i-1]:
                nums[next_new]=nums[i]
                next_new=next_new+1
        return next_new
                
                
                
        
        
        
       
       
        
        