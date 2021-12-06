//created by Nicholas

#ifndef PERSON_H
#define PERSON_H

#include <String.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


class Person
{
	//variables for this instance
	public:
		string 	firstName = "";
		string 	lastName = "";
		string 	ID = "";
		string 	employer = "";
		string 	occupancy = "";
		string 	city = "";
		string 	state = "";
		
	public:
		Person();
		
		~Person();
			
		
		// Person
		// Person class instance
		/*
			input: first name (char*), last name (char*), ID (string), employer (char*), Occupancy (char*), city (char*), state (char*) 
		*/
		Person(string inputFirstName, string inputLastName, string inputID, string inputEmployer, string inputOccupancy, string inputCity, string inputState)
		{
			firstName 	= inputFirstName;
			lastName 	= inputLastName;
			ID 			= inputID;
			employer 	= inputEmployer;
			occupancy 	= inputOccupancy;
			city 		= inputCity;
			state	 	= inputState;			
		}
		
		void setFirstName(string first)
		{
			firstName = first;
		}
		
		
		// printData
		// print the variable data for this instance of Person
		/*
			input:
			ouptut:
		*/
		void printData()
		{
			cout << "First Name:\t" << firstName << "\n" <<
					"Last Name:\t" << lastName << "\n" <<	
					"ID:\t" << ID << "\n" <<	
					"Employer\t" << employer << "\n" <<	
					"Occupancy:\t" << occupancy << "\n" <<
					"City:\t" << city << "\n" <<		
					"State:\t" << state << "\n";
		}
	
};

#endif