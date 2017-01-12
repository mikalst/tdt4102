#include <iomanip>
#include <iostream>


void inputAndPrintInteger () {
	std::cout << "Skriv inn et heltall: " << std::endl;
	int n = 0;
	std::cin >> n;
	std::cout << n << std::endl;
}

int inputInteger () {
	std::cout << "Skriv inn et heltall: " ;
	int n = 0;
	std::cin >> n;
	return n;
}

double inputDouble () {
	std::cout << "Skriv inn en double: " ;
	double n = 0;
	std::cin >> n;
	return n;
}

int inputAndPrintIntegersAndPrintSum (int start = 0, bool terminate = false) {
	// Bruker inputInteger fordi denne returnerer en verdi
	if (terminate) {
		std::cout << "Summen av tallene: " <<  start << std::endl;
		return 0;
	}
	else {
		start += inputInteger();
		return start;
	}
}

bool isOdd (int n) {
	if (n%2 == 0) {
		return false;
	}
	else {
		return true;
	}
}

void printHumanReadableTime (int n) {
	int hourOfDay = n/3600;
	n -= hourOfDay*3600;
	int minuteOfHour = n/60;
	n -= minuteOfHour*60;
	std::cout << hourOfDay << " timer, " << minuteOfHour << " minutter og " << n << " sekunder" << std::endl;
}

void inputIntegersUsingLoopAndPrintSum (bool onlyTwo = false) {
	int numberArguments = 0;
	if (onlyTwo) {
		numberArguments = 2;
	}
	else { 
		std::cout << "Hvor mange tall vil du putte inn: " ;
		std::cin >> numberArguments;
	}
	int mySum = 0;
	while (numberArguments > 0) {
		mySum = inputAndPrintIntegersAndPrintSum(mySum);
		numberArguments -= 1;
	}
	inputAndPrintIntegersAndPrintSum(mySum,true);
	/* Typisk vil nok en for løkke være hensiktsmessig hvis bruker oppgir antall tall ved begynnelsen av løkken, og en while-løkke vil være hensiktsmessig ved et ukjent antall tall som skal inn. Her har jeg allikevel brukt en while-løkke. */
}
	
double convertKrEuro () {
	double euro = -1.0; 
	while (euro < 0.0) {
		euro = 9.64*inputDouble();
	}
	std::cout << "i euro: " << std::setprecision(2) << std::fixed << euro << std::endl ; 
	return euro;
	/* Vi bør bruke inputDouble fordi ved bruk av inputInteger vil vi få ValueError. Fordi vi i denne oppgaven ganger sammen to doubles må funksjonen også returnere en double. */
}

int main () {
/*	inputAndPrintInteger();
	int number = inputInteger();
	std::cout << number << std::endl;
	inputAndPrintIntegersAndPrintSum ();
	for
		(
		 int
		 i = 10; i < 15; i++) {
			if
				(isOdd(i)) {
					std::cout << i << " er et oddetall." << std::endl;
				}
			else
			{
				std::cout << i << " er et partall." << std::endl;
			}
		}
	printHumanReadableTime (10000);
	convertKrEuro ();*/
	
	// Start of menu
	std::cout << "Velkommen til Mikal sitt program, her er menyen: \n" ;
	while (true) {
		std::cout  << " 0) Avslutt \n" << " 1) Summer to tall \n" << " 2) Summer flere tall \n" << " 3) Konverter NOK til EURO \n" ;
		int n = 0;
		std::cin >> n;
		switch (n) {
			case 0 : std::cout << "Ha det bra!" << std::endl;
				 break;
			case 1 : inputIntegersUsingLoopAndPrintSum(true);
				 break;
			case 2 : inputIntegersUsingLoopAndPrintSum();
				 break;
			case 3 : convertKrEuro();
				 break;
		}
		std::cout << std::endl;;
	}
}
