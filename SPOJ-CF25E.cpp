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

void solve(){
  int n; cin >> n;
  
}

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
 
	int match(const string & text){
		int u = 0;
		int ans = 0;
		for(int j = 0; j < text.size(); ++j){
			int i = text[j] - 'a';
			while(true){
				// ans++;
				if(t[u].child[i] != -1){
					ans++;
					u = t[u].child[i];
					break;
				}
				if(u == 0) break;
				u = t[u].suffixLink;
			}
			int v = u;
			while(true){
				// ans++;
				v = t[v].endLink;
				if(v == 0) break;
				
				int id = t[v].id;
				int L = lenghts[id];
				
				cout << "Found word #" << t[v].id << " at position " << j << "\n";
				// matches[j].pb(L);
				// ans++;
				v = t[v].suffixLink;
			}
		}
		return ans;
	}
};

int overlap (string a, string b) {
    int n = sz(a), m = sz(b);
   	int L = min(n, m);
    // int ans = 0;
    for(int k = L; k > 0; k--) {
    	if (a.compare(n - k, k, b, 0, k) == 0) return k; 
    }
    
    return 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s1, s2, s3;
    while(cin >> s1 >> s2 >> s3){
    	// How to make  
    	// hay que encontrar cuanto de prefijo hay de sufijo en el s1 y s2
    	vector<string> vs = {s1, s2, s3};
    	sort(all(vs));
    	int ans = 1e9;
    	do{
    		string x = vs[0];
    		s1 = vs[0], s2 = vs[1], s3 = vs[2];
    		
	    	int overlap1 = overlap(x, s2);
	    	// cout << overlap1 << endl;
	    	x += s2.substr(overlap1);
	    	// cout << s1 << endl;
	    	int overlap2 = overlap(x, s3);
	    	// cout << overlap2 << endl;
	    	x += s3.substr(overlap2);
	    	ans = min(ans, sz(x));
	    	cout << sz(s1) << " " << s1 << endl;
    	}while(next_permutation(all(vs)));
    	cout << ans << endl;
    }
    return 0;
}