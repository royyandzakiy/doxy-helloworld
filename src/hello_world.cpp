/**
 * @file hello_world.cpp
 * @brief Implementation of the hello world function
 */

 #include "hello_world.h"
 #include <iostream>
 
 void print_hello_world() {
     std::cout << "Hello, World!" << std::endl;
 }
 
 /**
  * @brief Main function
  * 
  * Entry point of the application.
  * @return Exit code
  */
 int main() {
     print_hello_world();
     return 0;
 }