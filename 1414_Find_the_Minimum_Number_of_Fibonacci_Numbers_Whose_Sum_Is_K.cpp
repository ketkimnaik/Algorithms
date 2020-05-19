class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        
        vector<int> fib;
        fib.push_back(1);
        fib.push_back(1);
        int first=1;
        int second=1;
        while(second<k)
        {
            int num=first+second;
            first=second;
            second=num;
            fib.push_back(second);
        }
        
        if(fib.back()==k)
            return 1;
        else
            fib.pop_back();
        
        int result=0,num=k;
        
        for(int i=fib.size()-1;i>=0;--i)
        {
            if(fib[i]<=num)
            {
                result++;
                num-=fib[i];
            }
            
            if(num==0)
                break;
        }
        
        return result;
            
    }
};