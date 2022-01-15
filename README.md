# Coin-Exchange

Contents
---------------------
* File Contents
* Introduction
* Algorithm
* Requirements

## File Contents
	
	Coin_Exchange.cpp  (program file containing code)

## Introduction
Book practice project from Problem Solving With C++ Chapter 5. Project 4.
This program gives the exact amount of coins necessary for a certain value of change. Demonstrates ability to use multiple functions and math in c++.
Written using Microsoft Visual Studio. 

## Algorithm

		1. receive input of change left
			1a. value should be an int less than 100;
		2. calculate the number of coins to return
			2a. if change > 25, get the number of quarters and return the remainder to change
			2b. if change > 10, get the number of dimes and return remainder of change
			2c. if change > 0, get the number of pennies and return remainder of change (should be zero)
		3. output the number of coins to return
		4. prompt user to continue

## Requirements
No requirements or modules needed for running this program.
