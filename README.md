# 🩸 National Blood Bank Coordination Network

## 📌 Project Title

**National Blood Bank Coordination Network Using Data Structures and Algorithms in C++**

---

## 📝 Problem Statement

Blood is one of the most critical resources in healthcare systems. Hospitals require blood for surgeries, emergency treatments, accident victims, cancer therapies, and disaster response operations. Managing blood inventories manually can lead to shortages, delays, and inefficient distribution.

The National Blood Bank Coordination Network is designed to provide centralized coordination between blood banks, hospitals, and donors. The system manages donor information, blood inventories, emergency requests, transportation routes, and healthcare analytics using Data Structures and Algorithms.

This project demonstrates how DSA concepts can be applied to solve real-world healthcare logistics challenges and ensure timely blood availability during emergencies.

---

## 🎯 Objectives

The primary objectives of this project are :- 

* Develop a centralized blood bank coordination system using C++.
* Manage blood inventories efficiently.
* Maintain donor registration and availability records.
* Process emergency blood requests systematically.
* Rank blood banks according to available inventory.
* Search donor records quickly using efficient algorithms.
* Optimize blood transportation routes.
* Verify connectivity of the healthcare distribution network.
* Generate healthcare analytics and reports.
* Demonstrate practical applications of Data Structures and Algorithms.

---

## 🏥 Industry Context

Modern healthcare systems handle thousands of blood donations and transfusions every day.

Major challenges include :- 

* Maintaining adequate blood inventory.
* Finding suitable donors quickly.
* Processing emergency requests efficiently.
* Coordinating multiple blood banks.
* Reducing transportation delays.
* Monitoring network-wide blood availability.

National healthcare organizations increasingly rely on centralized digital systems to manage these operations effectively.

---

## 🏗️ System Architecture

The system consists of the following components:

### 🩸 Blood Banks

Stores and manages blood inventory.

### 🏥 Hospital Database

Maintains hospital information and emergency requests.

### 👤 Donor Registry

Stores donor records including blood groups and contact details.

### 📦 Inventory Management System

Tracks available blood units and low-stock situations.

### 🚨 Emergency Response Dashboard

Monitors pending emergency requests.

### 🚚 Transportation Network

Represents routes between blood banks and hospitals.

### 📊 Analytics & Reporting Module

Generates healthcare statistics and reports.

---

## 🔄 System Workflow

Donor Registration
│
▼
Donor Database
│
▼
Blood Inventory Management
│
▼
Emergency Request Queue
│
▼
Blood Allocation System
│
▼
Route Optimization Engine
│
▼
Healthcare Dashboard & Reports

---

## 🧠 Data Structures and Algorithms Used

### 1️⃣ Queue (FIFO)

**Purpose:**
Used for Emergency Request Processing.

**Why Queue?**

Emergency requests must be processed in the exact order they arrive.

Example:

Hospital A Request
Hospital B Request
Hospital C Request

Processing Order:

A → B → C

**Time Complexity:**

* Enqueue → O(1)
* Dequeue → O(1)

---

### 2️⃣ Merge Sort

**Purpose:**
Rank Blood Banks according to inventory availability.

**Why Merge Sort?**

* Stable Sorting Algorithm
* Efficient for large datasets
* Divide and Conquer approach

**Time Complexity:**

O(n log n)

---

### 3️⃣ Binary Search

**Purpose:**
Search donors by ID.

**Why Binary Search?**

Searching donor records becomes much faster than linear searching.

Example:

Search Donor ID = 102

Result:

Priya | A+

**Time Complexity:**

O(log n)

---

### 4️⃣ Dijkstra's Algorithm

**Purpose:**
Find the shortest transportation route.

**Why Dijkstra?**

Blood delivery must reach hospitals in minimum possible time.

Example:

City Blood Bank → Grace Clinic

Shortest Route:

City Blood Bank → LifeCare Bank → Grace Clinic

Distance:

18 km

**Time Complexity:**

O((V + E) log V)

---

### 5️⃣ Breadth First Search (BFS)

**Purpose:**
Verify network connectivity.

**Why BFS?**

Ensures all blood banks and hospitals remain connected.

Output Example :- 

ALL FACILITIES CONNECTED

**Time Complexity:**

O(V + E)

---

## ⚙️ Features Implemented

### ✅ Donor Management

* Add Donor
* Display Donors
* Search Donor by ID
* Search Donor by Blood Group

### ✅ Blood Inventory Management

* Add Inventory
* Display Inventory
* Low Stock Alerts

### ✅ Blood Bank Ranking

* Inventory Based Ranking
* Merge Sort Implementation

### ✅ Emergency Request Processing

* Add Emergency Request
* Queue Dashboard
* Process Requests

### ✅ Transportation Management

* Shortest Route Calculation
* Network Connectivity Check

