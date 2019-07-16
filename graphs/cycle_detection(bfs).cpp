#include<iostream>
using namespace std;
#include<map>
#include<list>
#include<queue>
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
    void print()
    {
        for(auto i:adjlist)
        {
            cout<<i.first<<"-";
            for(T neighbour:i.second)
            {
                cout<<neighbour<<"=>";
            }
            cout<<endl;
        }
    }
    bool detectcycle(T src)
    {
       map<T,bool> visited;
       map<T,T> parent;
       queue<T> q;
       q.push(src);
       visited[src]=true;
       parent[src]=src;

       while(!q.empty())
       {
           T node=q.front();
           q.pop();
           for(T neighbour:adjlist[node])
           {
               if(visited[neighbour]&&neighbour!=parent[node])
               {
                   return true;
               }
               else if(!visited[neighbour])
               {
                  q.push(neighbour);
                  visited[neighbour]=true;
                  parent[neighbour]=node;
               }
           }
       }

       return false;
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
    g.print();
    bool ans=g.detectcycle(0);
    cout<<ans;
}

