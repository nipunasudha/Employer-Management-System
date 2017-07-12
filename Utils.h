#ifndef UTILS
#define UTILS


#include<string>
#include<sstream>
#include<iostream>
#include<vector>



using namespace std;
namespace utils{
    inline string helpText(){

        return "Help\r\n------------------------------------\r\n1. [list_all]           List all the employees\r\n2. [list_monthly_pay]   List the monthly pay amounts\r\n3. [get_total_pay]      Get total statistics\r\n4. [get_details <id>]   Get details of a worker\r\n5. [remove <id>]        Remove a worker\r\n6. [exit]               Exit from software\r\n7. [help]               Help section";
    }
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
        inline bool concatVec(vector<T> &vector1,vector<T> vector2){
            vector1.insert( vector1.end(), vector2.begin(), vector2.end() );
            return true;
        }
}

#endif
