#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generatePermutations(string& s, int start, vector<string>& result) {
    if (start == s.length()) {
        result.push_back(s);
        return;
    }
    for (int i = start; i < s.length(); i++) {
        swap(s[start], s[i]);

        generatePermutations(s, start + 1, result);

        swap(s[start], s[i]);
    }
}

int main() {
    
    string s;
    cout << "Enter a string: ";
    cin >> s;

    vector<string> result;
    generatePermutations(s, 0, result);

    cout << "All permutations are: \n";
    for (const string& perm : result) {
        cout << perm << endl;
    }

    return 0;
}