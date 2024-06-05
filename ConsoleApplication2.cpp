
#include <iostream>
#include <string>
using namespace std;

class Car {
public:
	int wheels;
	string color;
	string engine;
	int seats;
	bool gps;

	void show() {
		cout << "Wheels: " << wheels<< endl;
		cout << "color: " << color<<endl;
		cout << "engine: " << engine<<endl;
		cout << "seats: " << seats<< endl;
		cout << "gps: " << gps<< endl;


	}

};


class CarBuilder {
private:
	Car* result;
public:
	CarBuilder() {}
	~CarBuilder() {
		delete result;
	}
	CarBuilder& reset() {
		this->result = new Car();
		return *this;
	}

	CarBuilder& setWheels(int count) {
		this->result->wheels = count;
		return *this;
	}

	CarBuilder& setColor(string color) {
		this->result->color = color;
		return *this;
	}

	CarBuilder& setEngine(string engine) {
		this->result->engine = engine;
		return *this;
	}

	CarBuilder& setSeats(int count) {
		this->result->seats = count;
		return *this;
	}

	CarBuilder& setGps(bool gps) {
		this->result->gps = gps;
		return *this;
	}

	Car* getResult() {
		return this->result;
	}


};


class Director {
private:
	CarBuilder builder;

public:
	Car* constructSportsCar() {
		builder.reset();
		builder.setColor("black");
		builder.setEngine("sport");
		builder.setGps(false);
		builder.setSeats(2);
		builder.setWheels(4);
		return builder.getResult();
	}

	Car* constructMusclecar() {
		builder.reset();
		builder.setColor("yellow");
		builder.setEngine("10200");
		builder.setGps(true);
		builder.setSeats(2);
		builder.setWheels(4);
		return builder.getResult();

	}





	
};




int main()
{

	Director d1;
	d1.constructMusclecar()->show();
	cout << endl;
	d1.constructSportsCar()->show();



	

}

