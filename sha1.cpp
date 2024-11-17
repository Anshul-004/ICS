#include <iostream>
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>
using namespace std;

string sha1(const string &input)
{
    unsigned char hash[SHA_DIGEST_LENGTH];
    SHA1(reinterpret_cast<const unsigned char *>(input.c_str()), input.size(), hash);

    stringstream ss;
    for (int i = 0; i < SHA_DIGEST_LENGTH; ++i)
    {
        ss << hex << setw(2) << setfill('0') << static_cast<int>(hash[i]);
    }
    return ss.str();
}

int main()
{
    string input;
    cout << "Enter the string to hash: ";
    getline(cin, input);
    string output = sha1(input);
    cout << "SHA1 hash: " << output << endl;
    return 0;
}