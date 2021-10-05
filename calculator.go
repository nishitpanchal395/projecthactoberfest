package main

import "fmt"

func main() {
	var val1, val2, output int64
	var operator string
	fmt.Print("Enter your first number: ")
	fmt.Scanln(&val1)
	fmt.Print("Enter your second number: ")
	fmt.Scanln(&val2)
	fmt.Println("Choose any operator (+,-,*,/,%): ")
	fmt.Scanln(&operator)
	switch operator {
	case "+":
		output = val1 + val2
	case "-":
		output = val1 - val2
	case "*":
		output = val1 * val2
	case "/":
		output = val1 / val2
	case "%":
		output = val1 % val2
	default:
		fmt.Println("Invalid input")
	}
	fmt.Printf("%d %s %d = %d", val1, operator, val2, output)
}
