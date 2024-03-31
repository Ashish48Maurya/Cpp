#include<bits/stdc++.h>
using namespace std;
void encrypt(string p)
{
    vector<char> store;
    int columns = p.size();
    int key = columns;

    for (int i = 0; i < p.size(); i++)
    {
        char ch = p[i];
        
        int encrypted_value = (ch + key) % 126;
        if (encrypted_value < 32) {
            encrypted_value += 32;
        }
        store.push_back(encrypted_value);
    }

    vector<vector<int>> row(1, vector<int>(columns));
    vector<vector<int>> rowTranspose(columns, vector<int>(1));

    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            row[i][j] = store[j];
            rowTranspose[j][i] = store[j];
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
            char ch = result[i][j];
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

    vector<vector<char>> result(count, vector<char>(count));
    int strCount = 0;

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            result[i][j] = cipherText[strCount++];
        }
    }

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if(i==j){
                prevtext += result[i][j];
            }
        }
    }

    for(auto i :prevtext){

        int encrypted_value = (i - key);
        // if (encrypted_value < 32) {
        //     encrypted_value += 32;
        // }
        cout<<char(encrypted_value);
        // cout<<(i - key)<<"-"<<encrypted_value<<"-"<<char(encrypted_value)<<endl;
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