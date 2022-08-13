#include <iostream>
#include <iomanip>

#include <cstdlib>
#include <ctime>

#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector <unsigned short int> pozicija_trenutnog_najmanjeg_elementa(const vector <vector<double> > &matrica_brojeva,
                                                                  const unsigned short int &pocetak_reda,
                                                                  const unsigned short int &poslije_kraja_reda,
                                                                  const unsigned short int &pocetak_kolone,
                                                                  const unsigned short int &poslije_kraja_kolone,
                                                                  const unsigned short int &srednji_red,
                                                                  const unsigned short int &srednja_kolona);

bool je_li_lokalni_minimum(const vector <vector<double> > &matrica_brojeva, const unsigned short int pocetak_reda,
                           const unsigned short int &poslije_kraja_reda, const unsigned short int &pocetak_kolone,
                           const unsigned short int &poslije_kraja_kolone, const unsigned short int &red,
                           const unsigned short int &kolona) noexcept;

vector <unsigned short int> pozicija_lokalnog_minimuma(const vector<vector <double> > &matrica_brojeva,
                                                       unsigned short int &pocetak_reda,
                                                       unsigned short int &poslije_kraja_reda,
                                                       unsigned short int &pocetak_kolone,
                                                       unsigned short int &poslije_kraja_kolone);

vector <unsigned short int> trazi_lokalni_minimum(const vector <vector<double> > &matrica_brojeva) noexcept;
void unos_matrice(vector <vector<double> > &matrica_brojeva, const unsigned short int &n);
vector <vector<double> > generisanje_nasumicne_matrice(const unsigned short int &n)  noexcept;
void ispis_matrice(const vector <vector<double> > &matrica_brojeva)   noexcept;
void korisnicki_interface();


int main()
{
    /*vector <vector <double> > matrica{{25, 24, 33, 22, 21}, {40, 50, 48, 99, 20}, {15, 16, 17, 18, 19}, {14, 31, 37, 105, 206}, {13, 12, 11, 10, 9}};
    vector <unsigned short> lokalni_minimum(trazi_lokalni_minimum(matrica));
    cout << lokalni_minimum[0] << " " << lokalni_minimum[1] << " " << matrica[lokalni_minimum[0]][lokalni_minimum[1]];*/

    try
    {
        korisnicki_interface();
    }
    catch (const char *poruka)
    {
        cout << poruka;
    }
    return 0;
}


vector <unsigned short int> pozicija_trenutnog_najmanjeg_elementa(const vector<vector <double> > &matrica_brojeva,
                                                                  const unsigned short int &pocetak_reda,
                                                                  const unsigned short int &poslije_kraja_reda,
                                                                  const unsigned short int &pocetak_kolone,
                                                                  const unsigned short int &poslije_kraja_kolone,
                                                                  const unsigned short int &srednji_red,
                                                                  const unsigned short int &srednja_kolona)
{
    vector <unsigned short int> indeksi_najmanjeg_elementa{srednji_red, srednja_kolona, 8};
    double najmanji_element_vektora(matrica_brojeva[srednji_red][srednja_kolona]);

    for (unsigned short int red(pocetak_kolone); red < srednji_red; red++)
    {
        if (matrica_brojeva[red][srednja_kolona] < najmanji_element_vektora)
        {
            indeksi_najmanjeg_elementa[0] = red;
            najmanji_element_vektora = matrica_brojeva[red][srednja_kolona];
        }
    }
    for (unsigned short int kolona(pocetak_reda); kolona < srednja_kolona; kolona++)
    {
        if (matrica_brojeva[srednji_red][kolona] < najmanji_element_vektora)
        {
            indeksi_najmanjeg_elementa[0] = srednji_red;
            indeksi_najmanjeg_elementa[1] = kolona;
            indeksi_najmanjeg_elementa[2] = 4;
            najmanji_element_vektora = matrica_brojeva[srednji_red][kolona];
        }
    }
    for (unsigned short int kolona(srednja_kolona+1); kolona < poslije_kraja_reda; kolona++)
    {
        if (matrica_brojeva[srednji_red][kolona] < najmanji_element_vektora)
        {
            indeksi_najmanjeg_elementa[0] = srednji_red;
            indeksi_najmanjeg_elementa[1] = kolona;
            indeksi_najmanjeg_elementa[2] = 6;
            najmanji_element_vektora = matrica_brojeva[srednji_red][kolona];
        }
    }
    for (unsigned short int red(srednji_red+1); red < poslije_kraja_kolone; red++)
    {
        if (matrica_brojeva[red][srednja_kolona] < najmanji_element_vektora)
        {
            indeksi_najmanjeg_elementa[0] = red;
            indeksi_najmanjeg_elementa[1] = srednja_kolona;
            indeksi_najmanjeg_elementa[2] = 2;
            najmanji_element_vektora = matrica_brojeva[red][srednja_kolona];
        }
    }
    return indeksi_najmanjeg_elementa;
}

