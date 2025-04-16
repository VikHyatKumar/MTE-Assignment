#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;

    for (int i = 0; i < n; i++) {
        minHeap.push({matrix[i][0], i, 0});
    }

    int result = 0;
    for (int i = 0; i < k; i++) {
        auto [val, row, col] = minHeap.top();
        minHeap.pop();
        result = val; git add .
        
        if (col + 1 < n) {
            minHeap.push({matrix[row][col + 1], row, col + 1});
        }
    }

    return result;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k = 8;

    int result = kthSmallest(matrix, k);
    cout << "The " << k << "-th smallest element is: " << result << endl;

    return 0;
}