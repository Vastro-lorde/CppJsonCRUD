// JsonCRUD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <json/json.h>

using namespace std;


const string jsonFileName = "data.json"; // Change this to your desired JSON file name

// Function to read JSON data from file
Json::Value readJSONFromFile() {
    Json::Value jsonData;
    ifstream inputFile(jsonFileName);
    if (inputFile.is_open()) {
        inputFile >> jsonData;
        inputFile.close();
    }
    return jsonData;
}


// Function to write JSON data to file
void writeJSONToFile(const Json::Value& jsonData) {
    ofstream outputFile(jsonFileName);
    if (outputFile.is_open()) {
        outputFile << jsonData;
        outputFile.close();
    }
}


// Function to create a new record in JSON
void createRecord(const string& connectionString, string apiKey) {
    Json::Value jsonData = readJSONFromFile();

    Json::Value newRecord;
    newRecord["connectionString"] = connectionString;
    newRecord["apiKey"] = apiKey;
    
    jsonData.append(newRecord);

    writeJSONToFile(jsonData);
}


void readRecords() {
    Json::Value jsonData = readJSONFromFile();

    for (const Json::Value& record : jsonData) {
        string name = record["connectionString"].asString();
        string age = record["apiKey"].asString();

        cout << "Name: " << name << ", Age: " << age << endl;
    }
}


void updateRecord(int index, const string& connectionString, string apiKey) {
    Json::Value jsonData = readJSONFromFile();

    if (index >= 0 && index < jsonData.size()) {
        jsonData[index]["connectionString"] = connectionString;
        jsonData[index]["apiKey"] = apiKey;

        writeJSONToFile(jsonData);
    }
    else {
        cout << "Invalid index." << endl;
    }
}




void deleteRecord(int index) {
    Json::Value jsonData = readJSONFromFile();

    if (index >= 0 && index < jsonData.size()) {
        jsonData.removeIndex(index, NULL);

        writeJSONToFile(jsonData);
    }
    else {
        cout << "Invalid index." << endl;
    }
}

int main()
{
    /*createRecord("seun:sdajfj;ajefjija", "luhhlugyuyvyluh");
    createRecord("Bob:dsjajfjh", "8go7og7oy78ho8h");
    createRecord("Carol:skdafihpie", "3jorjij3irj38eijwi");

    cout << "All Records:" << endl;
    readRecords();*/

    /*updateRecord(1, "", "ajfijpi4ijqij34iqj");

    cout << "After Update:" << endl;
    readRecords();*/

    /*deleteRecord(0);
    deleteRecord(1);
    deleteRecord(2);

    cout << "After Deletion:" << endl;
    readRecords();*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
