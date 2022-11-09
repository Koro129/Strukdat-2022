#include <iostream>
using namespace std;

class MHS{
    private:
    string MHSname;
    public:
    // MHS(string name);
    MHS(string nama){
        MHSname = nama;
        cout << MHSname;
    }
};

int main() {
    MHS mhs1("jajan");
    
    return 0;
}