bool je_li_lokalni_minimum(const vector <vector<double> > &matrica_brojeva, const unsigned short int pocetak_reda,
                           const unsigned short int &poslije_kraja_reda, const unsigned short int &pocetak_kolone,
                           const unsigned short int &poslije_kraja_kolone, const unsigned short int &red,
                           const unsigned short int &kolona)    noexcept
{
    vector <double> okolni_elementi;
    if (red - 1 >= pocetak_kolone) okolni_elementi.push_back(matrica_brojeva[red-1][kolona]);
    if (red + 1 < poslije_kraja_kolone) okolni_elementi.push_back(matrica_brojeva[red+1][kolona]);
    if (kolona - 1 >= pocetak_reda) okolni_elementi.push_back(matrica_brojeva[red][kolona-1]);
    if (kolona + 1 < poslije_kraja_reda) okolni_elementi.push_back(matrica_brojeva[red][kolona+1]);

    if (okolni_elementi.empty()) return true;
    else
    {
        for (double element : okolni_elementi)
        {
            if (matrica_brojeva[red][kolona] > element) return false;
        }
        return true;
    }
}

vector <unsigned short int> pozicija_lokalnog_minimuma(const vector<vector <double> > &matrica_brojeva,
                                                       unsigned short int &pocetak_reda,
                                                       unsigned short int &poslije_kraja_reda,
                                                       unsigned short int &pocetak_kolone,
                                                       unsigned short int &poslije_kraja_kolone)
{
    unsigned short int srednji_red(((poslije_kraja_kolone - pocetak_kolone) / 2) + pocetak_kolone),
            srednja_kolona(((poslije_kraja_reda - pocetak_reda) / 2) + pocetak_reda);

    vector <unsigned short int> indeksi_lokalnog_minimuma_matrice(2, 0);
    if (je_li_lokalni_minimum(matrica_brojeva, pocetak_reda, poslije_kraja_reda, pocetak_kolone,
                              poslije_kraja_kolone, srednji_red, srednja_kolona)) // Za srednji element.
    {
        indeksi_lokalnog_minimuma_matrice[0] = srednji_red;
        indeksi_lokalnog_minimuma_matrice[1] = srednja_kolona;
        return indeksi_lokalnog_minimuma_matrice;
    }

    vector <unsigned short int> pozicija_elementa
            (pozicija_trenutnog_najmanjeg_elementa(matrica_brojeva, pocetak_reda, poslije_kraja_reda, pocetak_kolone,
                                                   poslije_kraja_kolone, srednji_red, srednja_kolona));

    unsigned short int red_elementa(pozicija_elementa[0]), kolona_elementa(pozicija_elementa[1]), smjer(pozicija_elementa[2]);
    if (je_li_lokalni_minimum(matrica_brojeva, pocetak_reda, poslije_kraja_reda, pocetak_kolone,
                              poslije_kraja_kolone, red_elementa, kolona_elementa))   // Za srednji red i kolonu.
    {
        indeksi_lokalnog_minimuma_matrice[0] = red_elementa;
        indeksi_lokalnog_minimuma_matrice[1] = kolona_elementa;
        return indeksi_lokalnog_minimuma_matrice;
    }

    if (smjer == 8) // Gore
    {
        if (kolona_elementa + 1 < poslije_kraja_reda)   // Ako ima desni element.
        {
            if (matrica_brojeva[red_elementa][kolona_elementa-1] <= matrica_brojeva[red_elementa][kolona_elementa+1])   // Ako je lijvei manji od desnog.
            {
                poslije_kraja_reda = kolona_elementa;
                poslije_kraja_kolone = kolona_elementa;
                if (je_li_lokalni_minimum(matrica_brojeva, pocetak_reda, poslije_kraja_reda,
                                          pocetak_kolone, poslije_kraja_kolone, red_elementa, kolona_elementa - 1))
                {
                    indeksi_lokalnog_minimuma_matrice[0] = red_elementa;
                    indeksi_lokalnog_minimuma_matrice[1] = kolona_elementa - 1;
                    return indeksi_lokalnog_minimuma_matrice;
                }
                return pozicija_lokalnog_minimuma(matrica_brojeva, pocetak_reda, poslije_kraja_reda,
                                                  pocetak_kolone, poslije_kraja_kolone);
            }
            else    // Ako je desni manji od lijevog.
            {
                pocetak_reda = kolona_elementa + 1;
                poslije_kraja_kolone = kolona_elementa + 1;
                if (je_li_lokalni_minimum(matrica_brojeva, pocetak_reda, poslije_kraja_reda,
                                          pocetak_kolone, poslije_kraja_kolone, red_elementa,kolona_elementa + 1))
                {
                    indeksi_lokalnog_minimuma_matrice[0] = red_elementa;
                    indeksi_lokalnog_minimuma_matrice[1] = kolona_elementa + 1;
                    return indeksi_lokalnog_minimuma_matrice;
                }
                return pozicija_lokalnog_minimuma(matrica_brojeva, pocetak_reda, poslije_kraja_reda,
                                                  pocetak_kolone, poslije_kraja_kolone);
            }
        }
        else    // Ako nema desni element.
        {
            poslije_kraja_reda = kolona_elementa;
            poslije_kraja_kolone = kolona_elementa;
            if (je_li_lokalni_minimum(matrica_brojeva, pocetak_reda, poslije_kraja_reda, pocetak_kolone,
                                      poslije_kraja_kolone, red_elementa, kolona_elementa - 1))
            {
                indeksi_lokalnog_minimuma_matrice[0] = red_elementa;
                indeksi_lokalnog_minimuma_matrice[1] = kolona_elementa - 1;
                return indeksi_lokalnog_minimuma_matrice;
            }
            return pozicija_lokalnog_minimuma(matrica_brojeva, pocetak_reda,poslije_kraja_reda,
                                              pocetak_kolone,poslije_kraja_kolone);
        }
    }
    else if (smjer == 2)    // Dole.
    {
        if (kolona_elementa + 1 < poslije_kraja_reda)
        {
            if (matrica_brojeva[red_elementa][kolona_elementa-1] <= matrica_brojeva[red_elementa][kolona_elementa+1] )
            {
                pocetak_kolone = kolona_elementa + 1;
                poslije_kraja_reda = kolona_elementa;
                if (je_li_lokalni_minimum(matrica_brojeva, pocetak_reda, poslije_kraja_reda,
                                          pocetak_kolone, poslije_kraja_kolone, red_elementa,kolona_elementa - 1))
                {
                    indeksi_lokalnog_minimuma_matrice[0] = red_elementa;
                    indeksi_lokalnog_minimuma_matrice[1] = kolona_elementa - 1;
                    return indeksi_lokalnog_minimuma_matrice;
                }
                return pozicija_lokalnog_minimuma(matrica_brojeva, pocetak_reda, poslije_kraja_reda,
                                                  pocetak_kolone, poslije_kraja_kolone);
            }
            else
            {
                pocetak_reda = kolona_elementa + 1;
                pocetak_kolone = kolona_elementa + 1;
                if (je_li_lokalni_minimum(matrica_brojeva, pocetak_reda, poslije_kraja_reda,
                                          pocetak_kolone, poslije_kraja_kolone, red_elementa,kolona_elementa + 1))
                {
                    indeksi_lokalnog_minimuma_matrice[0] = red_elementa;
                    indeksi_lokalnog_minimuma_matrice[1] = kolona_elementa + 1;
                    return indeksi_lokalnog_minimuma_matrice;
                }
                return pozicija_lokalnog_minimuma(matrica_brojeva, pocetak_reda, poslije_kraja_reda,
                                                  pocetak_kolone, poslije_kraja_kolone);
            }
        }
        else
        {
            pocetak_kolone = kolona_elementa + 1;
            poslije_kraja_reda = kolona_elementa;
            if (je_li_lokalni_minimum(matrica_brojeva, pocetak_reda, poslije_kraja_reda,
                                      pocetak_kolone, poslije_kraja_kolone, red_elementa,kolona_elementa - 1))
            {
                indeksi_lokalnog_minimuma_matrice[0] = red_elementa;
                indeksi_lokalnog_minimuma_matrice[1] = kolona_elementa - 1;
                return indeksi_lokalnog_minimuma_matrice;
            }
            return pozicija_lokalnog_minimuma(matrica_brojeva, pocetak_reda, poslije_kraja_reda,
                                              pocetak_kolone, poslije_kraja_kolone);
        }
    }
    else if (smjer == 4)    // Lijevo.
    {
        if (red_elementa + 1 < poslije_kraja_kolone)
        {
            if (matrica_brojeva[red_elementa-1][kolona_elementa] <= matrica_brojeva[red_elementa+1][kolona_elementa])
            {
                poslije_kraja_reda = red_elementa;
                poslije_kraja_kolone = red_elementa;
                if (je_li_lokalni_minimum(matrica_brojeva, pocetak_reda, poslije_kraja_reda,
                                          pocetak_kolone, poslije_kraja_kolone,red_elementa - 1, kolona_elementa))
                {
                    indeksi_lokalnog_minimuma_matrice[0] = red_elementa - 1;
                    indeksi_lokalnog_minimuma_matrice[1] = kolona_elementa;
                    return indeksi_lokalnog_minimuma_matrice;
                }
                return pozicija_lokalnog_minimuma(matrica_brojeva, pocetak_reda, poslije_kraja_reda,
                                                  pocetak_kolone, poslije_kraja_kolone);
            }
            else
            {
                pocetak_kolone = red_elementa + 1;
                poslije_kraja_reda = red_elementa;
                if (je_li_lokalni_minimum(matrica_brojeva, pocetak_reda, poslije_kraja_reda,
                                          pocetak_kolone, poslije_kraja_kolone,red_elementa + 1, kolona_elementa))
                {
                    indeksi_lokalnog_minimuma_matrice[0] = red_elementa + 1;
                    indeksi_lokalnog_minimuma_matrice[1] = kolona_elementa;
                    return indeksi_lokalnog_minimuma_matrice;
                }
                return pozicija_lokalnog_minimuma(matrica_brojeva, pocetak_reda, poslije_kraja_reda,
                                                  pocetak_kolone, poslije_kraja_kolone);
            }
        }
        else
        {
            poslije_kraja_reda = red_elementa;
            poslije_kraja_kolone = red_elementa;
            if (je_li_lokalni_minimum(matrica_brojeva, pocetak_reda, poslije_kraja_reda, pocetak_kolone,
                                      poslije_kraja_kolone,red_elementa - 1, kolona_elementa))
            {
                indeksi_lokalnog_minimuma_matrice[0] = red_elementa - 1;
                indeksi_lokalnog_minimuma_matrice[1] = kolona_elementa;
                return indeksi_lokalnog_minimuma_matrice;
            }
            return pozicija_lokalnog_minimuma(matrica_brojeva, pocetak_reda,poslije_kraja_reda,
                                              pocetak_kolone, poslije_kraja_kolone);
        }
    }
    else if (smjer == 6)    // Desno.
    {
        if (red_elementa + 1 < poslije_kraja_kolone)
        {
            if (matrica_brojeva[red_elementa-1][kolona_elementa] <= matrica_brojeva[red_elementa+1][kolona_elementa])
            {
                pocetak_reda = red_elementa + 1;
                poslije_kraja_kolone = red_elementa;
                if (je_li_lokalni_minimum(matrica_brojeva, pocetak_reda, poslije_kraja_reda, pocetak_kolone,
                                          poslije_kraja_kolone,red_elementa - 1, kolona_elementa))
                {
                    indeksi_lokalnog_minimuma_matrice[0] = red_elementa - 1;
                    indeksi_lokalnog_minimuma_matrice[1] = kolona_elementa;
                    return indeksi_lokalnog_minimuma_matrice;
                }
                return pozicija_lokalnog_minimuma(matrica_brojeva, pocetak_reda, poslije_kraja_reda,
                                                  pocetak_kolone, poslije_kraja_kolone);
            }
            else
            {
                pocetak_reda = red_elementa + 1;
                pocetak_kolone = red_elementa + 1;
                if (je_li_lokalni_minimum(matrica_brojeva, pocetak_reda, poslije_kraja_reda, pocetak_kolone,
                                          poslije_kraja_kolone,red_elementa + 1, kolona_elementa))
                {
                    indeksi_lokalnog_minimuma_matrice[0] = red_elementa + 1;
                    indeksi_lokalnog_minimuma_matrice[1] = kolona_elementa;
                    return indeksi_lokalnog_minimuma_matrice;
                }
                return pozicija_lokalnog_minimuma(matrica_brojeva, pocetak_reda, poslije_kraja_reda,
                                                  pocetak_kolone, poslije_kraja_kolone);
            }
        }
        else
        {
            pocetak_reda = red_elementa + 1;
            poslije_kraja_kolone = red_elementa;
            if (je_li_lokalni_minimum(matrica_brojeva, pocetak_reda, poslije_kraja_reda, pocetak_kolone,
                                      poslije_kraja_kolone,red_elementa - 1, kolona_elementa))
            {
                indeksi_lokalnog_minimuma_matrice[0] = red_elementa - 1;
                indeksi_lokalnog_minimuma_matrice[1] = kolona_elementa;
                return indeksi_lokalnog_minimuma_matrice;
            }
            return pozicija_lokalnog_minimuma(matrica_brojeva, pocetak_reda, poslije_kraja_reda,
                                              pocetak_kolone, poslije_kraja_kolone);
        }
    }
    return vector<unsigned short>();
}


