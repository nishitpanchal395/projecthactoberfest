# This function adds two numbers
def add(x, y):
    return x + y

# This function subtracts two numbers
def subtract(x, y):
    return x - y

# This function multiplies two numbers
def multiply(x, y):
    return x * y

# This function divides two numbers
def divide(x, y):
    return x / y

while True:
    # take input from the user
    num1 = float(input("Enter first number: "))
    choice = input("Enter the operation (+,-,*,/): ")

    # check if choice is valid
    if choice in ('+', '-', '*', '/'):
        #take second number
        num2 = float(input("Enter second number: "))

        #call function
        if choice == '+':
            print(num1, "+", num2, "=", add(num1, num2))

        elif choice == '-':
            print(num1, "-", num2, "=", subtract(num1, num2))

        elif choice == '*':
            print(num1, "*", num2, "=", multiply(num1, num2))

        elif choice == '/':
            print(num1, "/", num2, "=", divide(num1, num2))
        
    
    else:
        print("Invalid Input")
      
     # check if user wants another calculation
     # break the while loop if answer is no
     next_calculation = input("Do you want to continue? (yes/no): ")
     if next_calculation == "no":
        break
