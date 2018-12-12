
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
vi cost(26,0);
string s,t;
int L[5000][5000];
int LCS( int i, int j )
{
    int sol1, sol2, sol3;
    if(!i or !j) return 0;
    if(~L[i][j]) return L[i][j];
	if ( s[i-1] == t[j-1] )
        return L[i][j]=(LCS(i-1, j-1)+cost[(s[i-1]-'a')]);
	else
	 	return L[i][j]=max(LCS(i-1,j),LCS(i,j-1));
	 
      return 0;
}
signed main(){
	int n,m;
	cin>>n>>m;
	memset(L,-1,sizeof L);
	ff(26) cin>>cost[i];
	cin>>s>>t;

	if(m>n) {swap(s,t); swap(m,n);}
	
	cout<<LCS(n,m);
}
