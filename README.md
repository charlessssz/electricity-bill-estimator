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
```bash
g++ main.cpp -o app
