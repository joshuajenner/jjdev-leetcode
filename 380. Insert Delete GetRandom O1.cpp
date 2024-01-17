#include <unordered_map>
#include <random>
using namespace std;

//Implement the RandomizedSet class :
//
//RandomizedSet() Initializes the RandomizedSet object.
//bool insert(int val) Inserts an item val into the set if not present.Returns true if the item was not present, false otherwise.
//bool remove(int val) Removes an item val from the set if present.Returns true if the item was present, false otherwise.
//int getRandom() Returns a random element from the current set of elements(it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
//You must implement the functions of the class such that each function works in average O(1) time complexity.

//Constraints:
//
//-231 <= val <= 231 - 1
//At most 2 * 105 calls will be made to insert, remove, and getRandom.
//There will be at least one element in the data structure when getRandom is called.

class RandomizedSet {

    unordered_map<int, int> map;
    vector<int> indexes;
    int size = 0;
    mt19937 rng;

public:
    RandomizedSet() {
        rng = mt19937(time(NULL));
    }

    bool insert(int val) {
        if (map.count(val)) {
            return false;
        }
        else {
            map[val] = size++;
            indexes.push_back(val);
            return true;
        }
    }

    bool remove(int val) {
        if (!map.count(val)) {
            return false;
        }
        else {
            int back = indexes.back();
            int index = map[val];

            map[back] = index;
            indexes[index] = back;

            map.erase(val);
            indexes.pop_back();
            size--;

            return true;
        }
    }
    int getRandom() {
        return indexes[rng() % size];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
