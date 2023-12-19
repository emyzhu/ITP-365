#include "fileio.h"

// Read in a file and return a vector of strings
bool getData(const std::string& inputLocation, std::vector<std::string>& data)
{
    bool dataSuccess = false;
    // TODO: Complete function
    std::ifstream fileInput (inputLocation);
    if (fileInput.is_open()) {
        while (fileInput.eof()!= true) {
            std::string line;
            std::getline(fileInput, line);
            data.push_back(line);
        }
        fileInput.close();
        dataSuccess = true;
    }
    else {
        std::cout << "Error: file not found." << std::endl;
    }
    return dataSuccess;
}

// Output the vector of strings to the file
bool putData(const std::string& outputLocation, const std::vector<std::string>& data)
{
    bool dataSuccess = false;
    // TODO: Complete function
    std::ofstream fileOutput(outputLocation);
    if (fileOutput.is_open()) {
        for (int i = 0; i < data.size(); i++) {
            fileOutput << data[i] << std::endl;
        }
        fileOutput.close();
        dataSuccess = true;
    }
    return dataSuccess;
}
