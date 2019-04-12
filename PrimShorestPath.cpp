#include<bits/stdc++.h>
#define mx 100
#include<limits>
#include<queue>
using namespace std;

typedef pair<int,int>pi;
vector<pi>v[mx];
int vertex,edge;

struct node{
   int vertex;
   int value;
};

bool operator<(node a,node b){

return a.value>b.value;
}


prim(){
    priority_queue <node> pq;

    map<int,int>key;
    map<int,bool>check;
    map<int,int>parent;

    for(int i=0;i<vertex;i++){
            key.insert(pair<int,int>(i,INT_MAX));
            check.insert(pair<int,bool>(i,true));
            parent.insert(pair<int,int>(i,8888));

    }
  key[0]=0;
  check[0]=true;
  parent[0]=8888;
  node temp;
  temp.vertex=0;
  temp.value=0;
  pq.push(temp);

  while(!pq.empty()){
    temp =pq.top();
    check[temp.vertex]=false;
    pq.pop();
    for(int i=0;i<v[temp.vertex].size();i++){

        if(key[v[temp.vertex][i].first]>v[temp.vertex][i].second&&check[v[temp.vertex][i].first]==true){
            //check[v[temp.vertex][i].first]=false;
            key[v[temp.vertex][i].first]=v[temp.vertex][i].second;
            parent[v[temp.vertex][i].first]=temp.vertex;
            node T;
            T.vertex=v[temp.vertex][i].first;
            T.value=v[temp.vertex][i].second;
            pq.push(T);
        }
    }



  }

int cost=0;
for(int i=0;i<vertex;i++){
    cost+=key[i];
}

cout<<"Total Cost: "<<cost;


}


int main(){

cout<<"Enter Number of Vertex & Number of Edge:\n";

  cin>>vertex>>edge;

  for(int i=0;i<edge;i++){

     pi p;

     int source,src2;

     cout<<"Enter main vertex & Adjent & Edge:\n";

     cin>>source>>p.first>>p.second;

     v[source].push_back(p);

     src2=p.first;

     p.first=source;

     v[src2].push_back(p);
     }

prim();

}
