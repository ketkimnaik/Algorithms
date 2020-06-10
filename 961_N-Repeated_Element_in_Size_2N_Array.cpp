class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        map<int,int> m;
        int n=A.size();
        for(int i=0;i<(n/2)+2;++i) {
            m[A[i]]++;
            
            if(m[A[i]]>1)
                return A[i];
        }
       return 0; 
    }
};