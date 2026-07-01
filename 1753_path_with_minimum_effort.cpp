class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[0][0] = 0;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>> pq;
        pq.push({0, {0,0}});

        vector<int> d = {-1, 0, 1, 0, -1};

        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            int eff = it.first, x = it.second.first, y = it.second.second;
            if(x==n-1 && y==m-1) return eff;

            for(int i=0; i<4; i++){
                int nx = x+d[i], ny = y+d[i+1];
                if(nx>=0 && nx<n && ny>=0 && ny<m && 
                    dist[nx][ny]>max(eff, abs(heights[nx][ny] - heights[x][y]))){

                    dist[nx][ny] = max(eff, abs(heights[nx][ny] - heights[x][y]));
                    pq.push({dist[nx][ny], {nx, ny}});
                }
            }
        }
        return dist[n-1][m-1];
    }
};