#include<bits/stdc++.h>
using namespace std;
//SEE INCREASING PATH IN A MATRIX FOR ITERATIVE CODE ;)

int solve(vector<int>&a,int n,int lastelement)
{
    if(n==a.size())    return 0;

    //IF LAST ELEMENT IS GREATER THAN THE PRESENT ELEMENT..IGNORE IT(THE CASE OF IGNORING THE LAST
    //ELEMENT AND TAKING THE CURRENT ELEMENT WILL BE DEALT IN NEXT CASE)
    if(a[n]<=lastelement)  return solve(a,n+1,lastelement);

    else
    {
        //IF TAKEN, THEN ADD IT'S VALUE AND MODIFY THE VALUE OF LAST ELEMENT ELSE IGNORE IT.
        return max(a[n]+solve(a,n+1,a[n]),solve(a,n+1,lastelement));
    }
}

int main()
{
    vector<int> a={1, 101, 2, 3, 100, 4, 5};
    cout<<solve(a,0,INT_MIN)<<endl;
}