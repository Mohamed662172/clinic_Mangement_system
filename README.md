# Clinic Management System

A comprehensive **Clinic Management System** developed in **C**, designed to streamline patient record management and appointment scheduling. This project demonstrates the use of **Linked Lists**, **Custom Data Types**, and **Modular Programming** in C.

---

## 🏥 Project Overview

The system provides two primary modes of operation: **Admin Mode** and **User Mode**. It allows for efficient handling of patient data, including registration, editing, and reservation of time slots with doctors.

### 🔑 Key Features

#### **Admin Mode**
- **Add New Patient:** Register a new patient with details like Name, Age, Gender, and a unique ID.
- **Edit Patient Record:** Update existing patient information.
- **Reserve Slot:** Book an available time slot with a doctor for a specific patient.
- **Cancel Reservation:** Remove a previously booked appointment.

#### **User Mode**
- **View Patient Record:** Search and display patient details using their ID.
- **View Today's Reservations:** List all appointments scheduled for the current day.

---

## 🏗️ Project Structure

The project is organized into several modules to ensure maintainability and clarity. Below is a high-level overview of the system's architecture:

![Project Structure](https://private-us-east-1.manuscdn.com/sessionFile/6d6PodzvRjfNhM4gyqPamI/sandbox/3CGMJBn6gBAk0LaFZNo9A6-images_1771587868851_na1fn_L2hvbWUvdWJ1bnR1L2NsaW5pY19NYW5nZW1lbnRfc3lzdGVtL3N0cnVjdHVyZQ.png?Policy=eyJTdGF0ZW1lbnQiOlt7IlJlc291cmNlIjoiaHR0cHM6Ly9wcml2YXRlLXVzLWVhc3QtMS5tYW51c2Nkbi5jb20vc2Vzc2lvbkZpbGUvNmQ2UG9kenZSamZOaE00Z3lxUGFtSS9zYW5kYm94LzNDR01KQm42Z0JBazBMYUZaTm85QTYtaW1hZ2VzXzE3NzE1ODc4Njg4NTFfbmExZm5fTDJodmJXVXZkV0oxYm5SMUwyTnNhVzVwWTE5TllXNW5aVzFsYm5SZmMzbHpkR1Z0TDNOMGNuVmpkSFZ5WlEucG5nIiwiQ29uZGl0aW9uIjp7IkRhdGVMZXNzVGhhbiI6eyJBV1M6RXBvY2hUaW1lIjoxNzk4NzYxNjAwfX19XX0_&Key-Pair-Id=K2HSFNDJXOU9YS&Signature=QZ12Oh~NgLvGQZYPNAezasMeCsv-NtsP0fLRaRhQbjiwcvOuoVJKo0J8Zhxs1n-3mGAYotCwfkM54ZP7n7tyx9uIwv2ThMwKqRDn7TSjZtJwcWkVSK3-pm~~jRyZ367YXeJu~qf46seAQwtWl5sQrJFHETey0NozPvPHJHd~hfn-xHrA5TRWTn7GPT3RfAFGb-b7-VEBJXlJK91opIYCgjxyT7HI3KXg8u7RNLqMLyYPIWRn2EsZveQfsmxNdO28mYi~LJT9FxF1NLbbK5-Mfuodq~MX3jBo6xTnp0lXwqBeLTmayF9u36Br6HBvpaycwDxyvpCnG21ma4OXHKVUBQ__)

### 📂 File Descriptions

| File | Description |
| :--- | :--- |
| `Sys.c` | The main entry point of the application, handling the main loop and mode selection. |
| `admin_mode.c` / `.h` | Contains logic for administrative tasks like adding/editing patients and managing slots. |
| `user_mode.c` / `.h` | Implements features accessible to general users, such as viewing records. |
| `login.c` / `.h` | Handles authentication for the Admin mode. |
| `Std_Types.h` | Defines standard data types (e.g., `u8`, `u32`, `u64`) for cross-platform compatibility. |
| `Bit_Math.h` | Provides macros for bitwise operations (Set, Clear, Toggle, Get). |

---

## 💻 Technical Implementation

- **Data Structure:** The system utilizes a **Singly Linked List** to store patient records dynamically, allowing for efficient insertion and deletion.
- **Memory Management:** Uses dynamic memory allocation (`malloc`) to manage patient nodes.
- **Modular Design:** Each functional area is separated into its own `.c` and `.h` files, promoting clean code practices.

---

## 🚀 How to Run

1. **Clone the repository:**
   ```bash
   git clone https://github.com/Mohamed662172/clinic_Mangement_system.git
   ```
2. **Navigate to the project directory:**
   ```bash
   cd clinic_Mangement_system/clinic_Mangement_system
   ```
3. **Compile the source files:**
   ```bash
   gcc Sys.c admin_mode.c user_mode.c login.c -o clinic_system
   ```
4. **Execute the program:**
   ```bash
   ./clinic_system
   ```

---

## 🛠️ Requirements
- A C compiler (e.g., GCC, Clang, or MSVC).
- Standard C libraries.

---

## 👤 Author
**Mohamed**
- GitHub: [@Mohamed662172](https://github.com/Mohamed662172)
