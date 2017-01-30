#include <iomanip>
#include <iostream>
#include <math.h>	/* sqrt */

void inputAndPrintInteger () {
	std::cout << "Skriv inn et heltall: "; 
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

void gangetabell() {
	int width;
	std::cout << "Bredde: " << std::endl;
	std::cin >> width;
	int height;
	std::cout << "Høyde: " << std::endl;
	std::cin >> height;
	for (int y = 1; y<height+1; y++) {
		for (int x = 1; x<width+1; x++) {
			std::cout << std::setprecision(3) << " " << x*y << " " ;
		}
		std::cout << std::endl;
	}
}

double discriminant (double a, double b, double c) {
	return (b*b - 4*a*c);
}

void printRealRoots (double a, double b, double c) {
	double numberOfRoots = discriminant(a,b,c);
	if(numberOfRoots>0) {
		double root1 = -b/(2*a) + sqrt(numberOfRoots)/(2*a);
		double root2 = -b/(2*a) - sqrt(numberOfRoots)/(2*a);
		std::cout << "x_1: " << root1 << "\n" << "x_2: " << root2 << std::endl;
	}
	else if(numberOfRoots==0) {
		double root1 = -b/(2*a); 
		std::cout << "x_1: " << root1 << std::endl;
	}
	else {
		std::cout << "No roots" << std::endl;
	}
}

int solveQuadraticEquation(){
	std::cout << "Velkommen til Mikals abc-formel" << std::endl;
	double a = inputDouble();
	double b = inputDouble();
	double c = inputDouble();
	printRealRoots(a,b,c);
	return 0;
}

void calculateLoanPayments() {
	double totalLoan;
	double interestRate;
	std::cout << "størrelse på lån: ";
	std::cin >> totalLoan;
	std::cout << "rentesats: ";
	std::cin >> interestRate;
	double remainingLoan=totalLoan;
	for (int x=1; x<10; x++) {
		double payment = totalLoan/(10) + interestRate/100 * remainingLoan;
		if (payment > remainingLoan) {
			payment = remainingLoan;
		}
		else {
			remainingLoan -= payment;
		}
		std::cout << "År " << x << ": " << std::setprecision(2) << std::fixed << payment << std::endl;
	}
}

int main () {
/*	inputAndPrintInteger();
	int number = inputInteger();
	std::cout << number << std::endl;
	inputAndPrintIntegersAndPrintSum ();
	for (i = 10; i < 15; i++) {
		if(isOdd(i)) {
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

}
