class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i=0
        k=len(nums)-2
        while i>=0 and nums[i]>nums[i+1]:
            i-=1
            
        if i!=-1:
            j=i+1
            while j<len(nums) and nums[i]<nums[j]:
                j+=1
            j-=1
            nums[i],nums[j]=nums[j],nums[i]
            
            #reverse the lst
            left=i+1
            right=len(nums)-1
            while left<right:
                nums[left],nums[right]=nums[right],nums[left]
                left+=1
                right-=1
        else:
            for i in range(len(nums)-1):
                for j in range(i+1,len(nums)):
                    if nums[i]>nums[j]:
                        nums[i],nums[j]=nums[j],nums[i]
                        
        return nums
        