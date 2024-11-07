#include <iostream>
using namespace std;

const int N = 4;
int graph[N][N];
int mincost=100;

bool visited [N]={false};

void tsp(int curr,  int count,int cost,int start){
    if (count==N && graph[curr][start]){
        mincost=min(mincost,cost  + graph[curr][start]);
    }
    else{
        for ( int i=0; i< N;i++)
    {
        if(!visited[i] && graph[curr][i]){
            visited[i]=true;
            tsp(i, count + 1 , cost  + graph[curr][i] , start);
            visited[i]=false;

        }
    }
    }
}
int main()
{cout<<"enter the adjecent matrix :"<<endl;
for(int i =0; i<N ; i++){
    for( int j=0; j<N ;j++){
        cin>>graph[i][j];

    }
}
visited[0]=true;
tsp(0,1,0,0);
cout<<"min cost to traversal is a:"<<mincost<<endl;
return 0;
}