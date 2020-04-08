#include <vector>

class Solution {
public:
    int maxDistance(std::vector<std::vector<int>>& grid) {
        int N = grid.size();
        auto count_land = 0;
        auto count_turn = 0;
        for (auto i = 0; i < N; i++) {
            for (auto j = 0; j < N; j++) {
                if (grid[i][j] == 1) {
                    count_land++;
                }
            }
        }
        if (count_land == N * N || count_land == 0) {
            return -1;
        }
        auto count_last_space = N * N - count_land;
        while (count_last_space != 0) {
            count_turn++;
            for (auto i = 0; i < N; i++) {
                for (auto j = 0; j < N; j++) {
                    if (grid[i][j] == count_turn) {
                        if (i > 0 && grid[i - 1][j] == 0) {
                            grid[i - 1][j] = count_turn + 1;
                            count_last_space--;
                        }
                        if (i < N - 1 && grid[i + 1][j] == 0) {
                            grid[i + 1][j] = count_turn + 1;
                            count_last_space--;
                        }
                        if (j > 0 && grid[i][j - 1] == 0) {
                            grid[i][j - 1] = count_turn + 1;
                            count_last_space--;
                        }
                        if (j < N - 1 && grid[i][j + 1] == 0) {
                            grid[i][j + 1] = count_turn + 1;
                            count_last_space--;
                        }
                    }
                }
            }
        }
        return count_turn;
    }
};
