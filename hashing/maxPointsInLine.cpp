#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<long long int>> points={{0,0},{94911151,94911150},{94911152,94911151}};
        int result = 0;
        if(points.size()<=2)
            return points.size();
        
        
        for(int i=0;i<points.size();i++)
        {
            
            int samepoint = 1;
            //ALL POINTS ARE TAKEN AS REFERENCE 
            //MAP: SLOPE vs COUNT
            unordered_map<long double,int> m(0);
            
            for(int j=i+1;j<points.size();j++)
            {
                //IF POINT IS SAME
                if(points[i][0]==points[j][0] && points[i][1]==points[j][1])
                    samepoint++;
                
                //SLOPE IS INF
                else if(points[i][0]==points[j][0])
                    m[INT_MAX]++;
                else
                {

                    long double slope = double(points[j][1]-points[i][1])/double(points[j][0]-points[i][0]);
                    
                    cout<<slope<<" Yahi slope hai for "<<i<<" "<<j<<endl;
                    m[slope]++;
                }
            }
            //NOW GET THE MAX FREQ
            int tempmax = 0;
            for(auto it = m.begin(); it != m.end(); it++)
            {
                //FIXME: Precision Value!!!
                //cout<<"Moshi "<<i;
                tempmax = max(tempmax,it->second);
                //cout<<"  "<<it->first<<" "<<it->second<<endl;
                //cout<<tempmax;
            }
            //cout<<"Moshi";
            tempmax += samepoint;
            //cout<<tempmax<<" "<<samepoint<<endl;
            result = max(result,tempmax);
        }
        cout<<result<<endl;
}