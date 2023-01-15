//******************************************************************************
// Computer Science 50X2
// Fall 2019
// Assignment # 14
// Due Date: Wednesday, Ocorber 28
// Instructor: Dr. Jeff Jenness
// Programmer: Chao He
// Description: choosing options from a menu to list, append, edit, sort and delete the records  
// Input: choices
// Output: Display the records
//******************************************************************************

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

struct record
{
    bool deleted;
    char name[51];
    char addr1[101];
    char addr2[101];
    char phone[21];
    double balance;
    char date[9];
};

const ios_base::openmode mode = ios::in|ios::out|ios::binary;
const string filename = "accounts.dat";
fstream datafile(filename, mode);
int recordCnt, recordNum;

record getData();

int main()
{
    string userInput;
    bool quit = false;
    int recordCnt, recordNum;
    record data;

    //Checking for file's existence
    fstream datafile(filename, mode);
	if (datafile.fail()) 
    {
		datafile.open(filename, ios::out|ios::app|ios::binary);
		if (datafile.fail()) 
        {
			cout << "Could not create 'accounts.dat'";
			cout << "Failed to open datafile, exiting" << endl;
			exit(1);
		} 
		datafile.close();
		datafile.open(filename, mode);
        cout << endl << endl << '\t' << '\t' << "Customer Accounts" << endl;
        cout << "*******************************************************************************" << endl;
		cout << "Created data file accounts.dat'" << endl;  
    }
    datafile.seekg(0L, ios::end);
    recordCnt = datafile.tellg()/sizeof(record);
    
    do
    {
        cout << endl << endl << '\t' << '\t' << "Customer Accounts" << endl;
        cout << "*******************************************************************************" << endl;
        cout << endl 
             << "L" << "\t" << "- list all records" << endl
             << "A" << "\t" << "- add new records" << endl
             << "E" << "\t" << "- edit existing records" << endl
             << "D" << "\t" << "- delete existing records" << endl
             << "S" << "\t" << "- sort records" << endl
             << "Q" << "\t" << "- quit" << endl << endl
             << "Pleast input your choice > ";
        getline(cin,userInput);

        if(userInput.length() != 1)
        cout << "Error: invalid input!" << endl;
        else
        {
            char c = tolower(userInput[0]);
            // Add a new record
            if (c == 'a')
            {
                fstream datafile(filename, mode);
                data = getData();
                datafile.seekp(0L, ios::end);
                recordNum = datafile.tellp()/sizeof(record);
                datafile.write(reinterpret_cast<char*>(&data), sizeof(record));
                datafile.clear();
                datafile.seekp(0L, ios::beg);
                ++recordCnt;
            }
            //List all records
            if(c == 'l')
            {
                fstream datafile(filename, ios::in|ios::binary);
                int recordNum = 1;
                datafile.seekg(0, ios::beg);
                datafile.read(reinterpret_cast<char*>(&data), sizeof(record));
                while (!datafile.eof()) 
                {
                    if (!data.deleted)  
                    {
                        cout << endl << "The record "<< recordNum << ":" << endl
                             << data.name << "  " 
                             << "Address: " << data.addr1 << "  "
                             << "City, Zip code: " << data.addr2 << "  "
                             << "Phone: " << data.phone << "  "
                             << "Balance: " << data.balance << "  "
                             << "Date(mmddyyyy): " << data.date << endl;   
                    }
                    ++recordNum;
                    datafile.read(reinterpret_cast<char*>(&data), sizeof(record));
                } 
                datafile.clear();
                datafile.seekp(0L, ios::beg);
            }   

            //Edit the existing record
            if (c == 'e')
            {
                fstream datafile(filename, mode);
                cout << "Which record number to edit? ";
                cin >> recordNum;
                cin.ignore();
                datafile.seekg(((recordNum - 1) * sizeof(record)), ios::beg);
                datafile.read(reinterpret_cast<char*>(&data), sizeof(record));
                cout << "You want to edit record No. " << recordNum << ": " 
                     << data.name << "  " 
                     << "Address: " << data.addr1 << "  " 
                     << "City, Zip code: " << data.addr2 << "  "
                     << "Phone: " << data.phone << "  "
                     << "Balance: " << data.balance << "  "
                     << "Date(mmddyyyy): " << data.date << endl;
                if (recordNum < 0 || recordNum > recordCnt) 
                    cout << "Record number out of range!\n";
                else 
                {
                    datafile.read(reinterpret_cast<char*>(&data),sizeof(record));
                    cout << "Enter the new record:\n";
                    data = getData();
                    datafile.seekp((recordNum - 1) * sizeof(record), ios::beg);
                    datafile.write(reinterpret_cast<char*>(&data), sizeof(record));
                }
                datafile.clear();
                datafile.seekp(0L, ios::beg);
            }
            //Delete record
            if (c == 'd')
            {       
                fstream datafile(filename, mode);
                cout << "Which record number to delete? ";
                cin >> recordNum;
                cin.ignore();

                if (recordNum < 0 || recordNum > recordCnt)
                    cout << "Record number out of range!\n";
                else 
                {
                    datafile.seekg(( (recordNum - 1) * sizeof(record)) , ios::beg );
                    datafile.read(reinterpret_cast<char*>(&data), sizeof(record));
                    if (data.deleted == true) 
                        cout << "Record does not exist!\n";
                    else 
                    {  
                        data.deleted = true;
                        datafile.seekp( ((recordNum - 1) * sizeof(record)) , ios::beg );
                        datafile.write(reinterpret_cast<char*>(&data), sizeof(record));
                        cout << "Deleted Record " << endl;
                    }
                }
                datafile.clear();
                datafile.seekp(0L, ios::beg);
            }
            if(c == 'q')
            {
                exit(0);
            }
            //Sort records
            if(c == 's')
            {
                fstream datafile(filename, mode);
                int minIndex, swaps = 0;
                record minRec, temp;
                char *minName, *tmpName;
                char name[51], candidate[51];
                for (int i = 0; i < recordCnt - 1; ++i) 
                {
                    minIndex = i;
                    datafile.seekg( (i * sizeof(record)) , ios::beg);
                    datafile.read(reinterpret_cast<char*>(&data), sizeof(record));
                    minRec = data;
                    minName = strrchr(minRec.name, ' ')+1;
                    if (minName == NULL) minName = minRec.name;
                    for (int j=i+1; j<recordCnt; ++j) 
                    {
                        datafile.seekg(j * sizeof(record), ios::beg);
                        datafile.read(reinterpret_cast<char*>(&temp), sizeof(record));
                        tmpName = strrchr(temp.name, ' ')+1;
                        if (tmpName == NULL) tmpName = temp.name;
                        if (strncmp(tmpName, minName, 51) < 0) 
                        {
                            minIndex = j;
                            minRec = temp;
                            minName = strrchr(minRec.name, ' ')+1;
                            if (minName == NULL) minName = minRec.name;
                        }
                    }
                    if (minIndex != i)
                    {
                        datafile.seekp( (minIndex * sizeof(record)) , ios::beg);
                        datafile.write(reinterpret_cast<char*>(&data), sizeof(record));
                        datafile.seekp( (i * sizeof(record)) , ios::beg);
                        datafile.write(reinterpret_cast<char*>(&minRec), sizeof(record));
                        ++swaps;
                    }
                }
                cout << "Sorted " << recordCnt << " records with " << swaps << " swaps " << endl;
                
		    }
        }   
    } while (!quit);

    datafile.close();

    return 0;
}
record getData()
{
    record data;
    data.deleted = false;
    cout << "Enter the following data: " << endl;
    cout << "Name: ";
    cin.getline(data.name, 51);
    cout << "Address: " << endl;
    cin.getline(data.addr1, 101);
    cout << "City, Zip: " << endl;
    cin.getline(data.addr2, 101);
    cout << "Phone: ";
    cin.getline(data.phone, 21);
    cout << "Banlance: ";
    cin >> data.balance;
    cin.ignore();
    cout << "Date: ";
    cin.getline(data.date, 9);
    return data;
}