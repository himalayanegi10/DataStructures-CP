#include "bits/stdc++.h"
using namespace std;

const int sz = 1e6 + 1;

class node{
	public:
		node *child[26];
		bool isend;
		node();
};
node :: node(){
	for(int i = 0 ; i < 26 ; i++)child[i] = NULL;
	isend = false;
}

void insert(node *root , string key){
	node *temp = new node;
	temp = root;
	for(int i = 0 ; key[i] ; i++){
		int idx = key[i] - 'a';
		if(!temp->child[idx]){
			temp->child[idx] = new node;
		}
		temp = temp->child[idx];
	}
	temp->isend = true;
}

bool search(node *root , string key){
	node *temp = new node;
	temp = root;
	for(int i = 0 ; key[i] ; i++){
		int idx = key[i] - 'a';
		if(!temp->child[idx]){
			return false;
		}
		temp = temp->child[idx];
	}
	return (temp != NULL and temp->isend);
}
int main(){
	int n;
	cout << "Enter Number of Strings : ";
	cin >> n;
	cout << "Enter Strings here : ";
	string str;
	node *root = new node;
	for(int i = 0 ; i < n ; i++){
		cin >> str;
		insert(root , str);
	}
	bool x;
	cout << "Enter String to be searched : ";
	cin >> str;
	if(search(root , str)){
		cout << "Found\n";
	}
	else cout << "Not Found\n";
	return 0;
}
