// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

//deklarasi linked list
struct game{
    string name;
    int year;
    game *next;
};

game *head, *tail, *cur, *newNode, *del, *before;

//Buat single linked list
void createSSL(string name, int year){
    head = new game();
    head->name = name;
    head->year = year;
    head->next = NULL;
    tail = head;
}

//Hitung isi single linked list
int countSSL(){
    int count = 0;
    cur = head;
    while(cur != NULL){
        count++;
        cur = cur->next;
    }
    return count;
}

//Cetak single linked list
void printSSL(){
    cout << "Jumlah Data = " << countSSL() << endl;
    cur = head;
    while(cur != NULL){
        cout << "Nama : " << cur->name << endl;
        cout << "Tahun : " << cur->year << endl;
        cur = cur->next;
    }
}

//Tambah awal SSL
void addFirst(string name, int year){
    newNode = new game();
    newNode->name = name;
    newNode->year = year;
    newNode->next = head;
    head = newNode;
}

//Tambah tengah SSL
void addMid(string name, int year, int pos){
    if(pos < 1 || pos > countSSL()) cout << "Tidak ada posisi tersebut" << endl;
    else if(pos == 1) cout << "Bukan posisi tengah" << endl;
    else{
        newNode = new game();
        newNode->name = name;
        newNode->year = year;
        
        //Transversing
        int count = 1;
        cur = head;
        while (count < pos-1){
            cur = cur->next;
            count++;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }
}

//Tambah akhir SSL
void addLast(string name, int year){
    newNode = new game();
    newNode->name = name;
    newNode->year = year;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

//Hapus Awal SSL
void delFirst(){
    del = head;
    head = head->next;
    delete del;
}

//Hapus tengah SSL
void delMid(int pos){
    if(pos < 1 || pos > countSSL()) cout << "Tidak ada posisi tersebut" << endl;
    else if(pos == 1) cout << "Bukan posisi tengah" << endl;
    else{
        int count = 1;
        cur = head;
        while(count <= pos){
            if(count == pos - 1) before = cur;
            if(count == pos) del = cur;
            cur = cur->next;
            count++;
        }
        before->next = cur;
        delete del;
    }
}

//Hapus akhir SSL
void delLast(){
    del = tail;
    cur = head;
    while(cur->next != tail) cur = cur->next;
    tail = cur;
    tail->next = NULL;
    delete del;
}

//Ubah awal SSL
void changeFirst(string name, int year){
    head->name = name;
    head->year = year;
}

//Ubah tengah SSL
void changeMid(string name, int year, int pos){
    if(pos < 1 || pos > countSSL()) cout << "Tidak ada posisi tersebut" << endl;
    else if(pos == 1) cout << "Bukan posisi tengah" << endl;
    else{
        int count = 1;
        cur = head;
        while(count < pos){
            cur = cur->next;
            count++;
        }
        cur->name = name;
        cur->year = year;
    }
}

//Ubah akhir SSL
void changeLast(string name, int year){
    tail->name = name;
    tail->year = year;
}

int main() {
    createSSL("The Witcher 3", 2015);
    addFirst("Press Any Button", 2021);
    addLast("The Awesome Adventures of Captain Spirit", 2018);
    addMid("Yakuza 0", 2018, 2);
    addFirst("Monster Hunter: World", 2018);
    addLast("Ni no Kuni Wrath of the White Witch™ Remastered", 2019);
    addMid("Black Desert", 2019, 4);
    addFirst("Coffee Talk", 2020);
    printSSL();
    cout << endl;
    delFirst();
    delMid(2);
    delLast();
    printSSL();
    cout << endl;
    changeFirst("Code Vein", 2019);
    changeMid("METAL GEAR SOLID V: THE PHANTOM PAIN", 2015, 3);
    changeLast("Batman™: Arkham Knight", 2015);
    printSSL();
    
    return 0;
}