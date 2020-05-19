Optimized using floyd Warshall algo:

class Solution {
public:
	int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
		vector<vector<int>> dp(n,vector<int>(n,INT_MAX/2));
		for(auto& x:edges){
			dp[x[0]][x[1]]=x[2];
			dp[x[1]][x[0]]=x[2];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
				}
			}
		}   
		int ans=-1;
		int cur=INT_MAX;
		for(int i=0;i<n;i++){
			int count=0;
			for(int j=0;j<n;j++){
				if(j!=i && dp[i][j]<=distanceThreshold){
					count++;
				}
			}
			if(count<=cur){
				cur=count;
				ans=i;
			}
		}
		return ans;
	}
};

Brute Force:

class Solution {
    list< pair<int, int> > *adj;
public:
    
    void dijkshtras(int s,int dist,vector<int> &result,int n)
    {
        int count=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        vector<int> d(n,INT_MAX);
        pq.push(make_pair(0,s));
        d[s]=0;
        
        while(!pq.empty())
        {
            int u=pq.top().second;
            pq.pop();
            list< pair<int, int> >::iterator it; 
            for(it=adj[u].begin();it !=adj[u].end();++it)
            {
                int v=(*it).first;
                int weight=(*it).second;
                
                if(d[v]>d[u]+weight)
                {
                    d[v]=d[u]+weight;
                    pq.push(make_pair(d[v],v));
                    
                }
            }
        }
        
        for(int i=0;i<n;++i)
        {
            if(d[i]>0 && d[i]<=dist)
                count++;
            
        }
        
        result[s]=count;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<int> result(n,0);
        adj=new list<pair<int,int>> [n];;
        
        for(auto &i: edges)
        {
            adj[i[0]].push_back(make_pair(i[1], i[2])); 
    adj[i[1]].push_back(make_pair(i[0], i[2])); 
        }
        for(int i=0;i<n;++i)
        {
            dijkshtras(i,distanceThreshold,result,n);
        }
        
        int minimum;
        int compare=INT_MAX;
        for(int i=0;i<n;++i)
        {
            compare=min(compare,result[i]);
            if(compare==result[i])
                minimum=i;
        }
        
        return minimum;
    }
};