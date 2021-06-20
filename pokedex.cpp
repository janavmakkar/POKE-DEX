#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>

using namespace std;

int main(){

    vector<string> row;
    int n,index;
    string name, response, line, word, temp;

    ifstream infile;

    cout << "Welcome to the Pokedex." << endl;

    while(response!="q"){
        int count = 0, found = 0;
        infile.open("pokemon.csv");
        cout<< "Would you like to search by Name or by Number? (Or Enter '1' for Name-Search or '2' for Number-Search) " << endl
        << "Or press 'q' to Quit" << endl;
        cin >> response;
        if(response=="name" || response=="Name" || response=="1"){
            cout << "Please enter the name of the Pokemon: "<<endl;
            cin >> name;
            while (getline(infile, line))
            {
                row.clear();
                if (count != 0)
                {   
                    stringstream s(line);
                    while (getline(s, word, ','))
                    {
                        row.push_back(word);
                    }
                    if (name==row[1])
                    {
                        cout << "Details of Index: " << row[0] << " : \n";
                        cout << "Name: " << row[1] << "\n";
                        cout << "Classification: " << row[2] << "\n";
                        cout << "Type-1: " << row[3] << "\n";
                        cout << "Type-2: " << row[4] << "\n";
                        found = 1;
                        break;
                    }
                }
                count=1;
            }
            if (found==0){ cout << "Record not found!" << endl;} 
            infile.close();
        }
        else if (response=="number" || response=="Number" || response=="2"){
            cout << "Enter the Index Number ";
            cin >> n;
            while (getline(infile, line))
            {
                row.clear();
                if (count != 0) //To skip the Header
                {
                    stringstream s(line);         // Breaking line into s stream
                    while (getline(s, word, ',')) // saving each s stream into word string
                    {
                        row.push_back(word); //adding each word to row vector
                    }
                    if (n == stoi(row[0]))
                    {
                        cout << "Details of Index " << row[0] << " : \n";
                        cout << "Name: " << row[1] << "\n";
                        cout << "Classification: " << row[2] << "\n";
                        cout << "Type-1: " << row[3] << "\n";
                        cout << "Type-2: " << row[4] << "\n";
                        found = 1;
                        break;
                    }
                }
                count = 1;
                }
                if (found==0){
                    cout << "Record not found!" << endl;
                }    
                infile.close();
        }
    }


}