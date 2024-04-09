﻿#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Takim {
    string adi;
    int puanlar;
};

bool karsilastirTakimlar(const Takim& a, const Takim& b) {
    return a.puanlar > b.puanlar;
}
int main() {
    ifstream girisDosyasi("giris.txt");

    if (!girisDosyasi) {
        cerr << "Hata: Giriş dosyası açılamadı\n";
        return 1;
    }

    vector<Takim> takimlar;
    Takim takim;

    while (girisDosyasi >> takim.adi >> takim.puanlar) {
        takimlar.push_back(takim);
    }

    girisDosyasi.close();

    // Takımları puanlarına göre sırala
    sort(takimlar.begin(), takimlar.end(), karsilastirTakimlar);

    ofstream cikisDosyasi("cikis.txt");

    if (!cikisDosyasi) {
        cerr << "Hata: Çıkış dosyası oluşturulamadı\n";
        return 1;
    }

    // Sıralı takımları çıkış dosyasına yazdır
    cikisDosyasi << "Sıra\tTakım adı\tPuanlar\n";
    for (int i = 0; i < takimlar.size(); ++i) {
        cikisDosyasi << i + 1 << "\t" << takimlar[i].adi << "\t" << takimlar[i].puanlar << "\n";
    }

    cikisDosyasi.close();

    cout << "Takımlar başarıyla sıralandı ve cikis.txt dosyasına yazıldı.\n";

    // Console'un kapanmasını engellemek için bir tuşa basılmasını bekleyin
    cout << "Programdan cikmak icin bir tusa basin...";
    cin.get();

    return 0;
}
