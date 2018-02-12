#include <stdio.h>
using namespace std;

int main(){
	int n, q, s, temp;
	int count = 0;
	scanf("%d", &n);

	int *S = new int[n+1];
	for(int i=0; i<n; ++i){
		scanf("%d", &S[i]);
	}

	scanf("%d", &q);
	int *T = new int[q];
	for(int i=0; i<q; ++i){
		scanf("%d", &T[i]);
	}

	// Linear Search
	for(int i=0; i<q; ++i){
		temp = T[i];
		S[n] = temp;
		
		s = 0;
		while(S[s] != temp){
			s += 1;
		}
		if(s != n){
			count += 1;
		}
	}

	printf("%i\n", count);	

	return 0;
}
