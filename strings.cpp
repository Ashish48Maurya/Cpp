#include <iostream>
#include <string>
#include <algorithm>

// ❇️❇️ Explore more functions of string from cppreference site ❇️❇️

using namespace std;
int main()
{
  // string str;
  // cin >> str;
  // cout << str << endl;
  // cout << str[1] << endl;

  string str1(5, 'n');
  cout << str1 << endl;

  string s1 = "fam";
  string s2 = "ily";
  s1.append(s2); // One of the Method
  cout << s1 << endl;

  cout << s1 + s2 << endl; // another method, ⚠️Use only one at a time

  string abc = "Hello Ashish How are you";
  cout << abc << endl;
  abc.clear(); // clears the string
  cout << abc << endl;

  string s3 = "nincompoop";
  cout << s3.length() << endl;

  s3.erase(3, 3);
  cout << s3 << endl;

  s3.insert(2, "Ashish");
  cout << s3 << endl;

  string S = s3.substr(3, 3);
  cout << S << endl;

  string s4 = "786";
  int x = stoi(s4);
  cout << x + 2 << endl;

  int y = 786;
  cout << to_string(y) + "2" << endl;

  s3.push_back('a');
  cout << s3 << endl;

  s3.erase(s3.begin());
  cout << s3 << endl;

  reverse(s3.begin(), s3.end()); // include algorithm header file for using this reverse function
  cout << s3 << endl;
  return 0;
}
