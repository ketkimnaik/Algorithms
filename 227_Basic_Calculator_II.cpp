class Solution {
public:
    int calculate(string s) {
        int result=0;
        int temp_result=0;
        char oper='+';
        
        for(int i=s.find_first_not_of(' ');i<s.size();i=s.find_first_not_of(' ',i))
        {
            if(isdigit(s[i]))
            {
            int tmp=s[i]-'0';
            
            while(++i<s.size() && isdigit(s[i]))
                tmp=tmp*10+(s[i]-'0');
            
            switch(oper)
            {
            case('+'):temp_result+=tmp;
                    break;
            case('-'):temp_result-=tmp;
                    break;
            case('*'):temp_result*=tmp;
                    break;
            case('/'):temp_result/=tmp;
                    break;
                    
            }       
                    
            }
            else
            {
                if(s[i]=='+'|| s[i]=='-')
                {
                    result+=temp_result;
                    temp_result=0;
                }
                
                oper=s[i++];
            }
            
            
        }
        
        return result+temp_result;
        
    }
};