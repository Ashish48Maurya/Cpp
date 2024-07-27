#include<bits/stdc++.h>
using namespace std;

struct ClassData
{
    string subject;
    string branch;
    int students;
};

int main(){
    ClassData classes[] = {
        {"Maths", "CSE", 74},
        {"WADL", "ELEX", 63},
        {"DAA", "IOT", 65},
        {"WADL", "MECH", 60},
        {"DAA", "AIDS", 65},
    };

    int numClasses = sizeof(classes) / sizeof(classes[0]);
    ClassData newClasses[numClasses] = {};

    map<char, vector<ClassData>> mp;

    for(int i = 0; i < numClasses; i++){
        char index = classes[i].subject[0];
        mp[index].push_back(classes[i]);
    }

    int index = 0; // index to store elements in newClasses[]

    while (!mp.empty()) {
        for(auto it = mp.begin(); it != mp.end();) {
            auto& class_vector = it->second;
            if (!class_vector.empty() && index < numClasses) {
                auto class_info = class_vector.begin();
                newClasses[index++] = *class_info;
                cout << class_info->subject << " " << class_info->branch << endl;
                class_vector.erase(class_info);
            }
            if (class_vector.empty()) {
                it = mp.erase(it);
            } else {
                ++it;
            }
        }
    }

    // Printing the newClasses[] array
    cout << "New Classes Array:" << endl;
    for (int i = 0; i < numClasses; ++i) {
        cout << newClasses[i].subject << " " << newClasses[i].branch << endl;
    }

    return 0;
}
