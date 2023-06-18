# cn lab programs

# Q1

```md
1. Write a program to implement the following Error Detection
   Techniques
   a. Single Parity Check
   b. Cyclic Redundancy Check (CRC)
   c. Checksum
```

## Q1a.cpp

```md
Simple Parity Check
Simple-bit parity is a simple error detection method that involves adding an extra bit to a data transmission. It works as:

- 1 is added to the block if it contains an odd number of 1’s, and
- 0 is added if it contains an even number of 1’s

This scheme makes the total number of 1’s even, that is why it is called even parity checking.
```

```cpp
//  Simple Parity Check

#include <bits/stdc++.h>
using namespace std;

int findParity(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            count++;
        }
    }

    return count % 2 == 0;
}
int main()
{
    int n;
    cout << " Enter the number of bits" << endl;
    cin >> n;
    cout << " Enter the bits of message  from   sender   side  with space  " << endl;
    int *b = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    cout << " Enter the  parity  1 for even or 0 for odd  " << endl;
    int parity;
    cin >> parity;

    int snderSideParity = findParity(b, n);
    cout << " the message send my sender is " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    if (snderSideParity != parity)
    {

        cout << "1" << endl;
    }
    else
    {
        cout << "0" << endl;
    }

    cout << " Enter the bits of message  from reciver  side  with space  " << endl;
    int *a = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
    }

    if (parity == findParity(a, (n + 1)))
    {
        cout << " the message is correct" << endl;
        cout << " the message is : ";
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
    }
    else
    {
        cout << findParity(a, (n + 1)) << endl;
        string err = parity ? "even  " : "odd";
        cout << " the message is incorrect" << endl;
        cout << " the  parity" << err << " error " << endl;
    }
}

```

### output :

```md
Enter the number of bits
5
Enter the bits of message from sender side with space
1 0 0 0 1
Enter the parity 1 for even or 0 for odd
0
the message send my sender is
1 0 0 0 1 1
Enter the bits of message from reciver side with space
1 0 0 0 1 1
the message is correct
the message is : 1 0 0 0 1
```

---

## Q1b.cpp

```cpp
#include<bits/stdc++.h>
using namespace std;
int find_sum(int * a, int n ) {
	int ans =0;
	for(int i=0;i<n;i++ ) {
		ans += a[i];
	}
	cout<< " sum " << ans<<endl;
	return ans;
}
int c_sender(int* a ,int n ) {
	int ans = ~find_sum(a,n);
	return ans;
}
void c_reciver(int * a, int n ,int sec) {
	int ans= find_sum(a,n) + sec;
	int checksum = ~ans ;
	if ( checksum == 0 ) {
		cout << " correct message " << endl;
	}
	else {
		cout << " checksum error " <<endl;
	}
	return;
}
int main (){
	int n;
	cout << " Entter the size of message " << endl;
	cin>>n;

	int * a= new int [n ];
	cout<< "Enter the message numebrs " <<endl;
	for (int i=0;i <n;i++) 
		cin >>a[i];
	int sender = c_sender(a,n);
	c_reciver(a,n,sender);
	return 0;
}

```

---

## Q1c.cpp

```cpp

```

---

# Q2

```md
2. Write a program to implement Caesar substitution cipher.
```

## Q2.cpp

```cpp
#include <bits/stdc++.h>
using namespace std;

string encrypt(string s, int n)
{
    string result = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            result += ' ';
        }
        else if (isupper(s[i]))
        {
            result += char((s[i] + n - 'A') % 26 + 'A');
        }
        else if (islower(s[i]))
        {
            result += char((s[i] + n - 'a') % 26 + 'a');
        }
        else
        {
            result += char((s[i] + n - '0') % 10 + '0');
        }
    }
    return result;
}

string decryption(string s, int n)
{

    string result = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            result += ' ';
        }
        else if (isupper(s[i]))
        {
            result += char((s[i] + n - 'A' + 26) % 26 + 'A');
        }
        else if (islower(s[i]))
        {
            result += char((s[i] + n - 'a' + 26) % 26 + 'a');
        }
        else
        {
            result += char((s[i] + n - '0' + 10) % 10 + '0');
        }
    }
    return result;
}
int main()
{
    string s;
    cout << "enter text : " << endl;
    getline(cin, s);
    cout << " enter the adder : " << endl;
    int n;

    cin >> n;
    n = n % 26;
    cout << " text : " << s << endl;
    cout << " adder : " << n << endl;
    cout << " encrypted text : " << encrypt(s, n) << endl;
    cout << " decrypted text : " << decryption(encrypt(s, n), -n) << endl;
}

```

### output

```md
enter text :
some 12839 849 djls
enter the adder :
894
text : some 12839 849 djls
adder : 10
encrypted text : cywo 12839 849 ntvc
decrypted text : some 12839 849 djls
```

---

## Q3.cpp

```md
3. implement RSA
```

```cpp

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> e;
vector<int> d;
vector<long int> ciperTextInt;

int p, q;
bool isPrime(int n);
int find_d(int e, int n);
void find_e_and_d(int n);
void encryption(string plaintext);
string decryption(vector<char> ciphertext);

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void find_e_and_d(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (__gcd(i, n) == 1 && isPrime(i) == true)
        {
            if (i != p and i != q)
            {

                e.emplace_back(i);
                int x = find_d(i, n);
                if (x != i)
                    d.emplace_back(x);
                else
                    e.pop_back();
            }
        }
    }
}
int find_d(int e, int n)
{
    for (int i = 2; i < n; i++)
    {
        if ((e * i) % n == 1 and i != q and i != p)
        {
            return i;
            break;
        }
    }
}

void encryption(string plaintext)
{
    for (auto p : plaintext)
    {

        int x = p - 'a';
        int key = e[0];
        long int k = 1;
        for (int i = 0; i < key; i++)
        {
            k = k * x;
            k = k % n;
        }

        ciperTextInt.emplace_back(k);
    }
}

string decryption()
{
    string s = "";
    for (auto p : ciperTextInt)
    {
        int key = d[0];
        long int k = 1;
        for (int i = 0; i < key; i++)
        {
            k = k * p;
            k = k % n;
        }
        char c = k + 'a';
        s += c;
    }
    return s;
}

int main()
{

    cout << "Enter a prime number" << endl;
    cin >> p;
    if (isPrime(p) == false)

    {
        cout << "the entered prime number is not prime" << endl;
        return 0;
    }

    cout << " Enter another prime number" << endl;
    cin >> q;
    if (isPrime(q) == false)
    {
        cout << "the entered prime number is not prime" << endl;
        return 0;
    }
    n = p * q;

    int f = (p - 1) * (q - 1);
    find_e_and_d(f);

    cout << " the possibe values of e and d are " << endl;
    for (int i = 0; i < e.size(); i++)
    {
        cout << e[i] << "\t " << d[i] << endl;
    }
 // string message = "abcdefghijklmnopqrstuvwxyz";
    string message = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // string message="12345678901234567890";
    encryption(message);
    cout << " Encryption messge " << endl;
    for (auto i : ciperTextInt)
    {
        cout << (char)(i + 'a');
    }
    cout << endl;
    cout << " decryption message :" << endl;
    cout << decryption() << endl;
    return 0;
}
```

### output

```txt
Enter a prime number
11
 Enter another prime number
7
 the possibe values of e and d are
13       37
17       53
23       47
37       13
43       60
47       23
53       17
 Encryption messge
abçû{ƒäô¢klmèÆíå¬Å₧ªvwxò¥
 decryption message :
abcdefghijklmnopqrstuvwxyz
```

---
