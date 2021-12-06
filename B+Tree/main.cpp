//created by Nicholas

#include <iostream>
#include <fstream>

#include "Person.h"
#include "BPlusTree.h"
#include "Error.h"

int main(int argc, char** argv) {
	
	Error *error;

	/*	*** test creating a new person ***	*/	
	printf("new person:\n");
	Person *people = new Person("John", "baker", "1086894", "Info Requested", "info Requested", "Abbeville", "LA");
	people->printData();
	
	
	
	/* *** read contents of the file and for each line, make them into a person *** */
	ifstream file;
    string str;
    
    // file name
   	char fname[100] = "personRelation.csv";
  	file.open(fname);
   
   	// simple check to ensure file is present
   	if (!file)
   	{
   	   cout << "Error Occurred while opening file!";
   	   exit(0);
   	}
   	cout << "\n";
   
    // create 2002 (the number of rows in the file +1) people
	Person instance[2002];
   
   	int iteration = 0;
   	
   	while( getline(file, str) )
    { 
    	iteration++;
		//read data from file object and put it into string.
        cout << str << "\n"; //print the data of the string
        
        if( str.empty()  )break;
         
        // create a new instance of Person based on this iteration
        Person person = instance[iteration];
         
		int length = str.length() + 1;
		//char *strBuf = new char[length]; 
		string strBuf;
		int term = 0;
		
		// variable to store individual terms (first name, last name, )
		string valueBuf;
		
		// so... strBuf should now store the line of text
		//strcpy( strBuf, str.c_str() );        
		strBuf += str;
		
		cout << "buffer: " << strBuf << "\n";
		
		for(int i = 0; i < length; i++)
		{
			
			string stringChar;
			stringChar = strBuf[i];
			//cout << "string to char: " << stringChar << "\n";
			
			valueBuf += stringChar;
			
			// ',' is a delineating term, so split the terms into words bound by commas
			if( strBuf[i] == ',' )
			{
				//cout << "comma detected.  Substring valueBuf:" << valueBuf << "\n";
				//cout << valueBuf;
				
				// because the term is an iterated variable, it is used to determine whether to write to the firstname, lastname, etc.
				switch(term)
				{
					// first name
					case 0:
						person.firstName = valueBuf;
						break;
					
					// last name	
					case 1:
						person.lastName = valueBuf;
						break;
					
					// id	
					case 2:
						person.ID = valueBuf;
						break;
					
					// employer	
					case 3:
						person.employer = valueBuf;
						break;
						
					// occupation
					case 4:
						person.occupancy = valueBuf;
						break;
					
					// city	
					case 5:
						person.city = valueBuf;
						break;
					
					// state	
					case 6:
						person.state = valueBuf;
						term = -1;
						
						break;
				}
				
				// clear the value buffer
				valueBuf.clear();
				strBuf.clear();
				term++;	
				cout << "\n";				
			}	
		}
		
		person.printData();

	}
   file.close();
   cout << "\n\n";
   
	
	/* *** build b+ tree *** */
	printf("Starting test of BPlusTree\n");
	int m = 5;
	// create a new instance of the BPlusTree
	BPlusTree *bPlusTree = new BPlusTree();
	
	// test the b+tree using the internal testing script
	bPlusTree->test();
	
	// when the B+ tree is done, run this code	
	/*
	for(int i = 0; i < 2002; i++)
		// insert an instance of Person into the B+ tree
		bPlusTree->insert(instance[i]);
	*/
	
	return 0;

}
