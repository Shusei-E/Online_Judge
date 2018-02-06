#include <iostream>
#include <vector>

using namespace std;

void show_vec(vector<string> &vec){
	int N = vec.size();
	for(int i=0; i<N; ++i){
		cout << vec[i];
		if(i < N-1){
			cout << " ";
		}
	}	
	cout << endl;
}

int main(){
	string temp; 
	int N;
	cin >> N;
	vector <string> data1(N), data2(N); 
	vector<int> keep_num;
	
	// Input
	for(int i=0; i<N; ++i){
		cin >> data1[i];
		data2[i] = data1[i];
	}

	// Bubble Sort
	for(int i=0; i<N; ++i){
		for(int j=N-1; i+1<=j; --j){
			if(data1[j][1] < data1[j-1][1]){
				temp = data1[j];
				data1[j] = data1[j-1]; 
				data1[j-1] = temp;
			}
		}
	}

	// Selection Sort
	int minj;
	for(int i=0; i<N; ++i){
		minj = i;
		for(int j=i; j<N; ++j){
			if(data2[j][1] < data2[minj][1]){
				minj = j;
			}
		}

		temp = data2[i];
		data2[i] = data2[minj];
		data2[minj] = temp;
	}

	// Judge
	show_vec(data1);	
	cout << "Stable" << endl; //bubble sort is stable
	show_vec(data2);

	for(int i=0; i<N; ++i){
		if(data1[i][0] != data2[i][0]){
			cout << "Not stable" << endl;
			return 0;
		}
	}
	cout << "Stable" << endl;
	return 0;
}
