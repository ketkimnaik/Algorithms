class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        flag=index=0
        for i in range(len(nums)):
            if nums[i]==target:
                flag=1
                return i
            
            if nums[i]>target and flag !=1:
                index=i
                break
                
        return index