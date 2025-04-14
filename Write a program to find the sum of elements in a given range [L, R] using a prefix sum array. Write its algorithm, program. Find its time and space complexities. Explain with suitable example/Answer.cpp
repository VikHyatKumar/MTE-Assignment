// Algorithm:
// 1.Create a prefix sum array where each element at index i stores the sum of elements from index 0 to i in the original array.
// 2. To find the sum of elements in the range [L, R], use the formula:
//    sum = prefix[R] - prefix[L-1] (if L > 0), otherwise sum = prefix[R].
// 3. Return the result.

#include <iostream>
#include <vector>
using namespace std;

vector<int> prefixSum(vector<int>& arr) {
    vector<int> prefix(arr.size());
    prefix[0] = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    return prefix;
}


int rangeSum(vector<int>& prefix, int L, int R) {
    if (L == 0) {
        return prefix[R];
    }
    return prefix[R] - prefix[L - 1];
}

int main() {
    vector<int> arr = {2, 4, 6, 8, 10};
    int L = 1, R = 3;
    vector<int> prefix = prefixSum(arr);

    int result = rangeSum(prefix, L, R);

    cout << "Sum of elements in the given range = " << result << endl;

    return 0;
}

//Time Complexity - O(n)
//Space Complexity - O(n)