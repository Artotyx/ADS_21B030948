#include <iostream>
#include <vector>

using namespace std;

int minSubarrayLength(int k, vector<int>& nums) {
    int n = nums.size();
    int minLength = n + 1;
    int left = 0;
    int sum = 0;

    for (int right = 0; right < n; right++) {
        sum += nums[right];

        while (sum >= k) {
            minLength = min(minLength, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }

    return (minLength == n + 1) ? 0 : minLength;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = minSubarrayLength(k, nums);
    cout << result << endl;

    return 0;
}