#include <stdio.h>
using namespace std;

int binary_search(int *A, int &key, int &length){
	int left = 0;
	int right = length;
	int mid;

	while(left < right){
		mid = (left + right) / 2;
		
		if(A[mid] == key){
			return 1;
		}else if(key < A[mid]){
			right = mid;
		}else{
			left = mid + 1;	
		}
	}

	return 0;
}

int main(){
	int n, q, s, temp;
	scanf("%d", &n);

	int *S = new int[n];
	for(int i=0; i<n; ++i){
		scanf("%d", &S[i]);
	}

	scanf("%d", &q);
	int *T = new int[q];
	for(int i=0; i<q; ++i){
		scanf("%d", &T[i]);
	}

	int key;
	int count = 0;
	for(int i=0; i<q; ++i){
		key = T[i];
		count += binary_search(S, key, n);
	}

	printf("%d\n", count);

	return 0;
}
