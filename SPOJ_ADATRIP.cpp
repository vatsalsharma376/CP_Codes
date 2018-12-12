

#include <bits/stdc++.h>
#define getcx getchar_unlocked
#define putcx putchar_unlocked
#define pb(x) push_back(x);
#define in(y) insert(y);
#define tt(t) while(t--)
#define int long long int
#define itr ::iterator it;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define si set<int>                      
#define msi map<string, int>
#define lines printsf("\n")
#define ff(n) for(int i=0;i<n;i++)
#define fors(i,a,b) for(int i=a;i<b;i++)
#define all(v) v.begin(),v.end()
#define mp make_pair
using namespace std;
const int MOD = 1e9+7;
std::vector<ii> grp[600000];
vi dist;
vector<bool> vis;
void dijk(int src){
	dist[src]=0;
	priority_queue<ii,vector<ii>,greater<ii>> pq;
	pq.push({0,src});
	while(!pq.empty()){
		ii cur = pq.top(); pq.pop();
		int curn = cur.second,curd=cur.first;
		if(vis[curn]) continue;
		vis[curn]=1;	
		for(auto v:grp[curn]){
			
				if(dist[v.first]>dist[curn]+v.second){
					dist[v.first]=dist[curn]+v.second;
					pq.push({dist[v.first],v.first});
				}
			
		}
	}
}
signed main(){
	int n,m,q;
	cin>>n>>m>>q;
	while(m--){
		int u,v,w; cin>>u>>v>>w;
		grp[v].push_back({u,w});
		grp[u].push_back({v,w});
	}
	ff(q){
		// calc distance to all nodes from node i
		// now find max in dist[] array = mx
		// find number of entries dist[] array that are mx
		// it is the answer
		// we can use dial algo because of small weight or maybe very optimised implementation
		int node; cin>>node;
		dist.resize(n,INT_MAX);
		vis.resize(n,0);
		dijk(node);

		int mx=-1;
		fors(j,0,n){
			if(dist[j]==INT_MAX) continue;
			mx=max(mx,dist[j]);
		}
		int ans=0;
		fors(j,0,n)
			if(dist[j]==mx) ++ans;
		
		cout<<mx<<" "<<ans<<"\n";
		vis.clear();
		dist.clear();
	}
}
