#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <stdlib.h>  // atoi

using namespace std;

void get_values(vector<int> &values, int &v1, int &v2){
	v2 = values.back();
	values.pop_back();

	v1 = values.back();
	values.pop_back();
}

int main(){
	// Get Input
	string temp;
	getline(cin, temp);
	istringstream iss(temp);
	vector<string> calc{istream_iterator<string>{iss},
                      istream_iterator<string>{}};

	vector<int> values;
	int v1, v2, val;
	for(int i=0; i<calc.size(); ++i){
		temp = calc[i];
		if(temp == "+"){
			get_values(values, v1, v2);
			val = v1 + v2;
			values.push_back(val);
			continue;
		}	
		if(temp == "-"){
			get_values(values, v1, v2);
			val = v1 - v2;
			values.push_back(val);
			continue;
		}	
		if(temp == "*"){
			get_values(values, v1, v2);
			val = v1 * v2;
			values.push_back(val);
			continue;
		}	
		values.push_back(atoi(temp.c_str()));
	}
	cout << values[0] << endl;	
}

// From answer
// #include <stack>
// #include <string>
// #include <cstdlib>
// #include <iostream>
// 
// using namespace std;
// 
// int main()
// {
// 	stack<int> D;
//
// 	string S;
//
// 	while (cin >> S)
// 	{
// 			if (S == "+" || S == "-" || S == "*")
// 			{
// 				int B = D.top();
//
// 				D.pop();
//
// 				int A = D.top();
//
// 				D.pop();
//
// 				if (S == "+")
// 				{
// 						D.push(A + B);
// 				}
// 				if (S == "-")
// 				{
// 						D.push(A - B);
// 				}
// 				if (S == "*")
// 				{
// 						D.push(A * B);
// 				}
// 			}
// 			else
// 			{
// 				D.push(atoi(S.c_str()));
// 			}
// 	}
//
// 	cout << D.top() << endl;
//
// 	return 0;
// }