vector <unsigned short int> trazi_lokalni_minimum(const vector <vector<double> > &matrica_brojeva)  noexcept
{
    unsigned short int pocetak_reda(0), poslije_kraja_reda(matrica_brojeva.size()), pocetak_kolone(0),
            poslije_kraja_kolone(matrica_brojeva.size());
    return pozicija_lokalnog_minimuma(matrica_brojeva, pocetak_reda, poslije_kraja_reda,
                                      pocetak_kolone,poslije_kraja_kolone);
}

void unos_matrice(vector <vector<double> > &matrica_brojeva, const unsigned short int &n)
{
    cout << "Vrijednosti matrice unosite red po red.\n" << endl;
    cin.clear();
    cin.ignore(10000, '\n');
    for (unsigned int i(0); i < n; i++)
    {
        cout << "Unesite " <<  i+1 << "." << " red:\n";
        string red;
        getline(cin, red);
        stringstream konvertovanje(red);
        vector <double> red_matrice;
        double x;
        while (konvertovanje >> x)
        {
            red_matrice.push_back(x);
            if (konvertovanje.peek() == ' ') konvertovanje.ignore();
        }
        if (red_matrice.size() != n) throw "Doslo je do problema sa unosom kvadratne matrice. Molimo ponovo pokrenite program.";
        matrica_brojeva.push_back(red_matrice);
    }
}

