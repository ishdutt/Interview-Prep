#include<bits/stdc++.h>
using namespace std;

// 1. BRUTE FORCE APPRAOCH: SEARCH EVERY NUMBER FROM 1-N IN ARRAY ->> O(N**2)
// 2. OPTIMISED : WITH XTRA SPACE AND USING O(N) TIME COMPLEXITY: USE SET TO STORE ALL THE NUMBER 
// AND THEN SEARCH FOR EVERY NUMBER FROM 1 TO N SINCE SEARCH IS IN LINEAR TIME IN SET 

// 3. BEST APPROACH : (TRICK) : PLACE EVERY ELEMENT IN IT'S INDEXED PLACE ONLY LEFT IS NOT PRESENT


int main()
{
    vector<int> array = {2,1,3,5};
    
    for(int i=0;i<array.size();i++)
    {
        //TRAVERSE THROUGHT THE LIST AND FIND THE NUMBER WHICH IS NOT AT IT'S ROGHT PLACE 
        // SWAP IT
        // SECOND CONDITION TO IGNORE THE EXTRA NUMBER WHICH CAN BE EITHER SAMLLER OR LARGER THAN THE NUMBER

        //HERE LOOP IS USED INSTEAD OF IF SINCE ONE SWAP WON'T MAKE THE 1 AT A[0].. WE HAVE TO PERFORM IT TILL
        // IT HAPPENS
        while (array[i]!=i+1 && array[i]<=array.size() && array[i]>0)
        {
            //PUT A[I] TO I+1(SWAP THE TWO VALUES)
            swap(array[i],array[array[i]-1]);
        }
    }

    //NOW CHECK WHERE ARR[I]!= I+1
    for(int i=0;i<array.size();i++)
        if(array[i]!=i+1)
        {
            cout<<i+1<<endl;
            return 0;
        }

    //IF EVERYONE AT SAME PLACE THEN IT IS N+1 ****NO NEED!!!************
    // JUST FOR LC SINCE RETURN IS MUST SO WE USED IT HERE SEPARATELY
    // cout<<array.size()+1<<endl;
    // return 0;
}