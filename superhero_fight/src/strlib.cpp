#include "strlib.h"

std::vector<std::string> strSplit(const std::string& str, char splitChar)
{
	std::vector<std::string> retval;
    
    int start = 0;
    int index = str.find(splitChar);
    
    if(index != std::string::npos) {
        //while we haven't ran out of things to split aka as long as there's a delimiter still
        while (index != std::string::npos) {
            //add things between delimiters into the vector
           retval.push_back(str.substr(start, index - start));
           start = ++index;
           index = str.find(splitChar, index);
            
            // this is so that the last item in the delimiter separated values gets included
           if (index == std::string::npos)
              retval.push_back(str.substr(start, str.length()));
        }
    }
    
    // this is in case if there's nothing that actually needs to be splitted; just automatically add to vector
    else {
        retval.push_back(str);
    }

	return retval;
}

