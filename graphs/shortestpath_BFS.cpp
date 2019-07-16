#include<iostream>
using namespace std;
#include<map>
#include<list>
#include<queue>
#include<bits/stdc++.h>
template<typename T>
class graph
{
    int v;
    map<T,list<T>> adjlist;

public:
    graph(int v)
    {

    }

    void addedge(T u,T v,bool bidir=true)
    {
        adjlist[u].push_back(v);
        if(bidir)
        {
            adjlist[v].push_back(u);
        }
    }
    void print(T src)
    {
        for(auto i:adjlist)
        {
            cout<<i.first<<"-";
            for(auto neighbour:i.second)
            {
                cout<<neighbour<<",";
            }
            cout<<endl;
        }
    }
    void shortestpath(T src)
    {
       map<T,int>dist;
       map<T,T> parent;
       queue<T> q;
       for(auto i:adjlist)
       {
           dist[i.first]=INT_MAX;
       }

       q.push(src);
       dist[src]=0;
       parent[src]=src;

       while(!q.empty())
       {
           T node=q.front();
           q.pop();

           for(T neighbour:adjlist[node])
           {
               if(dist[neighbour]==INT_MAX)
               {
                   q.push(neighbour);
                   dist[neighbour]=dist[node]+1;
                   parent[neighbour]=node;
               }
           }

       }

       for(auto i:adjlist)
       {
           cout<<"dist of "<<i.first<<" is "<<dist[i.first]<<endl;
       }
    }
};
int main()
{
    graph<int> g(5);
    g.addedge(0,1,true);
    g.addedge(0,4,true);
    g.addedge(4,3,true);
    g.addedge(1,4,true);
    g.addedge(1,2,true);
    g.addedge(2,3,true);
    g.addedge(1,3,true);
    g.print(0);
    g.shortestpath(0);
}
