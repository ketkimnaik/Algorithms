class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
         
        temp=[]
        a=[]
        l=len(nums)
        
        for i in range(l-3):
            
            j=i+1
            for c1 in range(j,(l-2)):
                
                k=j+1
                for c2 in range(k,(l-1)):
                   
                    m=k+1
                    for c3 in range(m,(l)):
                        
                        if nums[i]+nums[c1]+nums[c2]+nums[c3]==target:
                            a=[nums[i],nums[c1],nums[c2],nums[c3]]
                            a.sort()
                            
                            temp.append(a)
                            
                            
                            

       
        final_result=[]
        for i in temp:
            if i not in final_result:
                final_result.append(i)
        final_result.sort()
        return final_result
       
        