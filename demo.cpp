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

    string message = "abcdefghijklmnopqrstuvwxyz";
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