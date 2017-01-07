#include <iostream>
using namespace std;

int main(){
	int a, b, c;
	int res=0;

	// input
	cin >> a >> b >> c;	

	for(int i=a; i<=b; i++){
		if ((c % i) == 0) res++;
	}

	cout << res << endl;
	return 0;

}
