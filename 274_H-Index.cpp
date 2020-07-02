class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h;
        priority_queue<int> pq(begin(citations), end(citations));
        
        for (h = 0; !pq.empty() && h < pq.top(); ++h)
            pq.pop();  

        return h;
    }
};