class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result=[[]]
        
        for n in nums:
            temp=[]
            for p in result:
                for i in range(len(p)+1):
                    temp.append(p[:i]+[n]+p[i:])
                    
            result=temp
            
        return result