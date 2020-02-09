class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
	vector<int> count(26);
	int hi = 0, hiCount = 0;
	for(char t : tasks)
    {
        hi = max(hi, ++count[t - 'A']);
    }
	for(int i = 0; i < 26; i++) 
    {
        if(count[i] == hi) 
            hiCount++;
    }
	return max((int)tasks.size(), (hi - 1) * (n + 1) + hiCount);
}
};