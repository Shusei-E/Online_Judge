#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int A[5][4][11] = {0};
	int n, b,f,r,v;
	cin >> n; 

	for(int i=0; i<n; i++){
		cin >> b >> f >> r >> v;
		A[b][f][r] += v;
	}

	for(int b=1; b<=4; b++){
		for(int f=1; f<=3; f++){
			for(int r=1; r<=10; r++){
				cout <<  " " << A[b][f][r] ;
			}
			cout << endl;
		}
		if(b!=4)
			cout << "####################" << endl;
	}

	return 0;
}
