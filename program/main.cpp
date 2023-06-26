#include <iostream>
#include <vector>

#include "../include/sistema.h"

int main() {
    vector<Jogador> participantes;

    Sistema tudo;
   
    
    while(true){
        cout << "Seja Bem vindo ao simulador de jogos vorazes, inicialmente quantos players gostariam de jogar?" \ 
        << endl << "digite um número de 1 a 5" << endl;
        int quantidade = 0;
        while(true){
            cin >> quantidade;
            if(quantidade > 5 || quantidade < 1){
                cout << "Desculpe, a quantidade inserida não é valida, digite outro numero" << endl;
            }
            else{
                break;
            }
        }
        cout <<"Okay, está na hora de nomear os jogadores" << endl;
        for(int i = 0; i < quantidade; i++){
            string nome;
            int distrito;
            cout << "Qual é o nome do jogador " << i + 1 << "?" << endl;
            cin >> nome;
            cout << "E de qual distrito será esse tributo?" << endl;
            cin >> distrito;
            participantes.push_back(Jogador(nome, distrito));
        }
        cout << "Muito bem, agora você deseja criar os nomes e distritos dos bots, ou deseja que a maquina decida?" \
        << endl<< "Digite 1 para você escolher e 2 para deixar a maquina" << endl;
        int desc = -1;
        while(true){
            cin >> desc;
            if(desc > 2 || desc < 1){
                cout << "Desculpe, a quantidade inserida não é valida, digite outro numero" << endl;
            }
            else{
                break;
            }
        }
        if(desc == 1){
            for(int i = 0; i < (12 - quantidade); i++){
            string nome;
            int distrito;
            cout << "Qual é o nome do Bot " << i + quantidade + 1 << "?" << endl;
            cin >> nome;
            cout << "E de qual distrito será esse tributo?" << endl;
            cin >> distrito;
            participantes.push_back(Jogador(nome, distrito));
        }
        if(desc == 2){
            participantes.push_back(Jogador("Jorge", 1));
            participantes.push_back(Jogador("Ana", 1));
            participantes.push_back(Jogador("Carlos", 1));
            participantes.push_back(Jogador("Marisa", 1));
            participantes.push_back(Jogador("Joao o matador", 1));
            participantes.push_back(Jogador("Junior o esperto", 1));
            participantes.push_back(Jogador("Eliane", 1));
            while (quantidade - 12 > 0){
                int i = 2;
                participantes.push_back(Jogador("Jorge " + i, 1));
                i++;
            }
        }
        }



    break;
    }
    return 0;

}