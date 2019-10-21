class Solution():
    def solve(self,a):
        l=len(a)
        area = a[0]*1
        for i in range(0,l):
            for j in range(0,l):
                c=abs(j-i)
                if a[i] < a[j]:
                    area1= a[i] * c
                    if area1 > area:
                        area = area1
        return area
            
s=Solution()        

a=[1,8,6]

print(s.solve(a))         
            
            
                
    
        


            
        
        
        
        



