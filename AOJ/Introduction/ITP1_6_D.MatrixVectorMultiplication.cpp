#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	int **A = new int*[n+1];
	for(int i=0; i < n+1; i++){
		A[i] = new int[m+1];
	}

	int *B = new int[m+1];
	int *C = new int[n+1];
	int temp=0;

	for(int r=1; r<=n; r++){
		for(int c=1; c<=m; c++){
			cin >> A[r][c];
		}
	}

	for(int r=1; r<=m; r++){
		cin >> B[r];
	}

	for(int i=1; i<=n; i++){
		temp = 0;
		for(int j=1; j<=m; j++){
			temp += A[i][j]*B[j];
		}
		C[i] = temp;
	}

	for(int i=1; i<=n; i++){
		cout << C[i] << endl;
	}

	return 0;
}
