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
           adjlist[v].push_back(v);
       }
    }
    void print()
    {
        for(auto i:adjlist)
        {
            cout<<i.first<<":";
            for(T node:i.second)
            {
                cout<<node<<"=>";
            }
            cout<<endl;
        }
    }
    void topologicalsort(T src)
    {
       map<T,bool> visited;
       list<T> ordering;

       for(auto i:adjlist)
       {
           T node=i.first;
           if(!visited[i.first])
           {
               helper(visited,node,ordering);
           }
       }

       for(T element:ordering)
       {
           cout<<element<<" ";
       }
    }
    void helper(map<T,bool>&visited,T node,list<T> &ordering)
    {
        visited[node]=true;

        for(T child:adjlist[node])
        {
            if(!visited[child])
            {
                helper(visited,child,ordering);
            }
        }

        ordering.push_back(node);
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
    g.topologicalsort(0);
}
