#include <iostream>
#include <vector>

#include "../include/sistema.h"

int main() {
    vector<Jogador> participantes;

    Sistema tudo;
   
    
    while(true){
        cout << "Seja Bem vindo ao simulador de jogos vorazes, inicialmente quantos players gostariam de jogar?" \ 
        << endl << "digite um número de 1 a 5" << endl;
        bool alo = false;
        int quantidade = 0;
        while(alo != true){
            cin >> quantidade;
            if(quantidade > 5 || quantidade < 1){
                cout << "Desculpe, a quantidade inserida não é valida, digite outro numero" << endl;
            }
            else{
                alo = true;
            }
        }
        cout <<"Okay, está na hora de nomear os jogadores" << endl;
        for(int i = 0; i < quantidade; i++){
            string nome;
            int distrito;
            cout << "Qual é o nome do jogador " << i << "?" << endl;
            cin >> nome;
            cout << "E de qual distrito será esse tributo?" << endl;
            cin >> distrito;
            participantes.push_back(Jogador(nome, distrito));
        }

    }


}