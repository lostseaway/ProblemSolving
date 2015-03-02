#include <cstdio>
#include <vector>
using namespace std;
 
#define MAX_N  100000
 
int n,m;
 
vector<int> adj[MAX_N];
int deg[MAX_N];
 

 
bool visited[MAX_N];
int colour[MAX_N];
 
void init()
{
  for(int i=0; i<n; i++){
    adj[i].clear();
    visited[i] = false;
    colour[i] =-1;
    deg[i] = 0;
  }

}

void read_input()
{
  scanf("%d %d",&n,&m);
  init();
  for(int i=0; i<m; i++) {
    int u,v;
    scanf("%d %d",&u,&v); u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
}
 
int dfs(int u,int col,int d)
{
  // printf("u : %d col : %d d : %d ",u+1,col,d );
  if(visited[u]){
    // printf("uc : %d\n",colour[u] );
    if(col==colour[u]&&col!=0)return 1;
    return 0;
  }
  if(col == colour[u])return 1;
  visited[u] = true;
  if(col==0)colour[u]=1;
  if(col==1)colour[u]=2;
  if(col==2)colour[u]=1;
  // printf("uc : %d\n",colour[u] );
  for(int i =0;i<deg[u];i++){
    int v = adj[u][i];
    if(colour[u]==colour[v])return 1;
  }
  for(int i=0; i<deg[u]; i++) {
    int v = adj[u][i];
    // printf("%d\n",adj[u][i]);
    if(dfs(v,colour[u],d+1)==1)return 1;

  }
  return 0;
}
int main(){
  int s;
  scanf("%d",&s);
  for(int j = 0;j<s;j++){
    read_input();
    // init();
    int ch=0;
    for(int i = 0;i<n;i++){
      if(dfs(i,0,0)==1){
        printf("no\n");
        ch=1;
        break;
      }
    }
    if(ch==0)printf("yes\n");
    // for (int i = 0; i < n; ++i)
    // {
    //   printf("i : %d n : %d\n",i+1,colour[i]);
    // }
  }
}