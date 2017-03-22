#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double fun_distance(int **data, int p, int n){
	double distance = 0.0;

	for(int c=0;c<n;c++){
		distance += pow( abs(data[0][c] - data[1][c]) ,p);
	}
	distance = pow(distance, 1.0/float(p));
	return distance;
}

int main(){
	int n;
	cin >> n;
	double output=0;

	int **data = new int*[2]; 
	for(int i = 0;i < 2; i++){
		data[i] = new int[n]; 
	}

	for(int r=0;r<2;r++){
		for(int c=0;c<n;c++){
			cin >> data[r][c];
		}
	}
	
	//p1
	cout << fixed << setprecision(10) << fun_distance(data, 1, n) << endl;

	//p2
	cout << fixed << setprecision(10) << fun_distance(data, 2, n) << endl;

	//p3
	cout << fixed << setprecision(10) << fun_distance(data, 3, n) << endl;
	
	//pinf
	output = 0; double temp;
	for(int c=0;c<n;c++){
		temp = abs(data[0][c] - data[1][c]);
		if(output < temp)
			output = temp;
	}
	cout << fixed << setprecision(10) << output << endl;

	return 0;
}
