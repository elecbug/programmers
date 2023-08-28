#include <string>
#include <vector>

using namespace std;

int mins(int x, int y) {
    return x < y ? x : y;
}
int maxs(int x, int y) {
    return x > y ? x : y;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 1) {
                for (int x = maxs(i - 1, 0); 
                     x <= mins(i + 1, board.size() - 1); x++) {
                    for (int y = maxs(j - 1, 0); 
                         y <= mins(j + 1, board[i].size() - 1); y++) {
                        if (board[x][y] != 1) {
                            board[x][y] = 2;
                        }
                    }
                }
            }
        }   
    }
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 0) {
                answer++;
            }
        }
    }
    return answer;
}