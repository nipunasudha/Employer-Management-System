#ifndef UTILS
#define UTILS


#include<string>
#include<sstream>
#include<iostream>
#include<vector>



using namespace std;
namespace utils{

    inline vector<string> splitt(string str, char delimiter)
    {
        vector<string> internal;
        stringstream ss(str); // Turn the string into a stream.
        string tok;
        if (str.find(delimiter) == string::npos){
            internal.push_back(str);
            return internal;
        }
        while(getline(ss, tok, delimiter)) {
            internal.push_back(tok);
        }

        return internal;
    }

    inline void cls(){
        cout << "\033[2J\033[1;1H";
    }
}

#endif
