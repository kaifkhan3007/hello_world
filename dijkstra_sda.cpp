#include <bits/stdc++.h>
using namespace std;

//dijsktra is similar to prism .only difference is in prism we need to cover each not .



typedef pair<int ,int> P;



void dijkstra(vector<P> arr[],int x,int n)
{
	priority_queue<P,vector<P>,greater<P> > q;                  //priority queue to put elements in ascending order
	bool marked[30];
	int distance[30], prev[30];             //prev array is included to track the path
	
	for(int i=0;i<30;i++)
	{
		distance[i]=1000;
		prev[i]=0;
		marked[i]=false;
	}
	
	distance[x]=0;
	
	q.push(make_pair(0,x));
	
	while(q.empty()==false)
	{
	  P	p=q.top();
		q.pop();
		x=p.second;
		
		if(marked[x]==true)                        
		continue;
		                        
		marked[x]=true;
		
		for(int i=0;i<arr[x].size();i++)                                //note that we do not need to worry about formation of cycles here.
		{
			int weight=arr[x][i].first;
			int vertex=arr[x][i].second;
			
			if(distance[vertex]>weight+distance[x])
			{
				distance[vertex]=weight+distance[x];
				q.push(make_pair(distance[vertex],vertex));                          //elements are pushed in queue as distance as weight,vertex pair..
				prev[vertex]=x;
			}
			
		}
	}
cout<<endl;	
for(int i=1;i<=n;i++)
{
	cout<<distance[i]<<" ";
}

cout<<endl;

for(int i=1;i<=n;i++)
{
	cout<<prev[i]<<" ";
}

}





int main() 
{vector<P> arr[30];                   //carefully note it is array of vectors. a kind of 2d array;
int x,y,weight,edges,nodes;

cin>>edges>>nodes;

for(int i=0;i<edges;i++)
{
	cin>>x>>y>>weight;
	arr[x].push_back(make_pair(weight,y));                   //we are associating corresponding edge and node to a node.
	arr[y].push_back(make_pair(weight,x));
}

 dijkstra(arr,1,nodes);                             

	return 0;
}
