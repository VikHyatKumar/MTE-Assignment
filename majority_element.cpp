// C++ program to find Majority
// element in an array using nested loops

#include <bits/stdc++.h>
using namespace std;

// Function to find the Majority element in an array
int majorityElement(const vector<int>& arr) {
    int n = arr.size();  

    // Loop to consider each element as a candidate for majority
    for (int i = 0; i < n; i++) {
        int count = 0; 

        // Inner loop to count the frequency of arr[i]
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        // Check if count of arr[i] is more than half the size of the array
        if (count > n / 2) {
            return arr[i]; 
        }
    }

    // If no majority element found, return -1
    return -1;
}

int main() {
    vector<int> arr = {1, 1, 2, 1, 3, 5, 1};
    
    cout << majorityElement(arr) << endl;

    return 0;
}


//Time Complexity: O(n^2)
//Space Complexity: O(1)    