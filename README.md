# 🩸 National Blood Bank Coordination Network

## 📌 2.1 Project Title

National Blood Bank Coordination Network Using Data Structures and Algorithms

---

## 📝 2.2 Problem Statement

Blood is a critical medical resource required for surgeries, emergency treatments, accident victims, cancer therapies, and disaster response operations. Managing blood inventories, donor records, hospital requests, and transportation logistics manually can lead to delays and inefficiencies.

Traditional blood management systems often struggle with inventory visibility, emergency allocation, donor coordination, and route planning. To overcome these challenges, an efficient centralized system is required that can manage blood resources effectively and ensure timely delivery during emergencies.

This project aims to develop a National Blood Bank Coordination Network using Data Structures and Algorithms (DSA) to simulate real-world healthcare logistics while improving inventory management, emergency response handling, and blood distribution efficiency.

---

## 🎯 2.3 Objectives

The primary objectives of this project are:

* To design and develop a blood bank coordination system using C++.
* To apply Data Structures and Algorithms in a healthcare environment.
* To manage donor records efficiently.
* To maintain blood inventories across multiple blood banks.
* To process emergency blood requests systematically.
* To rank blood banks based on available inventory.
* To search donor records efficiently.
* To optimize transportation routes between blood banks and hospitals.
* To verify network connectivity among healthcare facilities.
* To generate healthcare analytics and operational reports.

---

## 🏗️ 2.4 System Overview / Architecture

The National Blood Bank Coordination Network follows a modular architecture where each component performs a specific healthcare management task.

### System Flow

Donor Registration

```
  │

  ▼
```

Donor Database

```
  │

  ▼
```

Blood Inventory Management

```
  │

  ▼
```

Emergency Request Queue

```
  │

  ▼
```

Blood Allocation System

```
  │

  ▼
```

Route Optimization Engine

```
  │

  ▼
```

Healthcare Dashboard & Reports

---

### Main Modules

### 👤 Donor Registry

Stores donor details, blood groups, contact information, and availability status.

### 🩸 Blood Bank Management

Maintains blood inventories and stock levels across multiple blood banks.

### 🏥 Hospital Database

Stores hospital information and emergency blood requirements.

### 📥 Emergency Request Queue

Processes blood requests in FIFO order using Queue.

### 📊 Inventory Ranking System

Ranks blood banks according to available inventory using Merge Sort.

### 🔍 Donor Search Engine

Locates suitable donors using Binary Search.

### 🚚 Route Optimization Module

Calculates shortest transportation routes using Dijkstra's Algorithm.

### 🌐 Network Connectivity Module

Verifies healthcare network connectivity using BFS.

### 📈 Analytics Dashboard

Generates healthcare statistics and operational reports.

---

## 🧠 2.5 Data Structures and Algorithms Used

The project incorporates several important Data Structures and Algorithms.

| Data Structure / Algorithm | Purpose                                       |
| -------------------------- | --------------------------------------------- |
| Vector                     | Store donor, blood bank, and hospital records |
| Queue                      | Manage emergency blood requests               |
| Map                        | Maintain blood inventory records              |
| Binary Search              | Fast donor searching                          |
| Merge Sort                 | Blood bank inventory ranking                  |
| Graph                      | Represent transportation network              |
| Dijkstra's Algorithm       | Route optimization                            |
| BFS                        | Network connectivity verification             |

### Why These Data Structures?

### Queue

Emergency requests must be processed in the order they are received, making Queue the ideal choice.

### Binary Search

Allows rapid donor lookup in sorted donor databases.

### Merge Sort

Efficiently ranks blood banks according to inventory availability.

### Graph

Represents transportation routes between blood banks and hospitals.

### Dijkstra's Algorithm

Finds the shortest route for blood delivery.

### BFS

Ensures all healthcare facilities remain connected within the network.

---

## ⚙️ 2.6 Implementation Approach

The project was implemented using a modular approach where each module handles a specific healthcare operation.

### Step 1: Data Initialization

The system loads sample blood banks, hospitals, donors, and transportation routes.

### Step 2: Donor Management

Users can add, display, and search donor records.

### Step 3: Inventory Management

Blood inventories are monitored and updated across blood banks.

### Step 4: Emergency Request Processing

Hospitals submit emergency blood requests that are stored in a Queue.

