//Justin Ritchey. Machine Problem 6. Strings and Enums. 7/8/2020    
//Designing a program that will accept/read a file that has names in it. The progrom will rearrnage the names to be in a standerdized form.

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//functions
string names(string);                                                  //string function being used

enum married {married = 'M', single = 'S', divorced = 'D'};            //enum variable for if married, single or divorced

int main()
{ 
	int counter2 = 0;                                                 //counter to be used for finding length of the orignal input                              
	string words = "";                                                //holding the input for the file
	ifstream file;                                                    //opening file
	file.open("mp6Names.txt");
	ofstream outputFile;
	outputFile.open("OutputNames.txt");



	file.clear(); 
	file.seekg(0, ios::beg);
	
	cout << "Orignal" << "                            " << " Formatted" << "\n\n";         //formatting

	while (getline(file, words))                                     //creating a while loop to go line by line from the file
	{
		counter2 = words.length();                                   //getting line's lenght for formatting
		counter2 = 34 - counter2;                                    //formatting of cout

		cout << words;                                               //cout for the first orignal line
		outputFile << words;                                         //print to file

		for (int i = 0; i < counter2; i++)                           //loop to add in spaced for formatting
		{
			cout << " ";
			outputFile << " ";
		}
		

		words = names(words);                                        //using the function to reassign the word variable to the new formatted version

		cout << "|  " <<  words << endl;                             //printing out the final version
		outputFile << "|  " << words << endl;                        //Printing to file

	}

	return 0;

}

string names(string words)                                          //start of the string fucntion
{

	string first = "";                                              //will hold the first name of a person
	string last = "";                                               //will hold the last name of a person
	string middle = "";                                             //wil hold the middle intial of a person
	string formatted = "";                                          //will hold the final version of the formatted string                         
	int finder = 0;                                                 //used for finding various string lengths to gather names
	int counter = 0;                                                //used for adding in spaces between the first name and middle intial
	int counter2 = 0;                                               //used for adding in spaces between martial status and first name
	
	

	if (words[0] == 'M')                                            //loop to assign marriage or not
	{
		formatted = "Mr. ";
	}
	else                                                            //using a swtich statement to utilize the enum
	{
		switch (words[1])
		{
		case single: formatted = "Ms. ";
			break;
		default: formatted = "Mrs. ";
			break;
		}
	}

	finder = words.find(',');                                      //searching the first line for a comma to find the end of the last name
	last = words.substr(2, finder - 2);                            //gathering the last name into the "last" variable


	while (words[finder++] == ' ');                                //using a loop to find the beginning of the first name
	words = words.substr(finder);                                  //removing everything before the first name and assigning to words variable

	 
	finder = words.find(' ');                                      //setting the finder variable to the end of the first name
	first = words.substr(0, finder);                               //gathering the first name


	while (words[finder++] == ' ')                                 //using another loop to find if there is a middle intial
	middle = words.substr(finder, words.find('.'));                //gathering the middle intial if it exsits

	formatted.erase(remove(formatted.begin(), formatted.end(), ' '), formatted.end());   //removing all blank spaces for each variable
	first.erase(remove(first.begin(), first.end(), ' '), first.end());
	last.erase(remove(last.begin(), last.end(), ' '), last.end());
	middle.erase(remove(middle.begin(), middle.end(), ' '), middle.end());


	formatted.append(first + ' ');                                //adding them all together
	formatted.append(middle + ' ');
	formatted.append(last);

	
	counter = formatted.rfind('.');                              //checking for a space between the first name and middle inital
	if (counter > 2)
	{
		formatted.insert(counter - 1, " ");
	}
	
	counter2 = formatted.find('.');                             //checking for a space between the title and the first name
	if (formatted[counter2 + 1] != ' ')
	{
		formatted.insert(counter2 + 1, " ");
	}


	return formatted;                                          //sending the final variable back to the main

}