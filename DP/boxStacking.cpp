#include<bits/stdc++.h>
using namespace std;

//HERE.. W, L SHOULD BE STRICTLY INCREASING.. ARRAY BASED.. WE HAVE ALREADY SORTED ;) SO WHICHEVER
// HAVING STRICTLY GREATER THAN THE CURRENT BASE... WE WILL TAKE IT 

//WE HAD TO SORT THE ARRAY FIRST SINCE WE NEEDED THE AREA SHOULD BE MORE FOR BASE BOXES... AND THEN THE 
//CONDITION FOR W AND L SHOULD BE STRICTLY INCREASING

//VARIENT OF MAX SUM INCREASING SUBSEQUENCE(LIS)
int boxstacking(vector<int>height,vector<int>width,vector<int>length)
{
    //first 2 l and b .. last will be h
    vector<pair<pair<int,int>,int>>orientations;

    //ALL POSSIBLE ORIENTATIONS
    for(int i=0;i<length.size();i++)
    {
        //FIRST ARGUMENT WILL BE MAX SECOND WILL BE MIN.. THIS IS TO ENSURE THAT MAX BASE SIDE ALLIGN 
        //WITH MAX BASE SIDE 
        pair<int,int> temp=make_pair(max(length[i],width[i]),min(length[i],width[i]));
        pair<pair<int,int>,int> main=make_pair(temp,height[i]);
        orientations.push_back(main);
    }
    
    for(int i=0;i<length.size();i++)
    {
        pair<int,int> temp=make_pair(max(height[i],width[i]),min(height[i],width[i]));
        pair<pair<int,int>,int> main=make_pair(temp,length[i]);
        orientations.push_back(main);
    }

    for(int i=0;i<length.size();i++)
    {
        pair<int,int> temp=make_pair(max(length[i],height[i]),min(length[i],height[i]));
        pair<pair<int,int>,int> main=make_pair(temp,width[i]);
        orientations.push_back(main);
    }

    //SORT ALL THE POSSIBLE ORIENTAIONS 
    sort(orientations.begin(),orientations.end(),[&](pair<pair<int,int>,int>a,pair<pair<int,int>,int>b){
        return a.first.first*a.first.second>b.first.first*b.first.second;
    });
    
    // for(int i=0;i<orientations.size();i++)
    //     cout<<orientations[i].first.first<<" "<<orientations[i].first.second<<" "<<orientations[i].second<<endl;

    //NOW WE DO LIS FOR FIRST 2 ARGUMENTS IN ORIENTATIONS ARRAY
    vector<int>dp(orientations.size(),0);

    //INITIALISE THE ORIENTATIONS ARRAY WITH HEIGHTS 
    for(int i=0;i<orientations.size();i++)
        dp[i]=orientations[i].second;
    
    
    //NOW MAX SUM INCREASING SUBSEQUNCE NEEDED
    for(int i=1;i<orientations.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            //cout<<orientations[i].first.first<<" "<<orientations[j].first.first<<" "<<orientations[i].first.second<<" "<<orientations[j].first.second<<endl;
            //DEAREASING WIDTHS AMD LENGHT SO I<J
            if(orientations[i].first.first<orientations[j].first.first && 
            orientations[i].first.second<orientations[j].first.second)
            {
                //cout<<i<<" "<<j<<endl;
                //IF MAX INCREASING SEQUENCE THEN YAHA PE 1 ADD HOTA INSTEAD OG HEIGHT
                dp[i]=max(dp[i],dp[j]+orientations[i].second);
            }
        }
    }
    
    int ans=0;
    for(int i=0;i<orientations.size();i++)
        ans=max(ans,dp[i]);
    
    return ans;
    //return 0;
}

int main()
{
    int n;
    vector<int>height={4,1,4,10};
    vector<int>width={6,2,5,12};
    vector<int>length={7,3,6,32};
    
    cout<<boxstacking(height,width,length)<<endl;
}