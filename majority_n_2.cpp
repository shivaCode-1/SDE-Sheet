 int majorityElement(vector<int>& nums) {
        int el;
        int c = 0;
        for(int i : nums)
        {
            if(c==0) el = i;
            if(i==el) c++;
            else c--;
        }
        return el;
    }
//intuition: whenever count becomes 0, that means that whatever element was in majority was cancelled by minority that is count(major)=count(minor);
//so at some point, when count remains positive, that element is in majority since there is no element to cancel its count.
