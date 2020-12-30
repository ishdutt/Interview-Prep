#include<bits/stdc++.h>
using namespace std;

                    //TITLE: LONGEST CONSECUTIVE SUBSEQUENCE: 
                    //GIVES THE LENGTH OF THE LONGET SUBSEQUENCE POSSIBLE

// 1. BRUTE FORCE: use O(N*N) FOR GENERATING ALL SUBSEQUENCE TRAVERSE THROUGH THEM AND 
//                 CHECK OF ALL THE ELEMENTS ARE CONSECUTIVE TOTAL COMPLEXITY:
//                 O(N*N*N) CAN BE OPTIMISED WITH USING IN THE SAME LOOP TO CHECK FOR THE EXTRA ELEMENT
//                 AND REMOVING THE FIRST ELEMENT

//2. USING SORTING: COMPLEXITY: O(NLOGN) GET THE MAX ELEMENT WHILE TRAVERSING
//                  CHECKING THE CURRENT LENGTH
//                  SPACE COMPLEXITY : NILL

//3 USING MULTISET: SPACE COMPLEXITY : O(N)
//                  TIME COMPLEXITY : O(N) CONSIDERING ACCESSING UNORDERED MULTISET: O(1)
//              APPROACH: TRAVESE THROUGH THE MULTISET AND CHECK IF THERE IS ANY SMALLER 
//                        NUMBER THAN THE CURRENT, IF THEN SKIP AS IT WILL BE COUNTED IN THE 
//                        SMALLEST NUMBER(STARTING) IF IT IS STARTING(i.e NO SMALLLER NUMBER PRESENT)
//                        SEARCH FOR ALL THE NUMBERS CONSECUTIVELY GREATER THAN THE ORIGIN NUM.
//                        COUNT IS INCREMENTED AND COMPARED WITH LONGEST 

// int main()
// {
//     int a[]={1,2,8,9,10,36,80};
//     int n=7;
//     //Using SORT
//     sort(a,a+n);
//     int cur=1;
//     int ans=1;
        //This is kind of an Array trick!! to  get the max!
//     for(int i=0;i<n-1;i++)
//     {
//         if(a[i]+1==a[i+1])
//             cur++;
//         else if(cur!=1 && a[i]+1!=a[i+1])
//             cur=1;
//         ans = max(ans,cur);
//     }
//     cout<<ans<<endl;
// }
int main()
{
    //TODO:
    //**Approach: When an element greater than that number is present, increment it till reach the end of subseq.
    // If the lower is also present then we don't need to do the above thing since it will already be captured
    // in it's smaller number's set.
    vector<int> a={1,2,8,9,10,36,80};
    int n=a.size();
    //Using ultiset since can have repitation
    int longest = 0;
    
    unordered_multiset<int> s(a.begin(),a.end());
    for(int i=0;i<s.size();i++)
    {
        int num = a[i];
        int curr = 1;
        if (s.find(num-1)==s.end())
        {
            //skip this condition since it will be included in num-1 case
            //Moving in one direction... If the  is 
            while(s.find(num+1)!=s.end())
            {
                num++;
                curr++;
            }   
        }   
        longest = max(longest,curr);
    }
    cout<<longest<<endl;
}