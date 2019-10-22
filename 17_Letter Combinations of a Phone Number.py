class Solution:
    def letterCombinations(self, d: str) -> List[str]:
        mapping = {'2': ['a', 'b', 'c'],
                 '3': ['d', 'e', 'f'],
                 '4': ['g', 'h', 'i'],
                 '5': ['j', 'k', 'l'],
                 '6': ['m', 'n', 'o'],
                 '7': ['p', 'q', 'r', 's'],
                 '8': ['t', 'u', 'v'],
                 '9': ['w', 'x', 'y', 'z']}
        results=[[]]
                
        for digit in d:
            temp=[]
           
            for result in results:
                
                for letter in mapping[digit]:
                    temp.append(result + [letter])
                    
                    
            results = temp
            
            
        return ["".join(result) for result in results]
                
                
            
            
            
            
            
        
                
                
                
                
        