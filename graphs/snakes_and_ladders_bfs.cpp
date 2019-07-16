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
    graph()
    {

    }
    void addedge(T u,T v,bool bidir=false)
    {
        adjlist[u].push_back(v);
        if(bidir)
        {
            adjlist[v].push_back(u);
        }
    }

    void print()
    {
        for(auto i:adjlist)
        {
            cout<<i.first<<"-";
            for(T neighbour:i.second)
            {
                cout<<neighbour<<",";
            }
            cout<<endl;
        }
    }

    int snakeandladder(T src,T dest)
    {
        queue<T> q;
        map<T,int> dist;
        map<T,T> parent;


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
         T temp=dest;
         while(temp!=src)
         {
             cout<<temp<<" ";
             temp=parent[temp];
         }
         cout<<src<<endl;
         return dist[dest];

    }
};
int main()
{
    graph<int> g;
    int board[50]={0};
    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[25]=-10;
    board[32]=-2;
    board[34]=-22;

    for(int u=0;u<=35;u++)
    {
        for(int dice=1;dice<=6;dice++)
        {
            int v=u+dice+board[u+dice];
            g.addedge(u,v);
        }
    }
    cout<<g.snakeandladder(1,35);
}
