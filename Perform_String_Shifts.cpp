class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int a=s.size();
        
        
        int n=shift.size();
        for(int i=0;i<n;++i)
        {
            vector<char> temp(a);
            
            if(shift[i][0]==1)//right shift
            {
                int k=0;
                for(int j=0;j<a;++j)
                {
                    if(j+shift[i][1]>a-1)
                    {
                        temp[k]=s[j];
                        //cout<<temp[k]<<endl;
                        ++k;
                    }
                    else
                        temp[j+shift[i][1]]=s[j];
                        
                }
                
            }
           
            else //left shift
            {
                int k=a-1;
                for(int j=a-1;j>=0;j--)
                {
                    if(j-shift[i][1]<0)
                    {
                        temp[k]=s[j];
                        --k;
                    }
                    else
                        temp[j-shift[i][1]]=s[j];
                    
                }
                
                
            }
            
            for(int i=0;i<a;++i)
            {
                s[i]=temp[i];
            }
        }
        
        return s;
        

        
    }
};