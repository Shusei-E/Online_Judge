#include <iostream>
using namespace std;

int main(){
	int r, c;
	cin >> r >> c;

	int **Data = new int*[r+2]();
	for(int i=0; i < r+2; i++){
		Data[i] = new int[c+2]();
	}

	int *rowsum = new int[r+2]();
	int *colsum = new int[c+2]();
	int sum = 0;

	// Input Data
	for(int n=1; n<=r; n++){
		for(int m=1; m<=c; m++){
			cin >> Data[n][m];
		}
	}

	// Output Data
	for(int rn=1; rn<=r; rn++){
		for(int cn=1; cn<=c; cn++){
			cout << Data[rn][cn] << " ";
			rowsum[rn] += Data[rn][cn];
			colsum[cn] += Data[rn][cn];
		}
		cout << rowsum[rn] << endl;
	}
	for(int cn=1; cn<=c; cn++){
		cout << colsum[cn] << " ";
		sum += colsum[cn];
	}
	cout << sum << endl;

	return 0;
}
