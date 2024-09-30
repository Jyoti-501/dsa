#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
void findFrequencies(const vector<int>& arr) {
    unordered_map<int, int> frequencyMap;
    for (int num : arr) {
        frequencyMap[num]++;
    }
    for (const auto& pair : frequencyMap) {
        cout << "Element " << pair.first << " occurs " << pair.second << " times." << endl;
    }
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    findFrequencies(arr);
    return 0;
}
