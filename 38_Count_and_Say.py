class Solution:
    def countAndSay(self, n: int) -> str:
        a=[1]
        
        for i in range(n-1):
            result=[]
            for j in a:
                
                if not result or result[-1] != j:
                    result += [1,j] # new number is count=1 [count,num]
                else:
                    result[-2]+=1 # if that number is repeated in sequence increase it count
                    
            a=result
            
        return "".join(map(str,a)) # return the result in string format
        