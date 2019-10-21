
from numpy import iinfo, int32

class Solution():
    def Atoi(self, str):
        s= str.strip() # remove all white spaces that are there in starting
        i=iinfo(int32) #to get all inforrmation of int 32 i.e its min and max size
        built_string= "" # to hold the final numeric string

        for j, st in enumerate(s):
            if j==0 and st !='-' and st != '+' and not st.isnumeric() :
                return 0
            if j>0:
                if not st.isnumeric()and (st =='-' or st == '+')  : return 0
                if not st.isnumeric(): break
                
            

            built_string += st
        multiplier=1
        if built_string[0] =="-" :
            multiplier= -1
            built_string=built_string[1:]
        elif built_string[0] =="+" :
            built_string=built_string[1:]

        if not built_string: return 0

        final = int(built_string) * multiplier
        
       
       
        if i.min > final:
            final=i.min
        if i.max < final:
            final=i.max

        return final


s=Solution()
print(s.Atoi("294 not out"))

       
          




            



