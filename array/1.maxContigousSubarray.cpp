#include<bits/stdc++.h>
using namespace std;


//1. KADANE'S ALGORITHM O(N**2) HERE NEGATIVE NUMBERS ARE MUST SINCE IT DOES'NT MAKE SENSE TO 
//INCLUDE THE + ONLY AS ALL WILL CONTRIBUTE OT THE INCREMENT OF CURRENT SUM

//2. APPROACH IS TO CHECK ALL POSIBLE AND GET THE MAX SUM -> O(N**2)
int main()
{
    vector<int> a={-5,1,2,-3,9};
    int maxsum = INT_MIN;
    int cursum = 0;
    for(int i=0;i<a.size();i++)
    {
        cursum+=a[i];
        // IF NEGATIVE CURSUM THEN WHY CARRY THE LOAD, JUST MAKE IT ZERO AND WE WILL IGNORE THE NUMBERS BEFORE 
        // THAT
        if(cursum<0)cursum=0;
        
        //IF CURSUM IS GREATER THEN INCREMENT THE MAX
        if(cursum>maxsum) maxsum = cursum;

    }
    cout<<maxsum<<endl;
}