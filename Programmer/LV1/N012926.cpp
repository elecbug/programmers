#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    for (int i = 0; i < s.length(); i++) {
        if ('a' <= s[i] && 'z' >= s[i]) {
            s[i] = (s[i] + n - 'a') % 26 + 'a';
        }
        else if ('A' <= s[i] && 'Z' >= s[i]) {
            s[i] = (s[i] + n - 'A') % 26 + 'A';
        }
    }
    return s;
}