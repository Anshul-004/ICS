#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int extendedGcd(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int gcd = extendedGcd(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}

int main()
{
    int a, b;
    cout << "Enter Integers to find GCD " << endl;
    cin >> a >> b;

    // Using Euclid's algorithm
    cout << "Using Euclid's Algorithm " << endl;
    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b) << endl;

    // Using Extended Euclid's algorithm
    int x, y;
    int gcdExtended = extendedGcd(a, b, x, y);
    cout << "\nUsing Extended Euclid's Algorithm " << endl;
    cout << "GCD of " << a << " and " << b << " is " << gcdExtended << endl;
    cout << "Coefficients x and y are " << x << " and " << y << endl;

    return 0;
}