class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int>ans;
        int i=0;
        int j=0;
        while(i<n && j<m)
        {
            int temp=min(arr1[i],arr2[j]);
            ans.push_back(temp);
            while(i<n && arr1[i]==temp)
            {
                i++;
            }
            while(j<m && arr2[j]==temp)
            {
                j++;
            }
        }
        while(i<n)
        {
            int temp=arr1[i];
            ans.push_back(temp);
            while(i<n && arr1[i]==temp)
            {
                i++;
            }
        }
        while(j<m)
        {
            int temp=arr2[j];
            ans.push_back(temp);
            while(j<m && arr2[j]==temp)
            {
                j++;
            }
        }
        return ans;
    }
};