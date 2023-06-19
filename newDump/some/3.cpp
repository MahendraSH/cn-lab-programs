#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> e;
vector<int>d;
vector<long int > ctr;
int p;
int q;
int f;
bool is_prime(int n);
void find_e();
int find_d(int someE);
bool is_prime(int n) {

	if(n<1)
		return 0;
	for (int i =2;i <sqrt(n) ;i++) {
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
void find_e(){
	for(int i=2;i<f;i++) {
		if(__gcd(i,f)==1 && is_prime(i)==true){
			e.push_back(i);
			int some = find_d(i);
			cout<< i<< " " ;
			if(i==some){
				e.pop_back();
			}
			else{
				//cout<<i<< " " ;
				d.push_back(some);
			}
		}
	}
	return ;
}
int find_d(int someE){
	for(int i =2;i <f;i ++){
		if((i*someE)%f==1 and i!=q and i!=p ){
			return i;
		}
	}
}


int main (){
	cout << " prime number "<<endl;
	cin >>p;
	if(is_prime(p)) {
		cout << " not prime or too low " << endl;
		return 1;
	}
	cout << " prime  another number "<<endl;
	cin >>q;
	if(is_prime(q)) {
		cout << " not prime or too low  " << endl;
		return 1;
	}
	n =p*q;
	f=(p-1)*(q-1);
	find_e();
	cout<< " the possible values for e and d are " <<endl;

	for(int i=0;i< e.size();i++){
		cout<< e[i] << "\t " <<d[i]<<endl;
	}


	string mess;
	cout << " Enter the message " <<endl;
	//cin >> mess;

}




	
