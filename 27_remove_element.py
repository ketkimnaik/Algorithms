class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        new_index=0
        for i in range(len(nums)):
            if val!=nums[i]:
                nums[new_index]=nums[i]
                new_index=new_index+1
        return new_index
        