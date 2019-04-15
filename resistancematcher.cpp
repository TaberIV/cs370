//resistance matcher

#include <iostream>

using namespace std;

int main() {

	//assign target, tolerance, num_resistors, input_file

	target = argv[1];
	tolerance = argv[2];
	num_resistors = argv[3];
	input_file = argv[4];

	//open and read input_file into array, called resistor_values
	//file may have errors, need to do error checking
	//decltype *variable* yields type in c++? check if == double || == int


	//read line by line


	//fopen

	//loop for reading

		//if (decltype x != int || decltype x != double) ?
		//throw error

		//else continue

	//fclose


	resistor_values = [];



	//compute resistance range

	correct_range = target * (tolerance / 100);


	//compute solution

	//while loop to search for solution, since multiples are allowed
		//int s = sizeof(resistor_values);
		//for (int i = 0; i < s; i++)

	//condition for while loop, 0 = searching, 1 = done?
	int done = 0;
	solution = [];

	while(done != 1) {

		//if a resistance is smaller than the target, we never want it
		

	}


	//formatting/output

	cout << "Max resistors in parallel: " << num_resistors << endl;
	cout << "Tolerance: " << tolerance << " %" << endl;

	//if solution found {
	//replace array_of_solutions, result, percent error as necessary

	cout << "Target resistance of " << target << " ohms is possible with " << "array_of_solution" << " ohm resistors." << endl;
	cout << "Best fit: " << "result" << endl;
	cout << "Percent error: " << "percent error" << " %" << endl; 

	//} else {
	cout << "Target resistance of " << target << " ohms is not possible." << endl;

	//}

	return 0;
}