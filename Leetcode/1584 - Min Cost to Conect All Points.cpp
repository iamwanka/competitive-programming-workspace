//g++ -std=c++17 -Wall -Wextra -O2 -DLOCAL main.cpp -o main && ./main < in.txt
#include <string>
#include <bits/functexcept.h>
#include <iosfwd>
#include <bits/cxxabi_forced.h>
#include <bits/functional_hash.h>

#pragma push_macro("__SIZEOF_LONG__")
#pragma push_macro("__cplusplus")
#define __SIZEOF_LONG__ __SIZEOF_LONG_LONG__
#define unsigned unsigned long
#define __cplusplus 201102L

#define __builtin_popcountl __builtin_popcountll
#define __builtin_ctzl __builtin_ctzll

#include <bitset>

#pragma pop_macro("__cplusplus")
#pragma pop_macro("__SIZEOF_LONG__")
#undef unsigned
#undef __builtin_popcountl
#undef __builtin_ctzl

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

void solve() {
  int n; cin >> n;

}

vector<int> parent;
vector<int> sizeSubtree;
vector<vector<int>> poolEdges;

// Aquí deberían ir las funciones del union find
int findSet(int i) {
  if (parent[i] == i) return i;
  return parent[i] = findSet(parent[i]);
}

bool isSameSet(int i, int j) {return findSet(i) == findSet(j);}

void unionSet(int i, int j) {
  int parentSetI = findSet(i);
  int parentSetJ = findSet(j);

  if (sizeSubtree[parentSetI] <= sizeSubtree[parentSetJ]) {
    parent[parentSetI] = parentSetJ;
    sizeSubtree[parentSetJ]++;
  }
  else {
    parent[parentSetJ] = parentSetI;
    sizeSubtree[parentSetI]++;
  }
}

int calculateManhattanDistance(vector<int> point1, vector<int> point2){
  return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1]);
}

int minCostConnectPoints(vector<vector<int>>& points) {
  // Plan para implementarlo
  // Hacer la lista de conexiones
  // Ir uniendo con DSU

  // Metadata Necesaria
  int size = points.size();
  parent.resize(size);
  sizeSubtree.resize(size, 1);
  iota(parent.begin(), parent.end(), 0);

  // for (auto i : parent) cout << i << " "; cout << endl;
  // for (auto i : sizeSubtree) cout << i << " "; cout << endl;

  for (int i = 0; i < size - 1; i++)
    for (int j = i + 1; j < size; j++) {
      vector<int> point1 = points[i];
      vector<int> point2 = points[j];
      int manhattanDistance = calculateManhattanDistance(point1, point2);
      poolEdges.push_back({i, j, manhattanDistance});
    }
  // cout << poolEdges.size() << endl;
  sort(
    poolEdges.begin(), 
    poolEdges.end(), 
    [] (vector<int> &a, vector<int> &b) {return a[2] < b[2];});
  // for (auto edge : poolEdges) {
  //   for (auto i : edge) cout << i << " ";
  //   cout << endl;
  // }
  long long costNetwork = 0;
  // cout << "New Network - Edges " << endl;
  for (auto point : poolEdges)  {
    if (isSameSet(point[0], point[1])) continue;
    
    unionSet(point[0], point[1]);
    costNetwork += point[2];
    // cout << point[0] << " " << point[1] << " " << point[2] << endl;
  }
  
  return costNetwork;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>> test1 = {
    {3, 12},
    { -2, 5},
    { -4, 1}
  };
  
  vector<vector<int>> test2 = {
    {0,0},{2,2},{3,10},{5,2},{7,0}
  };
  
  cout << minCostConnectPoints(test1) << endl;
  return 0;
}