vector <vector<double> > generisanje_nasumicne_matrice(const unsigned short int &n)  noexcept
{
    vector < vector<double> > nasumicna_matrica;
    double nasumicni_realni_broj;
    const double donja_granica(-1000.0);
    const double gornja_granica(1001.0);
    srand(time(nullptr));

    for (unsigned short int i(0); i < n; i++)
    {
        vector <double> red_matrice;
        for (unsigned short int j(0); j < n; j++)
        {
            nasumicni_realni_broj = (double)(rand()) / ((double)(RAND_MAX/(gornja_granica -
                                                                           donja_granica)))+donja_granica;
            red_matrice.push_back(nasumicni_realni_broj);
        }
        nasumicna_matrica.push_back(red_matrice);
    }
    return nasumicna_matrica;
}

void ispis_matrice(const vector <vector<double> > &matrica_brojeva)   noexcept
{
    const unsigned short int n(matrica_brojeva.size());
    for (unsigned short int i(0); i < n; i++)
    {
        for (unsigned short int j(0); j < n; j++)
        {
            cout << setw(10) << setprecision(5) <<  matrica_brojeva[i][j];
        }
        cout << endl;
    }
}

void korisnicki_interface()
{
    cout << "Dobar dan. Trenutno koristite program za pronalazak lokalnog minimuma kvadratne matrice.\n";
    while (true)
    {
        cout << "\nUkoliko zelite izaci, ukucajte 'EXIT'. Ukoliko zelite nastaviti sa koristenjem programa, ukucajte 'CONTINUE'.\n";
        string odgovor;
        while (true)
        {
            cin >> odgovor;
            if (odgovor.compare("EXIT") == 0 || odgovor.compare("CONTINUE") == 0)
            {
                break;
            }
            else
            {
                cout << "Molimo unesite jednu od predlozenih rijeci." << endl;
            }
        }
        if (odgovor.compare("EXIT") == 0)
        {
            exit(0);
        }
        else
        {
            cout << endl;
            cout << "Ukoliko zelite unijeti proizvoljnu matricu, ukucajte 'PROIZVOLJNA'.\n"
                    "Ukoliko zelite generisati matricu nasumicnih brojeva, ukucajte 'NASUMICNA'.\n";
            string vrsta_matrice;
            while (true)
            {
                cin >> vrsta_matrice;
                if (vrsta_matrice.compare("PROIZVOLJNA") == 0 || vrsta_matrice.compare("NASUMICNA") == 0)
                {
                    break;
                }
                else
                {
                    cout << "Molimo unesite jednu od dvije predlozene rijeci." << endl;
                }
            }
            cout << endl;
            if (vrsta_matrice.compare("PROIZVOLJNA") == 0)
            {
                cout << "Unesite dimenziju kvadratne matrice: ";
                int dimenzija_matrice;
                while (!(cin >> dimenzija_matrice) || dimenzija_matrice <= 0)
                {
                    cout << "Dimenzija matrice mora biti prirodan broj. Ponovo unesite dimenziju matrice: \n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }

                vector <vector<double> > matrica_realnih_brojeva;
                unos_matrice(matrica_realnih_brojeva, dimenzija_matrice);
                const vector <unsigned short int> lokalni_minimum_matrice(trazi_lokalni_minimum(matrica_realnih_brojeva));
                cout << "Indeksi lokalnog minimuma unesene matrice\n" << endl;
                ispis_matrice(matrica_realnih_brojeva);
                cout << endl << "\n su " << lokalni_minimum_matrice[0] << " i " << lokalni_minimum_matrice[1] << "." << endl;
                cout << "Lokalni minimum navedene matrice na datim indeksima iznosi " <<
                     matrica_realnih_brojeva[lokalni_minimum_matrice[0]][lokalni_minimum_matrice[1]] << "." << endl << endl;
            }
            else
            {
                cout << "Unesite dimenziju kvadratne matrice: ";
                int dimenzija_matrice;
                while (!(cin >> dimenzija_matrice) || dimenzija_matrice <= 0)
                {
                    cout << "Dimenzija matrice mora biti prirodan broj. Ponovo unesite dimenziju matrice: \n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }

                const vector <vector<double> > nasumicna_matrica(generisanje_nasumicne_matrice(dimenzija_matrice));
                const vector <unsigned short int> lokalni_minimum_matrice(trazi_lokalni_minimum(nasumicna_matrica));
                cout << "Indeksi lokalnog minimuma nasumicne matrice\n" << endl;
                ispis_matrice(nasumicna_matrica);
                cout << endl << "\n su " << lokalni_minimum_matrice[0] << " i " << lokalni_minimum_matrice[1] << "." << endl;
                cout << "Lokalni minimum navedene matrice na datim indeksima iznosi " <<
                     nasumicna_matrica[lokalni_minimum_matrice[0]][lokalni_minimum_matrice[1]] << "." << endl << endl;
            }
            cout << "------------------------------------------------------------------------------------" << endl;
        }

        cout << "Zelite li nastaviti sa koristenjem programa?   (DA/NE)\n";
        while (true)
        {
            cin >> odgovor;
            if (odgovor.compare("DA") == 0 || odgovor.compare("NE") == 0)
            {
                break;
            }
            else
            {
                cout << "Molimo unesite jednu od predlozenih rijeci." << endl;
            }
        }
        if (odgovor.compare("NE") == 0)
        {
            cout << "Zahvaljujemo na koristenju naseg programa.";
            exit(0);
        }
    }
}