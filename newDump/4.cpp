#include<bits/stdc++.h>
using namespace std;
int bucket_size=400;
void bucket (int random  ,int n) {
	if(random >bucket_size) {
		cout<< " bucket overflow " << endl;
	}
	else {
		while( random > n ) {
			 cout << " bytes transfered is : " << n << endl;
			 random -=n;
		}
		cout << " last bytes send = " << random << endl;
		cout << " bucket is empty " << endl;
	}
	return ;
}


int main (){
	int n;
	cout << " Enter the size of output " <<endl;
	cin>>n;
	for (int i =0 ;i < 5;i++ ) {
		int random = rand() % 1000;
		cout << endl << " Generated packet : "<< random << endl;
		bucket(random ,n) ;
	}

	return 0 ;
}

