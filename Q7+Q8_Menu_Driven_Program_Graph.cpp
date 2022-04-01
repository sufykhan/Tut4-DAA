#include <bits/stdc++.h>
using namespace std;


void dfs(int i,vector<vector<int>>adj,vector<bool>&vis){
   if(vis[i]==false){
        cout<<i<<" ";
        vis[i]=true;
        for(int j=0;j<adj[i].size();j++){
            if(!adj[i][j]){
                dfs(adj[i][j],adj,vis);   
            }
        }
   }
    
    
}
void iterativeDFS(int s,vector<vector<int>>adj,vector<bool> &visited){
    stack<int> stack;
    stack.push(s);
 
    while (!stack.empty())
    {
        int s = stack.top();
        stack.pop();
        if (!visited[s])
        {
            cout << s << " ";
            visited[s] = true;
        }
 
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
            if (!visited[*i])
                stack.push(*i);
    }
}

void DFS(vector<vector<int>>adj,int type){
    
    int n=adj.size();
    vector<bool>visited(n,false);
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(type==1) dfs(i,adj,visited);
            else iterativeDFS(i,adj,visited);
        }
    }
    
}
void bfs(vector<bool>&visited,int src,vector<vector<int>>adj){
    visited[src]=true;
    queue<vector<int>>q;
    vector<int>xx={src,0};
    q.push(xx);
    while(!q.empty()){
        vector<int>parent=q.front();
        q.pop();
        //cout<<parent[0]<<" --> level: "<<parent[1]<<"\n";
        cout<<parent[0]<<" ";
        for(auto x:adj[parent[0]]){
            if(!visited[x]){
                visited[x]=true;
                q.push({x,parent[1]+1});
            }
        }
    }
}
void BFS(vector<vector<int>>adj){
    int V=adj.size();
    vector<bool>vis(V,false);
    for(int i=0;i<V;i++){
        if(!vis[i]){
             bfs(vis,i,adj);
        }
    }
   
}

bool isCyclicUtil(int v, vector<bool>&visited, vector<bool>&recStack,vector<vector<int>>adj)
{
    if(visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;
 
     
        for(int i=0;i<adj[v].size();i++)
        {
            int xx=adj[v][i]; 
            
            if ( !visited[xx] && isCyclicUtil(xx, visited, recStack,adj) )
                return true;
            else if (recStack[xx])
                return true;
        }
 
    }
    recStack[v] = false;
    
    return false;
}



bool isCyclicDirected(vector<vector<int>>adj)
{
    int V=adj.size();
    
    vector<bool>visited(V,false);
    vector<bool>recStack(V,false);
 
    for(int i = 0; i < V; i++)
        if ( !visited[i] && isCyclicUtil(i, visited, recStack,adj))
            return true;
 
    return false;
}

bool isCU(int v,vector<bool>&visited, int parent,vector<vector<int>>adj)
{
    visited[v] = true;
    for (int i=0;i<adj[v].size();i++)
    {
        int xx=adj[v][i];
        if (!visited[xx])
        {
           if (isCU(xx, visited, v,adj))
              return true;
        }
        else if (xx != parent)
           return true;
    }
    return false;
}
 

bool isCyclicUndirected(vector<vector<int>>adj)
{
    int V=adj.size();
     
    vector<bool>visited(V,false);
 
    for (int u = 0; u < V; u++)
    {
        if (!visited[u])
          if (isCU(u, visited, -1,adj))
             return true;
    }
    return false;
}
 


int main(){

    cout<<"Enter the 1 for directed Graph\n";
    cout<<"Enter the 2 for undirected Graph\n";
    
    int type;cin>>type;
    cout<<"Enter Total Nodes to include:";
    
    int n;cin>>n;
    
    cout<<"NOTE : Value of node should be strictly smaller than "<<n<<"\n";
  
    
    vector<vector<int>>adj(n,vector<int>());
    
    cout<<"Enter number of Edges :";
    
    int edges;cin>>edges;
    
    cout<<"Enter the array of u and v :\n";
    
    if(type==1){
        
        for(int i=0;i<edges;i++){
            cout<<"Enter the value of u and v: ";
            int v,u;cin>>u>>v;
            adj[u].push_back(v);
        }
        cout<<"DFS for the GRAPH is AS Follows: =>";
        DFS(adj,1);  //DFS STARTS FROM NODE 0
        cout<<"\n";
        
        cout<<"BFS for the GRAPH is AS Follows: =>";
        BFS(adj);
        cout<<"\n";
        
        cout<<"\n";
        
        if(isCyclicDirected(adj)){
            cout<<"CYCLE DETECTED\n";
        }
        else{
            cout<<"NO CYCLE DETECTED\n";
        }
        
        
    }
    else{
        for(int i=0;i<edges;i++){
            int v,u;cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout<<"DFS for the GRAPH is AS Follows: =>";
        DFS(adj,1);  //DFS STARTS FROM NODE 0
        cout<<"\n";
        
        cout<<"BFS for the GRAPH is AS Follows: =>";
        BFS(adj);
        cout<<"\n";
        
        cout<<"\n";
        if(isCyclicUndirected(adj)){
            cout<<"CYCLE DETECTED\n";
        }
        else{
            cout<<"NO CYCLE DETECTED\n";
        }
    }
    
    cout<<"Q8  iterativeDFS \n ";
    
    DFS(adj,2);
    
}