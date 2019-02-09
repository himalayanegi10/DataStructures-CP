#include "bits/stdc++.h"
using namespace std;

const int sz = 1e6+1;
int arr[sz];
int BIT[sz];

int query(int pos){
	int sum = 0;
	while(pos > 0){
		sum += BIT[pos];
		pos = pos - (pos&-pos);
	}
	return sum;
}

void update(int pos , int val , int n){
	while(pos <= n){
		BIT[pos] += val;
		pos = pos + (pos&-pos);
	}
}

int inversions(int n){
	int res = 0;
	for(int i = 1 ; i <= n ; i++){
		update(arr[i],1,n);
		res += query(arr[i]-1); 
	}
	return res;
}

int main(){
	cout << "Enter Number Of Integers ";
	int n;
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> arr[i];
	}
	cout << inversions(n) << endl;

}
