class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //SINCE WE NEED TO COMPARE FROM BOTH FRONT AND BACK
        vector<int>ans;
        deque<int>q;
        //ON FRONT WILL HAVE THE LASRGEST ELEMENT IN DECREASING ORDER
        //q.push_back(0);
        
        for(int i=0;i<nums.size();i++)
        {
            if(i<k-1)
            {
                while(!q.empty() && nums[q.back()]<nums[i]) q.pop_back();
                q.push_back(i);
            }
            else
            {
                //REMOVE THE CALCULATIONS AND ADD THE CALCULATIONS
                if(q.front()==i-k)    q.pop_front();
                
                //add the value
                while(!q.empty() && nums[q.back()]<nums[i]) q.pop_back();
                q.push_back(i);
                
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};