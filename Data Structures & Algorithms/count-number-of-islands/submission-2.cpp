class Solution {
private:
   class DSU{
        int n; 
        vector<int> parent, rank;
     public:
        DSU(int n ){
            this->n = n;
            for(int i = 0 ; i < n; i++){
                parent.push_back(i);
                rank.push_back(0);
            }
        }

        int find(int x){
            if(parent[x] == x){
                return x;
            }
            return parent[x] = find(parent[x]);
        }
         
        bool unionByRank(int a, int b){
            int pa = find(a);
            int pb = find(b);

            if(pa == pb) return false;

            if(rank[pa] == rank[pb]){
                parent[pb] = pa;
                rank[pa]++;
            }else if (rank[pa] > rank[pb]){
                parent[pb] = pa; 
            }else {
                parent[pa] = pb;
            }
            return true;
        }
   };
public:

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;

        int row = grid.size() , col = grid[0].size();
        int island = 0;
        DSU dsu(row * col);
        int directions[2][2]= {{1, 0}, {0, 1}};

        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col; j++){
                if(grid[i][j] == '1'){
                    island++;
                    int current = i * col + j;
                    for(auto& d : directions){
                        int r = i + d[0];
                        int c = j + d[1];
                        if(r >= 0 && c >= 0 && r < row && c < col && grid[r][c] == '1'){
                            int neighbour = r * col + c;
                            if(dsu.unionByRank(current, neighbour)){
                                island --;
                            }
                        }
                    }
                }
            }
        }
       
       return island;
    }
};
