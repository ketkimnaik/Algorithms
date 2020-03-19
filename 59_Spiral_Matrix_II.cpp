class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> result(n,vector<int> (n));
        vector<int> path{};
        if(n==0)
            return result;
        
        
        int i=-1,j=-1;
        int row=0;
        int col=1;
        int count=1;
        while(count <= (n*n))
        {
            int l=row++/2;
            
            for(i++,j++;j<n-l;++j)
            {
               
                result[i][j]= count++;
            }
            
            
             l=col++/2;
            
            for(i++,j--;i<n-l;++i)
            {
               result[i][j]= count++;
                
            }
            
            l=row++/2;
           
            for(i--,j--;j>=0+l;--j)
            {
               result[i][j]= count++;
                
            }
            
          l=col++/2;
            
            for(i--,j++;i>=0+l;--i)
            {
               result[i][j]= count++;
            }
           
        }
        
        return result;
    }
};

Optimal Solution:

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        if(!n) {
            return matrix;
        }
        int t = 0;
        int b = n - 1;
        int l = 0;
        int r = n - 1;
        int dir = 0;
        int elem = 1;
        while(t <= b && l <= r) {
            if(dir == 0) {
                for(int i = l; i <= r; i++) {
                    matrix[t][i] = elem;
                    elem++;
                }
                t++;
                dir = 1;
            }
            else if(dir == 1) {
                for(int i = t; i <= b; i++) {
                    matrix[i][r] = elem;
                    elem++;
                }
                r--;
                dir = 2;
            }
            else if(dir == 2) {
                for(int i = r; i >= l; i--) {
                    matrix[b][i] = elem;
                    elem++;
                }
                b--;
                dir = 3;
            }
            else if(dir == 3) {
                for(int i = b; i >= t; i--) {
                   matrix[i][l] = elem;
                   elem++;
                }
                l++;
                dir = 0;
            }
        }
        return matrix;
    }
};