#include<bits/stdc++.h>
using namespace std;
int p;
int q;
int n;
vector<int> e;
vector<int> d;
vector<long int > ctr;
bool is_prime(int n);
void enc(string s);
string dec();
void fint_e(int f);
int find_d(int e, int f);

 bool is_prime(int n){
	 if ( n==1 ) {
		 return false ;
	 }
	 for (int i=2;i<=sqrt(n);i++){
		 if(n%i==0){
			 return false;
		 }
	 }
	 return true;
 }

void find_e(int f){
	for (int i=2;i <f ;i++) {
		if(__gcd(i,f)==1 &&  is_prime(i)==true  &&  i !=p && i!=q){
			e.push_back(i);
			int some=find_d(i,f);
			if(some== i){
				e.pop_back();
			}else{
			d.push_back(some);
			}

		}
	}
	return;
}
int find_d(int e,int f){
	for(int i=2;i<f;i++){
		if((i*e)%f == 1 && i !=p && i !=q){
			return i;
		}
	}
}

void enc(string s ){

	for(int some =0; some< s.size();some++ ) {
		 int   x = s[some]-'a';
		 long int k=1;
		
		for(int i =0;i < e[0] ;i++) {
			k= k*x;
			k = k%n;
		}
		ctr.push_back(k);
	}
}
string dec(){
	string p="";
	for (auto some : ctr ){
		long int k=1 ;
		for (int i =0 ;i< d[0];i++){
			k=k*some;
			k=k%n;
		}
		long int re = k +'a';
		p+=(char)re;
	}
	return p;
}

int main(){
	cout << "Enter a prime number " <<endl;
	cin>>p;
	
	cout<< "Enter another prime number " <<endl;
	cin>>q;
	if(is_prime(p) == false  && is_prime(q) == false)  {
		cout << " not prime " <<endl;
	}

	n=p*q;
	int f=(p-1)*(q-1);
	find_e(f);
	cout << " Enter the possible e and d values are " <<endl;
	for ( int i=0;i< e.size();i++)
	{
		cout << e[i]<< "\t " << d[i]<<endl;
	}

	string s ;
	cout << "Enter the message " <<endl;
	cin >>s;
	enc(s);
	cout << " Encryed message : "<<endl;
	for(int i=0;i<ctr.size();i++)
	{
		cout <<((char)( ctr[i]+'a')) ;
	}
	cout <<endl;
	cout << dec();
	return 0;
}





