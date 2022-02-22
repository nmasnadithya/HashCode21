#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

struct Road {
    string name;
    int B;
    int E;
    int L;

    Road(const string &name, int b, int e, int l) : name(name), B(b), E(e), L(l) {}

    Road() {}
};

int main() {
    int D, I, S, V, F;
    cin >> D >> I >> S >> V >> F;

    unordered_map<string, Road> roadMap;
    vector<string> iEnd[I];
    vector<string> iStart[I];
    vector<string> cars[V];

    unordered_set<string> travelledStreets;

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
            travelledStreets.insert(street);
        }
    }


    //Output
    vector<string> finalOutp;
    for (int i = 0; i < I; i++) {
        vector<string> outp;
        for (int j = 0; j < iEnd[i].size(); j++) {
            if (travelledStreets.find(iEnd[i][j]) != travelledStreets.end()) {
                outp.push_back(iEnd[i][j]);
            }
        }
        if (!outp.empty()) {
            string outStr = to_string(i) + "\n" + to_string(outp.size()) + "\n";

            for (int j = 0; j < outp.size(); j++) {
                outStr += outp[j] + " 1\n";
            }
            finalOutp.push_back(outStr);
        }
    }

    cout << finalOutp.size() << endl;
    for (const auto& s: finalOutp) {
        cout << s;
    }
    return 0;
}
