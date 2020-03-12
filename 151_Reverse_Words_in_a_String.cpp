class Solution {
public:
    string reverseWords(string s) {
        
        if(!s.size())
            return s;
        
        // remove all spaces that are more than 1
        
        for(int i=0;i<s.size()-1;++i)
        {
            if(s[i]==' ' && s[i+1]==' ')
            {
                s=s.substr(0,i)+s.substr(i+1,s.size()-i+1);
                --i;//i shift by one place
            }
        }
        
        //remove space in first position
        if(s[0]==' ')
        {
            if(s.size()==1)
                return "";
            s=s.substr(1,s.size()-1);
        }
        
        //remove space at the end of string
        
        if(s[s.size()-1]==' ')
        {
            if(s.size()==0)
                return "";
            s=s.substr(0,s.size()-1);
        }
        
        // reverse string completely
        
        int i=0;
        int j=s.size()-1;
        
        while(i<j)
        {
            char temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            i++;
            j--;
        }
        
        //now reverse particular word till space to get desired output
        
        i=0;
        while(i<s.size()-1)
        {
            j=i;
            while(s[j+1] !=' ' && j+1 !=s.size())
                ++j;
            int end=j;
            while(i<j)
            {
                char temp=s[i];
                s[i]=s[j];
                s[j]=temp;
                ++i;
                --j;
            }
            
            i=end+2;
        }
        
        return s;
    }
};