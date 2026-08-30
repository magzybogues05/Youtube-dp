class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minPos = 0;
        int maxPos = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minPos])
            {
                minPos = i;
            }

            if (nums[i] > nums[maxPos])
            {
                maxPos = i;
            }
        }

        int left = min(minPos, maxPos);
        int right = max(minPos, maxPos);

        int fromFront = right + 1;
        int fromBack = n - left;
        int bothSides = (left + 1) + (n - right);

        return min({fromFront, fromBack, bothSides});
    }
};