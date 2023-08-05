#include<iostream>
#include<string>
using namespace std;
int main(){
  string  str;
  cin>> str;
  cout<<str<<endl;
  cout<<str[1]<<endl;

  string str1(5 , 'n');
  cout<<str1<<endl;   

   string s1="fam";
   string s2="ily"; 
   s1.append(s2);       //One of the Method
   cout<<s1;

   cout<<s1+s2;         //another method

  string abc = "Hello Ashish How are you";
  abc.clear();          //clears the string
  cout<<abc<<endl;

  string s3="nincompoop"; 
    cout<<s3.length()<<endl; 
    
    for(int i=0; i<s3.size(); i++)
    cout<<s3[i]<<" ";
    cout<<endl;

    s3.erase(3 , 3);
    cout << s3<<endl;   

    //cout<<s3.find("com")<<endl;

    s3.insert(2, "Ashish");
    cout<<s3<<endl;


   string S=s3.substr(3,3);
   cout<<S<<endl;

   string s4= "786";
   int x= stoi(s4);
   cout<<x+2<<endl;

   int y=786;
   cout<<to_string(y) + "2"<<endl;
    return 0;   
}

