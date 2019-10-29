class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        result=0
        maximum=0
        for n in nums:
            if maximum>0:
                maximum +=n
            else:
                maximum=n
            result=max(result,maximum)
        return result
        