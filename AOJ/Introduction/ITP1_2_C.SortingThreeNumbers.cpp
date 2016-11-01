/* My Attempt */
#include <iostream>
using namespace std;
 
int main(){
	int a, b, c, tmp;
	cin >> a >> b >> c;
	
	while (!(a <= b && b <= c)){
		if (a > b){
			tmp = a;
			a = b;
			b = tmp;
		}
		if (b > c){
			tmp = b;
			b = c;
			c = tmp;
		}
	}

	cout<<a<<" "<<b<<" "<<c<<endl;;
	
	return 0;
}

/* Found Code */
#include <iostream>
using namespace std;
 
int main() {
    int a,b,c,t;
     
    cin>>a>>b>>c; 
     
    if (a>b){t=a;a=b;b=t;}
    if (b>c){t=b;b=c;c=t;}
    if (a>b){t=a;a=b;b=t;}
     
    cout<<a<<" "<<b<<" "<<c<<endl;     
    return 0;        
          
}
