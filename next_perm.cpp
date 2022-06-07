 void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        while(i>0)
        {
            if(nums[i-1] < nums[i]) break;
            else i--;
        }
        int brk_point = i-1; //beyond brk_point, everything is sorted in reverse
        if(brk_point==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        int j = n-1;
        while(j>brk_point && nums[j]<=nums[brk_point]) j--; //find immediate next greter
        swap(nums[j],nums[brk_point]); //swap
        reverse(nums.begin()+brk_point+1,nums.end()); //reverse to produce smallest next perm.
    }
