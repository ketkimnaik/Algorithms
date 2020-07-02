Optimized Approach:

class StockSpanner {
public:
    vector<int> elements{};
    int i;
    stack<int> stk;
    StockSpanner() {
        i = 0;
    }
    
    int next(int price) {
        elements.push_back(price);
        
        while(! stk.empty() && elements[i] >= elements[stk.top()]) {
            stk.pop();
        }
        
        int result;
        
        if(stk.empty()) {
            result = i + 1;
        } else {
            result = i - stk.top();
        }
        
        stk.push(i++);
        
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
Brute Force:

class StockSpanner {
public:
    vector<int> elements{};
    int i;
    StockSpanner() {
        i = 0;
    }
    
    int next(int price) {
        elements.push_back(price);
        
        i++;
        int count = 0;
        int temp = i - 1;
        while(temp >= 0 && elements[temp--] <= price) {
            count++;
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */