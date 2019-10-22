class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def result(target,left,right):
            if left>right:
                return left
            mid=(left+right)//2
            if target>=nums[mid]:
                left=mid+1
            else:
                right=mid-1
            return result(target,left,right)
        
        lower=result(target-0.5,0,len(nums)-1)
        upper=result(target+0.5,0,len(nums)-1)
        
        if lower==upper:
            return [-1,-1]
        else:
            return [lower,upper-1]
        
                
        
        
        
            
    
        