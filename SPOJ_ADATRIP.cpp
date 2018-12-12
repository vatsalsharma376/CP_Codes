/*input
10 10 10
1 1 1
1 2 1
1 2 3 
3 1 1
5 4 10
8 5 10
5 6 5
6 7 3
6 9 3
9 7 4
0
1
2
3
4
5
6
7
8
9
*/

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
			
				if(dist[v.second]>curd+v.first){
					dist[v.second]=curd+v.first;
					pq.push({dist[v.second],v.second});
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
		// we can use dial algo because of small weight or traditional dijkstra implementation(loose TL)
		int node; cin>>node;
		dist.resize(n,INT_MAX);
		vis.resize(n,0);
		dijk(node);

		int mx=-1;
		
		int ans=0;
		fors(j,0,n){
			if(dist[i]==INT_MAX) continue;
			if(dist[i]==mx) ++ans;
			else if(dist[i]>mx){
				mx=dist[i];
				ans=1;
			}
		}
		cout<<mx<<" "<<ans<<"\n";
		vis.clear();
		dist.clear();
	}
}
