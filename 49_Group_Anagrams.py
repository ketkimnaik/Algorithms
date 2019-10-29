from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        sorted_list=defaultdict(list)
        
        for w in strs:
            letter_list=[c for c in w] # this gives output in for ['e','a','t'] for each word in list
            letter_list.sort()
            sorted_words="".join(letter_list)#it will will join letter of each word i.e ['e','a','t']=ate
            sorted_list[sorted_words].append(w) #sorted_wprd is acting as key
            
        return list(sorted_list.values()) # this will return just values for that key
        