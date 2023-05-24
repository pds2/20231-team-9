#include <iostream>
#include <vector>

#include "./include/participante.h"

int main() {
    int n_participantes;
    cin >> n_participantes;

    vector<Participante *> participantes;

    Mapa jogo;
    for(int i = 0; i < n_participantes; i++) {
        while(1) {
            string nome;
            int idade, distrito;
            cin >> nome >> idade >> distrito;

            try{
                jogo.criar_participante(nome, idade, distrito);
            } catch(participante_ja_existe_e &e) {
                cout << "Participante já existe." << endl;
            } catch(idade_invalido_e &e) {
                cout << "A idade do participante é inválida. Deve ser maior de 15 anos" << endl;
            } catch(distrito_invalido_e &e) {
                cout << "Distrito inválido." << endl;
            }
        }
    }

    jogo.inicio();

}