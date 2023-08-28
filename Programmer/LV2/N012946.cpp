#include <string>
#include <vector>

using namespace std;

vector<vector<int>> move(int from, int to, int n) {
    int other;
    switch (from + to) {
        case 3: other = 3; break;
        case 4: other = 2; break;
        case 5: other = 1; break;
    }
    if (n == 2) { 
        vector<vector<int>> result = {{from, other}, {from, to}, {other, to}};
        return result;
    }
    else {
        vector<vector<int>> result = move(from, other, n - 1);
        result.push_back({from, to});
        vector<vector<int>> temp = move(other, to, n - 1);
        result.insert(result.end(), temp.begin(), temp.end());
        return result;
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer = move(1, 3, n);
    return answer;
}