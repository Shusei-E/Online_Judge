// Incomplete
#include <iostream>
#include <string>
using namespace std;

const int m = 1046527;

int convert(string &str){
	string res = "";
	char temp;

	for(int i=0; i<str.size(); ++i){
		temp = str[i];

		if (temp == 'A'){
			res += "1";
		}else if(temp == 'C'){
			res += "2";
		}else if(temp == 'G'){
			res += "3";
		}else if(temp == 'T'){
			res += "4";
		}
	}
	return stoi(res);
}

int h1(int &key){
	return (key % m);
}
int h2(int &key){
	return (1 + key % (m-1));
}
int h(int &key, int &i){
	return ((h1(key) + i*h2(key)) % m);
}

void insert(short int *storage, string &str){
	int key = convert(str);

	int i=0;
	int j=0;
		j = h1(key);

		if(storage[j] == 0){
			storage[j] = 1;
			return;
		}else{
			i += 1;
		}
	}
}


void find(short int *storage, string &str){
	int key = convert(str);

	int i=0;
	int j;

	while(1){
		j = h1(key);
		if(storage[j] == 1){
			cout << "yes" << endl;
			return;
		}else if(i >= m || storage[j] == 0){
			cout << "no" << endl;
			return;
		}else{
			i += 1;
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);

	char command[7];
	string str;

	short int storage[m] = {0}; 
	for(int i=0; i<n; ++i){
		scanf("%s", command);
		cin >> str;

		if(command[0] == 'i'){
			insert(storage, str);
		}else{
			find(storage, str);
		}
	}

	return 0;
}


// #include<iostream>
// #include<vector>
// #include<string>
// #include<unordered_set>
// using namespace std;
// 
// int main() {
//     int a;
//     cin >> a;
//     unordered_set<string>b;
//     for (int c = 0; c < a; c++) {
//         string d, e;
//         cin >> d >> e;
//         if (d == "insert")b.insert(e);
//         else {
//             if (b.find(e) == b.end())cout << "no" << endl;
//             else cout << "yes" << endl;
//         }
//     }
// }
