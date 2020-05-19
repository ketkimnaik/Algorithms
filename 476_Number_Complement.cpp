class Solution {
public:
    int findComplement(int num) {
        
       
        int a=ceil(log2(num));
        
        int result=(pow(2,a)-1 )-num;
        if(result==-1)
            result=pow(2,a)-1;
        
        return result;
        
    }
};