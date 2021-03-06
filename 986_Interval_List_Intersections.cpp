class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> result{};
        if(A.size() == 0 || B.size() == 0)
            return result;
        
        for(int i = 0, j = 0; i < A.size() && j < B.size() ; ){
            if(A[i][1] >= B[j][0] && A[i][1] >= B[j][1] && (B[j][0] >= A[i][0] || B[j][1] >= A[i][0])){
                result.push_back({max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});
                j++;
            }
            else if(A[i][1] >= B[j][0] && A[i][1] <= B[j][1]){
                result.push_back({max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});
                i++;
            }
            else if(B[j][0] > A[i][0])
                i++;
            else
                j++;
            
                
        }
        
        return result;
    }
};