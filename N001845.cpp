#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answers = 1;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] != nums[i + 1]) {
            answers++;
        }
    }
    return answers > nums.size() / 2 ? nums.size() / 2 : answers;
}