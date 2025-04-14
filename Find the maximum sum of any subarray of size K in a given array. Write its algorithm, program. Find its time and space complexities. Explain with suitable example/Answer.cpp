#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the maximum sum of any subarray of size K
int maxSumSubarrayOfSizeK(const vector<int>& arr, int K) {
    int n = arr.size();
    if (n < K) {
        cout << "Array size is smaller than K." << endl;
        return -1;
    }

    int maxSum = INT_MIN, currentSum = 0;

    for (int i = 0; i < K; i++) {
        currentSum += arr[i];
    }
    maxSum = currentSum;

    // Sliding window technique
    for (int i = K; i < n; i++) {
        currentSum += arr[i] - arr[i - K];
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int K = 3;

    int result = maxSumSubarrayOfSizeK(arr, K);
    if (result != -1) {
        cout << "Maximum sum of any subarray of size " << K << " is: " << result << endl;
    }

    return 0;
}