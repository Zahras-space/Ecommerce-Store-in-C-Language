# Ecommerce-Store-in-C-Language

This project implements a real-time, Ecommerce Store application written in C. It caters to both users and administrators, providing functionalities just like a modern e-commerce website.

Features:

User Side:
User registration and login.
Browsing product categories (pants, shoes, shirts, and potentially more).
Viewing detailed information about individual products.
Real-time inventory updates reflecting purchase quantities.
Out-of-stock notifications when a product is unavailable.
"Back" option for navigating through the user interface.
Secure storage of user details and login credentials in files.

Admin Side:
Admin registration and login.
Ability to add new product categories.
Creation of new products within existing categories.
Management of product details (name, description, price, stock quantity).
Real-time inventory updates based on user purchases.
Secure storage of admin login credentials and store data in files.

Project Structure:
The project likely consists of C source file (.c) that organize the code for different modules:

User Management: Handles user registration, login, and data storage.
Product Management: Facilitates admin product creation, category management, and inventory control.
Inventory Management: Tracks product quantities, updates in real time, and displays out-of-stock messages.
File I/O: Handles data persistence by reading from and writing to files.