### Step 5: Blood Bank Ranking

Blood banks are ranked according to available inventory using Merge Sort.

### Step 6: Donor Search

Suitable donors are identified using Binary Search.

### Step 7: Route Optimization

The shortest transportation route is calculated using Dijkstra's Algorithm.

### Step 8: Connectivity Verification

BFS checks whether all facilities remain connected.

### Step 9: Report Generation

The system generates healthcare analytics and operational reports.

---

## 📈 2.7 Time and Space Complexity Analysis

| Operation             | Time Complexity | Space Complexity |
| --------------------- | --------------- | ---------------- |
| Add Donor             | O(1)            | O(1)             |
| Search Donor          | O(log n)        | O(1)             |
| Search Blood Group    | O(n)            | O(1)             |
| Add Emergency Request | O(1)            | O(1)             |
| Process Request       | O(1)            | O(1)             |
| Rank Blood Banks      | O(n log n)      | O(n)             |
| Shortest Route Search | O((V+E) log V)  | O(V)             |
| Connectivity Check    | O(V+E)          | O(V)             |

Where:

* n = Number of donors or blood banks
* V = Number of healthcare facilities (vertices)
* E = Transportation routes (edges)

### Observations

* Queue operations execute in constant time.
* Binary Search significantly reduces donor search time.
* Merge Sort efficiently ranks blood banks.
* Graph-based route planning scales effectively.
* BFS provides fast connectivity verification.

---

## ▶️ 2.8 Execution Steps

### Step 1: Clone the Repository

git clone YOUR_GITHUB_LINK

### Step 2: Navigate to Project Folder

cd DSA-FINAL-PROJECT

### Step 3: Compile the Project

g++ main.cpp -o bloodbank

### Step 4: Run the Application

./bloodbank

### Step 5: Interact with the System

Use the menu-driven interface to:

* Manage donors
* Search blood groups
* Update inventories
* Process emergency requests
* Rank blood banks
* Optimize routes
* Generate reports

---

## 🧪 2.9 Sample Inputs and Outputs

### Sample Input

15
2
3
102
4
O+
6
7

### Sample Output

Hospital Database Displayed

Donor Found:
Priya | A+

Available Donors:
Rahul (O+)

Blood Inventory Displayed

Blood Banks Ranked Successfully

---

## 📸 2.10 Screenshots

Include screenshots of:

### Screenshot 1

Main Menu Interface

### Screenshot 2

Donor Database

### Screenshot 3

Blood Inventory Dashboard

### Screenshot 4

Blood Bank Ranking Output

### Screenshot 5

Transportation Network Connections

### Screenshot 6

Shortest Route Calculation

### Screenshot 7

Emergency Request Dashboard

### Screenshot 8

Request Processing Output

### Screenshot 9

Request History

### Screenshot 10

Healthcare Analytics Report

Replace this section with actual screenshots captured while running the project.

---

## 📊 2.11 Results and Observations

The project successfully demonstrates the practical application of Data Structures and Algorithms in healthcare logistics.

### Key Results

* Efficient donor searching using Binary Search.
* Inventory ranking using Merge Sort.
* Organized emergency request handling using Queue.
* Route optimization using Dijkstra's Algorithm.
* Network verification using BFS.
* Effective inventory monitoring and reporting.

### Observations

* Queue simplifies emergency request processing.
* Graph algorithms improve transportation planning.
* Sorting algorithms assist inventory allocation decisions.
* Modular architecture improves maintainability.
* DSA concepts significantly improve operational efficiency.

---

## ✅ 2.12 Conclusion

The National Blood Bank Coordination Network successfully applies Data Structures and Algorithms to solve real-world healthcare logistics challenges.

The project demonstrates how Queue, Merge Sort, Binary Search, Dijkstra's Algorithm, and BFS can be integrated into a practical blood management system. Through this implementation, valuable experience was gained in healthcare resource management, algorithm design, graph processing, object-oriented programming, and system optimization.

Overall, the project serves as a strong demonstration of how DSA concepts can be used to build efficient and scalable healthcare management applications.

---

## 👩‍💻 Developed By

**Rashmeet Kaur**

B.Tech CSE (2025–2029)

ITM Skills University

DSA Final Project – National Blood Bank Coordination Network
