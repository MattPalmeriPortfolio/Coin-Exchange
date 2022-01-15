#include <iostream>
//declare constants
const int QUARTER = 25, DIME = 10, PENNY = 1;
//declare functions
void coinInput(int& change);
//receives input for the value of change left over after a sale. will prompt user to retry if change >= 100
//as they should then give a full dollar to the customer.
void computeCoins(int coinValue, int& num, int& amountLeft);
//precondition: coinValue corresponds to the value of a coin; amountLeft is greater than the coinValue before call;
//postcondition: adds (amountLeft / coinValue) to num, and leaves amountLeft with the value of change less than coinValue
void coinOutput(int quarters, int dimes, int pennies);
//precondition: a number of quarters, dimes, and pennies are stored in three variables and represent an amount of change
//postcondition: outputs the number of quarters, dimes, and pennies that should be returned to the customer.
bool promptContinue();
//precondition: placed in the controlling expression of a while or do-while loop;
//postcondition: based on user input, either continues or ends the loop.
//main
int main()
{
	using namespace std;
	//initialize variables
	int numQuarters = 0, numDimes = 0, numPennies = 0;
	//greet user
	cout << "This program will determine the amount of coins you need based on the change value input.\n";
	do //loop while user wants to continue using program
	{
		int change = 0;
		//get input
		coinInput(change);
		//calculate
		if (change >= 25) //if quarters can be used
			computeCoins(QUARTER, numQuarters, change);
		if (change >= 10) //if dimes can be used
			computeCoins(DIME, numDimes, change);
		if (change > 0) //if pennies can be used
			computeCoins(PENNY, numPennies, change);
		//output
		coinOutput(numQuarters, numDimes, numPennies);
		numQuarters = 0, numDimes = 0, numPennies = 0;
	} while (promptContinue());
	cout << "Goodbye!\n";
	return 0;
}

//define functions
//uses iostream
void coinInput(int& change)
{
	using namespace std;
	bool postcondition = false;
	do
	{
		cout << "Enter the amount of change you need converted to coins, as a whole number\n";
		cin >> change;
		if (change >= 100) //if change is greater than a dollar amount
			cout << "Your change is above 100, give the customer a dollar bill and try again!\n";
		else
			postcondition = true;
	} while (postcondition == false);
	return;
}
//uses iostream
void coinOutput(int quarters, int dimes, int pennies)
{
	using namespace std;
	cout << "You should give the customer " << quarters << " quarters, " << dimes << " dimes, and " << pennies
		<< " pennies.\n";
	return;
}
void computeCoins(int coinValue, int& num, int& amountLeft)
{
	num = amountLeft / coinValue;
	amountLeft %= coinValue;
	return;
}
//uses iostream
bool promptContinue()
{
	using namespace std;
	char prompt;
	cout << "Would you like to continue? Y to continue, N to end\n";
	cin >> prompt;
	if (prompt == 'Y' || prompt == 'y')
		return true;
	else
		return false;
}