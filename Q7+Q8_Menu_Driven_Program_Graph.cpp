// #include <bits/stdc++.h>

// using namespace std;


// class Graph{
//     int V;
//     list<int>*adj;
//     void DFS(vector<bool>&vis,int src);
//     void BFS(vector<bool>&vis,int src);

//     public:
//     Graph(int V);
//     ~Graph();
//     void addEdge(int u,int v,int type);
//     void printDFS();
//     void printBFS();
//     void printDFS_with_stack();
//     void checkCycleUndirected();
//     void checkCycleDirected();

// };


// Graph::Graph(int V){
//     this->V=V;
//     this->adj=new list<int>[V];
// }
// Graph::~Graph(){
//     delete[] this->adj;
// }
// void Graph::addEdge(int u,int v,int type){
//     adj[u].push_back(v);
//     if(type==1) adj[v].push_back(u);
// }
// void Graph::DFS(vector<bool>&visited,int src){
//     visited[src]=true;
//     cout<<src<<" ";

//     for(auto x:adj[src]){
//         if(!visited[x]){
//             DFS(visited,x);
//         }
//     }
// }
// void Graph::printDFS_with_stack(){
//     vector<bool>visited(V,false);
//     for(int i=0;i<V;i++){
//         if(visited[i]){
//             continue;
//         }
//         stack<int>s;
//         s.push(i);  //source node 0 by default
//         while(!s.empty()){
//             int val=s.top();
//             s.pop();
//             if( !visited[val]) {cout<<val<<" ";visited[val]=true;}
//             for(auto x:adj[val]){
//                 if(!visited[x]){
//                     s.push(x);
//                 }
//             }
//         }
//     }
    
// }
// void Graph::printDFS(){
//     vector<bool>vis(V,false);
//     int cnt=0;
//     for(int i=0;i<V;i++){
//         if(!vis[i]){
//             cout<<cnt<<"-->";
//             DFS(vis,i);
//             cnt++;
//             cout<<"\n";
//         }
//     }
// }
// void Graph::printBFS(){
//     vector<bool>vis(V,false);
//     for(int i=0;i<V;i++){
//         if(!vis[i]){
//              BFS(vis,i);
//         }
//     }
   
// }

// void Graph::BFS(vector<bool>&visited,int src){
//     visited[src]=true;
//     queue<vector<int>>q;
//     vector<int>xx={src,0};
//     q.push(xx);
//     while(!q.empty()){
//         vector<int>parent=q.front();
//         q.pop();
//         cout<<parent[0]<<" --> level: "<<parent[1]<<"\n";
//         for(auto x:adj[parent[0]]){
//             if(!visited[x]){
//                 visited[x]=true;
//                 q.push({x,parent[1]+1});
//             }
//         }
//     }
// }

// void Graph::checkCycleUndirected(){
//     vector<bool>visited(V,false);
//     vector<int>parent(V,INT_MAX);
//     for(int i=0;i<V;i++){
//         if(!visited[i]){
//            stack<int>s;
//            s.push(i);
//            while(!s.empty()){
//                int val=s.top();
//                s.pop();
//                for(auto x:adj[val]){
//                    if(visited[x]){
//                        if(parent[x]!=val){
//                             cout<<"Cycle found\n";
//                             return;
//                        }
//                    }
//                    else{
//                        parent[x]=val;
//                        visited[x]=true;
//                    }
//                }
//            }
//         }
//     }
//     cout<<"Graph is Acyclic\n";    
// }

// int main()
// {
//     cout<<"Select the type of Graph\n";
//     cout<<"Press 1 for undirected graph\n";
//     cout<<"Press 2 for directed graph\n";
    
//     int type;cin>>type;
    
//     int n;cin>>n;
//     Graph one(n);
//     int edge;cin>>edge;
//     for(int i=0;i<edge;i++){
//             int x,y;cin>>x>>y;
//             one.addEdge(x,y,type);
//     }

    
//     //Q7//
//     //{
//     // addEdge(int u,int v,int type);
//     // printDFS();
//     // printBFS();
//     // checkCycleUndirected();
//     // checkCycleDirected();
//     //}
  
//     // Q8 // printDFS_with_stack();

// }


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
        
    }
    else{
        for(int i=0;i<edges;i++){
            int v,u;cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    
    DFS(adj,2);
    
}