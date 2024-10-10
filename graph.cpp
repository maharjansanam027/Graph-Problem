#include<iostream>
#include<stdio.h>
using namespace std;

class GraphMatrix
{
private:
    int v_count;
    int e_count;
    int **adj;
public:
    void createGraph(int vno,int eno);
    void printGraph();
    void printAdjacentNodes(int v);
    bool isIsolated(int v);
    ~GraphMatrix();
};

GraphMatrix::~GraphMatrix()
{
    for(int i=0;i<v_count;i++)
        delete []adj[i];
    delete []adj;
}

bool GraphMatrix::isIsolated(int v)
{
    bool flag=true;
    if(v<v_count && v>=0)
    {
        for(int i=0;i<v_count;i++)
            if(adj[v][i]==1)
                flag=false;
    }
    return flag;
}
void GraphMatrix::printAdjacentNodes(int v)
{
    if(v<v_count && v>=0)
    {
        for(int i=0;i<v_count;i++)
        {
            for(int j=0;j<v_count;j++)
            {
                if(v==i)
                {
                    if(adj[i][j]==1)
                    cout<<endl<<"V"<<j;
                }
            }
        }
    }
}
void GraphMatrix::printGraph()
{
    for(int i=0;i<v_count;i++)
    {
        for(int j=0;j<v_count;j++)
            cout<<adj[i][j]<<" ";
        cout<<endl;
    }
}

void GraphMatrix::createGraph(int vno,int eno)
{
    int u,v;
    v_count=vno;
    e_count=eno;
    adj=new int*[v_count];
    for(int i=0;i<v_count;i++)
        adj[i]=new int[v_count];


    for(int i=0;i<v_count;i++)
        for(int j=0;j<v_count;j++)
            adj[i][j]=0;


    for(int j=1;j<=e_count;j++)
    {
        cout<<"\n Enter node number connecting edge :";
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;

    }
}

int main()
{
    GraphMatrix G;
    G.createGraph(5,6);
    G.printGraph();
    G.printAdjacentNodes(2);
    cout<<endl;
    return 0;
}
