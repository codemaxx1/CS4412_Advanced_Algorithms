// created by Nicholas Garrett

#ifndef ERROR_H
#define ERROR_H

#include <String.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>

using namespace std;

class Error
{
	protected:
		char* errorList;

	public:
		Error();
		~Error();
		
		// newError
		// simple function for implementing a small error log
		/*
			input: error: (char*), some text and explanation of the error
			output: 
		*/
		void newError(char* error)
		{
			printf("\n*** ERROR *** \n\t %s \n*************\n", error);
			strcat(errorList, error);
		}
		
};

#endif