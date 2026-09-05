//g++ -std=c++17 -Wall -Wextra -O2 -DLOCAL main.cpp -o main && ./main < in.txt
#include <bits/stdc++.h>
using namespace std;

void _print() { cerr << "]" << endl; }
template<typename T, typename... V>
void _print(T t, V... v) { cerr << t; if (sizeof...(v)) cerr << ", "; _print(v...); }

#define LOCAL
#ifdef LOCAL
  #define dbg(x...) cerr << "[" << #x << "]: ["; _print(x)
#else
  #define dbg(x...)
  #define endl '\n'
#endif

#define pb push_back
#define ff first
#define ss second
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define forn(i, n) for (int i = 0; i < n; ++i)
#define forne(i, n) for (int i = 0; i <= n; ++i)
#define rforn(i, n) for (int i = n-1; i >= 0; --i)
#define forab(i, a, b) for (int i = a; i < b; ++i)
#define forabe(i, a, b) for (int i = a; i <= b; ++i)
#define form(i, n, m, x) for (int i = n; i < m; i += x)
#define rform(i, n, m, x) for (int i = n; i >= m; i -= x)

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;


const int M = 26;
struct node{
	vector<int> child;
	int p = -1;
	char c = 0;
	int suffixLink = -1, endLink = -1;
	int id = -1;
	//int cnt = 0; Para contar patrones repetidos
	node(int p = -1, char c = 0) : p(p), c(c){
		child.resize(M, -1);
	}
};
 
struct AhoCorasick{
	vector<node> t;
	vector<int> lenghts;
	int wordCount = 0;
 
	AhoCorasick(){
		t.emplace_back();
	}
 
	void add(const string & s){
		int u = 0;
		for(char c : s){
			if(t[u].child[c-'a'] == -1){
				t[u].child[c-'a'] = t.size();
				t.emplace_back(u, c);
			}
			u = t[u].child[c-'a'];
		}
		t[u].id = wordCount++;
		lenghts.push_back(s.size());
	}
 
	void link(int u){
		if(u == 0){
			t[u].suffixLink = 0;
			t[u].endLink = 0;
			return;
		}
		if(t[u].p == 0){
			t[u].suffixLink = 0;
			if(t[u].id != -1) t[u].endLink = u;
			else t[u].endLink = t[t[u].suffixLink].endLink;
			return;
		}
		int v = t[t[u].p].suffixLink;
		char c = t[u].c;
		while(true){
			if(t[v].child[c-'a'] != -1){
				t[u].suffixLink = t[v].child[c-'a'];
				break;
			}
			if(v == 0){
				t[u].suffixLink = 0;
				break;
			}
			v = t[v].suffixLink;
		}
		if(t[u].id != -1) t[u].endLink = u;
		else t[u].endLink = t[t[u].suffixLink].endLink;
	}
 
	void build(){
		queue<int> Q;
		Q.push(0);
		while(!Q.empty()){
			int u = Q.front(); Q.pop();
			link(u);
			for(int v = 0; v < M; ++v)
				if(t[u].child[v] != -1)
					Q.push(t[u].child[v]);
		}
	}
 
	void match(const string & text, vector<vector<int>> &matches){
		int u = 0;
		
		for(int j = 0; j < text.size(); ++j){
			int i = text[j] - 'a';
			while(true){
				if(t[u].child[i] != -1){
					u = t[u].child[i];
					break;
				}
				if(u == 0) break;
				u = t[u].suffixLink;
			}
			int v = u;
			while(true){
				v = t[v].endLink;
				if(v == 0) break;
				
				int id = t[v].id;
				int L = lenghts[id];

				// cout << "Found word #" << t[v].id << " at position " << idx << "\n";
				matches[j].pb(L);
				
				v = t[v].suffixLink;
			}
		}
		
	}
};



void solve(){
  string s; cin >> s;
  cin.ignore();
  int n; cin >> n;
  AhoCorasick aho;
  vector<string> vs(n);
  
  forn(i, n) {
  	
  	cin >> vs[i];
  	// cout << vs[i] << "\n";
  	aho.add(vs[i]);
  }
  
  aho.build();
  
  int m = s.size();
	vector<vector<int>> matches(m);
	aho.match(s, matches);

	vector<char> dp(m+1, 0);
	dp[0] = 1;
	
	for(int end = 0; end < m; end++){
		if (!dp[end] && matches[end].empty()) continue;
		
		for(int l: matches[end]){
			int start = end - l + 1;
			if (start >= 0 && dp[start]){
				dp[end + 1] = 1;
			}
		}
	}
	
	// for (int end = 0; end < m; end++) {
	//     for (int L : matches[end]) {
	//         int start = end - L + 1;
	//         if (start >= 0 && dp[start]) {
	//             dp[end + 1] = 1;
	//         }
	//     }
	// }

	cout << (dp[m] ? "yes" : "no") << "\n";
  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}