#include <iostream>

using namespace std;

class Temperature {
	private:
		double degreesKelvin,
		       degreesFahrenheit,
		       degreesCelsius;
	public:
		void setTempKelvin(double dK) {degreesKelvin=dK;}
		double getTempKelvin() {return degreesKelvin;}
		void setTempCelsius(double dK) {degreesCelsius = dK-273.15;}
		double getTempCelsius() {return degreesCelsius;} 
		void setTempFahrenheit(double dK) {degreesFahrenheit=((dK-273.15)/(5.0/9))+32;}
		double getTempFahrenheit() {return degreesFahrenheit;}
};

int main() {
	Temperature Temp;
	double dK;

	cout << "\nWhat is the temperature in Kelvin?\n:";
	cin >> dK;

	Temp.setTempKelvin(dK);
	Temp.setTempCelsius(dK);
	Temp.setTempFahrenheit(dK);

	cout << "\nThe temperature is:\n" << Temp.getTempCelsius() << " degrees Celcius\n" << Temp.getTempFahrenheit() << " degrees Fahrenheit";
}
