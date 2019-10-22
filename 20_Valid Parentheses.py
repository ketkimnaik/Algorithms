class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []

        # Hash map for keeping track of mappings. This keeps the code very clean.
        # Also makes adding more types of parenthesis easier
        mapping = {")": "(", "}": "{", "]": "["}

        # For every bracket in the expression.
        for c in s:
            if c in mapping:
                if stack:
                    last_element=stack.pop()
                else:
                    last_element="#"
                if mapping[c] != last_element:
                    return False
            else:
                stack.append(c)
                
        return not stack  
            