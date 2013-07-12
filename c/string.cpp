#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){

    cout << "sizeof(string)=" << sizeof(string) << endl;

    string strArr1[] = 
    {"Trend","Micro","Soft"};
    cout << "sizeof(strArr1)=" << sizeof( strArr1 ) << endl;

    string *pStrArr1 = new string[2];
    cout << "sizeof(*pStrArr1)=" << sizeof( *pStrArr1 ) << endl;

    pStrArr1[0] = "US";
    pStrArr1[1] = "CN";

    for( int i =0; i<sizeof(strArr1) / sizeof(string) ; i++)
        cout << strArr1[i];
    for( int j =0; j<sizeof(*pStrArr1)*2 / sizeof(string) ; j++)
        cout << pStrArr1[j];

    cout << endl;
}

