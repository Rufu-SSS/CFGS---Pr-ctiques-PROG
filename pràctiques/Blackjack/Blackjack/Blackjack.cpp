#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class BlackjackGame {
public:
    BlackjackGame() : saldo(100000.0) {}  // Comença amb un saldo inicial de 100$

    void jugar() {
        cout << "Benvingut al Blackjack!\n\n";
        while (true) {
            cout << "Saldo actual: $" << saldo << "\n\n";
            if (saldo <= 0) {
                cout << "T’has quedat sense diners. El joc ha acabat.\n";
                break;
            }

            double aposta;
            cout << "Introdueix l’aposta: $";
            cin >> aposta;

            if (aposta > saldo) {
                cout << "No tens prou diners per aquesta aposta.\n\n";
                continue;
            }

            jugarMa(aposta);
            cout << "\nVols jugar de nou? (s/n): ";
            char resposta;
            cin >> resposta;
            if (resposta == 'n' || resposta == 'N') {
                break;
            }
            cout << "\n";
        }
    }

private:
    double saldo;

    int obtenirCarta() {
        return rand() % 10 + 1;
    }

    int calcularPunts(const vector<int>& cartes) {
        int total = 0;
        for (int carta : cartes) {
            total += carta;
        }
        return total;
    }

    void jugarMa(double aposta) {
        vector<int> cartesJugador;
        vector<int> cartesDealer;

        cartesJugador.push_back(obtenirCarta());
        cartesJugador.push_back(obtenirCarta());
        cartesDealer.push_back(obtenirCarta());
        cartesDealer.push_back(obtenirCarta());

        cout << "\nCartes del dealer: " << cartesDealer[0] << " ?\n";
        cout << "La teva suma de cartes: " << calcularPunts(cartesJugador) << "\n\n";

        bool jugadorEsPlantat = false;
        while (!jugadorEsPlantat && calcularPunts(cartesJugador) < 21) {
            cout << "Vols una altra carta? (s/n): ";
            char resposta;
            cin >> resposta;
            if (resposta == 's' || resposta == 'S') {
                cartesJugador.push_back(obtenirCarta());
                cout << "La teva nova suma de cartes: " << calcularPunts(cartesJugador) << "\n\n";
            }
            else {
                jugadorEsPlantat = true;
            }
        }

        int puntsJugador = calcularPunts(cartesJugador);
        if (puntsJugador > 21) {
            cout << "Has sobrepassat 21! Has perdut $" << aposta << ".\n";
            saldo -= aposta;
            return;
        }

        cout << "Cartes del dealer: ";
        for (int carta : cartesDealer) cout << carta << " ";
        cout << "(Total: " << calcularPunts(cartesDealer) << ")\n";

        while (calcularPunts(cartesDealer) < 17) {
            cartesDealer.push_back(obtenirCarta());
            cout << "El dealer agafa una altra carta. Total: " << calcularPunts(cartesDealer) << "\n";
        }

        int puntsDealer = calcularPunts(cartesDealer);
        if (puntsDealer > 21 || puntsJugador > puntsDealer) {
            cout << "Has guanyat $" << aposta << "!\n";
            saldo += aposta;
        }
        else if (puntsJugador == puntsDealer) {
            cout << "Empat! Es retorna l’aposta.\n";
        }
        else {
            cout << "Has perdut $" << aposta << ".\n";
            saldo -= aposta;
        }
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0)));

    BlackjackGame joc;
    joc.jugar();

    return 0;
}
