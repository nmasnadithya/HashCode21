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
    vector<double> carWeight(V, 0);

    unordered_map<string, float> streetVehicles;

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
            carWeight[i] += roadMap[street].L;
        }
        double tempVal = D - carWeight[i];
        if (tempVal == 0) {
            tempVal = 1;
        }
        carWeight[i] = 1 / (D - carWeight[i]);
        for (int j = 0; j < P; j++) {
            streetVehicles[cars[i][j]] += carWeight[i];
        }
    }


//Output
    vector<string> finalOutp;
    for (int i = 0; i < I; i++) {
        vector<int> roadWeight;
        for (int j = 0; j < iEnd[i].size(); j++) {
            if (streetVehicles[iEnd[i][j]] > 0) {
                roadWeight.push_back(ceil(streetVehicles[iEnd[i][j]]));
            }
        }
        if (!roadWeight.empty()) {
            int val = findGCD(roadWeight);
            string outStr = to_string(i) + "\n" + to_string(roadWeight.size()) + "\n";

            vector<pair<int, string>> order;
            for (int j = 0, k = 0; j < iEnd[i].size(); j++) {
                if (streetVehicles[iEnd[i][j]] > 0) {
                    order.emplace_back(roadWeight[k] / val,
                                       iEnd[i][j] + " " + to_string(roadWeight[k] / val) + "\n");
                    k++;
                }
            }
//            sort(order.begin(), order.end());
            for (const auto &item:order) {
                outStr += item.second;
            }
            finalOutp.push_back(outStr);
        }
    }

    cout << finalOutp.size() << endl;
    for (const auto &s: finalOutp) {
        cout << s;
    }
    return 0;
}
