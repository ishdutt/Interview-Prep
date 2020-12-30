#include<bits/stdc++.h>
using namespace std;

//                            TITLE: NUMBER OF SUBARRAY WHOSE SUM IS 'K'
//                            VARITATION OF LONGEST SUBARRAY SUM 'K'
//                            HERE IT STORES FREQ AS A VALUE AND CUMSUM AS KEY IN MAP
//                            FREQ SO THAT IT CAN BE UTILISED AS A COUNT OF NUMBERS WITH SAME
//                            CUMULATIVE SUM.

int main()
{
    vector<int> nums={ 100,0,-2, 3, 1, 10,20 };
    int n=nums.size();     
    int k  = 39;   
    //it will store the cumsum and it;s frequency
    unordered_map<int,int> mp; 
        int cumsum = 0, ans = 0; 
        for(int i = 0; i < nums.size(); i++){
            cumsum += nums[i];
			if(cumsum == k) ans++;
            //HERE we didn't just added 1 since many repitition case so for that we have to count 
            //each one of that number
            if(mp[cumsum-k])
                ans += mp[cumsum-k];
            mp[cumsum]++;
        }
        cout<< ans;
}