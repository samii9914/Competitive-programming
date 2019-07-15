#include<iostream>
using namespace std;
#include<map>
#include<list>
template<typename T>
class graph{
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
            T node=i.first;
            cout<<node<<"-";
            for(T neighbour:i.second)
            {
                cout<<neighbour<<",";
            }
            cout<<endl;
        }
    }

    void dfs(T src)
    {
        map<T,bool> visited;
        dfshelper(visited,src);
    }
private:
    void dfshelper(map<T,bool> &visited,T node)
    {
        visited[node]=true;
        cout<<node<<" ";
        for(T neighbour:adjlist[node])
        {
            if(!visited[neighbour])
            {
                dfshelper(visited,neighbour);
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
    g.dfs(0);
}
