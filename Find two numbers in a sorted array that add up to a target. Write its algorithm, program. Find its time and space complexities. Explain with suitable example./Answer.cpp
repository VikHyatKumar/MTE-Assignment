#include <iostream>
#include <vector>
using namespace std;

pair<int, int> findTwoNumbers(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return {arr[left], arr[right]};
        } else if (sum < target) {
            ++left;
        } else {
            --right;
        }
    }

    return {-1, -1}; // Indicating no solution
}

int main() {
    vector<int> sortedArray = {1, 2, 3, 4, 6, 8, 10};
    int target = 10;

    pair<int, int> result = findTwoNumbers(sortedArray, target);

    if (result.first != -1) {
        cout << "The two numbers are: " << result.first << " and " << result.second << endl;
    } else {
        cout << "No two numbers add up to the target." << endl;
    }

    return 0;
}