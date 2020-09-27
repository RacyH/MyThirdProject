/*Racy Halterman
C++ Fall 2020
Due: September 28th
Lab 2 Introduction to C++ Programming
Write an interactive C++ program that computes and outputs the mean and population standard deviation of a set of
four integers. Use proper formatting and appropriate comments throughout.
*/

#include <iostream>
#include <cmath> // including the necessary libraries
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//mean = (sum of all)/how many were counted (these are just notes on the different equations)
//variance = (sum of (each individual number - mean)^2)/(how many were counted)
//standard deviation = sqrt of the variance


int main()
{
	int x, y, a, b;
	float c, d, e, f; // I made these floating number variables, because the reality of stats is that a lot of the numbers you get have decimal points
	string inputFileName = "inMeanStd.dat";
	string outputFileName = "outMeanStd.dat";
	ifstream inFile; //These two are here to allow you to access the files smoothly. ifstream allows reading from files, ofstream allows writing in files
	ofstream outFile;
	inFile.open(inputFileName);		// Places input file in the project folder
	outFile.open(outputFileName);	// Places output file in the project folder
	inFile >> x >> y >> a >> b;		// This pulls the variables from the input file
	int sum = x + y + a + b;		//Calculates the sum of numbers
	float mean = sum / 4.000;		//Calculates the average/mean of the numbers - The next line calculates the variances of the various numbers, then squares them.
	float xvar = (x - mean) * (x - mean), yvar = (y - mean) * (y - mean), avar = (a - mean) * (a - mean), bvar = (b - mean) * (b - mean);
	float Evar = xvar + yvar + avar + bvar; //This is just to calculate the sum of the variances squared.
	float stD = sqrt(Evar/4.000); //This, and the last two lines, are a different way of calculating the standard deviation without having any overload warnings.
	// I would like to note that I understand that there is a way to do this a little easier using cmath, but I wanted to do it this way just in case I had to switch between population or sample data.

	cout << "These are the numbers that are provided:\n" << x << " " << y << " " << a << " " << b << endl;
	cout << "This is the sum of the numbers provided:\n" << sum << endl; //This set of lines is just the outputs for the numbers in the inFile, and those calculated form them
	cout << "This is the average of the numbers provided:\n" << setprecision(6) << mean << endl;
	cout << "This is the standard deviation of the numbers provided:\n" << stD << "\n\n";
	cout << "Type four random numbers. Please put a space or press enter between your numbers.\n";

	cin >> c >> d >> e >> f; 
	outFile << c << " " << d << " " <<  e << " " << f; //This prints the numbers you entered into the outMeanStd.dat file
	cout << "The numbers you chose were:\n" << c << " " << d << " " << e << " " << f << endl;

	// These next lines are just defining things after you give the numbers, such as the sum, mean, variance, and so forth.
	float sum2 = c + d + e + f;		
	//Calculates the sum of the numbers the user entered
	//The reason these are here, is because in order for these things to work, you have to define things before you can use them in a code, and you just defined c, d, e, and f as numbers.
	float mean2 = sum2 / 4.000;		//Calculates the average/mean of the numbers the user entered
	float cvar = (c - mean2) * (c - mean2), dvar = (d - mean2) * (d - mean2), evar = (e - mean2) * (e - mean2), fvar = (f - mean2) * (f - mean2);
	float Evar2 = cvar + dvar + evar + fvar;
	float stD2 = sqrt(Evar2 / 4.000); //Again, just a way to calculate the standard deviation equation without causing warnings to appear

	cout << "The sum of the numbers you have entered is:\n" << sum2 << endl;
	cout << "The mean of the numbers you have entered is:\n" << setprecision(6) << mean2 << endl;
	cout << "The standard deviation of the numbers you entered is:\n" << setprecision(6) << stD2 << endl;

	inFile.close();
	outFile.close();

	return 0;
}

