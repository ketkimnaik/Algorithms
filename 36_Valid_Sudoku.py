class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        digits={str(i) for i in range(1,10)}
        size=9
        rows=[set() for _ in range(size)]
        cols=[set() for _ in range(size)]
        boxes=[set() for _ in range(size)]
        
        for i in range(size):
            for j in range(size):
                digit=board[i][j]
                
                if digit==".":
                    continue
                
                if digit not in digits:
                    return False
                
                box=(size//3) * (i // (size // 3)) + (j // (size // 3))
                
                if digit in rows[i] or digit in cols[j] or digit in boxes[box]:
                    return False
                rows[i].add(digit)
                print(rows)
                cols[j].add(digit)
                print(cols)
                boxes[box].add(digit)
                print(boxes)
                print("hi")
                
        return True
                

output:

[{'8'}, set(), set(), set(), set(), set(), set(), set(), set()]
[{'8'}, set(), set(), set(), set(), set(), set(), set(), set()]
[{'8'}, set(), set(), set(), set(), set(), set(), set(), set()]
hi
[{'3', '8'}, set(), set(), set(), set(), set(), set(), set(), set()]
[{'8'}, {'3'}, set(), set(), set(), set(), set(), set(), set()]
[{'3', '8'}, set(), set(), set(), set(), set(), set(), set(), set()]
hi
[{'7', '3', '8'}, set(), set(), set(), set(), set(), set(), set(), set()]
[{'8'}, {'3'}, set(), set(), {'7'}, set(), set(), set(), set()]
[{'3', '8'}, {'7'}, set(), set(), set(), set(), set(), set(), set()]
hi
[{'7', '3', '8'}, {'6'}, set(), set(), set(), set(), set(), set(), set()]
[{'6', '8'}, {'3'}, set(), set(), {'7'}, set(), set(), set(), set()]
[{'6', '3', '8'}, {'7'}, set(), set(), set(), set(), set(), set(), set()]
hi
[{'7', '3', '8'}, {'1', '6'}, set(), set(), set(), set(), set(), set(), set()]
[{'6', '8'}, {'3'}, set(), {'1'}, {'7'}, set(), set(), set(), set()]
[{'6', '3', '8'}, {'7', '1'}, set(), set(), set(), set(), set(), set(), set()]
hi
[{'7', '3', '8'}, {'9', '1', '6'}, set(), set(), set(), set(), set(), set(), set()]
[{'6', '8'}, {'3'}, set(), {'1'}, {'9', '7'}, set(), set(), set(), set()]
[{'6', '3', '8'}, {'9', '7', '1'}, set(), set(), set(), set(), set(), set(), set()]
hi
[{'7', '3', '8'}, {'9', '1', '6', '5'}, set(), set(), set(), set(), set(), set(), set()]
[{'6', '8'}, {'3'}, set(), {'1'}, {'9', '7'}, {'5'}, set(), set(), set()]
[{'6', '3', '8'}, {'9', '7', '1', '5'}, set(), set(), set(), set(), set(), set(), set()]
hi
[{'7', '3', '8'}, {'9', '1', '6', '5'}, {'9'}, set(), set(), set(), set(), set(), set()]
[{'6', '8'}, {'9', '3'}, set(), {'1'}, {'9', '7'}, {'5'}, set(), set(), set()]
[{'9', '6', '3', '8'}, {'9', '7', '1', '5'}, set(), set(), set(), set(), set(), set(), set()]
hi