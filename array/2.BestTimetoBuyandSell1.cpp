#include<bits/stdc++.h>
using namespace std;

//4 VARIANTS: 1. ONLY ONE TIME BUY AND SELL
//            2. CAN SELL ANY NUMBER OF TIMES NO CONSTRAINTS
//            3. CAN BUY K NO. OF TIMES

//SOL : 1. FIND THE PAIRS WITH MAX DIFFERNCE BETWEEN THEM SUCH THAT I<J AND A[I]<A[J] (MAX)
//         OR FIND MIN ELEMENT SUCH THAT MAX ELEMNT IS AFTER MIN ELEMENT.
//         
//         BRUTE FORCE: FOR EVERY PAIRS, WE CHECK THE DIFFERENCE AND FIND MAX DIFF. O(N**2)

// IMPORTANT APP. OPTIMISED : TRAVERSE THE ARRAY, SEE IF THE ELEMENT IS SMALLER THAN THE MIN_ELEMENT
//  UPDATE THE MIN_ELEMENT, ELSE STORE THE DIFFERENCE (MAXIMISING THIS VAR)... WHICH WILL GIVE US THE 
//      ANSWER  ---> O(N**2)



int main()
{
    vector<int> sp = { 100, 180 ,260, 310, 40 ,535, 695};
    int min_element = INT_MAX;
    int profit = 0;

    //WE CAN USE MIN_ELEMENT OR MAX_ELEMENT(FOR GETTING THE BEST SELLING DAY)
    for(int i=0;i<sp.size();i++)
    {
        //cout<<min_element<<endl;
        //UPDATE THE MIN ELEMENT
        if(min_element>sp[i])   min_element = sp[i];

        //UPDATE THE PROFIT
        else if(profit < sp[i]-min_element)   profit = sp[i]-min_element;
    }

    cout<<profit<<endl;
}