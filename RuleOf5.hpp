#pragma once
#include <print>
#include <utility>
#include <iostream>

class Vehicle {
	char* m_name{};
	size_t m_size{};
public:
	Vehicle()noexcept;

	~Vehicle();

	Vehicle(const char* name);

	Vehicle(const char* name, size_t size);

	Vehicle(const Vehicle& other);

	Vehicle(Vehicle&& other)noexcept;

	////old way of copy assignment 
	//Vehicle& operator=(const Vehicle& other);

	//new way of copy assignment 
	void swap(Vehicle& other)noexcept;
    Vehicle& operator=(Vehicle other);
};