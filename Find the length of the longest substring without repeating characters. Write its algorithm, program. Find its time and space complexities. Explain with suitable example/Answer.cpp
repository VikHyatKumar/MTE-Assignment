#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastSeen;
    int maxLen = 0, left = 0;

    for (int right = 0; right < s.length(); ++right) {
        char ch = s[right];

        if (lastSeen.find(ch) != lastSeen.end() && lastSeen[ch] >= left) {
            left = lastSeen[ch] + 1;
        }

        lastSeen[ch] = right;
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
- O(n), where n is the length of the string. Each character is processed at most twice (once for adding to the map and once for updating the start index).

Space Complexity:
- O(min(n, a)), where n is the length of the string and a is the size of the character set (e.g., 26 for lowercase English letters).

Example:
Input: "abcabcbb"
Output: 3
Explanation: The longest substring without repeating characters is "abc", with a length of 3.
*/