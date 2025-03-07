# orientation-week3-plot

![GitHub repo size](https://img.shields.io/github/repo-size/ysnanako/orientation-week3-plot)
![GitHub last commit](https://img.shields.io/github/last-commit/ysnanako/orientation-week3-plot)

This project is part of the **National Cheng Kung University (NCKU) - Smart Electronic Design Automation Laboratory (SEDA)** summer training program, focusing on **YAL format parsing and MATLAB visualization**.

## 📖 Table of Contents

- [Project Overview](#project-overview)
- [Input Format](#input-format)
- [Output Format](#output-format)
- [Project Structure](#project-structure)
- [YAL Parsing & Plotting Flow](#yal-parsing--plotting-flow)
- [Example Execution](#example-execution)
- [Generated Plots](#generated-plots)
- [Contribution Guide](#contribution-guide)
- [Contact Information](#contact-information)

## 📝 Project Overview

This project parses **YAL format circuit placement files**, extracts **module positions and dimensions**, and generates **MATLAB scripts for visualization**.

### **Key Features:**
- **Parses `.yal` files to extract module information.**
- **Reads `.out` files for placement coordinates.**
- **Generates a `.m` MATLAB script for visualization.**
- **Plots circuit layout with labeled modules.**

## 📄 Input Format

The program requires the following input files:
- **`.yal`** - Defines circuit modules and dimensions.
- **`.out`** - Contains placement results (x, y, rotation).

📄 **Example `.yal` File**
```
MODULE M1 DIMENSIONS 100 200
MODULE M2 DIMENSIONS 150 100
...
```

📄 **Example `.out` File**
```
M1 50 60 0
M2 200 100 1
...
```

## 📄 Output Format

The program generates a MATLAB script:
- **`yal_parser.m`** - Plots circuit placement results.

📄 **Example `yal_parser.m`**
```matlab
axis equal;
hold on;
grid on;
fill([50 50 150 150 50], [60 260 260 60 60], 'c');
text(100, 160, 'M1');
...
```

## 🧰 Project Structure

```
📂 orientation-week3-plot/
│── 📂 src/ *(C++ source files for YAL parsing)*  
│   ├── main.cpp  
│   ├── yal_parser.cpp  
│   ├── yal_parser.h  
│── 📄 ami49.yal # (ignored)   
│── 📄 ami49_1_10.out # (ignored)  
│── 📄 yal_parser.m # (ignored)
│── 🖥️ yal_parser # (ignored)
│── 🔧 Makefile  
│── 📜 README.md # This file  
│── 📜 .gitignore  
```

## 🔹 **YAL Parsing & Plotting Flow**

### **1. Read YAL and OUT Files**
- Extracts **module names, dimensions, and positions**.

### **2. Parse Placement Results**
- Reads `.out` file and applies **rotation transformations**.

### **3. Generate MATLAB Script**
- Constructs MATLAB `fill()` and `text()` commands for visualization.

## ⚡ **Example Execution**

```bash
make
./yal_parser ami49.yal ami49_1_10.out yal_parser.m
```

## 🖼️ Generated Plots
Below are the generated plots from the `matlab` output: 

**ami49**  
![yal](https://github.com/user-attachments/assets/a3edfbdc-ee0f-41cc-b36a-4583cee6b218)  

## 🤝 Contribution Guide

1. Fork this repository.
2. Create a new branch (`git checkout -b feature-xyz`).
3. Commit your changes (`git commit -m 'Add new feature'`).
4. Push to the remote branch (`git push origin feature-xyz`).
5. Submit a Pull Request.

## 📬 Contact Information

- 📧 Email: [m16131056@gs.ncku.edu.tw](mailto:m16131056@gs.ncku.edu.tw)
- 🌎 University: [National Cheng Kung University (NCKU)](https://www.ncku.edu.tw)
- 📖 Course: Summer Training Program - YAL Visualization
