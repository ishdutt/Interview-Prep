#include<bits/stdc++.h>
using namespace std;
vector<int> a,b;

vector<string> solve(int i,int j,int k,vector<vector<vector<int>>> &dp)
{
    for(int l = i;l < i+k;l++)
    {
        //MATCH HUA
        if(a[l] == b[j+k-1])
        {
            //SAME CHEEZ..LAST N-1 CHARCTER KISSE ,ATCH KAR RAHA HAI.. WO TRUE HOGA...
            //2 SUBSTRING MATCH KAR RAHE HAI... TOH DIVERSION 
            bool ok1 = (l-i > 0 ? dp[i][j][l-i] : 1);
            bool ok2 = (k-(l-i+1) > 0 ? dp[l+1][j+l-i][k-(l-i+1)] : 1);
            if(ok1 & ok2)
            {
                vector<string> a1,a2;
                if(l-i > 0)
                    a1 = solve(i, j, l-i, dp);
                
                if(k-(l-i+1) > 0)
                    a2 = solve(l+1, j+l-i, k-(l-i+1), dp);
                
                vector<string> ans; 
                ans = a1;
                string p = "p_" + to_string(a[l]);
                string o = "o_" + to_string(a[l]);
                ans.push_back(p);
                //SEARCHING IN LEFT OVER PART 
                for(auto i: a2)
                    ans.push_back(i);
                ans.push_back(o);
                return ans;
            }
        }
    }
    vector<string> a;
    return a;
}

int main()
{
    int n;
    cin>>n;
    a.resize(n);
    b.resize(n);
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    for(int i = 0;i < n;i++){
        cin>>b[i];
    }
    //DP[I][J][K]->I SE START HUA HAI 1ST STRING ME, 2ND CHAR ME J SE START HUA HAI SUBSTRING..LENGTH HAI K
    // FOR BOTH THE SUBSTRINGS .... KYA WO SAHI SE POP KARKE AT THE END EMPTY STACK KAR PAA RAHE HAI...
    //YE SUBPROBLEM HUA HAI-> boolean data hi hoga 

    //ANSWER-> 0,0,N HAI... STARTING FROM 0 OF BOTH THE STRING AND LENGTH IS 'N'.
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (n+1,vector<int> (n+1,0)));
    //LAST POP CHARACTER KAUNSA HAI WO... PATA KARNE KA TRY KIYA HAI..JITNE BHI USKE OCCURENCES HAI..USSE MATCH 
    //KARENE KA TRY KARENGE-> JAHA BHI MATCH KAREGA THEN .. USKE BAAD JITNE BHI CHARCTER AAYE HAI WO
    //USKE BAAD AAYE HAI AUR USSE PEHLE POP HUE HAI
    /*
        eg. S1=>Ith CHARACTER SE MATCH KIYA, i+1 se string 1st ke end tak.. jitne bhi character honge... wo char
        just uske pehle pop hue honge(as independent set honge wo).. so 2 part me baat diya.. string 1st me
        jitne number of charcter hai jo uske baad pop hue aur 


        -> SO ALL THE CHARACTERS 
    */
    for(int k = 1;k <= n;k++)
    {
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                //LAST CHARCTER IS LESS THEN n-1...IF THEN GO INSIDE THE LOOP
                if(i+k-1 < n && j+k-1 < n)
                {
                    //TRAVERSE THE 1ST STRING'S SUBSTRINGS FROM I OF LENGTH 'K'
                    for(int l = i;l < i+k;l++)
                    {
                        //MATCHING THE 1ST  
                        if(a[l] == b[j+k-1])
                        {
                            /*l-i -> jab traverse kar rahe hai .. tab hum first charcter pe tph nahi
                            k-(l-i+1) - > abhi aur kitna lenght bacha hai */
                            //YAHA PE 2 PART ME DIVIDE HO RAHA HAI -> 1ST PART OF AND SYMBOLISE SOMETHING
                            // AND OTHER PART OF AND SYMBOLISES SOMETHING
                            
                            /*
                                1ST STRING: STRING 1ST ME JO ELEMENTS POP HO RAHE HAI UNKA LENGHT LE LIYE
                                2ND STRING:  JO BACHA HUA STRING HAI USKO CONSIDER KAR LIYA 
                            */
                            //2ND IS REMAINING PART AFTER TAKING L LENGHT STRING IN BOTH

                            //LAST CHARACTER MATCH KAR RAHE HAI ... SO OBSERVE STACK
                            dp[i][j][k] = max(dp[i][j][k],
                            (l-i > 0 ? dp[i][j][l-i] : 1) &
                            (k-(l-i+1) > 0 ? dp[l+1][j+l-i][k-(l-i+1)] : 1));
                            
                        }
                    }
                }
            }
        }
    }
    if(dp[0][0][n]){
        vector<string> ans = solve(0, 0, n, dp);
        for(int i=0;i<ans.size();i++)
        {
            if(i==ans.size()-1)
                cout<<ans[i]<<endl;
            else
            cout<<ans[i]<<", ";
        }
    }
    else{
        cout<<"Invalid Input"<<endl;
    }
}
// 
/*
    10  
    448 414 613 356 356 414 367 448 367 613
    414 356 367 448 367 356 613 414 448 613
*/