class Solution {
public:
    const int INF = 1e9;
    vector<int> d = {-1, 0, 1, 0, -1};

    bool inside(int i, int j, int n){
        return (i >= 0 && i < n && j >= 0 && j < n);
    }
    vector<vector<int>> mark(vector<vector<int>> &grid){
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INF));
        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }
        int t = 1;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                pair<int,int> p = q.front();
                q.pop();
                int r = p.first, c = p.second;
                for(int i = 0; i < 4; i++){
                    int nr = r + d[i], nc = c + d[i+1];
                    if(inside(nr, nc, n) && dist[nr][nc] == INF){
                        q.push({nr, nc});
                        dist[nr][nc] = t;
                    }
                }
            }
            t++;
        }
        return dist;
    }
    
    bool help(vector<vector<int>> &dist, int r, int c, int n, int safe,
                vector<vector<int>> &vis){
        if(r == n-1 && c == n-1) return true;
        vis[r][c] = 1;

        for(int i = 0; i < 4; i++){
            int nr = r + d[i], nc = c + d[i+1];
            if(inside(nr, nc, n) && !vis[nr][nc] && dist[nr][nc] >= safe){
                bool flag = help(dist, nr, nc, n, safe, vis);
                if(flag) return true;
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist = mark(grid);
        int s = 0, e = 2*n, ans = -1, startSafe = dist[0][0];;
        while(s <= e){
            int m = (s + e)/2;
            if(m > startSafe){
                e = m - 1;
                continue;
            }
            vector<vector<int>> vis(n, vector<int>(n, 0));
            if(help(dist, 0, 0, n, m, vis)){
                ans = m;
                s = m + 1;
            }
            else e = m - 1;
        }
        return ans;
    }
};