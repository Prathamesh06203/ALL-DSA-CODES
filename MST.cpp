#include<iostream>
#define infinte 999
using namespace std;
class Graph{
    int graph[10][10];
    int no_vertices,n;
    public:
    Graph(){
        no_vertices=n;
    }
    public :
    void accpet();
    void display();
    int mst();
};
void Graph::accpet()
{
    cout << "Enter Number of Vertices" << endl;
    cin>>n;
    int i;int j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            graph[i][j]=infinte;

        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout << "\nPlease Enter weight from " << i <<" to "<< j << ":"<<endl;
            cin>>graph[i][j];
            graph[j][i] = graph[i][j];
        }
    }
}
void Graph::display()
{
    cout << "Grapgh Ajacenty matrix is :: " << endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << "\t" << graph[i][j]  ;

        }
        cout << endl;
    }
}
int Graph::mst()
{
    int cost,curr,scr,cost1=0,desti,start,new1,i,j,k=1,temp;
    int visited[20],dist[20];
    cout << "Enter The source : " << endl;
    cin>>scr;
    cout << "Enter The Destination : " << endl;
    cin>>desti;
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
        dist[i]=infinte;
    }
    visited[scr]=1;
    dist[scr]=0;
    curr=scr;
    cout << "Path is : " << scr << endl;
    while(curr!=desti)
    {
        cost = infinte;
        start = dist[curr];
        for(i=1;i<=n;i++)
        {
            if(visited[i]==0)
            
                new1 = start + graph[curr][i];
                if(new1<dist[i])
                {
                    dist[i]=new1;
                    if(dist[i]<cost){
                        cost = dist[i];
                        temp = i;
                    }
                }
            
        }
        curr  = temp;
        visited[curr]=1;
        cout << "\nCurrent node is" << curr << endl;
    }
    return cost1;
}
int main()
{
    Graph g;
    int m;
    g.accpet();
    g.display();
    m = g.mst();
    cout << " ** ** Shortest Distance is : " << m <<endl;
    return 0;
}
