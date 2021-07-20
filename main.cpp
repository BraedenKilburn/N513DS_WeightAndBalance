/********************************
 * Author: Braeden Kilburn
 * Date Created: 12 May 2020
 * Description: Calculates the weight
 * and balance for N513DS, a 
 * Diamond DA-40. 
 *******************************/
#include <iostream>
#include <iomanip>
using namespace std;

// Global Constants
const double EMPTY_WEIGHT = 1730.0;
const double EMPTY_WEIGHT_ARM = 96.86;
const double PILOT_ARM = 90.6;
const double REAR_PASSENGER_ARM = 128;
const double BAGGAGE_ARM = 143.7;
const double FUEL_ARM = 103.5;
const double FUEL_WEIGHT_PER_GALLON = 6.01;
const double MAX_GROSS_WEIGHT = 2535;

// Function Prototypes
void welcomeUser();
void inputWeight(double&, string, string);
double calculateMoment(double);

int main()
{
    // Print home screen
    welcomeUser();
    
    // Weight of everything
    double pilotWeight, coPilotWeight, rearPassengerOneWeight, rearPassengerTwoWeight,
           baggageWeight, noFuelWeight, fuelWeight, rampTotalWeight;
    double gallonsOfFuel;
    double centerOfGravity;
    
    // Moment of everything
    double emptyMoment, pilotMoment, coPilotMoment, rearPassengerOneMoment, rearPassengerTwoMoment,
           baggageMoment, noFuelMoment, fuelMoment, rampTotalMoment;
    
    // Prompt user for weights (lbs)
    inputWeight(pilotWeight, "Enter Pilot Weight (lbs): ", "Weight");
    inputWeight(coPilotWeight, "Enter Co-pilot Weight (lbs): ", "Weight");
    inputWeight(rearPassengerOneWeight, "Enter Rear Passenger #1 Weight (lbs): ", "Weight");
    inputWeight(rearPassengerTwoWeight, "Enter Rear Passenger #2 Weight (lbs): ", "Weight");
    inputWeight(baggageWeight, "Enter Baggage Weight (lbs): ", "Weight");
    inputWeight(gallonsOfFuel, "Enter Amount of Fuel (gallons): ", "Amount");
    
    // Convert gallons of fuel to lbs
    fuelWeight = gallonsOfFuel * FUEL_WEIGHT_PER_GALLON;
    
    // Calculate the individual Moments (in*lbs)
    emptyMoment = EMPTY_WEIGHT * EMPTY_WEIGHT_ARM;
    pilotMoment = pilotWeight * PILOT_ARM;
    coPilotMoment = coPilotWeight * PILOT_ARM;
    rearPassengerOneMoment = rearPassengerOneWeight * REAR_PASSENGER_ARM;
    rearPassengerTwoMoment = rearPassengerTwoWeight * REAR_PASSENGER_ARM;
    baggageMoment = baggageWeight * BAGGAGE_ARM;
    fuelMoment = fuelWeight * FUEL_ARM;
    
    // Calculate total weights
    noFuelWeight = EMPTY_WEIGHT + pilotWeight + coPilotWeight + rearPassengerOneWeight + rearPassengerTwoWeight + baggageWeight;
    rampTotalWeight = noFuelWeight + fuelWeight;
    
    // Calculate total moments
    noFuelMoment = emptyMoment + pilotMoment + coPilotMoment + rearPassengerOneMoment + rearPassengerTwoMoment + baggageMoment;
    rampTotalMoment = noFuelMoment + fuelMoment;
    
    // Calculate Center of Gravity (Inches aft of Datum)
    centerOfGravity = rampTotalMoment / rampTotalWeight;
    
    // Warn user that they exceed the max gross weight
    if (noFuelWeight >= MAX_GROSS_WEIGHT)
    {
        cout << "\nWARNING!!!\nYour current total weight w/o fuel exceeds the maximum gross weight!" << endl;
        cout << "You're currently " << noFuelWeight - MAX_GROSS_WEIGHT << "lbs overweight!" << endl;
        cout << "Please lighten your load before you go flying!" << endl;
    }
    else if (rampTotalWeight >= MAX_GROSS_WEIGHT)
    {
        cout << "WARNING!!!\nYour current total ramp weight exceeds the maximum gross weight!" << endl;
        cout << "You're currently " << rampTotalWeight - MAX_GROSS_WEIGHT << "lbs overweight!" << endl;
        cout << "Please get rid of some fuel or lighten your load before you go flying!" << endl;
    }
    
    // Output Weight & Balance Worksheet
    cout << fixed << setprecision(2) << right << endl;
    cout << "+" << setfill('-') << setw(61) << "" << "+" << endl;
    cout << "|" << setfill(' ') << setw(19) << "|" << setw(14) << " Weight (lbs) " << "X" << setw(10) << " Arm (in) " << "=" << right << setw(16) << " Moment (in*lbs)" << "|" << endl;
    cout << "|" << setfill('-') << setw(18) << "" << "+" << setw(43) << right << "|" << left << endl;
    
    cout << setfill(' ') << setw(19) << "|Empty Weight" << "|" << right << setw(13) << EMPTY_WEIGHT << " X ";
    cout << left << setw(9) << EMPTY_WEIGHT_ARM << "=" << right << setw(16) << emptyMoment << "|" << endl;
    cout << "|" << setfill('-') << setw(18) << "" << "+" << setw(43) << right << "|" << left << endl;
    
    cout << setfill(' ') << setw(19) << "|Pilot Weight" << "|" << right << setw(13) << pilotWeight << " X ";
    cout << left << setw(9) << PILOT_ARM << "=" << right << setw(16) << pilotMoment << "|" << endl;
    cout << "|" << setfill('-') << setw(18) << "" << "+" << setw(43) << right << "|" << left << endl;
    
    cout << setfill(' ') << setw(19) << "|Co-Pilot Weight" << "|" << right << setw(13) << coPilotWeight << " X ";
    cout << left << setw(9) << PILOT_ARM << "=" << right << setw(16) << coPilotMoment << "|" << endl;
    cout << "|" << setfill('-') << setw(18) << "" << "+" << setw(43) << right << "|" << left << endl;
    
    cout << setfill(' ') << setw(19) << "|Rear Passenger #1" << "|" << right << setw(13) << rearPassengerOneWeight << " X ";
    cout << left << setw(9) << REAR_PASSENGER_ARM << "=" << right << setw(16) << rearPassengerOneMoment << "|" << endl;
    cout << "|" << setfill('-') << setw(18) << "" << "+" << setw(43) << right << "|" << left << endl;
    
    cout << setfill(' ') << setw(19) << "|Rear Passenger #2" << "|" << right << setw(13) << rearPassengerTwoWeight << " X ";
    cout << left << setw(9) << REAR_PASSENGER_ARM << "=" << right << setw(16) << rearPassengerTwoMoment << "|" << endl;
    cout << "|" << setfill('-') << setw(18) << "" << "+" << setw(43) << right << "|" << left << endl;
    
    cout << setfill(' ') << setw(19) << "|Baggage" << "|" << right << setw(13) << baggageWeight << " X ";
    cout << left << setw(9) << BAGGAGE_ARM << "=" << right << setw(16) << baggageMoment << "|" << endl;
    cout << "|" << setfill('-') << setw(18) << "" << "+" << setw(43) << right << "|" << left << endl;
    
    cout << setfill(' ') << setw(19) << "|Total (No Fuel)" << "|" << right << setw(13) << noFuelWeight << setw(29) << noFuelMoment << "|" << endl;
    cout << "|" << setfill('-') << setw(18) << "" << "+" << setw(43) << right << "|" << left << endl;
    
    cout << setfill(' ') << setw(19) << "|Fuel" << "|" << right << setw(13) << fuelWeight << " X ";
    cout << left << setw(9) << FUEL_ARM << "=" << right << setw(16) << fuelMoment << "|" << endl;
    cout << "|" << setfill('-') << setw(18) << "" << "+" << setw(43) << right << "|" << left << endl;
    
    cout << setfill(' ') << setw(19) << "|Total (With Fuel)" << "|" << right << setw(13) << rampTotalWeight << setw(29) << rampTotalMoment << "|" << endl;
    cout << "|" << setfill('-') << setw(18) << "" << "+" << setw(43) << right << "|" << left << endl;
    
    cout << setfill(' ') << setw(19) << "|CG (inches aft)" << "|" << right << setw(13) << centerOfGravity << setw(30) << "|" << endl;
    cout << "+" << setfill('-') << setw(61) << "" << left << "+" << endl; 
    
    return 0;
}

void inputWeight(double& dataVariable, string prompt, string variable)
{
    cout << prompt;
    while(!(cin >> dataVariable))
    {
        cout << "Invalid " << variable << endl << endl;
        cout << prompt;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void welcomeUser()
{
    cout << "N513DS Weight & Balance Worksheet / Pre-Flight Worksheet" << endl;
    
    cout << "\nFAR 91.103b2 : Calculated Weight and Balance and Takeoff and Landing Performance" << endl;
    cout << "for all runways of intended use required before each flight!" << endl;
    
    cout << "\nAll information herein is derived from aircraft approved flight manual supplement" << endl;
    cout << "and aircraft weight and balance." << endl << endl;
}