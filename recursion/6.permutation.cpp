#include <bits/stdc++.h>
using namespace std;

set<string> sete;

//USE SET if repetation else just use Vector-> SET(greater<int>) as parameter->DEscending order sort.

//HERE "POS" AND 'n' CAN BE SEEN AS LEFT AND RIGHT RESPEC. AND WE ARE MOVING FROM LEFT TO RIGHT SWAPING EACH VALUE 

void per(string s, string ans, int pos, int n)
{
    //Probale Mistake If check the other looped solution
    if (pos == n)
    {
        sete.insert(s);
    }
    else
    {
        //Here pushing logic won't won't work since it will allow repitation
        //Here K is from pos to n since if K is from 0 then All possible combinations of 3 letters from A,B,C
        // with repitition.
        for (int k = pos; k < n; k++)
        {
            //You have to add the correct element that's it pal!! The iterations are correct
            //But With ans.push_back() -> You may end up pushing the same element also
            //Hence new approach is used here
            
            //ans.push_back(s[k]);
            //So that's why...-> Swap is used
            swap(s[pos], s[k]);
            per(s, ans, pos + 1, n);
            //ans.pop_back();
            swap(s[pos], s[k]);
        }
    }
}

int main()
{
    string s = "ACB";
    string ans = "";
    per(s, ans, 0, s.size());
    for (auto i = sete.begin(); i != sete.end(); ++i)
        cout << *i << endl;
}