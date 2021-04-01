#include<bits/stdc++.h>
using namespace std;

class point2d{
    public: 
        int x,y;

    point2d(int val_x,int val_y){
        x=val_x;
        y=val_y;
    }
    double dist2d(point2d p1, point2d p2)
    {
        return pow(pow(p1.x - p2.x , 2) + pow(p1.y - p2.y , 2) ,0.5);
    }
};

class point3d :public point2d{
    public:
    int z;

    point3d(int val_x,int val_y,int val_z) : point2d(val_x,val_y)
    {
        z=val_z;
    }
};


void printDistance(double d)
{
    cout<<floor(d)<<endl;
}

double dist3d(point3d p1, point3d p2)
{
    return pow(pow(p1.x-p2.x , 2) + pow(p1.y - p2.y , 2) + pow(p1.z - p2.z , 2) ,0.5);
}


int main()
{
    // point2d pa;

    int x,y,z;
    int a,b,c;
    cin>>x>>y>>z;
    cin>>a>>b>>c;
    

    point3d pp3(x,y,z);
    point3d pp2(a,b,c);
    cout<<ceil(dist3d(pp3, pp2))<<endl;
}