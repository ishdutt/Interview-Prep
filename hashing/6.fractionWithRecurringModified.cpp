#include<bits/stdc++.h>
using namespace std;

//                    TITLE: GET THE FRACTION WITH RECURRING DECIMAL IN 0.(6) FORMAT
//                    APPROACH:TIME COMPLEXITY : O(N)
//                             SPACE COMPLEXITY: O(N) FOR USING MAP
//                    IDEA: HANDLE BEFORE DECIMAL PART IN A STRING AND STORE A REMAINDER THAT IS
//                          LESS THAN DENOMINATOR. WE WILL MULTIPLY THE REMAINDER WITH 10 
//                          EVERYTIME IN THE LOOP SO THAT TO COMPENSATE THE 0'S IN THE DECIMAL.
//                          NOW WE WILL CREATE A HASHMAP THAT STORES THE REMAINDER
//                          AS KEY AND STRING LENGTH(INDEX) WHEN IT OCURRED IN THE PROCESS
//                          IF REMAINDER IS FOUND THEN ADD THE BRACKETS AND RETURN    
//             CORNER CASES: 1. NO DECIMAL PART (REMAINDER IN THE START IS 0)
//                           2. DECIMAL, EVERY PART AFTER DECIMAL IS RECURRING
//                           3. DECIMAL, RECURRING AFTER CERTAIN NUMBERS

//MANY CORNER CASES
int main()
{
    int numerator = 11;
    int denominator = 30;

    //Check for negative number
        string s;
        if((numerator<0&& denominator>0)||(numerator>0&& denominator<0))
        {
            s+='-';
            numerator = abs(numerator);
            denominator = abs(denominator);
        }
        
        s+=to_string(numerator/denominator);
        numerator  = numerator % denominator;
        if(numerator==0)
        {
            cout<<s<<endl;
            return 0;
        }
        s.append(".");
        
        //First index will store the remainder 2nd index will store the index
        //key : remainder and value is the place where recurrence start
        // i.e the size of the string 
        unordered_map<int,int> rem;
        int index = 0;
        //THe remainder before decimal is not counted LOGIC EITHER terminating or non terminating (Not recurrent will not occur)
        while(numerator)
        {
            //Take the case of adding zero at multiple places add while 
            //Mantain a remainder if repeated then stop
            if(rem.find(numerator)!=rem.end())
            {
                s.insert(rem[numerator],"(");
                //s.insert(rem[numerator],"(");
                s+=")";
                cout<<s<<endl;
                return 0;
            }
            //rem[temprem] = index++;
            rem[numerator] = s.size();
            numerator = numerator*10;
            s+=to_string(numerator/denominator);
            numerator  = numerator % denominator;
        }
        cout<<s<<endl;
}