class Solution {
public:
    vector<int> dir = {-1, 0, 1, 0, -1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue< pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>> > pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        while(!pq.empty()){
            auto [eff, cell] = pq.top();
            pq.pop();
            int r = cell.first, c = cell.second;

            if(r == m - 1 && c == n - 1) return eff;
            if(eff > dist[r][c]) continue;

            for(int k = 0; k < 4; k++){
                int nr = r + dir[k], nc = c + dir[k + 1];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    int edge = abs(heights[r][c] - heights[nr][nc]);
                    int neff = max(eff, edge);

                    if(neff < dist[nr][nc]){
                        dist[nr][nc] = neff;
                        pq.push({neff, {nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};