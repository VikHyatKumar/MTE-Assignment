#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastIndex;
    int maxLen = 0, left = 0;

    for (int right = 0; right < s.length(); ++right) {
        char ch = s[right];

        if (lastIndex.find(ch) != lastIndex.end() && lastIndex[ch] >= left) {
            left = lastIndex[ch] + 1;
        }

        lastIndex[ch] = right;
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    string s = "abcabcbb";
    int result = lengthOfLongestSubstring(s);

    cout << "Length of longest substring without repeating characters = " << result << endl;

    return 0;
}


/*
Algorithm:
1. Initialize an unordered_map to store the last index of each character.
2. Initialize two variables: maxLength to store the maximum length of the substring and start to track the start index of the current substring.
3. Iterate through the string using an index `end`:
   a. If the current character is already in the map and its last index is greater than or equal to `start`, update `start` to `charIndexMap[s[end]] + 1`.
   b. Update the last index of the current character in the map.
   c. Update maxLength as the maximum of maxLength and (end - start + 1).
4. Return maxLength.

Time Complexity:
- O(n)

Space Complexity:
- O(min(n, a))
*/
