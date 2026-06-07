#include "addEmployee.hpp"

int main(int argc, char *argv[])
{
    // check for number of arguments
    if (argc < 2)
    {
        cout << "file name missing" << endl;
        return -1;
    }

    string fileName = argv[1]; // TODO 1: get the file name from the command line parameters
    employee array[4];

    // open the file
    ifstream myfile;
    myfile.open(fileName);

    string line;
    string name;
    string emailid;
    string birthday;
    int length = 0;

    if (myfile.is_open()) // check that this file exists
    {
        // TODO 2:  Read each line from the file
        //          for each line do the following
        //               extract name, extract email, exract birthday
        //               call the addAemployee function to add them in the array
        while (getline(myfile, line))
        {
            string employee[3];
            stringstream stream(line);
            string cell;
            int i = 0;
            while(getline(stream, cell, ',')){
                employee[i] = cell;
                i++;
            }
            addAnEmployee(array, employee[0], employee[2], employee[1], length); 
            length++;
        }
    }
    else
    {
        cout << "err: can not open file" << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        cout << "name:" << array[i].name << " email:" << array[i].email << " bday:" << array[i].birthday << endl;
    }

    return 0;
}