class Solution {

private:

    int dir[5] = {0,-1,0,1,0};

    void bfs(int r, int c, vector<vector<char>> &board, vector<vector<bool>> &safe){

        safe[r][c] = true;

        queue<pair<int,int>> q;

        q.push({r,c});

        while(!q.empty()){

            int row = q.front().first;

            int col= q.front().second;

            q.pop();

            for(int i = 0; i < 4; ++i){

                int nrow = row + dir[i], ncol = col + dir[i+1];

                if(nrow >= 0 && ncol >= 0 && nrow < board.size() && ncol < board[0].size() && board[nrow][ncol] != 'X' && !safe[nrow][ncol]){

                    safe[nrow][ncol]  = true;

                    q.push({nrow,ncol});

                }

            }

        }

    }

public:

    void solve(vector<vector<char>>& board) {

        int m = board.size(), n = board[0].size();

        vector<vector<bool>> safe(m,vector<bool>(n,false));

        for(int i = 0; i < m; ++i){

            for(int j= 0; j < n; ++j){

                if(i == 0 || j == 0 || i == m-1 || j == n-1){

                    if(board[i][j] != 'X' && !safe[i][j]){

                        bfs(i,j,board,safe);

                    }

                }

            }

        }

        for(int i =0; i < m ; ++i){

            for(int j = 0; j < n; ++j){

                if(board[i][j] != 'X' && safe[i][j] == true){

                    continue;

                }else{

                    board[i][j] = 'X';

                }

            }

        }

    }

};
