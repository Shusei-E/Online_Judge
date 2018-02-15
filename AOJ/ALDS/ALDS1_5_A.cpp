#include<stdio.h>

int solve(const int *A, const int &n, int i, int m){
 if(i == n){
		return 0;
	}else if(A[i] == m){
		return 1;
	}else{
		int new_i = i + 1;
		int a = solve(A, n, new_i, m);
		int new_m = m - A[i];
		int b = solve(A, n, new_i, new_m);

		if(a == 0 && b==0){
			return 0;
		}else{
			return 1;	
		}
	}
}

int main(){
	int n, q;
	scanf("%d", &n);

	int *A = new int[n];
	for(int i=0; i<n; ++i){
		scanf("%d", &A[i]);
	}

	scanf("%d", &q);
	int *m = new int[q];
	for(int i=0; i<q; ++i){
		scanf("%d", &m[i]);
	}

	int res;
	for(int i=0; i<q; ++i){
		int index = 0;
		int mv = m[i];
		res = solve(A, n, index, mv);	
		if(res){
			printf("yes\n");
		}else{
			printf("no\n");
		}
	}

	return 0;
}
