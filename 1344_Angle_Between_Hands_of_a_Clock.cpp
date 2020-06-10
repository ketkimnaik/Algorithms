class Solution {
public:
    double angleClock(int hour, int minutes) {
        double result=0.0;
        
        result=abs(0.5*(60*hour-11*minutes));
        
        if(result>180)
            result=360-result;
        return result;
    }
};