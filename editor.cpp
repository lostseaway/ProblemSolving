#include <iostream>
#include <cstdio>
#include <string.h>
#include <stdio.h>
#include <list>
using namespace std;

list<string> lst;
int main(){
	list<string>::iterator it=lst.begin();
	list<string>::iterator k;
	int n;
	int j=0;
	string op;
	string w;
	scanf("%d ",&n);

	for(int i = 0;i<n;i++){
		cin >> op;
		if(op.compare("i")==0){
			cin >> w;
			advance(it,j);
			lst.insert(it,w);
			j++;
		}
		else if(op.compare("l")==0){
			// if(it==lst.begin())continue;
			it--;
		}
		else if(op.compare("r")==0){
			if(it==lst.end())continue;
			it++;
		}
		else if(op.compare("d")==0){
			if(++it==lst.end()){
				--it;
				continue;
			}
			it = lst.erase(it);
			it--;
		}
		else if(op.compare("b")==0){
			// if(it==lst.begin()){
			// 	++it;
			// 	continue;
			// }
			it = lst.erase(it);
			it--;

		}
		printf("\n-----------\n");
		
		cout << "NOW : " << *it << endl;
		for(k = lst.begin();k!=lst.end();++k){
			cout << *k << endl;
		}
	}

		
	for(it = lst.begin();it!=lst.end();++it){
		cout << *it << endl;
	}
	return 0;
}