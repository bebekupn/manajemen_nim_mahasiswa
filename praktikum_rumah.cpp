#include<iostream>
using namespace std;

struct Mahasiswa {
    std::string nim;
    std::string nama;
    double ipk;
};

struct Node {
    Mahasiswa mhs;
    Node* next;
};

void nimTersedia(const Node* head) {

    const Node* bantu = head;

    while (bantu != nullptr) {
        cout << bantu->mhs.nim << ' ';
        bantu = bantu->next;
    }

    std::cout << "\n";
}

bool tambahAkhir(Node*& head,const Mahasiswa& data) {
    Node* bantu = head;
    Node* ekor = nullptr;

    while (bantu != nullptr) {

        if (bantu->mhs.nim == data.nim){
            return false;
        }
        ekor = bantu;
        bantu = bantu->next;
    }

    Node* baru = new Node{data, nullptr};

    if (head == nullptr) {
        head = baru;
    } else {
        ekor->next = baru;
    }

    return true;
}

Node* cariNim(Node* head, const string& nim) {

    Node* bantu = head;
    while (bantu != nullptr){

        if (bantu->mhs.nim == nim){
            return bantu;
        }

        bantu = bantu->next;
    }
    return nullptr;
}

bool hapusNim(Node*& head, const string& nim) {
    if (head == nullptr){
        return false;
    }

    Node* target = head;
    Node* sebelum = nullptr;

    while (target != nullptr && target->mhs.nim != nim){
        sebelum = target;
        target = target->next;
    }

    if (target == nullptr){
        return false;
    }

    if (sebelum == nullptr){
        head = target->next;
    }else{
        sebelum->next = target->next;
    }
    delete target;
    return true;
}

int jumlah(Node*& head){
    int jumlah = 0;
    const Node* bantu = head;

    if (bantu != nullptr){
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;

}

void clear(Node*& head) {
    while (head != nullptr) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
    }
}




int main(){
    Node* head = nullptr;
    Mahasiswa mhsBaru;
    int pilihan;

 do {
    cout << "1. Tambah\n2. Tampilkan\n3. Cari\n";
    cout << "4. Hapus\n5. Jumlah\n6. Keluar\n";
    cin >> pilihan;

    switch (pilihan){
        case 1:{
            cout << "==== tambahkan mahasiswa baru ====" <<endl;

            cout << "masukkan NIM :";
            cin >> mhsBaru.nim;

            cin.ignore();
            cout << "masukkan nama :";
            getline(cin,mhsBaru.nama);

            cout << "masukkan ipk :";
            cin >> mhsBaru.ipk;

            if(tambahAkhir(head, mhsBaru)){
                cout << "[succes] data berhasil ditambahkan" << endl;
            }else{
                cout << "[Error] nim sudah ada !!";
            }

            break;
        }
        case 2:{
            
            cout << "==== tampilkan nim yang tersedia ====" << endl;
            if (head == nullptr) {
                    cout << "NIM belum dimasukkan / data masih kosong.\n";
                } else {
                    cout << "Tampilkan NIM yang tersedia: ";
                    nimTersedia(head);
                }
            
            break;

        }
        
        case 3:{
            string cari;

            cout << "==== cari data nim yang tersedia ====" << endl;
            cout << "masukkan nim yang anda cari :";
            cin >> cari;

            Node* ditemukan = cariNim(head, cari);

            if (ditemukan == nullptr ){
                cout << "[Error]nim " << cari << " belum terdaftar!" << endl;
            }else{
                cout << "Nama : " << ditemukan->mhs.nama << endl;
                cout << "NIM : " << ditemukan->mhs.nim << endl;
                cout << "IPK : " << ditemukan->mhs.ipk << endl;
            }

            break;
        }

        case 4:{
            string cari;

            cout << "==== menghapus data mahasiswa ====" << endl;
            cout << "masukkan nim yang ingin dihapus :";
            cin >> cari;

            bool ditemukan = hapusNim(head, cari);

            if (ditemukan == false ){
                cout << "[Error]nim  "<< cari << " tidak ada!!" << endl;
            }else{
                cout << "[Succes]nim  "<< cari << "berhasil dihapus" << endl;
            }

            break;
        }

        case 5:{
            cout << "==== jumlah mahasiswa yang telah diinput ====" << endl;
            cout << jumlah(head) << " mahasiswa" << endl;
        }

        default:{

            break;

        }
    }

 } while (pilihan != 6);
 
    clear(head);
    return 0;
}