#include <iostream>

void hanoi(int n, char origen, char destino, char auxiliar) {
    if (n == 1) {
        std::cout << "Mover disco de " << origen << " a " << destino << std::endl;
    } else {
        hanoi(n-1, origen, auxiliar, destino);
        std::cout << "Mover disco de " << origen << " a " << destino << std::endl;
        hanoi(n-1, auxiliar, destino, origen);
    }
}

int main() {
    int num_discos = 3;
    hanoi(num_discos, 'A', 'C', 'B');
    return 0;
}
