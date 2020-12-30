#include<bits/stdc++.h>
using namespace std;

//TODO:
// 1. BRUTE FORCE:  TO GET THE SEQUENCE IN O(N**n2) ... SEARCHING EVERY POSSIBLE SUBARRAY
// HOW SEARCH---> 0th TO 1,2,3..N THEN 1st TO 2,3...N LIKEWISE

//2. FOR ONLY POSITIVE NUMBERS -> WE HAVE TO USE SLIDING WINDOW APPROACH HERE
// 3. USING HASHMAPS , FOR NEGATIVE INTEGERS TOO. SEE LC solution
int main()
{
    vector<int> a={5,1,2,3,9};
    int sum = 12;
    int tempsum = 0;
    for(int i=0;i<a.size();i++)
    {
        tempsum=0;
        for(int j=i;j<a.size();j++)
        {
            tempsum += a[j];
            if(tempsum==sum)
            {
                cout<<i<<" "<<j<<endl;
                return 0;
            }
            //FOr efficient search
            if(tempsum>sum)break;
        }
    }
    cout<<"Not possible"<<endl;
}