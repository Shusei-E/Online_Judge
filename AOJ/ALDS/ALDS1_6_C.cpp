#include<stdio.h>
#include<utility>
#include<vector>
using namespace std;


int partition(vector< pair<char, int> >&data, 
		const int &n, int p, int r){
	pair<char, int> temp;

	int x = data[r].second;
	int i = p - 1;
	for(int j=p; j<r; ++j){
		if(data[j].second <= x){
			i += 1;
			temp = data[i];
			data[i] = data[j];
			data[j] = temp; 
		}	
	}
	temp = data[i + 1];
	data[i+1] = data[r];
	data[r] = temp;

	return (i + 1);
}

void quicksort(vector<pair<char,int>> &data, const int &n,
		int p, int r){

	int q;
	if(p < r){
		q = partition(data, n, p, r);
		quicksort(data, n, p, q-1);
		quicksort(data, n, q+1, r);
	}
}

int main(){
	int n;
	scanf("%d", &n);

	vector< pair<char, int> > data;
	char tempc[5];
	int tempv;
	for(int i=0; i<n; ++i){
		scanf("%s %d", tempc, &tempv);
		data.push_back(make_pair(tempc[0], tempv));
	}

	quicksort(data, n, 0, n-1);

	for(int i=0; i<n; ++i){
		tempv = data[i].second;
		printf("%d", tempv);
		if(i != n-1)
			printf(" ");
	}
	return 0;
}
