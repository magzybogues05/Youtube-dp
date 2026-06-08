class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>ans(n,0);
        int left = 0;
        int right = n-1;
        int i=0; 
        int j=n-1;

        while(i<n){
            if(nums[i]<pivot)
            {
                ans[left] = nums[i];
                left++;
            } 
            if(nums[j]>pivot)
            {
                ans[right] = nums[j];
                right--;
            }
            i++; 
            j--;
        }
        while(left<=right)
        {
            ans[left] = pivot;
            left++;
        }
        return ans;
    }
};           