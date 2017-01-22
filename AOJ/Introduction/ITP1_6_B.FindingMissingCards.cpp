#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> S(13,0);
  vector<int> H(13,0);
  vector<int> C(13,0);
  vector<int> D(13,0);
	int n;
	char c; int num;
	cin >> n;

	for(int i=0; i<n; i++){
		cin >> c >> num;
		switch(c){
			case 'S':
				S[num-1] = 1; break;
			case 'H':
				H[num-1] = 1; break;
			case 'C':
				C[num-1] = 1; break;
			case 'D':
				D[num-1] = 1; break;
		}
	}

	for(int i=0; i<13; i++){
		if(S[i] == 0) { n=i+1; cout << "S" << " " <<n << endl ;}
	}
	for(int i=0; i<13; i++){
		if(H[i] == 0) { n=i+1; cout << "H" << " " << n<< endl ;}
	}
	for(int i=0; i<13; i++){
		if(C[i] == 0) { n=i+1; cout << "C" << " " << n<< endl ;}
	}
	for(int i=0; i<13; i++){
		if(D[i] == 0) { n=i+1; cout << "D" << " " <<n<< endl;}
	}

}

// 提出されていたのにあった、上手なやり方。
// 配列をそもそも+1個用意しておくことで、indexのズレが気にならないようにする
// 出力は最後の printfにまとめる
// #include <stdio.h>
// #include <math.h>
//  
// int main(){
//     int n,a,d[4][14]={0};
//     char c;
//     scanf("%d",&n);
//     for(int i=0;i<n;i++){
//         scanf("%s %d",&c,&a);
//         //printf(" c%c a%d\n",c,a);
//         if(c=='S') d[0][a]=1;
//         else if(c=='H') d[1][a]=1;
//         else if(c=='C') d[2][a]=1;
//         else if(c=='D') d[3][a]=1;
//     }
//     for(int i=0;i<4;i++){
//         for(int j=1;j<=13;j++){
//             if(d[i][j]==0){
//                 if(i==0) c='S';
//                 else if(i==1) c='H';
//                 else if(i==2) c='C';
//                 else if(i==3) c='D';
//                 printf("%c %d\n",c,j);
//             }
//         }
//     }
//     return 0;
// }
