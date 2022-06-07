vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int i = 0;
        while(i<arr.size())
        {
            int start = arr[i][0];
            int max_end = arr[i][1];
            int j = i;
            while(j<n && arr[j][0] <= max_end)
            {
                max_end = max(max_end,arr[j][1]);
                j++;
            }
            vector<int> temp(2);
            temp[0] = start;
            temp[1] = max_end;
            ans.push_back(temp);
            i = j;
        }
        return ans;
    }
