public class Solution {
    public string solution(string s) {
        string str = "";
        if (s.Length % 2 == 0) {
            str += s[s.Length / 2 - 1];
            str += s[s.Length / 2];
        }
        else {
            str += s[s.Length / 2];
        }
        return str;
    }
}