#include <bits./stdc++.h>
using namespace std;

class Solution
{
public:
    // 2144. Minimum Cost of Buying Candies With Discount
    int minimumCost(vector<int> &nums)
    {
        sort(begin(nums), end(nums), greater<int>());

        int n = nums.size();
        int i = 0;

        int sum = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     if (i % 3 != 2)
        //         sum += nums[i];
        // }
        while (i <= 0)
        {
            if (i % 3 != 2)
                sum += nums[i];

            i++;
        }
        return sum;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution solution;
    int ans = solution.minimumCost(nums);
    cout << ans;
}