#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <memory>
#include <set>
#include <ctime>

using namespace std;

// Helper to get current datetime
string getCurrentDateTime() {
    time_t now = time(0);
    char* dt = ctime(&now);
    string datetimeStr(dt);
    // Remove newline character from ctime output
    datetimeStr.pop_back();
    return datetimeStr;
}

// --- Data Models ---

class Donor {
public:
    int id;
    string name;
    string bloodGroup;
    string phone;
    bool available;

    Donor(int _id, string _name, string _bg, string _ph = "N/A", bool _avail = true) 
        : id(_id), name(_name), bloodGroup(_bg), phone(_ph), available(_avail) {}
};

class BloodBank {
public:
    int id;
    string name;
    string city;
    map<string, int> inventory; // BloodGroup -> Units

    BloodBank(int _id, string _name, string _city) : id(_id), name(_name), city(_city) {
        // Initialize with 0 units for common blood groups
        inventory["O+"] = 0; inventory["O-"] = 0;
        inventory["A+"] = 0; inventory["A-"] = 0;
        inventory["B+"] = 0; inventory["B-"] = 0;
        inventory["AB+"] = 0; inventory["AB-"] = 0;
    }

    int getTotalInventory() const {
        int total = 0;
        for (auto const& [bg, units] : inventory) {
            total += units;
        }
        return total;
    }
};

class Hospital {
public:
    int id;
    string name;
    string city;

    Hospital(int _id, string _name, string _city) : id(_id), name(_name), city(_city) {}
};

class Request {
public:
    string hospitalName;
    string bloodGroup;
    int units;
    string timestamp;

    Request(string _hName, string _bg, int _u) : hospitalName(_hName), bloodGroup(_bg), units(_u), timestamp(getCurrentDateTime()) {}
};

// --- Algorithms with Viva Explanation ---

/**
 * WHY QUEUE? (FIFO - First In First Out)
 * Emergency requests are processed in the order they arrive. 
 * The first hospital to request blood should be the first one served.
 */
// standard queue<Request> emergencyQueue is used in main

/**
 * WHY MERGE SORT? (Divide and Conquer)
 * Time Complexity: O(n log n) - very efficient for large datasets.
 * Stable Sorting: Maintains the relative order of records with equal inventory.
 * Used here to rank Blood Banks from highest to lowest stock.
 */
void merge(vector<BloodBank>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<BloodBank> L, R;
    for (int i = 0; i < n1; i++) L.push_back(arr[l + i]);
    for (int j = 0; j < n2; j++) R.push_back(arr[m + 1 + j]);

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].getTotalInventory() >= R[j].getTotalInventory()) { // Descending for ranking
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }
}

void mergeSort(vector<BloodBank>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

/**
 * WHY BINARY SEARCH?
 * Reduces search time from O(n) to O(log n).
 * Ideal for searching donor IDs in a large, sorted database.
 */
int binarySearchDonor(const vector<Donor>& donors, int targetId) {
    int low = 0, high = donors.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (donors[mid].id == targetId) return mid;
        if (donors[mid].id < targetId) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

/**
 * WHY DIJKSTRA'S ALGORITHM?
 * Used to find the shortest path in a weighted graph (distance/time).
 * Essential for life-saving blood delivery where every minute counts.
 */
class Network {
    int V;
    vector<vector<pair<int, int>>> adj; // Adjacency list: node -> {neighbor, weight}
    map<int, string> idToName;

public:
    Network(int nodes) : V(nodes) {
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void setNodeName(int id, string name) {
        idToName[id] = name;
    }

    void dijkstra(int src, int dest) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, INT_MAX);
        vector<int> parent(V, -1);

        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (u == dest) break;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                    parent[v] = u;
                }
            }
        }

        if (dist[dest] == INT_MAX) {
            cout << "No path exists between " << idToName[src] << " and " << idToName[dest] << endl;
            return;
        }

        cout << "Shortest Distance: " << dist[dest] << " km" << endl;
        cout << "Path: ";
        vector<int> path;
        for (int v = dest; v != -1; v = parent[v]) path.push_back(v);
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << idToName[path[i]] << (i == 0 ? "" : " -> ");
        }
        cout << endl;
    }

    /**
     * WHY BFS (Breadth First Search)?
     * Traverses nodes level-by-level.
     * Used here to ensure the entire network is connected (no isolated blood banks).
     */
    bool isConnected() {
        if (V == 0) return true;
        vector<bool> visited(V, false);
        queue<int> q;

        q.push(0);
        visited[0] = true;
        int count = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& edge : adj[u]) {
                int v = edge.first;
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                    count++;
                }
            }
        }
        return count == V;
    }

    void displayEdges() {
        cout << "\n--- Transportation Network Connections ---\n";
        set<pair<int, int>> seen; // To avoid printing same edge twice in undirected graph
        for (int u = 0; u < V; u++) {
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;
                if (seen.find({min(u, v), max(u, v)}) == seen.end()) {
                    cout << idToName[u] << " <-> " << idToName[v] << " (" << w << " km)\n";
                    seen.insert({min(u, v), max(u, v)});
                }
            }
        }
    }
};

