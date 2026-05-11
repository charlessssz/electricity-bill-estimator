# Electricity Bill Estimator (C++)

## Project Description
The Electricity Bill Estimator is a C++ console-based application designed to compute electricity consumption and estimate billing costs. The system allows users to calculate electricity usage either through manual input or by tracking multiple appliances and their usage patterns.

It simulates real-world electricity monitoring by computing total energy consumption in kilowatt-hours (kWh) based on appliance power rating, usage hours, and number of days used.

---

## Key Features

### Manual Calculation
- Allows users to input total electricity consumption in kWh
- Calculates bill based on user-defined electricity rate

### Appliance Management System (CRUD)
- Add appliance with details (name, power, hours, days)
- View all stored appliances with computed energy usage
- Update existing appliance information
- Delete appliance records

### Automatic Energy Computation
- Computes electricity consumption using the formula:
  kWh = (Power in Watts × Hours × Days) / 1000

---

## Formula Used
kWh = (Power × Hours × Days) / 1000  
Bill = kWh × Rate per kWh

---

## How to Run the Program

### Step 1: Compile the program
```bash
g++ main.cpp -o app
