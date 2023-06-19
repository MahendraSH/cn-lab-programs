#include<bits/stdc++.h>
using namespace std;
int find_par(int * a,int n ) {
	int count =0;
	for (int i=0;i < n;i++ ) {
		if( a[i]==1) 
			count ++;
	}
	return count%2;
}
void display(int* a,int n) {
	for (int i=0;i <n;i++ ){
		cout << a[i] << " " ;
	}
	return ;
}

int main () {
	int n;
	cout<< " Enter the size of bits " << endl;
	cin >>n;
	cout << " Enter the bits " << endl;

	int * a= new int [n+1];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int par;
	cout << " Enter  0 for even parity and 1 for odd parity " << endl;
	cin>> par;
	int sen = find_par(a,n) ;
	if(sen!=par) {
		a[n]=1;
	}
	else {
		a[n]=0;
	}
	cout << "the message sent is : " <<endl;
	display(a,n+1) ;
	
	cout << " Enter the message recived : " <<endl;
	int * b = new int [n+1];
	for(int i=0;i<=n;i++) {
		cin >> b[i];
	}


	int rec= find_par(a,n+1)  ;
	if(rec==par) {
		cout << " the message is correct " << endl;
	}else {
		cout << " the message is worong " <<endl;
	}
	return 0;
}




