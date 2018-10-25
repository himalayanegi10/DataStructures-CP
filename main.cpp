#include "bits/stdc++.h"
using namespace std;
const int sz = 1e6+1;
int arr[sz] , BIT[sz];

int query(int pos){
	int sum = 0;
	while(pos > 0){
		sum += BIT[pos];
		pos = pos - (pos&(-pos));
	}
	return sum;
}

void update(int pos , int val , int n){
	while(pos <= n){
		BIT[pos] += val;
		pos = pos + (pos&(-pos));
	}
}

void build(int n){
	for(int i = 1 ; i <= n ; i++){
		update(i,arr[i],n);
	}
}

int main(){
	cout << "Enter Number Of Elements ";
	int n;
	cin >> n;
	cout << "\nEnter The Array ";
	for(int i = 1 ; i <= n ; i++){
		cin >> arr[i];
	}
	build(n);
	cout << query(1) << " "  <<  query(2) << " "  << query(3) << " "  << query(4) << " "  << query(5);
}
