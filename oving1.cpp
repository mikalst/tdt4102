#include <iostream>
#include <cmath>

int max(int a, int b) {
	if (a > b) {
		std::cout << "A is greater than B" << std::endl;
		return a;
	}
	else {
		std::cout << "B is greater than or equal A" << std::endl;
		return b;
	}
}

int fibonacci(int n) {
	int a = 0;
	int b = 1;
	std::cout << "Fibonacci numbers:" << std::endl;
	for(int x = 1; x < n+1; x++) {
		std::cout << x << " "  << b << std::endl;
		int temp = b;
		b += a;
		a = temp;
	}
	std::cout << "----" << std::endl;
	return b;
}

int squareNumberSum(int n) {
	int totalSum = 0;
	for(int i=0;i<n;i++) {
		totalSum += i*i;
		std::cout << i*i << std::endl;
	}
	std::cout << totalSum << std::endl;
	return totalSum;
}

int triangleNumbersBelow(int n) {
	int acc = 1;
	int num = 2;
	std::cout << "Triangle numbers below " << n << ":" << std::endl;
	while (acc < n) {
		std::cout << acc << std::endl;
		acc += num;
		num += 1;
	}
	std::cout << std::endl;
	return 0;
}

bool isTriangleNumber(int number){
	int acc = 1;
	while (number > 0) {
		number -= acc;
		acc +=1;
	}
	return number == 0;
}
	
bool isPrime(int n) {
	bool primeness = true;
	for (int j=2;j<n;j++) {
		if (n%j == 0) {
			primeness = false;
			break;
		}
	}
	return primeness;
}

int naivePrimeNumberSearch (int n) {
	for (int x=2;x<n;x++){
		if (isPrime(x)) {
			std::cout << x << " is a prime" << std::endl;
		}
	}
	return 0;
}

int findGreatestDivisor(int n){
	for (int x=n-1;x>0;x--){
		if (n%x == 0){
			return x;
		}
	}
	return 0;
}

int main() {
	std::cout << "Oppgave a)" << std::endl;
	std::cout << max(5,6) << std::endl;
	std::cout << std::endl << "Oppgave c)" << std::endl;
	std::cout << fibonacci(7) << std::endl;
	std::cout << std::endl << "Oppgave d)" << std::endl;
	squareNumberSum(6); 
	std::cout << std::endl << "Oppgave e)" << std::endl;
	triangleNumbersBelow (100);
	std::cout << isTriangleNumber(91)<< std::endl;
	std::cout << std::endl << "Oppgave f)" << std::endl;
	std::cout << isPrime(11)<< std::endl;
	std::cout << std::endl << "Oppgave g)" << std::endl;
	naivePrimeNumberSearch(40);
	std::cout << std::endl << "Oppgave h)" << std::endl;
	std::cout << findGreatestDivisor(99);
}


