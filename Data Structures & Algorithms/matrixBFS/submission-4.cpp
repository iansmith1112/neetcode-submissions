class Solution {
public:
    int shortestPath(std::vector<std::vector<int>>& grid) {
        if(grid.size() == 0) return -1;
        if(grid.size() < 2 && grid[0][0] == 1) return -1;

        int ROWS = grid.size();
        int COLS = grid[0].size();
        int length = 0;
        bool found = false;
        std::queue<std::pair<int, int>> q;
        std::vector<std::vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        
        q.push({0,0});

        while (q.size() > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int row, col;
                // Check if we've made it
                std::pair<int, int> node = q.front();
                q.pop();
                row = node.first;
                col = node.second;

                if(row == ROWS - 1 && col == COLS - 1) return length;
                if(grid[row][col] == 1) continue;
                // Check neighbors
                int numNeighbors = 4;
                // row, col
                std::pair<int,int> pairs[] = {{1,0}, {-1, 0}, {0,-1}, {0,1}};
                for (int j = 0; j < numNeighbors; j++) {
                    int offsetRow = row + pairs[j].first;
                    int offsetCol = col + pairs[j].second;
                    if(offsetRow >= ROWS || offsetRow < 0 || 
                        offsetCol >= COLS || offsetCol < 0 || 
                        visited[offsetRow][offsetCol] || 
                        grid[offsetRow][offsetCol] == 1) {    
                        continue;
                    }
                    // Add to queue and mark visited
                    q.push({offsetRow, offsetCol});
                    visited[offsetRow][offsetCol] = true;
                }
            }
            // increment length
            length += 1;
        }
        return -1;
    }
};
