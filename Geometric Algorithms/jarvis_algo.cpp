#include<iostream>
using namespace std;
#include<vector>
struct point
{
    int x;
    int y;
};
int orientation(point p,point q,point r)
{
    int value=((q.y-p.y)*(r.x-q.x))-((r.y-q.y)*(q.x-p.x));
    if(value==0)
    {
        return 0;
    }

     if(value>0)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
void convexhull(point p[],int n)
{
    if(n<3)
    {
        return;
    }

    vector<point> hull;
    int l=0;
    for(int i=1;i<n;i++)
    {
        if(p[i].x<p[l].x)
        {
            l=i;
        }
    }

    int pp=l;
    do
    {
        hull.push_back(p[pp]);
        int q=(pp+1)%n;
        for(int i=0;i<n;i++)
        {
            if(orientation(p[pp],p[i],p[q])==2)
            {
                q=i;
            }
        }
        pp=q;
    }while(pp!=l);

    for(int i=0;i<hull.size();i++)
    {
        cout<<hull[i].x<<" "<<hull[i].y<<endl;
    }
}
int main()
{
    point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1},
                      {3, 0}, {0, 0}, {3, 3}};
    int n = sizeof(points)/sizeof(points[0]);
    convexhull(points, n);
    return 0;

}
