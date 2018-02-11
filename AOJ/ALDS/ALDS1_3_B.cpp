#include<stdio.h>
#include<tuple>
#include<string>
#include <queue>
#include <iostream>

using namespace std;


int main(){
	int n, q;
	int time=0;
	scanf("%d %d", &n, &q);

	string temps;
	int tempv;
	queue< tuple<string,int> > processes;
	for(int i=0; i<n; ++i){
		cin >> temps >> tempv;
		tuple<string, int> tempt = make_tuple(temps, tempv);
		processes.push(tempt);	
	}

	int i = 0;
	while(n != 0){

		tuple<string, int> &process = processes.front();
		int &temp = get<1>(process);

		if(temp <= q){
			string &name = get<0>(process);
			time += temp;
			cout << name << " " << time << endl;
			processes.pop();
			n -= 1;
		}else{
			time += q;
			temp -= q;
			processes.push(make_tuple(get<0>(process), temp));
			processes.pop();
		}
	}

	return 0;
}
