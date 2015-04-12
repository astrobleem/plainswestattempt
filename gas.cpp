#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <stdio.h>
#include <fstream>

using namespace std;

int main(int argv, char *argc[])
{
	ifstream infile;
	ofstream outfile;

	const int NUM_STATIONS = 250;

	int gasStationMileMarkers[NUM_STATIONS];
	float gasStationPrices[NUM_STATIONS];

	outfile.open("gas.out");
	infile.open(argc[1]);

	int numGasStation = 0;
	int milemarker = 0;
	float price = 0.0f;
	float totalPrice = 0.0f;
	string buf = "";
	int milesdriven = 0;
	int currentmilemarker = 0;
	float lastPrice = 999.99f;
	int tank = 0;
	int element = 0;

	while (!infile.eof())
	{
		// Number of the gas stations on the trip.
		numGasStation = 0;
		currentmilemarker = 0;

		// For one trip.
		infile >> numGasStation;
		if (numGasStation == 0)
			break;


		float lowestPrice = 999.99f;
		int lastMileMarker = 0;
		int tank = 0;

		// Fill the array for one trip.
		for (int b = 0; b < numGasStation; b++)
		{
			infile >> gasStationMileMarkers[b] >> gasStationPrices[b];
		}

		// Filling up.
		while (currentmilemarker < gasStationMileMarkers[numGasStation - 1]){
			tank = 200;
			for (int i = 0; i < numGasStation; i++){
				if ((gasStationMileMarkers[i] > currentmilemarker) && gasStationMileMarkers[i] < (currentmilemarker + 200)){
					if (gasStationPrices[i] < lowestPrice){
						lowestPrice = gasStationPrices[i];
						element = i;
						lastMileMarker = gasStationMileMarkers[i];
					}
				}
			}
			//currentmilemarker += lastMileMarker;
			if (element == 0) 
				totalPrice = (lowestPrice / 100) * (currentmilemarker - gasStationMileMarkers[element - 1]);
			else 
				//totalPrice
				totalPrice = (lowestPrice / 100) *	gasStationMileMarkers[element];
			currentmilemarker += lastMileMarker;
			//totalPrice += (lowestPrice / 100) * lastMileMarker;
			
			//totalPrice += (lowestPrice / 100) * currentmilemarker;

			tank -= lastMileMarker;
			cout << "Current Mile Marker: " << gasStationMileMarkers[element] << endl; //
			cout << "Lowest Price: " << lowestPrice << endl;
			cout << "Total  Price: " << totalPrice << endl << endl;
			lowestPrice = 999.99f;
			lastMileMarker = 0;
		}


















		// Calculate for the one trip.

		// Module 1
		/*int lastMileMarker = 0;*/

		// For one trip.
		//while (currentmilemarker < gasStationMileMarkers[numGasStation - 1])
		//{
		//	tank = 200;
		//	// One fill up.

		//		for (int i = 0; i < numGasStation; i++)
		//		{
		//			if (((currentmilemarker + gasStationMileMarkers[i]) <= currentmilemarker + tank)){
		//				if (gasStationPrices[i] < lastPrice){
		//					lastPrice = gasStationPrices[i];
		//					lastMileMarker = gasStationMileMarkers[i];
		//				}
		//			}
		//		}
		//		tank = tank - lastMileMarker;
		//		totalPrice += (lastPrice / 100) * (lastMileMarker - currentmilemarker);
		//		currentmilemarker = lastMileMarker;
		//	}
		//	lastPrice = 999.99f;
		//}
		system("pause");
	}
}