// --- Global State ---
vector<BloodBank> bloodBanks;
vector<Donor> donors;
vector<Hospital> hospitals;
queue<Request> emergencyQueue;
vector<Request> completedRequests; // History tracking
unique_ptr<Network> cityNetwork = nullptr;

// --- Helper Functions ---

bool isValidBloodGroup(string bg) {
    static const set<string> validGroups = {"O+", "O-", "A+", "A-", "B+", "B-", "AB+", "AB-"};
    return validGroups.count(bg) > 0;
}

void displayDonors() {
    cout << "\n--- Donor List ---\n";
    cout << "ID\tName\t\tBlood Group\tPhone\t\tStatus\n";
    for (const auto& d : donors) {
        cout << d.id << "\t" << d.name << "\t\t" << d.bloodGroup << "\t\t" << d.phone << "\t" << (d.available ? "Available" : "Not Available") << endl;
    }
}

void searchDonorByBloodGroup(string bg) {
    bool found = false;
    cout << "\nAvailable Donors for " << bg << ":\n";
    for (const auto& d : donors) {
        if (d.bloodGroup == bg && d.available) {
            cout << "- " << d.name << " (ID: " << d.id << ") | Contact: " << d.phone << "\n";
            found = true;
        }
    }
    if (!found) cout << "No available donors found for " << bg << ".\n";
}

bool isDuplicatePhone(string ph) {
    for (const auto& d : donors) {
        if (d.phone == ph) return true;
    }
    return false;
}

void displayHospitals() {
    cout << "\n--- Hospital Database ---\n";
    cout << "ID\tHospital Name\t\tCity\n";
    for (const auto& h : hospitals) {
        cout << h.id << "\t" << h.name << "\t\t" << h.city << endl;
    }
}

void displayEmergencyQueue() {
    cout << "\n--- Emergency Response Dashboard ---\n";
    if (emergencyQueue.empty()) {
        cout << "No pending emergency requests.\n";
        return;
    }
    
    queue<Request> temp = emergencyQueue;
    int count = 1;
    while (!temp.empty()) {
        Request r = temp.front();
        temp.pop();
        cout << count++ << ". " << r.hospitalName << " | " << r.bloodGroup << " | " << r.units << " Units\n";
    }
}

void displayInventory() {
    cout << "\n--- Blood Bank Inventory ---\n";
    for (const auto& bb : bloodBanks) {
        cout << "Bank ID: " << bb.id << " - " << bb.name << " (" << bb.city << ") | Total: " << bb.getTotalInventory() << " units\n";
        for (auto const& [bg, units] : bb.inventory) {
            if (units > 0) {
                cout << "  " << bg << ": " << units << " units";
                if (units < 10) cout << " [LOW STOCK ALERT]";
                cout << endl;
            }
        }
    }
}

