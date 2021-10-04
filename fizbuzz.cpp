#include<iostream>

using namespace std;

/**
 * Write a program that outputs the string representation of numbers from 1 to n. 
 * But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. 
 * For numbers which are multiples of both three and five output “Fizz Buzz”
 * Example:
 * n = 15 
 * Return:
[
  “1",
  “2”,
  “Fizz”,
  “4”,
  “Buzz”,
  “Fizz”,
  “7",
  “8”,
  “Fizz”,
  “Buzz”,
  “11",
  “Fizz”,
  “13",
  “14”,
  “Fizz Buzz”
]
 */

void solveFizzBuzz(int n) {
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            cout << "Fizz Buzz" << endl;
        } else if (i % 3 == 0) {
            cout << "Fizz" << endl;
        } else if (i % 5 == 0) {
            cout << "Buzz" << endl;
        } else {
            cout << i << endl;
        }
    }
}

int main() {

    int n = 15;

    solveFizzBuzz(n);

    return 0;
}
