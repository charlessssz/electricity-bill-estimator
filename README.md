# Electricity Bill Estimator (C++)

## Project Description
The Electricity Bill Estimator is a C++ console-based application that calculates electricity consumption and estimated billing. The system allows users to compute electricity costs using either manual input or appliance-based energy tracking.

It simulates real-world electricity usage by allowing users to manage multiple appliances and compute total energy consumption in kilowatt-hours (kWh).

---

## Features

### Manual Calculation
- Allows users to input total electricity consumption in kWh
- Computes total bill using a given rate per kWh

### Appliance Management System (CRUD)
- Add appliance (name, power in watts, hours per day, days used)
- View all appliances with computed kWh consumption
- Update existing appliance information
- Delete appliance records

### Automatic Energy Computation
- Calculates electricity usage based on appliance data
- Uses structured input for real-world energy estimation

---

## Formula Used

### Appliance-Based Estimation
kWh = (Power in Watts × Hours per Day × Days Used) / 1000  
Bill = kWh × Rate per kWh

### Manual Calculation
Bill = Total kWh × Rate per kWh

---

## How to Run the Program

### Step 1: Compile the code
g++ main.cpp -o app

### Step 2: Run the program

On Windows (Git Bash):
./app

On Windows (alternative):
./app.exe

---

## Program Flow
The program runs in a menu-driven loop with the following options:
1. Manual Calculation
2. Add Appliance
3. View Appliances
4. Calculate Bill
5. Update Appliance
6. Delete Appliance
7. Exit

Each option performs a specific operation related to electricity computation and appliance management.

---

## Data Structures Used
- Struct (Appliance) for organizing appliance data
- Vector for dynamic storage of multiple appliances
- Linear search algorithm for finding appliances by ID

---

## Program Purpose
This project demonstrates the application of Data Structures and Algorithms concepts, including:
- Use of structures (struct)
- Dynamic memory management using vectors
- Modular programming through functions
- Input validation and error handling
- Implementation of CRUD operations
- Algorithmic problem-solving for real-world applications

This project is submitted as a final requirement for the course Data Structures and Algorithms.

---

## Developer
Charles Jullianne  
BS Computer Science Student
