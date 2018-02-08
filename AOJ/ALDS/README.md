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
