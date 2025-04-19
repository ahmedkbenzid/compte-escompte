# compte-escompte 

This C++ project simulates a financial tool for calculating the **discounting of commercial effects** (bills of exchange) in banking environments. It allows banks or financial analysts to compute various metrics related to the escompte (discount) process.

##  Features

- Supports multiple effects with per-effect calculations.
- Automatically handles leap years and accurate date differences.
- Calculates:
  - Agios (discount interest)
  - Endorsement commissions
  - Fixed commissions based on location/bank
  - TVA (18%)
  - Net discounted value
- Clear and formatted output in a tabular format.

##  Inputs

- Bank and location of discounting
- Discount rate and endorsement commission
- Number of bank days
- Fixed commission values (domiciled and non-domiciled)
- Dates in `jj/mm/aaaa` format
- Details per effect (value, due date, bank, location)

##  Compilation

Make sure to compile with C++20 to use modern features like `std::chrono` and `std::vector`:

```bash
g++ -std=c++20 -o compte-escompte main.cpp
./compte-escompte
