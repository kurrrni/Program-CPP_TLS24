#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//randomizer angka dari srand
int nomerDadu() {
    return (rand() % 6) + 1;
}
int rekening = 0;

//Function untuk game 
void playGame() {
    int tebakan, dadu1, dadu2, bet,topup;
    int winnings = 0, lost = 0;
    char topup_choice;
    
        //ngecek saldo 
        cout << "saldo anda: " << rekening << endl; 
        cout << "mau tambah saldo? (y/n): ";
        cin >> topup_choice;
            //mau top up atau ga
            if (topup_choice == 'y'){
                cout << "Masukkan nominal: ";
                cin >> topup;
                rekening += topup;
                cout << "Dana sudah masuk, saldo anda: Rp " << rekening <<endl;
            }

            //mau bet di angka berapa
            do {
                cout << "Pasan di angka berapa? (antara 2-12): "; 
                cin >> tebakan;

                if (tebakan < 2 || tebakan > 12) {
                    cout << "Gabisa gitu bang, antara 2-12 dong!\n";
                }
            } while (tebakan < 2 || tebakan > 12);

    //masukin nominal bet
    cout << "pasang berapa? "; 
    cin >> bet;

    dadu1 = nomerDadu();
    dadu2 = nomerDadu();

    //hasil dari randomizer
    int sum = dadu1 + dadu2;
    cout << "diceroll: " << dadu1 << " dan " << dadu2 << endl;
    cout << "Total: " << sum <<  endl;

    //menang atau tidak
    if (sum == tebakan) {
        int winnings = bet*sum;
        rekening += winnings;
        cout << "SELAMAT KAMU MENANG!!!\n" ;
        cout << "Kamu menang: " << winnings << endl;
    
    } else {
        rekening -= bet;
        cout << "Sayang Anda kurang hoki\n";
        cout << "kamu kehilangan " << bet << endl;
    }
    cout << "saldo sekarang: "<< rekening << endl;
}

//main function
int main() { 
    //masukin angka ke randomizer
    srand(static_cast<unsigned int>(time(0))); 
    char playAgain;

    do {
        playGame();
        cout << "Judi lagi? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Jangan judi ya ges ya" << endl;
    return 0;
}
//done