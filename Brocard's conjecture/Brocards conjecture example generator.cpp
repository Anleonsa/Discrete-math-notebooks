#include<iostream>
#include<queue>
#include<vector>

using namespace std;

#define ll long long

// Lista donde se guardan los primos en orden
vector<ll> primes = {2, 3, 5, 7, 11, 13, 17, 19};

// Función para saber si un x es el siguiente primo de la lista
bool isNextPrime (ll x) {
    for (int i = 0; i < primes.size() && primes[i]*primes[i] <= x; i++) {
        if (x % primes[i] == 0) return false;
    }
    return true;
}

// Función para rellenar la lista hasta que tenga n primos
void fillPrimesUntilN (int n) {
    ll primeCandidate = primes[primes.size() - 1];

    while (primes.size() < n) {
        primeCandidate += 2;

        if (isNextPrime(primeCandidate)) {
            primes.push_back(primeCandidate);
        }
    }
}

// Función para comprobar si x contiene un divisor en la lista de primos
bool hasPrimeDivisor (ll x) {
    for (int i = 0; i < primes.size() && primes[i]*primes[i] <= x; i++) {
        if (x % primes[i] == 0) return true;
    }
    return false;
}

void solve() {
    while (true) {
        cout << "Ingresa un n mayor o igual a 2. en caso de ingresar un n menor a 2, el programa terminara\n";
        cout.flush();
        
        int n; cin >> n;
        cout << "\n";
        if (n < 2) break;
        
        fillPrimesUntilN(n + 1);

        ll leftLimit = primes[n - 1]*primes[n - 1];
        ll rightLimit = primes[n]*primes[n];

        queue<ll> answer;

        for (ll i = leftLimit + 1; i < rightLimit; i++) {
            if (!hasPrimeDivisor(i)) answer.push(i);
        }

        cout << "El primo numero " << n << " es el " << primes[n - 1] << "\n";
        cout << "El primo numero " << (n + 1) << " es el " << primes[n] << "\n";
        cout << "La cantidad de primos entre " << leftLimit << " y " << rightLimit;
        cout << " es: " << answer.size() << "\n";
        cout << "Y son:\n";

        while (!answer.empty()) {
            cout << answer.front() << " ";
            answer.pop();
        }
        cout << "\n- - - - - - - // - - - - - - // - - - - - - // - - - - -\n\n";

        cout.flush();
    }

}

signed main () {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}