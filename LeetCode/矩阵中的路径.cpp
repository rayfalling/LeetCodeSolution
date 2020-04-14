#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::vector<char>> board;
    std::string word;
    bool find(int x, int y, int& index) {
        index++;
        if (y<0 || y>this->board.size() - 1 || x<0 || x>this->board[0].size() - 1) {
            index--;
            return false;
        }
        if (this->board[y][x] != this->word[index]) {
            index--;
            return false;
        }
        if (index == this->word.size() - 1 && this->word[index] == this->board[y][x]) {
            index--;
            return true;
        }
        const auto tmp = this->board[y][x];
        this->board[y][x] = ' ';
        const auto res = find(x - 1, y, index) || find(x + 1, y, index) || find(x, y - 1, index) || find(x, y + 1, index);
        this->board[y][x] = tmp;
        index--;
        return res;
    }
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        this->board = board;
        this->word = word;
        auto index = -1;
        for (auto y = 0; y < board.size(); y++) {
            for (auto x = 0; x < board[0].size(); x++) {
                if (find(x, y, index)) {
                    return true;
                }
            }
        }
        return false;
    }
};
