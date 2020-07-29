struct Log {
        int id;
        string status;
        int time;
    };
class Solution {
public:
    
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        
        vector<int> result(n, 0);
        stack<Log> stk;
        string temp1, temp2, temp3;

        
        for(auto l : logs) {
            
            stringstream ss(l);
            getline(ss, temp1, ':');
            getline(ss, temp2, ':');
            getline(ss, temp3, ':');
            int time_added;
            
            Log item = {stoi(temp1), temp2, stoi(temp3)};
            
            if (item.status == "start") {
                
                stk.push(item);
                
            } else {
                
                assert(stk.top().id == item.id);
                
                time_added = item.time - stk.top().time + 1;
                result[item.id] += time_added;
                
                stk.pop();
                
                if (! stk.empty()) {
                    assert(stk.top().status == "start");
                    result[stk.top().id] -= time_added;

                }
            }
            
        }
        
        return result;
    }
};