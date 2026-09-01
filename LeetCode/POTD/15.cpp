class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int sr = 0, sc = 0;
        int cnt = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        // Find S and assign an ID to every L
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if(classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        // No litter
        if(cnt == 0)
            return 0;

        // Initially ALL litter is uncollected.
        // So all bits are 1.
        int fullMask = (1 << cnt) - 1;

        queue<tuple<int,int,int,int>> q;

        // row, col, energy, mask
        q.push({sr, sc, energy, fullMask});

        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << cnt, false)
                )
            )
        );

        visited[sr][sc][energy][fullMask] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while(!q.empty()) {

            int sz = q.size();

            while(sz--) {

                auto [r, c, e, mask] = q.front();
                q.pop();

                // No litter left
                if(mask == 0)
                    return moves;

                // Cannot move if energy is 0
                if(e == 0)
                    continue;

                for(int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Outside grid
                    if(nr < 0 || nr >= m ||
                       nc < 0 || nc >= n)
                        continue;

                    // Obstacle
                    if(classroom[nr][nc] == 'X')
                        continue;

                    int newEnergy = e - 1;
                    int newMask = mask;

                    // If we reach R, energy becomes full
                    if(classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    // If we reach L, mark it as collected
                    if(classroom[nr][nc] == 'L') {
                        int idx = id[nr][nc];

                        newMask &= ~(1 << idx);
                    }

                    if(!visited[nr][nc][newEnergy][newMask]) {

                        visited[nr][nc][newEnergy][newMask] = true;

                        q.push({
                            nr,
                            nc,
                            newEnergy,
                            newMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};