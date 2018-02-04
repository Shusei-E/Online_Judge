#include <iostream>
using namespace std;
 
int main(){
	int n;
	cin >> n;
	int min = 2000000001;
	int output = -2000000000;
	int temp;
	int temp_o;
	
	// Input
	for(int t=0; t<n; ++t){
		cin >> temp;
		
		temp_o = temp - min;
		if(temp_o > output){
			output = temp_o;
		}

		if(temp < min){
			min = temp;
		}

	}

	cout << output << endl;
	
	return 0;
}
