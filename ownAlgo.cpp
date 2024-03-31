#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

void encrypt(string p)
{
    vector<char> store;
    int columns = p.size();
    int key = columns;

    vector<vector<char>> row(1, vector<char>(columns));
    vector<vector<char>> rowTranspose(columns, vector<char>(1));

    for (int i = 0; i < p.size(); i++)
    {
        int ch = p[i] - 65;
        store.push_back((ch + key) % 26 + 65);
    }

    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            row[i][j] = store[j] - 65;
            rowTranspose[j][i] = store[j] - 65;
        }
    }

    vector<vector<int>> result(rowTranspose.size(), vector<int>(row[0].size(), 0));

    for (int i = 0; i < rowTranspose.size(); ++i)
    {
        for (int j = 0; j < row[0].size(); ++j)
        {
            for (int k = 0; k < row.size(); ++k)
            {
                result[i][j] += rowTranspose[i][k] * row[k][j];
            }
        }
    }

    string enc;

    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[0].size(); ++j)
        {
            result[i][j] = sqrt(result[i][j]);
            char ch = result[i][j] + 65;
            enc.push_back(ch);
        }
        enc.push_back('.');
    }
    enc.pop_back(); // to remove the last fullstop
    for (int i = 0; i < enc.size(); i++)
    {
        cout << enc[i];
    }
}

void decrypt(string enc)
{
    int count = 0;
    for (int i = 0; i < enc.size(); i++)
    {
        if (enc[i] == '.')
        {
            break;
        }
        count++;
    }
    int key = count;

    string cipherText = "";
    string prevtext = "";
    for (int i = 0; i < enc.size(); i++)
    {
        if (enc[i] == '.')
        {
            continue;
        }
        cipherText.push_back(enc[i]);
    }

    vector<vector<int>> result(count, vector<int>(count));
    int strCount = 0;

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            int num = cipherText[strCount] - 65;
            result[i][j] = num;
            // cout<<result[i][j]<<" ";
            if (i == j)
            {
                prevtext.push_back(cipherText[strCount] - 65);
            }
            strCount++;
        }
        // cout<<endl;
    }

    string plainText = "";
    for (int i = 0; i < count; i++)
    {
        int num = prevtext[i];
        num -= key;
        while(num < 0){
            num += 26;
        }
        plainText.push_back(num % 26);
    }

    for (int i = 0; i < count; i++)
    {
        char ch = plainText[i] + 65;
        cout << ch;
    }
}

int main()
{
    int num;
    bool counter = true;
    cout<<"Don't Use any Special Char and Numbers\n";
    while (counter)
    {
        cout << "\nEnter 1 for Encrypt 2 for Decrypt and 3 for Exit\n";
        cin >> num;
        switch (num)
        {
        case 1:
        {
            string plainText;
            cout << "Enter PlainText for Encryption: ";
            cin >> plainText;
            transform(plainText.begin(), plainText.end(), plainText.begin(), ::toupper);
            cout << "Encrypted Text: ";
            encrypt(plainText);
            break;
        }

        case 2:
        {
            string cipherText;
            cout << "Enter CipherText for Decryption: ";
            cin >> cipherText;
            cout << "Decrypted Text: ";
            decrypt(cipherText);
            break;
        }

        case 3:
        {
            cout << "Thank-You" << endl;
            counter = false;
            break;
        }

        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }

    return 0;
}