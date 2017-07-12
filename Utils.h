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
    template<typename T>
    inline bool concatVec(vector<T> &vector1,vector<T> &vector2){
        vector1.insert( vector1.end(), vector2.begin(), vector2.end() );
        return true;
    }
}

#endif
