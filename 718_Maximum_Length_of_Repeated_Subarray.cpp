Optimized Approach:

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m=A.size();
        int n=B.size();
        if(n>m) {
            swap(A, B);
            swap(m, n);
        }
        vector<int> first(n+1, 0);
        vector<int> second(n+1);
        second[0]=0;
        int res=0;
        
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(A[i-1]==B[j-1]) {
                    second[j] = first[j-1] + 1; 
                    res = max(res, second[j]);
                }
                else
                    second[j] = 0;
            }
            swap(first, second);
        }
        return res;
    }
};

Brute Force Approach:

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int res = 0;
        vector<vector<int>> v(A.size(), vector<int>(B.size(), 0));
        for (auto i = 0; i < A.size(); i++) {
            for (auto j = 0; j < B.size(); j++) {
                if (A[i] == B[j]) {
                    if (i == 0 || j == 0)
                        v[i][j] = 1;
                    else
                        v[i][j] = v[i - 1][j - 1] + 1;
                    
                    res = max(res, v[i][j]);
                }
            }
        }
        
        return res;
    }
};