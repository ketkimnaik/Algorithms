class Solution:
    def canJump(self, nums: List[int]) -> bool:
        
        l=len(nums)
        
        i=0
        while l>i:
            i+=nums[i]
            
            if i==(l-1):
                return True
            if nums[i]<=0:
                return False
            
            
        return False
            
            
            
            
        