#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(const vector<string>& strs) {
    if (strs.empty()) {
        return "";
    }

    string prefix = strs[0];

    for (int i = 1; i < strs.size(); i++) {
        while (strs[i].find(prefix) != 0) {  // While the prefix is not a prefix of the current string
            prefix = prefix.substr(0, prefix.length() - 1); // Reduce the prefix by one character
            if (prefix.empty()) {
                return "";
            }
        }
    }

    return prefix;
}

int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    
    string result = longestCommonPrefix(strs);
    
    if (result.empty()) {
        cout << "There is no common prefix." << endl;
    } else {
        cout << "The longest common prefix is: " << result << endl;
    }

    return 0;
}