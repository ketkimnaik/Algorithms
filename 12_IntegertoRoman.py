class Solution:
    def intToRoman(self, num: int) -> str:
        mapping = [(1000,"M"),(900,"CM"),(500,"D"),(400,"CD"),(100,"C"),(90,"XC"),(50,"L"),(40,"XL"),(10,"X"),(9,"IX"),(5,"V"),(4,"IV"),(1,"I")]
        n=num
        roman=[]
        
        for i, numeral in mapping:'''i takes values like 1000,900,500,...till 1 and numeral takes values like M,CM,...,I and for loop keep on running till the time number in greater than on of the i value.'''
            
           
            while n >= i:

                n = n - i
                roman.append(numeral)
                
                
        return "".join(roman)

s=Solution()
print(s.intToRoman(33))
