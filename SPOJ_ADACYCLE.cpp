/*input
5
0 1 1 1 1
1 0 0 0 1
0 0 1 1 0
0 0 1 0 0
0 0 0 1 0
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
int n;

vi grp[3000];
vi posi[3000];
void solve(int u){
	// calculate shortest path from node u to u
	vi dist(n,0);
	queue<int> q;
	q.push(u);
	dist[u]=0;
	vector<bool> vis(n,0);

	while(!q.empty()){
		int v = q.front();
		q.pop();
		
		for(auto nxt:grp[v]){
			if(vis[nxt] or dist[nxt]>=n) continue;
			
			vis[nxt]=true;
			q.push(nxt); 
			dist[nxt] = dist[v]+1;
			if(nxt==u){
				cout<<dist[nxt]<<"\n";
				return;
			}
		}
	}
		cout<<"NO WAY\n";
	
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int x;

	fors(i,0,n){
		fors(j,0,n){
			cin>>x;
			posi[j].push_back(i); // i-->j path so j has incident node i
			if(x) grp[i].push_back(j);
		}
	}
	// converted adjacency matrix to list
	ff(n){
		// calc answer for each node
		if(grp[i].size()) solve(i);
		else cout<<"NO WAY\n";
	}


}
