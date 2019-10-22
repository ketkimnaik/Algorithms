class Solution:
    def search(self, nums: List[int], target: int) -> int:
        a=len(nums)
        left,right=0,a-1
        while left<=right:
            mid=(left+right)//2
            
            if nums[mid]==target:
                return mid
            
            if nums[left]<=nums[mid]:#left sorted
                if target>=nums[left] and target<nums[mid]:
                    right=mid-1
                else:
                    left+=1
            else:
                if target>nums[mid] and target<nums[right]:
                    left=mid+1
                else:
                    right-=1
        return -1
                
            
        
            