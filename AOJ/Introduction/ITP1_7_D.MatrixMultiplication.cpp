#include <iostream>
using namespace std;

int main(){
	long int n, m, l, sum=0;
	cin >> n >> m >> l;

	long int **A = new long int*[n+1];
	for(long int i=0; i<=n; i++){
		A[i] = new long int[m+1];
	}

	long int **B = new long int*[m+1];
	for(long int i=0; i<=m; i++){
		B[i] = new long int[l+1];
	}

	for(long int r=1; r<=n; r++){
		for(long int c=1; c<=m; c++){
			cin >> A[r][c];
		}
	}

	for(long int r=1; r<=m; r++){
		for(long int c=1; c<=l; c++){
			cin >> B[r][c];
		}
	}

	for(long int i=1; i<=n; i++){
		for(long int j=1; j<=l; j++){
			sum = 0;
			for(long int k=1; k<=m; k++){
				sum += A[i][k] * B[k][j];
			}
			if(j<l)
				cout << sum << " ";
			if(j==l)
				cout << sum;
		}
		cout << endl;
	}

	return 0;
}
