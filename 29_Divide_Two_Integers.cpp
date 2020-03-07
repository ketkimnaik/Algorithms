class Solution {
public:
   int divide(int dividend, int divisor) {
       int flag=1;
        
        if(dividend<0 && divisor<0)
        {
            flag=1;
        }
        
        else if(dividend<0)
        {
            
            flag=-1;
        }
        else if(divisor<0)
        {
            
            flag=-1;
        }
       
       long a=labs(dividend);
        long b=labs(divisor);
     
        long result = exp(log(a)-log(b));
        
        if(result >INT_MAX)
            return flag==1 ? INT_MAX:INT_MIN;
        return flag*(int)res;
       
   }
}; 