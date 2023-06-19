#include<bits/stdc++.h>
using namespace std;
int const bucket_size =500;
void bucket(int random ,int n ) {
	if (random > bucket_size) {
		cout << " bucket overflow " << endl;
	}
	else 
	{ 
		while(random > n ) {
			cout << " Transfered : " << n << endl;
			random-=n;
		}
		cout << "last transfer : "<< random  << endl;
		cout << " bucket is empty " << endl;
	}
	return ;
}

int main (){
	int n;
	cout << " Enter the size of output " << endl;
	cin >>n;
	for (int i=0;i < 5;i ++ ) {
		int random = rand()%1000;
		cout <<endl <<  " The generated  : " << random << endl;
		bucket(random ,n);
	}
	return 0;
}


