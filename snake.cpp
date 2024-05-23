#include<bits/stdc++.h>
using namespace std;
int graph1[7][7];
int main(){
	vector<int> graph2[7];

	int n,m;
	cin>>n>>m;
	for (int i = 0; i < m; i++)
	{
		int v1,v2;
		cin>>v1>>v2;
		graph1[v1][v2]=1;
		graph2[v1].push_back(v2);
		graph2[v2].push_back(v1);

		graph1[v2][v1]=1;

	}
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if(i==0){
				graph1[i][j]=j;
			}
			else if(j==0){
				graph1[i][j]=i;
			}
		}
		
	}
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cout<<graph1[i][j]<<" ";
		}
		cout<<"\n";
		
	}
	cout<<"\n\n";
	for (int i = 0; i < 7; i++)
	{
		for(auto it:graph2[i]){
			cout<<it<<" ";
		}
		cout<<"\n";
	}
	
}	
	
