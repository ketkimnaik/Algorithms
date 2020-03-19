class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         vector<int> result{};
        int count=0;
        int m=matrix.size();
        if(m==0)
            return result;
        int n =matrix[0].size();
        int i=-1,j=-1;
        
        int row=0;
        int col=1;
        while(count<(m*n))
        {
           //left to right 
           int l=row++/2;
            for(i++,j++;j<n-l;++j)
            {
                result.push_back(matrix[i][j]);
                count++;
            }
            
            //top to bottom
            l=col++/2;
            for(j--,i++;i<m-l;++i)
            {
                result.push_back(matrix[i][j]);
                count++;
            }
            
            //if all elements done then break
            if(count>=(m*n))
                break;
            
            //right to left
            l=row++/2;
            for(i--,j--;j>=0+l;--j)
            {
                result.push_back(matrix[i][j]);
                count++;
            }
            
            //bottom to top
            l=col++/2;
            for(j++,i--;i>=0+l;--i)
            {
                result.push_back(matrix[i][j]);
                count++;
            }
            
        }
        
        return result;
        
    }
};