#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;
class hashing{
    int buckets;
 
    public:
    vector<list<int>> hashtable;
    hashing(int capacity){
        buckets = capacity;
        hashtable.resize(capacity);
    }

    int hashvalue(int key){
        return key%buckets;  //Division Method;
    }


    list<int>::iterator searchKey(int key){
        int idx = hashvalue(key);
        return find(hashtable[idx].begin(), hashtable[idx].end(),key);
    }

    void addKey(int key){
        // int idx = key%buckets;
        int idx = hashvalue(key);
        hashtable[idx].push_back(key);
    }

    void deleteKey(int key){
        // int idx = key%buckets;
        int idx = hashvalue(key);
        if(searchKey(key)!=hashtable[idx].end()){
        hashtable[idx].erase(searchKey(key));
        cout<<key<<" is Deleted"<<endl;
        }
        else{
            cout<<"Key is Not Present in the HashTable"<<endl;
        }
    }

    
};
int main(){
    hashing* h = new hashing(5);
    h->addKey(1);
    h->addKey(1);
    h->addKey(2);
    h->addKey(3);
    h->addKey(4);
    h->addKey(5);
    h->addKey(30);

    for (auto &vec : h->hashtable) {
        cout << "Size: " << vec.size() << endl;
    }
    
    h->deleteKey(5);
    h->deleteKey(2);
    delete h;
    return 0;
}