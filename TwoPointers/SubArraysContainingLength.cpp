#include <iostream>
#include <vector>
using namespace std;

long function(vector<int> arr) {
    int N = arr.size();
    long count = 0;
    for (int i = 0; i < N; i++) {
        vector<int> freq(N + 1, 0);
        for (int j = i; j < N; j++) {
            if (arr[j] <= N)
                freq[arr[j]]++;
            int len = j - i + 1;
            if (len <= N && freq[len] > 0)
                count++;
        }
    }
    return count;
}

int main() {
    // Example input
    vector<int> arr = { 1, 2, 3, 4, 5 };
    cout << "Count of valid subarrays: " << function(arr) << endl;
    return 0;
}