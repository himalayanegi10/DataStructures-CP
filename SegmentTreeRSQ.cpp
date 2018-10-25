#include "bits/stdc++.h"
using namespace std;

#define left node * 2
#define right node * 2 + 1

const int sz = 1e6 + 1;
int arr[sz];
int Tree[4*sz];

int query(int node , int sta , int end , int l , int r){
	if(l > end or r < sta){
		return 0;
	}
	if(sta >= l and end <= r){
		return Tree[node];
	}
	int mid = (sta + end)/2;
	int p = query(left , sta , mid , l , r);
	int q = query(right , mid + 1 , end , l , r);
	return (p+q);
	
}
void build(int node , int sta , int end){
	if(sta == end){
		Tree[node] = arr[sta];
		return;
	}
	int mid =(sta + end )/2;
	build(left, sta , mid);
	build(right , mid + 1, end);
	Tree[node] = Tree[left] + Tree[right];
}

void update(int node , int sta , int end , int val , int pos){
	if(sta == end and sta == pos){
		Tree[node] = val;
		return;
	}
	int mid = (sta + end) / 2;
	if(pos > mid)update(right , mid + 1 , end , val , pos);
	else update(left , sta , mid, val , pos);
	Tree[node] = Tree[left] + Tree[right];
}

int main(){
	cout << "Enter Number Of Elements ";
	int n;
	cin >> n;
	cout << "Enter The Array ";
	for(int i = 1 ; i <= n ; i++)cin >> arr[i];
	build(1,1,n);
	cout << Tree[1] << endl;
	update(1,1,n,32,2);
	cout << Tree[1] << endl;
	cout << query(1,1,n,3,5) << endl << query(1,1,n,2,4) << endl << query(1,1,n,1,5);
	
	return 0;
}


