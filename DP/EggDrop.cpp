#include<bits/stdc++.h>
using namespace std;


//FIXME:

//MINIMUM FLOOR JAHA SE EGG PHENKE TOH PHUTT JAYE... USKO NIKAALNE KA KITNE ATTEMPTS ME NIKAAL LEGA (MIN) SUCH THAT ABLE TO 
//DETERMINE THE FLOOR, I.E BEFORE THE EGGS RUNS OUT. TO DO THAT WE WILL TAKE THE WORST CASE I.E START FROM THE SMALLEST 
//AND MOVE ON TO THE HIGHER PLACES... THIS INCREASES THE ATTEMPTS BUT ENSURES THAT WE ARE ABLE TO DETERMINE THE FLOOR

int solve(int floor,int eggs)
{
    if(eggs=1)   return floor;
    else if(floor==0 || floor==1)   return floor;

    int ans=INT_MAX;
    //SELECTING THE FLOOR ONE BY ONE
    for(int k=1;k<=floor;k++)
    {
        //DO CASES HAI YA TOH ANDA PHUTEGA YA TOH NAI PHUTEGA..
        //AGAR EGG BREAK HO GAYA ..THEN REDUCE THE FLOORS(ONE BY ONE).. 
        //IF NOT BROKEN THEN MOVE UPWARD...F-K FLOORS LEFT..

        // using a for loop where k is initiated from 1 again.the reason is we are checking for a 
        //range where we are min number of possibly attempt where egg didn't break.
        int temp=1+max(solve(eggs-1,k-1), solve(eggs,floor-k));
        ans=min(ans,temp);
    }
    return ans+1;
}       

int main()
{
    int floor=36;
    int eggs=2;
    cout<<solve(floor,eggs);
}