#include "RuleOf5.hpp"

using std::println;

Vehicle::Vehicle()noexcept :m_name(nullptr), m_size(0) {
		println("Vehicle Ctor called");
}

Vehicle::~Vehicle() {
		delete[]m_name;
		m_name = nullptr;
	}

Vehicle::Vehicle(const char* name) {
		println("Vehicle param ctor called {}" , name);

		if (!name) {
			println("\tVehicle param ctor :: InvariantCheck failed creating empty class");
			m_name = {}; m_size = {};
			return;
		}

		m_size = strlen(name);
		m_name = new char[m_size + 1];
		memcpy(m_name, name, m_size + 1);
	}

Vehicle::Vehicle(const char* name, size_t size) {
	println("Vehicle two param called");
	if (name == nullptr && size == 0) {
		println("\tVehicle two param ctor :: InvariantCheck failed creating empty class");
		m_name = {}; m_size = {};
		return;
	}

	if (name == nullptr || size == 0)
		throw std::invalid_argument("\tInvalid Argument");

	size_t actual = strlen(name);
	if (actual != size)
		throw std::invalid_argument("Invalid argument passed to Vehicle class");

	m_size = size;
	m_name = new char[m_size + 1];
	std::memcpy(m_name, name, m_size + 1);
}

Vehicle::Vehicle(const Vehicle& other) {
	println("Vehicle copy ctor called");
	if (!other.m_name) {
		println("\t Vehicle Copy Ctor :: InvariantCheck failed creating empty class");
		m_name = {}; m_size = 0;
		return;
	}

	m_size = other.m_size;
	m_name = new char[m_size + 1];
	std::memcpy(m_name, other.m_name, m_size + 1);
}

Vehicle::Vehicle(Vehicle&& other) noexcept :
	m_name(std::exchange(other.m_name, nullptr)),
	m_size(std::exchange(other.m_size, 0)) {
	println("Vehicle move ctor called");
}

////old way of copy assignment 
//Vehicle& operator=(const Vehicle& other) {
//	println("Vechile old assignment ctor called");
//	if (&other == this)
//		return *this;

//	char* temp = {};

//	if (other.m_name)
//	{
//		temp = new char[other.m_size + 1];
//			std::memcpy(temp, other.m_name, other.m_size + 1);
//	}

//	delete[] m_name;

//	m_name = temp;
//	m_size = other.m_size;

//	return *this;
//}

//new way of copy assignment 
void Vehicle::swap(Vehicle& other) noexcept {
	println(" Vehicle Swap called");
	std::swap(m_name, other.m_name);
	std::swap(m_size, other.m_size);
}

Vehicle& Vehicle::operator=(Vehicle other) {
	println("Vehicle new Assignment called");
	swap(other);
	return *this;
}

int main() {
	try {
		Vehicle v1("Car");
		Vehicle v2("Bus");
		Vehicle v4("Bus", 2);
		Vehicle v3;
		v3 = v1;
		v3 = std::move(v2);
	}
	catch (...) {
		println("\tUnkown exception captured ");
	}
}
