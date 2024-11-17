#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

typedef bitset<64> Bitset64;
typedef bitset<48> Bitset48;
typedef bitset<32> Bitset32;

const int IP[64] = {
    58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6,
    64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17, 9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7};

const int IP_INV[64] = {
    40, 8, 48, 16, 56, 24, 64, 32,
    39, 7, 47, 15, 55, 23, 63, 31,
    38, 6, 46, 14, 54, 22, 62, 30,
    37, 5, 45, 13, 53, 21, 61, 29,
    36, 4, 44, 12, 52, 20, 60, 28,
    35, 3, 43, 11, 51, 19, 59, 27,
    34, 2, 42, 10, 50, 18, 58, 26,
    33, 1, 41, 9, 49, 17, 57, 25};

Bitset64 permute(const Bitset64 &input, const int *table, int n)
{
    Bitset64 output;
    for (int i = 0; i < n; ++i)
    {
        output[n - 1 - i] = input[64 - table[i]];
    }
    return output;
}

Bitset64 initialPermutation(const Bitset64 &input)
{
    return permute(input, IP, 64);
}

Bitset64 finalPermutation(const Bitset64 &input)
{
    return permute(input, IP_INV, 64);
}

Bitset64 desEncrypt(const Bitset64 &plaintext, const Bitset64 &key)
{
    Bitset64 permutedText = initialPermutation(plaintext);
    // Simplified: Normally, there would be 16 rounds of processing here
    Bitset64 encryptedText = permutedText ^ key; // Simplified encryption step
    return finalPermutation(encryptedText);
}

Bitset64 desDecrypt(const Bitset64 &ciphertext, const Bitset64 &key)
{
    Bitset64 permutedText = initialPermutation(ciphertext);
    // Simplified: Normally, there would be 16 rounds of processing here
    Bitset64 decryptedText = permutedText ^ key; // Simplified decryption step
    return finalPermutation(decryptedText);
}

int main()
{
    Bitset64 plaintext(0x0123456789ABCDEF);
    Bitset64 key(0x133457799BBCDFF1);

    cout << "Plaintext: " << plaintext.to_ullong() << endl;

    Bitset64 encrypted = desEncrypt(plaintext, key);
    cout << "Encrypted: " << encrypted.to_ullong() << endl;

    Bitset64 decrypted = desDecrypt(encrypted, key);
    cout << "Decrypted: " << decrypted.to_ullong() << endl;

    return 0;
}