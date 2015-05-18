#include <iostream>

using namespace std;

class A {
public:
        A(const int d){
                data = d;
        }
        void showdata(){
                cout << "data=" << data << endl;
        }
private:
        int data;
};

int main(int argc, char * argv[])
{
        A a(1);
        a.showdata();

        return 0;
}
