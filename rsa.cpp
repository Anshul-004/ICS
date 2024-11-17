#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long modInverse(long long e, long long phi)
{
    long long m0 = phi, t, q;
    long long x0 = 0, x1 = 1;
    if (phi == 1)
        return 0;
    while (e > 1)
    {
        q = e / phi;
        t = phi;
        phi = e % phi, e = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
        x1 += m0;
    return x1;
}

long long power(long long base, long long exp, long long mod)
{
    long long result = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main()
{
    srand(time(0));
    long long p = 61; // First prime number
    long long q = 53; // Second prime number
    long long n = p * q;
    long long phi = (p - 1) * (q - 1);

    long long e;
    do
    {
        e = rand() % phi;
    } while (gcd(e, phi) != 1);

    long long d = modInverse(e, phi);

    cout << "Public Key: (" << e << ", " << n << ")\n";
    cout << "Private Key: (" << d << ", " << n << ")\n";

    long long message = 65; // Example message
    cout << "Original Message: " << message << "\n";

    long long encrypted = power(message, e, n);
    cout << "Encrypted Message: " << encrypted << "\n";

    long long decrypted = power(encrypted, d, n);
    cout << "Decrypted Message: " << decrypted << "\n";

    return 0;
}