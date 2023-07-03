#include <iostream>
#include <vector>

#include "../include/sistema.h"

int main() {
    /*
        * @brief Cria o vetor com os participantes
        */
    vector<Jogador> participantes;

    Sistema jogo;
    /*
    * @brief O jogo inteiro roda em um grande while com um break no final
    * Tentar tratar a maior quantidade de casos para o jogo não quebrar e sair do while
    */
    
    while(true){
        cout << "Seja Bem vindo ao simulador de jogos vorazes, inicialmente quantos players gostariam de jogar?" \ 
        << endl << "digite um número de 1 a 5" << endl;
        int quantidade = 0;
        /*
        * @brief da um check para ver se está valida a quantidade de pessoas.
        * Sujeito a alteração e adição de mais players jogaveis
        */
        while(true){
            cin >> quantidade;
            if(quantidade > 5 || quantidade < 1){
                cout << "Desculpe, a quantidade inserida não é valida, digite outro numero" << endl;
            }
            else{
                break;
            }
        }
        /*
        * @brief Cria string e int discartaveis e constroi o participante dentro de um vetor de jogadores
        */
        cout <<"Okay, está na hora de nomear os jogadores" << endl;
        for(int i = 0; i < quantidade; i++){
            string nome;
            cout << "Qual é o nome do jogador " << i + 1 << "?" << endl;
            cin >> nome;
            jogo.criar_jogador(nome);
            participantes.push_back(Jogador(nome));
        }
        /*
        * @brief Setta a quantidade de bots baseado em uma quantidade total de players em 12
        * Essa quantidade total de players pode ser alterada
        */
        cout << "Muito bem, agora você deseja criar os nomes e distritos dos bots, ou deseja que a maquina decida?" \
        << endl<< "Digite 1 para você escolher e 2 para deixar a maquina" << endl;
        int desc;
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
            jogo.criar_jogador(nome);
            participantes.push_back(Jogador(nome));
        }}
        /*
        * @brief Cria nomes aleatorios e alteraveis para os bots
        * Novamente baseado em 12 pessoas sendo isso alteravél
        * Depois há de se mudar os bots para o tipo bot
        */
        if(desc == 2){
            jogo.criar_bot("Jorginho");
            jogo.criar_jogador("Ana");
            jogo.criar_jogador("Carlos");
            jogo.criar_jogador("Marisa");
            jogo.criar_jogador("Joao o matador");
            jogo.criar_jogador("Junior o esperto");
            jogo.criar_jogador("Eliane");
            int j = quantidade + 7;
            int i = 2;
            while(j < 12){
                string nome_desc = "jorge" + std::to_string(i);
                jogo.criar_jogador(nome_desc);
                i++;
                j++;
        }
        }
        jogo.inicio();
        jogo.Jogo();
        
    break;
    }
    return 0;

}