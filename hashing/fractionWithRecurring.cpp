#include<bits/stdc++.h>
using namespace std;

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
            cout<<s;
            return 0;
        }
        s.append(".");
        
        //First index will store the remainder 2nd index will store the index
        unordered_map<int,int> rem;
        int index = 0;
        //THe remainder before decimal is not counted
        //LOGIC EITHER terminating or non terminating (Not recurrent will not occur)
        while(numerator)
        {
            //Take the case of adding zero at multiple places add while 
            
            //Terminating case is easy just witht he use of loop 
            //Mantain a remainder if repeated then stop

            numerator = numerator*10;
            //SAME THING IS REPEATED HERE (THE LAST PART ALSO DO THE SAME THING)
            while(numerator<denominator){
                rem[numerator] = index++;
                numerator = numerator*10;
                s+="0";
            }
            //FIXME: temprem just confuses the stuff
            
            int temprem = numerator%denominator;
            cout<<numerator <<" "<<temprem<<endl;
            //THe case for recurrent decimal
            if(rem.find(temprem)!=rem.end())
            {
                 //IF the non deciaml is zero then we will ignore the first case of adding temp
                //FIXME: check for the case of some recurrent and some non recurrent part

                //store the current value 2 Case: can recure after a certain numbers
                //traverse and add ()
                s.insert(s.find(".")+rem.find(temprem)->second+1,"(");
                //s.insert(rem[numerator],"(");
                s+=")";
                cout<<s;
                return 0;
            }
           
            rem[temprem] = index++;
            //rem[temprem] = s.size();
            s+=to_string(numerator/denominator);
            numerator  = numerator % denominator;
        }
        cout<<s;
}