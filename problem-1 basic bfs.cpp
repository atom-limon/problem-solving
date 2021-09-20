#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
#define ll long long
//globals 
int visited[6];
vector<int> vec[6];

//functions
void bfs(int source);


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//start code here
	int n,m,x,y;
	cin>>n>>m;
	for(auto i=0;i<n;i++){
		cin>>x>>y;
		//as it is unidiractional
		vec[x].push_back(y);
		//vec[y].push_back(x);
	}
	int count=0;

	for(auto i=1;i<=n;i++){
		if(!visited[i])	{
			count++;
			bfs(i);
		}	
	}

	cout<<"need to tell ="<<count<<endl;

	return 0;
}

void bfs(int source){
	queue<int>q;
	int current=source;
	visited[current]=1;
	q.push(current);
	while(!q.empty()){
		current=q.front();		q.pop();
		for(auto i=0;i<vec[current].size();i++){
			if(!visited[vec[current][i]]){
				q.push(vec[current][i]);
				visited[vec[current][i]]=1;
			}
		}
		
	}

}
