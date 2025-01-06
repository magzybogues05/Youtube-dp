class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        if(arr.size()==1)
        {
            return {};
        }
        sort(arr.begin(),arr.end());
        int i=0;
        int j=arr.size()-1;
        int f=arr[0];
        int s=arr[j];
        int currClosest=INT_MAX;
        while(i<j)
        {
            int sum=arr[i]+arr[j];
            int diff=abs(arr[i]-arr[j]);
            if(abs(target-sum)<currClosest)
            {
                currClosest=abs(target-sum);
                f=arr[i];
                s=arr[j];
            }
            else if(abs(target-sum)==currClosest && diff>=abs(f-s))
            {
                f=arr[i];
                s=arr[j];
            }
            if(sum>target)
            {
                j--;
            }
            else{
                i++;
            }
            
        }
        return {f,s};
    }
};