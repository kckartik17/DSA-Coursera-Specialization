#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
// #define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void c_p_c() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
}

int get_max_index(vector<int> weights, vector<int> values) {
	int max_i = 0;
	double max = 0;

	for (int i = 0; i < weights.size(); i++) {
		if (weights[i] != 0 && (double) values[i] / weights[i] > max) {
			max = (double) values[i] / weights[i];
			max_i = i;
		}
	}
	return max_i;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
	double value = 0.0;

	for (int i = 0; i < weights.size(); i++) {
		if (capacity == 0) return value;
		int index = get_max_index(weights, values);
		int a = min(capacity, weights[index]);
		value += a * (double) values[index] / weights[index];
		weights[index] -= a;
		capacity -= a;
	}

	return value;
}

int32_t main() {
	c_p_c();
	int n;
	int capacity;
	cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++) {
		cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);

	cout.precision(10);
	cout << optimal_value;
	return 0;
}