#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct ClassData
{
    string subject;
    string branch;
    int students;
};

int main()
{
    int noOfClasses;
    cout << "Enter Number of Classes You Want for Conducting Exam: ";
    cin >> noOfClasses;

    vector<pair<int,int>> classRoomNoAlongWithCapacity;
    for (int i = 1; i <= noOfClasses; i++)
    {
        int classroomNo, capacity;
        cout << "Enter ClassRoom Number and Number of Benches present in Class [" << i << "] :";
        cin >> classroomNo >> capacity;
        classRoomNoAlongWithCapacity.push_back({classroomNo, 2*capacity});
        cout << endl;
    }

    ClassData classes[] = {
        {"Maths", "CSE", 60},
        {"DAA", "CSE", 60},
        {"WADL", "CSE", 60},
        {"WADL", "IOT", 60}
    };

    int numClasses = sizeof(classes) / sizeof(classes[0]);

    unordered_map<int, vector<ClassData>> mapData;

    for (int i = 0; i < numClasses; i++)
    {
        int firstHalf = classes[i].students / 3;
        int secondHalf = firstHalf;
        int thirdHalf = classes[i].students - 2 * firstHalf;

        for (auto& ele : classRoomNoAlongWithCapacity) {
            if (ele.second >= firstHalf) {
                bool subjectNotPresent = true;
                for (const auto& data : mapData[ele.first]) {
                    if (data.subject == classes[i].subject) {
                        subjectNotPresent = false;
                        break;
                    }
                }
                if (subjectNotPresent) {
                    mapData[ele.first].push_back({classes[i].subject, classes[i].branch, firstHalf});
                    ele.second -= firstHalf;
                    break;
                }
            }
        }

        for (auto& ele : classRoomNoAlongWithCapacity) {
            if (ele.second >= secondHalf) {
                bool subjectNotPresent = true;
                for (const auto& data : mapData[ele.first]) {
                    if (data.subject == classes[i].subject) {
                        subjectNotPresent = false;
                        break;
                    }
                }
                if (subjectNotPresent) {
                    mapData[ele.first].push_back({classes[i].subject, classes[i].branch, secondHalf});
                    ele.second -= secondHalf;
                    break;
                }
            }
        }

        for (auto& ele : classRoomNoAlongWithCapacity) {
            if (ele.second >= thirdHalf) {
                bool subjectNotPresent = true;
                for (const auto& data : mapData[ele.first]) {
                    if (data.subject == classes[i].subject) {
                        subjectNotPresent = false;
                        break;
                    }
                }
                if (subjectNotPresent) {
                    mapData[ele.first].push_back({classes[i].subject, classes[i].branch, thirdHalf});
                    ele.second -= thirdHalf;
                    break;
                }
            }
        }
    }

    for (const auto& pair_data : mapData) {
        cout << "Classroom Number: " << pair_data.first << endl;
        for (const auto& data : pair_data.second) {
            cout << "Subject: " << data.subject << ", Branch: " << data.branch << ", Students: " << data.students << endl;
        }
        cout << "-------------------" << endl;
    }

    return 0;
}
