class Solution {
public:
    vector<int> dir = {-1, 0, 1, 0, -1};

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> time(n, vector<int>(n, INT_MAX));
        priority_queue< pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>> > pq;

        time[0][0] = grid[0][0];
        pq.push({time[0][0], {0, 0}});
        while(!pq.empty()){
            auto [t, cell] = pq.top();
            pq.pop();
            int r = cell.first, c = cell.second;

            if(r == n-1 && c == n-1) return t;
            if(t > time[r][c]) continue;
            for(int k = 0; k < 4; k++){
                int nr = r + dir[k], nc = c + dir[k + 1];

                if(nr >= 0 && nr < n && nc >= 0 && nc < n){
                    int nt = max(t, grid[nr][nc]);
                    if(nt < time[nr][nc]){
                        time[nr][nc] = nt;
                        pq.push({nt, {nr, nc}});
                    }
                }
            }
        }
        return INT_MAX;
    }
};