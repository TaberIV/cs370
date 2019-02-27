//scrambles_squares_solver

#include <iostream>

using namespace std;

char solved[4][3] = {"Y0", "Y1", "Y2", "Y3"};
char solved2[4][3] = {"R0", "R1", "R2", "R3"};

const char* hb = "+--------+--------+--------+\n";
const char* p = "|";
const char* tilenum = "1";
const char* dub = "  ";
const char* trip = "   ";

void horizontal_bound_print() {

	cout << hb;

}

int main(int argc, const char *argv[]) {

	for (int i = 0; i < 3; i++) {

		horizontal_bound_print();

		for (int j = 0; j < 3; j++) {

			int next = 0;

			if (j == 0) {

				for (int k = 0; k < 3; k++) {

					cout << p << tilenum << dub << solved[next][j] << "_" << trip;
					next++;
					tilenum++;

				}
				
				cout << p << endl;

			} else if (j == 1) {

				for (int k = 0; k < 3; k++) {

					cout << p << solved[next][j] << "_" << dub << dub << solved[next][j+1] << "_" << "_";
					next++;

				}
				
				cout << p << endl;

			} else {

				for (int k = 0; k < 3; k++) {

					cout << p << trip << solved[next][j+1] << "_" << trip;
					next++;

				}
				
				cout << p << endl;

			}

		}

	}

    horizontal_bound_print();

}