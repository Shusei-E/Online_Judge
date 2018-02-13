# Algorithms and Data Structures 
[Online Judge](http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=ALDS1)

## Input spaced integers
```cpp
for(int i=0; i<N; i++){
 scanf("%d", &A[i]);
}
```

## Input spaced string
```cpp
string S;
while (cin >> S){

}
```

## Get a line and split by whitespaces
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>

using namespace std;

int main(){
  // Get Input
  string temp;
  getline(cin, temp);
  istringstream iss(temp);
  vector<string> calc{istream_iterator<string>{iss},
                      istream_iterator<string>{}};

  for(int i=0; i<calc.size(); ++i){
    temp = calc[i];
    cout << temp << endl;
  }

}
```

## scanf and cin
```cpp
int n, q;
scanf("%d %d", &n, &q);

string temps;
int tempv;
vector< map<string,int> > processes;
for(int i=0; i<n; ++i){
	cin >> temps >> tempv;
	map<string, int> tempm;
	tempm[temps] = tempv;
	processes.push_back(tempm);	
}
```

## map and reference
```cpp
int & time = mSettings["WorldTime"];
```

## tuple
```cpp
tuple<string, int> tempt = make_tuple(temps, tempv);
int &temp = get<0>(tempt)
```

## free memory
```cpp
free(obj);
```

## Length of the array
関数の引数に配列のポインタを渡した時、呼び出された関数では、配列の正しい要素数を知るすべはありません。
