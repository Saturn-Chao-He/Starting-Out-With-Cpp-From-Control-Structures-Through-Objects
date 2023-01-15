//******************************************************************************
// Computer Science 50X2
// Fall 2019
// Assignment # 19
// Due Date: Monday, December 2
// Instructor: Dr. Jeff Jenness
// Programmer: Chao He
// Description: A program using map to contain the U.S. states and their capitals. Make a quiz.
// Input : Capital
// Output: responses of correct answers and incorrect answers
//******************************************************************************
#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>

using namespace std;


int main ()
{
    int num;
    string input;
    map<int, string> states;
    map<string, int> capital;
    int numCorrect = 0;
    int numWrong = 0;
    
    states[1] = "Alabama"; capital["Montgomery"] = 1;      
    states[2] = "Alaska";  capital["Juneau"] = 2;
    states[3] = "Arizona"; capital["Phoenix"] = 3;         
    states[4] = "Arkansas"; capital["Little Rock"] = 4;
    states[5] = "California"; capital["Sacramento"] = 5;   
    states[6] = "Colorado"; capital["Denver"] = 6;
    states[7] = "Connecticut"; capital["Hartford"] = 7;    
    states[8] = "Delaware"; capital["Dover"] = 8;
    states[9] = "Florida"; capital["Tallahassee"] = 9;     
    states[10] = "Georgia"; capital["Atlanta"] = 10;
    states[11] = "Hawaii"; capital["Honolulu"] = 11; 
    states[12] = "Idaho"; capital["Boise"] = 12;
    states[13] = "Illinois"; capital["Springfield"] = 13; 
    states[14] = "Indiana"; capital["Indianapolis"] = 14;
    states[15] = "Iowa"; capital["Des Moines"] = 15; 
    states[16] = "Kansas"; capital["Topeka"] = 16;
    states[17] = "Kentucky"; capital["Frankfort"] = 17; 
    states[18] = "Louisiana"; capital["Baton Rouge"] = 18;
    states[19] = "Maine"; capital["Augusta"] = 19; 
    states[20] = "Maryland"; capital["Annapolis"] = 20;
    states[21] = "Massachusetts"; capital["Boston"] = 21; 
    states[22] = "Michigan"; capital["Lansing"] = 22;
    states[23] = "Minnesota"; capital["Saint Paul"] = 23; 
    states[24] = "Mississippi"; capital["Jackson"] = 24;
    states[25] = "Missouri"; capital["Jefferson City"] = 25; 
    states[26] = "Montana"; capital["Helena"] = 26;
    states[27] = "Nebraska"; capital["Lincoln"] = 27; 
    states[28] = "Nevada"; capital["Carson City"] = 28;
    states[29] = "New Hampshire"; capital["Concord"] = 29; 
    states[30] = "New Jersey"; capital["Trenton"] = 30;
    states[31] = "New Mexico"; capital["Santa Fe"] = 31; 
    states[32] = "New York"; capital["Albany"] = 32;
    states[33] = "North Carolina"; capital["Raleigh"] = 33; 
    states[34] = "Ohio"; capital["Columbus"] = 34;
    states[35] = "Oklahoma"; capital["Oklahoma City"] = 35; 
    states[36] = "Oregon"; capital["Salem"] = 36;
    states[37] = "Pennsylvania"; capital["Harrisburg"] = 37; 
    states[38] = "Rhode Island"; capital["Providence"] = 38;
    states[39] = "South Carolina"; capital["Columbia"] = 39; 
    states[40] = "South Dakota"; capital["Pierre"] = 40;
    states[41] = "Tennessee"; capital["Nashville"] = 41; 
    states[42] = "Texas"; capital["Austin"] = 42;
    states[43] = "Utah"; capital["Salt Lake City"] = 43; 
    states[44] = "Vermont"; capital["Montpelier"] = 44;
    states[45] = "Virginia"; capital["Richmond"] = 45; 
    states[46] = "Washington"; capital["Olympia"] = 46;
    states[47] = "West Virginia"; capital["Charleston"] = 47; 
    states[48] = "Wisconsin"; capital["Madison"] = 48;
    states[49] = "Wyoming"; capital["Cheyenne"] = 49; 
    states[50] = "North Dakota"; capital["Bismarck"] = 50;

    map<int, string>::iterator iter1;
    map<string, int>::iterator iter2;


    cout << endl << '\t' << '\t' << " The Quiz of States' Capital " << endl
         << "***************************************************************************" << endl
         << "Input q to quit the quiz" << endl << endl << endl;   

    do
    {
        srand(time(0));
        num = rand() % 50 + 1;

        iter1 = states.find(num);
        cout << "Please input the capital of the state  " << iter1-> second << endl << endl;
        getline(cin, input);
        iter2 = capital.find(input); 

        if(num == iter2->second && input.size() > 2)
        {
            cout << endl << "Correct!" << endl << endl;
            numCorrect++;
        }
        if(num != iter2->second && input.size() > 2)
        {
            cout << endl << "Wrong!" << endl << endl;
            numWrong++;
        }
        if(input == "q")
        {
            cout << endl << "Quit!" << endl;
             break;
        }
           
    }while (input != "q");
    
    cout << endl << "The number of correct responses: " << numCorrect << endl
                 << "The number of incorrect responses: " << numWrong << endl
                 << endl << endl;
    return 0;
}

