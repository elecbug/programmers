#include <string>
#include <vector>

using namespace std;

void part(vector<vector<int>>& vec, int x, int y, int& zero, int& one, int sz) {
    if ((vec[x][y] == vec[x + sz][y]) && (vec[x][y + sz] == vec[x + sz][y + sz])
       && (vec[x][y] == vec[x][y + sz]) && vec[x][y] / 2 == sz / 2) {
        if (vec[x][y] % 2 == 0) {
            zero -= 3;
            vec[x][y] = 2 * sz;
        }
        else {
            one -= 3;
            vec[x][y] = 2 * sz + 1;
        }
    }
}

void reculsive(vector<vector<int>>& vec, int& zero, int& one) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            if (vec[i][j] == 0) {
                zero++;
            }
            else {
                one++;
            }
        }
    }
    for (int sz = 2; sz <= vec.size(); sz *= 2) {
        for (int i = 0; i < vec.size(); i += sz) {
            for (int j = 0; j < vec.size(); j += sz) {
                part(vec, i, j, zero, one, sz / 2);
            }
        }
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer = vector<int>(2);
    reculsive(arr, answer[0], answer[1]);
    return answer;
}