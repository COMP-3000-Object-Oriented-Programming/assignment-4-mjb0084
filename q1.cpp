#include <iostream>
#include <iomanip>

using namespace std;

class GasPump {
	private:
		double amountDispensed,
		       amountCharged,
		       costPerGallon;

	public:
		double getAmountDispensed() { return amountDispensed; }
		double getAmountCharged() { return amountCharged; }
		double getCostPerGallon() { return costPerGallon; }
		void setCostPerGallon(double cpg) { costPerGallon = cpg; }
        
		void dispense(int seconds) {
			amountDispensed=.1*seconds;
			amountCharged = amountDispensed * costPerGallon;
		}
		void reset() {
            costPerGallon=0.0;
			amountDispensed = 0.0;
			amountCharged = 0.0;
		}		
};
	
int main() {
	
	GasPump Person;
	double costpergallon;
	int seconds;

	Person.reset();

	cout << "What is the cost per gallon of gas?\n: ";
	cin >> costpergallon; 
    Person.setCostPerGallon(costpergallon);
	
	cout << "\nHow long do you want to pump gas for?\n:";
	cin >> seconds;
	Person.dispense(seconds);

	cout << "\nAmount Dispensed: " << Person.getAmountDispensed() << "\nCost Per Gallon: " << Person.getCostPerGallon() << "\nAmount Charged: " << Person.getAmountCharged();
	
	return 0;
}