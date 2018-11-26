#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int longestLength(0);
    for (int i = 0; i < s.size(); ++i) {            //令i = j' + 1
        vector<int> intVector(256, 0);              //常用字符对应的ASCII值0 ~ 255，可以使复杂度降低到O(1)
        ++intVector[s[i]];
        int j = i + 1;
        while (j < s.size()) {
            if (intVector[s[j]] == 0) {
                ++intVector[s[j]];
                ++j;
            } else if (intVector[s[j]] != 0)
                break;
        }
        longestLength = max(longestLength, j - i);  //max定义在algorithm
        while (s[i] != s[j])                        //令i = j'
            ++i;
    }
    return longestLength;
}

int main() {
    string s("abcbef");
    int longestLength = lengthOfLongestSubstring(s);
    cout << longestLength;
    return 0;
}
