#include<bits/stdc++.h>
using namespace std;
    

//          PROBLEM: TAKE THE COIN EITHER LAST OR THE FIRST SO THAT AT THEN END YOU HAVE THE MAX
//          HERE GREEDY SOLUTION FAILS SINCE eg. AFTER FIRST MAX YOU GET A REALLY BIG NUMBER, THAN YOUR
//          OPPONENT WINS... SO IT WILL CHOOSE THE PATH HAVING MAX SUM AT THE END OF PROCESS
//          IN SHORTS DP HAI YE PAGLE ;)


//HERE WHEN WE TAKE A NUMBER -> OPPONENT WILL TAKE THE MAX OF THE TWO SO WHAT'S LEFT WITH US IS MIN OF THE TWO
// SO IT WILL TAKE SUCH THAT WHAT IS LEFT WITH YOU IS MIN 

int hem,mu;
int coin(vector<int> a,int l,int r)
{
    //BASE IS WHEN L REACHES R
    if(l+1>=r)
        return max(a[l],a[r]);

    //LET SAY WE TAKE A[L] THEN NXT TIME WE GET IS THE MIN IN L+1 TO R SO TO GET THE MIN HE HAS 2 OPTIONS
    // EITHER TAKE THE RIGHTMOST OR TAKE THE LEFTMOST


    //  THIS IS RECURSION BELIEVE -> JUST THINK RECURION WILL HANDLE THE STUFF FROM HERE
    // hem = a[l]+min(coin(a,l+1,r-1),coin(a,l+2,r));
    // mu = a[r]+min(coin(a,l+1,r-1),coin(a,l,r-2));
    return max(a[l]+min(coin(a,l+1,r-1),coin(a,l+2,r)),   
           a[r]+min(coin(a,l+1,r-1),coin(a,l,r-2)));
    // return max(hem,mu);
}   

int main()
{
    vector<int> a = {1,3,700,200,4};
    int l=0,r = a.size()-1;
    int mysum = coin(a,l,r);
    cout<<mysum<<endl;
}