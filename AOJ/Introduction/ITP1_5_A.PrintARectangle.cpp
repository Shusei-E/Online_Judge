// Different from what question requires
#include <iostream>
#include <vector>
using namespace std;

int output(int H, int W, int finish){
	for(int h=0; h<H; h++){
		for(int w=0; w<W; w++){
			cout << "#";
		}
		if (h != H-1) cout << endl;
	}
  if(finish != 1)
		cout << endl;
	return 0;
}

int main(){
	vector<int> data;
	int H=1, W=1;
	int count = 0;
	int finish = 0;

	while(H!=0 & W!=0){
		cin >> H >> W;
		data.push_back(H);
		data.push_back(W);
		count++;
	}

	for(int i=0; i<count-1; i++){
		if (i == count-2) finish = 1;
		output(data[2*i], data[2*i+1], finish);
	}	
	return 0;
}

