class Solution {
public:
    int trailingZeroes(int n) {
        int answer = 0;
        
        while(n) {
            n = n / 5;
            answer += n;
        }
        
        return answer;
    }
};