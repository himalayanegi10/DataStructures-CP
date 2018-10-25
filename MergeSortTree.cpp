#include "bits/stdc++.h"
using namespace std;

#define left node * 2
#define right node * 2 + 1
#define pb push_back
#define lb lower_bound
#define all(x) x.begin() , x.end()

const int sz = 1e6 + 1;
int arr[sz];
vector<int> MST[4*sz];

int query(int node , int sta , int end , int l , int r , int val){
	if(l > end or r < sta)return 0;
	if(sta >= l and end <= r){
		return lb(all(MST[node]),val) - MST[node].begin();
	}
	int mid = (sta + end)/2;
	int p = query(left , sta , mid , l , r ,val);
	int q = query(right , mid + 1 , end , l , r , val);
	return p+q;
}

void build(int node , int sta , int end){
	if(sta == end){
		MST[node].pb(arr[sta]);
		return;
	}
	int mid = (sta + end) / 2;
	build(left,sta,mid);
	build(right,mid+1,end);
	merge(all(MST[left]),all(MST[right]),back_inserter(MST[node]));
}

int main(){
	cout << "Enter Number Of Elements ";
	int n;
	cin >> n;
	cout << "Enter The Array ";
	for(int i = 1 ; i <= n ; i++)cin >> arr[i];
	build(1,1,n);
	cout << query(1,1,n,1,5,3) << endl << query(1,1,n,2,5,3) << endl;
	return 0;
}
