#include <iostream>
#include <string>
using namespace std;

string longestPalindrome( const string &s) {
    string longest = "";
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            string sub = s.substr(i, j - i + 1);
            string rev = string(sub.rbegin(), sub.rend());
            if (sub == rev && sub.size() > longest.size()) {
                longest = sub;
            }
        }
    }
    return longest;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    cout << "Longest Palindromic Substring: " << longestPalindrome(input) << endl;
    return 0;
}


//Time Complexity:O(n^3)
//Space Complexity:O(n)