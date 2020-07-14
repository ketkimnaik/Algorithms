class Solution {
public:
    int Recursion(int n, int k) {
        if(n == 1) return 0;
        
        int ans ;
        ans = Recursion(n - 1, k / 2);
        
        if(k % 2 == 0) {
            if (ans == 1) {
               return 1; 
            } else {
                return 0;
            }
        } else {
            if (ans == 1) {
               return 0; 
            } else {
                return 1;
            }
        }
    }
    
    int kthGrammar(int N, int K) {
        return Recursion(N, K - 1); // 0 indexed
    }
};