### ✅ Healthcare Analytics

* Request History
* Inventory Statistics
* Blood Group Analysis
* Report Generation

---

## 📈 Time Complexity Analysis

| Operation          | Algorithm     | Complexity   |
| ------------------ | ------------- | ------------ |
| Add Donor          | Vector Insert | O(1)         |
| Search Donor       | Binary Search | O(log n)     |
| Search Blood Group | Linear Search | O(n)         |
| Add Request        | Queue         | O(1)         |
| Process Request    | Queue         | O(1)         |
| Rank Blood Banks   | Merge Sort    | O(n log n)   |
| Shortest Route     | Dijkstra      | O((V+E)logV) |
| Connectivity Check | BFS           | O(V+E)       |

---

## ▶️ How to Run

### Step 1: Clone Repository

```bash
git clone https://github.com/your-username/DSA-FINAL-PROJECT.git
```

### Step 2: Open Project Folder

```bash
cd DSA-FINAL-PROJECT
```

### Step 3: Compile Program

```bash
g++ main.cpp -o bloodbank
```

### Step 4: Run Program

```bash
./bloodbank
```

---

## 🧪 Sample Execution

### Display Hospitals

Input

15

Output

City Hospital - Mumbai
Grace Clinic - Pune

---

### Search Donor

Input

3
102

Output

Donor Found:
Priya | A+ | 9876543211

---

### Search Blood Group

Input

4
O+

Output

Rahul (ID:101)

---

### Rank Blood Banks

Input

7

Output

1. LifeCare Bank - 100 Units
2. City Blood Bank - 60 Units
3. RedCross Bank - 30 Units

---

### Shortest Route

Input

10
0
4

Output

Shortest Distance: 18 km

Path:

City Blood Bank → LifeCare Bank → Grace Clinic

---

### Connectivity Check

Input

11

Output

ALL FACILITIES CONNECTED

---

## 📊 Results and Observations

The system successfully demonstrates practical implementation of Data Structures and Algorithms in healthcare logistics.

### Key Results

* Efficient donor searching using Binary Search.
* Organized emergency request processing using Queue.
* Inventory ranking using Merge Sort.
* Fast route optimization using Dijkstra's Algorithm.
* Network verification using BFS.
* Real-time inventory monitoring.
* Automated healthcare reporting.

---

🌟 Project Highlights

Real-World Healthcare Problem

Simulates a national-level blood distribution and coordination system.

Efficient Data Management

Uses optimized Data Structures for storing and managing healthcare records.

Emergency Handling

Supports rapid emergency request allocation.

Route Optimization

Finds shortest delivery routes between blood banks and hospitals.

Network Monitoring

Verifies connectivity of all healthcare facilities.

Analytics Dashboard

Generates reports and statistics for decision-making.

📸 Screenshots

Screenshot 1 – Main Menu

Insert Screenshot Here

Screenshot 2 – Donor Database

Insert Screenshot Here

Screenshot 3 – Blood Inventory Dashboard

Insert Screenshot Here

Screenshot 4 – Blood Bank Ranking

Insert Screenshot Here

Screenshot 5 – Transportation Network

Insert Screenshot Here

Screenshot 6 – Shortest Route Calculation

Insert Screenshot Here

Screenshot 7 – Emergency Queue Dashboard

Insert Screenshot Here

Screenshot 8 – Request Processing

Insert Screenshot Here

Screenshot 9 – Request History

Insert Screenshot Here

Screenshot 10 – Final Healthcare Report

Insert Screenshot Here

🎓 Learning Outcomes

Through this project the following concepts were learned :- 

Object Oriented Programming
Data Structures Implementation
Queue Operations
Binary Search
Merge Sort
Graph Representation
Dijkstra's Algorithm
Breadth First Search
Healthcare Logistics Modeling
Real-World Problem Solving Using DSA

## 🚀 Future Enhancements

* Database Integration (MySQL/MongoDB)
* Web-Based Dashboard
* Mobile Application Support
* GPS-Based Live Tracking
* AI-Based Blood Demand Prediction
* SMS & Email Notifications
* Cloud Deployment

---

## ✅ Conclusion

The National Blood Bank Coordination Network successfully demonstrates how Data Structures and Algorithms can solve real-world healthcare logistics problems.

By integrating Queue, Merge Sort, Binary Search, Dijkstra's Algorithm, and BFS, the system provides efficient blood inventory management, donor coordination, emergency response handling, route optimization, and healthcare analytics.

The project highlights the importance of choosing appropriate data structures to improve performance, scalability, and operational efficiency in life-saving medical systems.

---

## 👩‍💻 Developed By

**Rashmeet Kaur**

B.Tech CSE (2025–2029)

ITM Skills University

DSA Final Project – National Blood Bank Coordination Network
