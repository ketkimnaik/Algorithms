class Solution:
    def lengthOfLongestSubstring(self, s) :
        dicts = {}
        maxlength = start = 0
        for i,value in enumerate(s):
            
            if value in dicts:
                sums = dicts[value] + 1
                print (dicts[value])
                if sums > start:
                    start = sums
            num = i - start + 1
            
            print (start)
            print(num)
            print("\n")
            if num > maxlength:
                maxlength = num
            dicts[value] = i
        return maxlength

s = "pwwfe"
solution= Solution()
print(solution.lengthOfLongestSubstring(s))