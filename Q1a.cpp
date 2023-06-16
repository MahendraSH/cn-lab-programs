//  Simple Parity Check

#include <bits/stdc++.h>
using namespace std;

int parity(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            count++;
        }
    }

    return (count % 2 == 0) ? 1 : 0;
}
int main()
{
    int n;
    cout << " Enter the number of bits" << endl;
    cin >> n;
    cout << " Enter the bits with space  " << endl;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (parity(a, n))
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
        cout << " the message is incorrect" << endl;
        cout << " the  parity error " << endl;
    }
}
