#include<iostream>
using namespace std;
#include<list>
#include<map>
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
            for(T node:i.second)
            {
                cout<<node<<",";
            }
            cout<<endl;
        }
    }
    bool detectcycle(T src)
    {
        map<T,bool> visited;
        for(auto i:adjlist)
        {
            T node=i.first;
            if(!visited[node])
            {
               bool ans=iscyclichelper(visited,node,node);
               if(ans)
               {
                   return true;
               }
            }
        }
    }

    bool iscyclichelper(map<T,bool> &visited,T node,T parent)
    {
        visited[node]=true;
        for(T neighbour:adjlist[node])
        {
            if(visited[neighbour]&&neighbour!=parent)
            {
                return true;
            }
            else if(!visited[neighbour])
            {
                bool ans=iscyclichelper(visited,neighbour,node);
                if(ans)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    graph<int> g(5);
    g.addedge(0,1);
    g.addedge(0,4);
    g.addedge(4,3);
    g.addedge(1,4);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(1,3);
    g.print(0);
}