int main() {
    // Sample Data
    bloodBanks.push_back(BloodBank(0, "City Blood Bank", "Mumbai"));
    bloodBanks.push_back(BloodBank(1, "LifeCare Bank", "Pune"));
    bloodBanks.push_back(BloodBank(2, "RedCross Bank", "Mumbai"));
    
    bloodBanks[0].inventory["O+"] = 50;
    bloodBanks[0].inventory["O-"] = 10;
    bloodBanks[1].inventory["A+"] = 100;
    bloodBanks[2].inventory["O+"] = 30;

    donors.push_back(Donor(101, "Rahul", "O+", "9876543210"));
    donors.push_back(Donor(102, "Priya", "A+", "9876543211"));
    donors.push_back(Donor(103, "Aman", "B-", "9876543212"));
    donors.push_back(Donor(104, "Simran", "O-", "9876543213"));
    donors.push_back(Donor(105, "Karan", "AB+", "9876543214"));

    hospitals.push_back(Hospital(3, "City Hospital", "Mumbai"));
    hospitals.push_back(Hospital(4, "Grace Clinic", "Pune"));

    cityNetwork = make_unique<Network>(5);
    cityNetwork->setNodeName(0, "City Blood Bank");
    cityNetwork->setNodeName(1, "LifeCare Bank");
    cityNetwork->setNodeName(2, "RedCross Bank");
    cityNetwork->setNodeName(3, "City Hospital");
    cityNetwork->setNodeName(4, "Grace Clinic");

    cityNetwork->addEdge(0, 3, 5);  // BB0 - H3: 5km
    cityNetwork->addEdge(1, 4, 3);  // BB1 - H4: 3km
    cityNetwork->addEdge(0, 1, 15); // BB0 - BB1: 15km
    cityNetwork->addEdge(2, 3, 2);  // BB2 - H3: 2km
    cityNetwork->addEdge(0, 2, 4);  // BB0 - BB2: 4km

    int choice;
    do {
        cout << "\n===== NATIONAL BLOOD BANK COORDINATION NETWORK =====\n";
        cout << "1. Add Donor\n";
        cout << "2. Display Donors\n";
        cout << "3. Search Donor (Binary Search by ID)\n";
        cout << "4. Search Donor by Blood Group\n";
        cout << "5. Add Blood Inventory\n";
        cout << "6. Show Inventory (with Low Stock Alerts)\n";
        cout << "7. Rank Blood Banks (Merge Sort)\n";
        cout << "8. Add Emergency Request (Queue)\n";
        cout << "9. Process Requests\n";
        cout << "10. Find Shortest Route (Dijkstra)\n";
        cout << "11. Check Network Connectivity (BFS)\n";
        cout << "12. View Request History\n";
        cout << "13. Generate Report\n";
        cout << "14. Exit\n";
        cout << "15. Display Hospitals\n";
        cout << "16. View Emergency Queue Dashboard\n";
        cout << "17. Display Network Connections\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id; string name, bg, ph;
                cout << "Enter ID: "; cin >> id;
                
                // Check for duplicate ID (safer than binary search if data is out of order)
                bool idExists = false;
                for(const auto& d : donors) {
                    if(d.id == id) {
                        idExists = true;
                        break;
                    }
                }
                if (idExists) {
                    cout << "Error: Donor ID " << id << " already exists!\n";
                    break;
                }

                cout << "Enter Name: "; cin.ignore(); getline(cin, name);
                cout << "Enter Blood Group (O+, O-, A+, A-, B+, B-, AB+, AB-): "; cin >> bg;
                
                if (!isValidBloodGroup(bg)) {
                    cout << "Error: Invalid blood group entered!\n";
                    break;
                }

                cout << "Enter Phone Number: "; cin >> ph;
                if (isDuplicatePhone(ph)) {
                    cout << "Error: Phone number " << ph << " already registered to another donor!\n";
                    break;
                }
                donors.push_back(Donor(id, name, bg, ph));
                sort(donors.begin(), donors.end(), [](const Donor& a, const Donor& b) {
                    return a.id < b.id;
                });
                cout << "Donor Added Successfully!\n";
                break;
            }
            case 2: displayDonors(); break;
            case 3: {
                int id; cout << "Enter Donor ID to search: "; cin >> id;
                int idx = binarySearchDonor(donors, id);
                if (idx != -1) {
                    cout << "Donor Found: " << donors[idx].name << " | Group: " << donors[idx].bloodGroup << " | Phone: " << donors[idx].phone << endl;
                } else cout << "Donor not found!\n";
                break;
            }
            case 4: {
                string bg; cout << "Enter Blood Group: "; cin >> bg;
                searchDonorByBloodGroup(bg);
                break;
            }
            case 5: {
                int bankIdx;
                cout << "Select Blood Bank (0-" << bloodBanks.size()-1 << "):\n";
                for(int i=0; i<bloodBanks.size(); i++) cout << i << ". " << bloodBanks[i].name << endl;
                cin >> bankIdx;
                if (bankIdx >=0 && bankIdx < bloodBanks.size()) {
                    string bg; int units;
                    cout << "Enter Blood Group: "; cin >> bg;
                    if (!isValidBloodGroup(bg)) {
                        cout << "Error: Invalid blood group!\n";
                        break;
                    }
                    cout << "Enter Units: "; cin >> units;
                    if (units <= 0) {
                        cout << "Error: Invalid Units! Must be greater than 0.\n";
                        break;
                    }
                    bloodBanks[bankIdx].inventory[bg] += units;
                    cout << "Inventory Updated!\n";
                }
                break;
            }
            case 6: displayInventory(); break;
            case 7: {
                mergeSort(bloodBanks, 0, bloodBanks.size() - 1);
                cout << "Blood Banks Ranked by Total Inventory:\n";
                for (const auto& bb : bloodBanks) {
                    cout << "ID: " << bb.id << " - " << bb.name << ": " << bb.getTotalInventory() << " units\n";
                }
                break;
            }
            case 8: {
                string hName, bg; int units;
                cout << "Enter Hospital Name: "; cin.ignore(); getline(cin, hName);
                cout << "Enter Blood Group Required: "; cin >> bg;
                if (!isValidBloodGroup(bg)) {
                    cout << "Error: Invalid blood group!\n";
                    break;
                }
                cout << "Enter Units: "; cin >> units;
                if (units <= 0) {
                    cout << "Error: Invalid Units! Must be greater than 0.\n";
                    break;
                }
                emergencyQueue.push(Request(hName, bg, units));
                cout << "Request Added to Emergency Queue!\n";
                break;
            }
            case 9: {
                if (emergencyQueue.empty()) {
                    cout << "No pending requests.\n";
                } else {
                    Request r = emergencyQueue.front();
                    emergencyQueue.pop();
                    cout << "Processing Request for " << r.hospitalName << " (" << r.units << " units of " << r.bloodGroup << ")...\n";
                    
                    // Rank blood banks by inventory before allocation to ensure efficient decision making
                    mergeSort(bloodBanks, 0, bloodBanks.size() - 1);

                    bool found = false;
                    for (auto& bb : bloodBanks) {
                        if (bb.inventory[r.bloodGroup] >= r.units) {
                            bb.inventory[r.bloodGroup] -= r.units;
                            cout << "Allocated from " << bb.name << ". Remaining stock: " << bb.inventory[r.bloodGroup] << " units.\n";
                            if (bb.inventory[r.bloodGroup] < 10) cout << "WARNING: LOW STOCK ALERT for " << r.bloodGroup << " at " << bb.name << "!\n";
                            completedRequests.push_back(r); // Add to history
                            found = true;
                            break;
                        }
                    }
                    if (!found) cout << "Sufficient stock not found in any blood bank! Search for donors (Option 4) recommended.\n";
                }
                break;
            }
            case 10: {
                int src, dest;
                cout << "Select Source Node ID (0-4):\n";
                cout << "0-2: Blood Banks, 3-4: Hospitals\n";
                cin >> src;
                cout << "Select Destination Node ID (0-4): ";
                cin >> dest;
                if (src >= 0 && src < 5 && dest >= 0 && dest < 5) {
                    cityNetwork->dijkstra(src, dest);
                } else cout << "Invalid IDs!\n";
                break;
            }
            case 11: {
                if (cityNetwork->isConnected()) {
                    cout << "Network Status: ALL FACILITIES CONNECTED.\n";
                } else {
                    cout << "Network Status: WARNING - ISOLATED FACILITIES DETECTED.\n";
                }
                break;
            }
            case 12: {
                cout << "\n--- Request History (Completed) ---\n";
                if (completedRequests.empty()) cout << "No history available.\n";
                for (const auto& r : completedRequests) {
                    cout << "\nDate/Time: " << r.timestamp << "\n";
                    cout << "  Hospital: " << r.hospitalName << "\n";
                    cout << "  Group: " << r.bloodGroup << "\n";
                    cout << "  Units: " << r.units << " [COMPLETED]\n";
                }
                break;
            }
            case 13: {
                cout << "\n--- National Blood Bank Report ---\n";
                cout << "Total Blood Banks: " << bloodBanks.size() << endl;
                cout << "Total Donors: " << donors.size() << endl;
                
                int availableDonors = 0;
                for(auto &d : donors) if(d.available) availableDonors++;
                cout << "Available Donors: " << availableDonors << endl;

                cout << "Total Completed Requests: " << completedRequests.size() << endl;
                cout << "Pending Emergency Requests: " << emergencyQueue.size() << endl;
                
                int totalUnits = 0;
                int lowStockCount = 0;
                for(const auto& bb : bloodBanks) {
                    totalUnits += bb.getTotalInventory();
                    for(auto const& [bg, units] : bb.inventory) {
                        if(units > 0 && units < 10) lowStockCount++;
                    }
                }
                cout << "Total Blood Units in Network: " << totalUnits << endl;
                cout << "Low Stock Alerts (Blood Groups): " << lowStockCount << endl;

                // Most requested blood group
                if (!completedRequests.empty()) {
                    map<string, int> requestCount;
                    for (const auto& r : completedRequests) {
                        requestCount[r.bloodGroup]++;
                    }
                    string mostRequested = "";
                    int maxCount = 0;
                    for (const auto& pair : requestCount) {
                        if (pair.second > maxCount) {
                            maxCount = pair.second;
                            mostRequested = pair.first;
                        }
                    }
                    cout << "Most Requested Blood Group: " << mostRequested << endl;
                }
                break;
            }
            case 14: {
                cout << "\nThank You For Using National Blood Bank Coordination Network!\n";
                break;
            }
            case 15: displayHospitals(); break;
            case 16: displayEmergencyQueue(); break;
            case 17: cityNetwork->displayEdges(); break;
            default: {
                cout << "Invalid Choice! Please enter a number between 1 and 17.\n";
                break;
            }
        }
    } while (choice != 14);

    return 0;
}
