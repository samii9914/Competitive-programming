#include<iostream>
using namespace std;
#include<queue>
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
        if(bidir==true)
        {
            adjlist[v].push_back(u);
        }
    }
    void print()
    {
        for(auto i:adjlist)
        {
            cout<<i.first<<"::";
            for(T node:i.second)
            {
                cout<<node<<"=>";
            }
            cout<<endl;
        }
    }
    void topologicalsort()
    {
        map<T,int> indegree;
        queue<T> q;
        map<T,bool> visited;
        for(auto i:adjlist)
        {
            indegree[i.first]=0;
            visited[i.first]=false;
        }

        for(auto i:adjlist)
        {
            T node=i.first;
            for(T neighbour:adjlist[node])
            {
                indegree[neighbour]++;
            }
        }

        for(auto i:adjlist)
        {
            if(indegree[i.first]==0)
            {
                q.push(i.first);
            }
        }

        while(!q.empty())
        {
            T node=q.front();
            q.pop();
            cout<<node<<"-->";
            for(T neighbour:adjlist[node])
            {
                indegree[neighbour]--;
                if(indegree[neighbour]==0)
                {
                    q.push(neighbour);
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
    g.topologicalsort();
}
