#include "bits/stdc++.h"
using namespace std;

#define left node * 2
#define right node * 2 + 1
#define all(x) x.begin() , x.end()

const int sz = 1e6 + 1;
int arr[sz];
int Tree[4*sz];
int Lazy[4*sz];


int query(int node , int sta , int end , int l , int r){
	if(Lazy[node] != 0){
		Tree[node] += (end - sta + 1) * Lazy[node];
		if(sta != end){
			Lazy[left] += Lazy[node];
			Lazy[right] += Lazy[node];
		}
		Lazy[node] = 0;
	}
	if(sta > r or end < l)return 0 ;
	if(sta >= l and end <= r)return Tree[node];
	int mid = (sta + end) / 2;
	int p = query(left , sta , mid , l , r);
	int q = query(right , mid + 1 , end , l , r);
	return p+q;
}

void update(int node , int sta , int end , int l , int r , int val){
	if(Lazy[node] != 0){
		Tree[node] += (end - sta + 1)*Lazy[node];
		if(sta != end){
			Lazy[left] += Lazy[node];
			Lazy[right] += Lazy[node];
		}
		Lazy[node] = 0;
	}
	if(sta > r or end < l)return;
	if(sta >= l and end <= r){
		Tree[node] += (end - sta + 1)*val;
		if(sta != end){
			Lazy[left] += val;
			Lazy[right] += val;
		}
		return;
	}
	int mid = (sta + end)/2;
	update(left , sta , mid , l , r , val);
	update(right , mid + 1 , end , l , r, val);
	Tree[node] = Tree[left] + Tree[right];
}

void build(int node , int sta , int end){
	if(sta == end){
		Tree[node] = arr[sta];
		return;
	}
	int mid = (sta + end)/2;
	build(left,sta,mid);
	build(right,mid+1,end);
	Tree[node] = Tree[left] + Tree[right];
}

int main(){
	int n;
	cout << "Enter Number of Elements : ";
	cin >> n;
	cout << "Enter Array Elements : ";
	for(int i = 1 ; i <= n ; i++){
		cin >> arr[i];
	}
	build(1,1,n);
	cout << query(1,1,n,1,5) << endl;
	update(1,1,n,1,5,3);
	cout << query(1,1,n,2,5) << endl;
	update(1,1,n,3,6,1);
	cout << query(1,1,n,1,6) << endl;
	return 0;
}
// HSN
