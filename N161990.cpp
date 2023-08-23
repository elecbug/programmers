#include <string>
#include <vector>

using namespace std;

bool have_file(string str) {
    for (int i = 0 ; i < str.length(); i++) {
        if (str[i] == '#') {
            return true;
        }
    }
    return false;
}

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer = vector<int>(4);
    for (int i = 0; i < wallpaper.size(); i++) {
        if (have_file(wallpaper[i])) {
            answer[0] = i;
            break;
        }
    }
    for (int i = wallpaper.size() - 1; i >= 0; i--) {
        if (have_file(wallpaper[i])) {
            answer[2] = i + 1;
            break;
        }
    }
    int min = wallpaper[0].length(), max = 0;
    for (int i = 0; i < wallpaper.size(); i++) {
        for (int j = 0; j < wallpaper[i].length(); j++) {
            if (wallpaper[i][j] == '#' && j < min) {
                min = j;
                break;
            }
        }
        for (int j = wallpaper[i].length() - 1; j >= 0; j--) {
            if (wallpaper[i][j] == '#' && j > max) {
                max = j;
                break;
            }
        }
    }
    answer[1] = min;
    answer[3] = max + 1;
    return answer;
}