#include <iostream>
#include <vector>
#include <climits>

using namespace std;

double findMedian(const vector<int>& array1, const vector<int>& array2) {
    if (array1.size() > array2.size()) {
        return findMedian(array2, array1);
    }

    int size1 = array1.size();
    int size2 = array2.size();
    int start = 0, end = size1;

    while (start <= end) {
        int partition1 = (start + end) / 2;
        int partition2 = (size1 + size2 + 1) / 2 - partition1;

        int left1 = (partition1 == 0) ? INT_MIN : array1[partition1 - 1];
        int right1 = (partition1 == size1) ? INT_MAX : array1[partition1];

        int left2 = (partition2 == 0) ? INT_MIN : array2[partition2 - 1];
        int right2 = (partition2 == size2) ? INT_MAX : array2[partition2];
        if (left1 <= right2 && left2 <= right1) {

            if ((size1 + size2) % 2 == 0) {
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            } else {
                return max(left1, left2);
            }
        } else if (left1 > right2) {
    
            end = partition1 - 1;
        } else {
           
            start = partition1 + 1;
        }
    }

}
int main() {
    vector<int> array1 = {1, 3};
    vector<int> array2 = {2};

    double median = findMedian(array1, array2);
    cout << "Median: " << median << endl;

    return 0;
}

/*
Time Complexity: O(log(min(size1, size2)))
Space Complexity: O(1)

*/