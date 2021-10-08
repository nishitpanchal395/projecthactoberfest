# -*- coding: utf-8 -*-
"""
Created on Fri Oct  8 13:27:12 2021

@author: DHIRAJ 
"""


import random
#importing random module to generate random values for game

user_action = input("Enter a choice (rock, paper, scissors): ") #user need to enter his/her choice


possible_actions = ["rock", "paper", "scissors"]

computer_action = random.choice(possible_actions) #the random.choice selects the possible actions from the possible_action list and stores in computer_action varriable 
print(f"\nYou choose {user_action}, computer choose {computer_action}.\n")

if user_action == computer_action:
    print(f"Both players selected {user_action}. It's a tie!")#if both computer and user action are same then its a tie

#the following code compares the two actions and gives user the result

elif user_action == "rock":
    if computer_action == "scissors":
        print("Rock smashes scissors! You win!")
    else:
        print("Paper covers rock! You lose.")
elif user_action == "paper":
    if computer_action == "rock":
        print("Paper covers rock! You win!")
    else:
        print("Scissors cuts paper! You lose.")
elif user_action == "scissors":
    if computer_action == "paper":
        print("Scissors cuts paper! You win!")
    else:
        print("Rock smashes scissors! You lose.")