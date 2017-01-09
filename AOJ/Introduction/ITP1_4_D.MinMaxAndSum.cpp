#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	cin >> n;

	vector<long int> numbers(n);
	for (int i=0; i<n; i++) {
	    cin >> numbers[i];
	}

	long long int min = 1000000;
	long long int max = -1000000;
	long long int sum = 0;

	for(int i=0; i<n; i++){
		if(numbers[i] < min) min = numbers[i];
		if(max < numbers[i]) max = numbers[i];
		sum += numbers[i];
	}

	cout << min << " " << max << " " << sum << endl;
	//printf("%ld %ld %ld", min, max, sum);

	return 0;
}
