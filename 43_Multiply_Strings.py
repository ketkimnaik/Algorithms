class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        l1=len(num1)
        l2=len(num2)
        dicts={"1":1,"0":0,"3":3,"2":2,"4":4,"5":5,"6":6,"7":7,"8":8,"9":9}
        final=0
        f=0
        p=l1
        for j in range(l2):
            l1=p
            if num2[l2-1-j] in dicts:
                
                carry=v=k=0
                
                while l1!=0:
                    c= dicts[num1[l1-1]]*dicts[num2[l2-1-j]]*pow(10,k)
                    l1-=1
                    k+=1
                    v+=c
                    
                    
            final+=pow(10,f)*v        
            f+=1        
            
            
            
        
        return str(final)
                
        