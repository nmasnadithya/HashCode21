#include <bits/stdc++.h>
#include <unordered_map>
#include <numeric>

using namespace std;

struct Road {
    string name;
    int B;
    int E;
    int L;

    Road(const string &name, int b, int e, int l) : name(name), B(b), E(e), L(l) {}

    Road() {}
};

int findGCD(vector<int> arr) {
    int result = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        result = gcd(arr[i], result);

        if (result == 1) {
            return 1;
        }
    }
    return result;
}

int main() {
    int D, I, S, V, F;
    cin >> D >> I >> S >> V >> F;

    unordered_map<string, Road> roadMap;
    vector<string> iEnd[I];
    vector<string> iStart[I];
    vector<string> cars[V];

    unordered_map<string, int> streetVehicles;

    for (int i = 0; i < S; i++) {
        int B, E, L;
        string name;
        cin >> B >> E >> name >> L;
        Road r = Road(name, B, E, L);
        roadMap[name] = r;
        iEnd[E].push_back(name);
        iStart[B].push_back(name);
    }


    for (int i = 0; i < V; i++) {
        int P;
        cin >> P;
        for (int j = 0; j < P; j++) {
            string street;
            cin >> street;
            cars[i].push_back(street);
            streetVehicles[street]++;
        }
    }


    //Output
    cout << I << endl;
    for (int i = 0; i < I; i++) {
        cout << i << endl;
        cout << iEnd[i].size() << endl;
        for (int j = 0; j < iEnd[i].size(); j++) {
            if (travelledStreets.find(iEnd[i][j]) != travelledStreets.end()) {
                outp.push_back(iEnd[i][j]);
            }
        }
    }
    return 0;
}
