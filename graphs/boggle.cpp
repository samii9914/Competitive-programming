#include<iostream>
using namespace std;
#include<cstring>
#define M 3
#define N 3
string dictionary[] = { "GEEKS", "FOR", "QUIZ", "GO" };
int n = sizeof(dictionary) / sizeof(dictionary[0]);
bool findword(string str)
{
    for(int i=0;i<n;i++)
    {
        if(str.compare(dictionary[i])==0)
        {
            return true;
        }
    }
    return false;
}
void helper(char boggle[M][N],bool visited[M][N],string &str,int i,int j )
{
    visited[i][j]=true;
   str=str+boggle[i][j];
   if(findword(str))
   {
       cout<<str<<endl;
   }

   for(int row=i-1;row<=i+1&&row<M;row++)
   {
       for(int col=j-1;col<=j+1&&col<N;col++)
       {
           if(row>=0&&col>=0&&!visited[row][col])
           {
               helper(boggle,visited,str,row,col);
           }
       }
   }
   str.erase(str.length()-1);
   visited[i][j]=false;
}
void findWords(char boggle[M][N])
{
    bool visited[M][N]={{false}};
    string str="";
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            helper(boggle,visited,str,i,j);
        }
    }
}
int main()
{
    char boggle[M][N] = { { 'G', 'I', 'Z' },
                          { 'U', 'E', 'K' },
                          { 'Q', 'S', 'E' } };

    cout << "Following words of dictionary are present\n";
    findWords(boggle);
    return 0;
}
