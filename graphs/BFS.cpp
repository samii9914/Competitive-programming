#include<iostream>
using namespace std;
#include<map>
#include<queue>
#include<list>
template<typename T>
class graph
{
    int v;
    map<T,list<T>> adjlist;
public:
    graph(int v)
    {

    }

    void addedge(T u,T v,bool bidir)
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
            for(T node:i.second)
            {
                cout<<node<<",";
            }
            cout<<endl;
        }
    }
    void bfs(T src)
{
    queue<T> q;
    map<T,bool> visited;
    q.push(src);
    visited[src]=true;

    while(!q.empty())
    {
        T node=q.front();
        cout<<node<<" ";
        q.pop();
        for(T neighbours : adjlist[node])
        {
            if(!visited[neighbours])
            {
                q.push(neighbours);
                visited[neighbours]=true;
            }
        }
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
    g.bfs(0);
}
