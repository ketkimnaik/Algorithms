class Solution {
public:
    bool buddyStrings(string A, string B) {
        
        int asize = A.size();
        int bsize = B.size();
        
        if(asize != bsize) return false;
        
        vector<int> count_letter(26, 0);
        int count = 0;
        vector<int> pos{};
        
        for(int i = 0; i < asize; ++i) {
            
            if(A[i] != B[i]) {
                count++;
                pos.push_back(i);
            }
            count_letter[A[i] - 'a']++;
            if(count > 2) return false;
        }
        
        if(count == 2) {
            if (A[pos[1]] == B[pos[0]] && A[pos[0]] == B[pos[1]]) return true;
        }
        
        
        if(count == 0) {
            // cout<<"hi";
            for(int i = 0; i < 26; ++i) {
                // cout<<i<<"  "<< count_letter[i]<<endl;
                if(count_letter[i] >= 2) return true;
            }
        }
    
        return false;
    }
};