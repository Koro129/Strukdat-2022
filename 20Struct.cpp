// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

struct data {
    string nama;
    int no;
    float dec;
    int arr[3];
};

int main() {
    struct data d[20];
    for(int i=0; i<20; i++){
        d[i].nama=char(65+i);
        d[i].no=i;
        d[i].dec=i/2.5;
        for(int j=0; j<3; j++){
            d[i].arr[j]=d[i].no+j;
        }
    }
    for(int i=0; i<20; i++){
        cout<<"=== Data ke-"<<i+1<<" ===="<<endl ;
        cout<<"nama = "<<d[i].nama<<endl;
        cout<<"no = "<<d[i].no<<endl;
        cout<<"dec = "<<d[i].dec<<endl;
        cout<<"arr = ";
        for(int j=0; j<2; j++){
            cout<<d[i].arr[j]<<", ";
        }
        cout<<d[i].arr[2]<<endl;
    }
    return 0;
}