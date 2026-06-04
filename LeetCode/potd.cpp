#include <bits./stdc++.h>
using namespace std;

class Solution
{
public:
    // 1 June 2026
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

    // 3633. Earliest Finish Time for Land and Water Rides I

    int checkOrder(vector<int> &landStartTime, vector<int> &landDuration, vector<int> &waterStartTime, vector<int> &waterDuration)
    {
        int minFirstEndTime = INT_MAX;
        for (int i = 0; i < landStartTime.size(); i++)
        {
            minFirstEndTime = min(minFirstEndTime, landStartTime[i] + landDuration[i]);
        }
        int totalEndTime = INT_MAX;
        for (int i = 0; i < waterDuration.size(); i++)
        {
            int startTimeOfSecond = max(minFirstEndTime, waterStartTime[i]);
            int secondRideTime = startTimeOfSecond + waterDuration[i];
            totalEndTime = min(totalEndTime, secondRideTime);
        }
        return totalEndTime;
    }

    int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration, vector<int> &waterStartTime, vector<int> &waterDuration)
    {
        int landTime = checkOrder(landStartTime, landDuration, waterStartTime, waterDuration);
        int waterTime = checkOrder(waterStartTime, waterDuration, landStartTime, landDuration);

        return min(landTime, waterTime);
    }
    // 3751. Total Waviness of Numbers in Range I

    int findWaviness(int num)
    {
        string s = to_string(num);
        if (s.length() < 3)
            return 0;
        int count = 0;

        for (int i = 1; i < s.length() - 1; i++)
        {
            if ((s[i] > s[i - 1] && s[i] > s[i + 1]))
                count++;
            if ((s[i] < s[i + 1] && s[i] < s[i - 1]))
                count++;
        }
        return count;
    }
    int totalWaviness(int num1, int num2)
    {
        int score = 0;

        for (int num = num1; num <= num2; num++)
        {
            score += findWaviness(num);
        }
        return score;
    }
};
int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    // int p;
    // cin >> p;
    // int q;
    // cin >> q;
    // vector<int> nums1(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> nums1[i];
    // }
    // vector<int> nums2(m);
    // for (int i = 0; i < m; i++)
    // {
    //     cin >> nums2[i];
    // }
    // vector<int> nums3(p);
    // for (int i = 0; i < p; i++)
    // {
    //     cin >> nums3[i];
    // }
    // vector<int> nums4(q);
    // for (int i = 0; i < q; i++)
    // {
    //     cin >> nums4[i];
    // }
    Solution solution;
    int ans = solution.totalWaviness(n, m);
    cout << ans;
}