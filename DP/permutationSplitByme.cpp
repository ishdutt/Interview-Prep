#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

//CODECHEF PERMSPL PROBELM SEPT. LUNCHTIME :)


// THE INVERSIONS ARE NOT CONSERVED... I.E NOT ALWAYS I1+I2=TOTAL INVERSIONS
//BUT THE DIFFERNCE IS WHAT IS NEEDED AND WE ARE CONCERNED WITH AND IT IS CONSERVED
// FOR INDEPENDENCE(HOW THE ARRAY IS CONVERTED TO Ci AND SUBSET SUM PROBLEM).. CHECK CASES
//  C1-: IF WE TRANSFER THE ELEMENT WITH NO INVOLVEMENT IN INVERSION PAIR
//  C2-: IF WE TRANSFER ONE IN THE PAIR INVLOLVED IN INVERSIONS(HOW DELTA IS EFFECTED)
//  C3-: WHAT IF BOTH THE ELEMENTS ARE TRANSFERED TO THE SECOND SET .. HOW DELTA IS EFFECTED
// FROM HERE YOU WILL REALISE THAT IT IS SUBSET SUM PROBLEM FOR THE INVERSION ARRAY (BIJECTION) AND SUM IS DELTA(TOTAL NUMBER OF
//  OF INVERSIONS EQUAL TO ZERO..IE NEW SET HAS TO HAVE SUM EQUAL TO DELTA)

ll solve(vector<ll>&a)
{
    //INVERSION ARRAY (CONTAINS PAIRS IN WHICH THE ELEMENT IS INVLOLVED IN ARRAY)
    vector<ll>c(a.size(),0);
    //DIFFERENCE BETWEEN THE INVERSIONS OF 2 SETS(IT DECREASES BY Ci WHEN Ci IS MOVED TO THE OTHER SET)
    // OUR TASK IS TO MAKE DELTA=0 I.E MAKE A SUBSET SUCH THAT IT'S SUM IS EQUAL TO DELTA :) 

    //HERE WE ARE NOT CONCERENED WITH WHAT IS THE VALUE OF INVERSION AFTER EACH TRANSFER.. WE ARE 
    // CONCERNED WITH ONLY THE DIFFERENCE WHICH WILL BE CONSERVED NO MATTER WHAT :3 

    ll delta=0;
    ll n=a.size();
    // NUMBER OF INVERSION COUNTS IN ARRAY
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            if(a[i]>a[j] && i<j)
            {
                c[i]++;
                c[j]++;
                delta++;
            }
        }
    }
    //cout<<"TEST="<<delta<<endl;
    
    // THIS IS TO HANDLE THE SCENARIO WHEN DELTA IS ZERO.. IN THAT CASE IT IS ALWAYS PSOOBLE TO DIVIDE IT INTO SETS WITH 0 INVERSION
    // BOTH SIDES
    if(delta==0)
        return 1;

    vector<vector<ll>>dp(n+1,vector<ll>(delta+1,0));

    //FOR ITERATING OVER THE ELEMENTS
    for(ll i=0;i<n+1;i++)
    {
        //FOR ITERATING OVER THE POSSIBLE DELTA VALUES
        for(ll j=0;j<delta+1;j++)
        {
            //I.E WHEN DELTA IS ZERO ALWAYS POSSIBLE :) 
            if(j==0)    dp[i][j]=1;
            
            else if(i==0)   continue;

            else
            {
                if(c[i-1]>j)    dp[i][j]=dp[i-1][j];

                else
                dp[i][j]=dp[i-1][j]||dp[i-1][j-c[i-1]];
            
            }
            
            
        }
    }

    return dp[n][delta];

}


int main() 
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        vector<ll>a;
        //cout<<"MOSHI0\n";
        for(int i=0;i<n;i++)
        {
            ll temp;
            cin>>temp;
            a.push_back(temp);
        }
        
        //cout<<"MOSHI\n";
        if(solve(a)==1) cout<<"YES\n";

        else    cout<<"NO\n";
    }
    return 0;        
}
    