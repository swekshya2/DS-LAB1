#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

// Function to input a set from the user
set<int> inputSet(int index) {
    int n, value;
    set<int> s;
    cout << "Enter number of elements in Set " << index << ": ";
    cin >> n;
    cout << "Enter elements of Set " << index << ":\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        s.insert(value); // avoids duplicates automatically
    }
    return s;
}

// Function to display a set
void displaySet(const set<int>& s, const string& label) {
    cout << label << ": { ";
    set<int>::const_iterator it;
    for (it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }
    cout << "}\n";
}

// Union of all sets
set<int> unionOfSets(const vector<set<int> >& sets) {
    set<int> result;
    for (int i = 0; i < sets.size(); ++i) {
        result.insert(sets[i].begin(), sets[i].end());
    }
    return result;
}

// Intersection of all sets
set<int> intersectionOfSets(const vector<set<int> >& sets) {
    if (sets.empty()) return set<int>();

    set<int> result = sets[0];
    for (int i = 1; i < sets.size(); ++i) {
        set<int> temp;
        set_intersection(result.begin(), result.end(),
                         sets[i].begin(), sets[i].end(),
                         inserter(temp, temp.begin()));
        result = temp;
    }
    return result;
}

// Symmetric difference of all sets
set<int> symmetricDifferenceOfSets(const vector<set<int> >& sets) {
    if (sets.empty()) return set<int>();

    set<int> result = sets[0];
    for (int i = 1; i < sets.size(); ++i) {
        set<int> temp;
        set_symmetric_difference(result.begin(), result.end(),
                                 sets[i].begin(), sets[i].end(),
                                 inserter(temp, temp.begin()));
        result = temp;
    }
    return result;
}

// Difference between Set 1 and Set 2
set<int> differenceSet(const set<int>& a, const set<int>& b) {
    set<int> result;
    set_difference(a.begin(), a.end(),
                   b.begin(), b.end(),
                   inserter(result, result.begin()));
    return result;
}

int main() {
    int numSets;
    cout << "Enter number of sets (2 or more): ";
    cin >> numSets;

    if (numSets < 2) {
        cout << "At least two sets are required.\n";
        return 1;
    }

    vector<set<int> > sets;
    for (int i = 0; i < numSets; ++i) {
        sets.push_back(inputSet(i + 1));
    }

    set<int> unionSet = unionOfSets(sets);
    set<int> intersectionSet = intersectionOfSets(sets);
    set<int> symDiffSet = symmetricDifferenceOfSets(sets);
    set<int> diffSet = differenceSet(sets[0], sets[1]);

    cout << "\n--- Set Operations Result ---\n";
    displaySet(unionSet, "Union of all sets");
    displaySet(intersectionSet, "Intersection of all sets");
    displaySet(symDiffSet, "Symmetric Difference of all sets");
    displaySet(diffSet, "Difference (Set 1 - Set 2)");

    return 0;
}
