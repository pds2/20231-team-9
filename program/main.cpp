#include <iostream>
#include <vector>

#include "../include/sistema.h"

int main() {
    /*
        * @brief Cria o vetor com os participantes
        */
    vector<Jogador> participantes;
    // Criando as Regioes:
    Regiao Centro(2,2,"centro",0,0,9,3);
    Regiao Floresta(2,1,"floresta",8,7,2,0);
    Regiao Pantano(3,1,"pantano",10,3,1,0);
    Regiao Montanhas(3,2,"montanhas",4,3,5,0);
    Regiao Deserto(3,3,"deserto",2,5,5,0);
    Regiao Ruinas(1,2,"ruinas",0,2,5,4);
    Regiao Campo(1,1,"campo",6,8,2,0);
    Regiao Cavernas(1,3,"cavernas",7,3,5,0);
    Regiao Savana(2,3,"savana",3,6,4,1);
    Sistema jogo;

    // Inserindo as Regioes no jogo:
    jogo.insere_regiao(&Centro);
    jogo.insere_regiao(&Floresta);
    jogo.insere_regiao(&Pantano);
    jogo.insere_regiao(&Montanhas);
    jogo.insere_regiao(&Deserto);
    jogo.insere_regiao(&Ruinas);
    jogo.insere_regiao(&Campo);
    jogo.insere_regiao(&Cavernas);
    jogo.insere_regiao(&Savana);

    /*
    * @brief O jogo inteiro roda em um grande while com um break no final
    * Tentar tratar a maior quantidade de casos para o jogo não quebrar e sair do while
    */
    
    while(true){
        cout << "Seja bem-vindo ao Simulador de Jogos Vorazes!" << endl << "Inicialmente, quantos players gostariam de jogar?" \
        << endl << "Digite um número de 1 a 5:" << endl;
        int quantidade = 0;
        /*
        * @brief da um check para ver se está valida a quantidade de pessoas.
        * Sujeito a alteração e adição de mais players jogaveis
        */
        while(true){
            cin >> quantidade;
            if(quantidade > 5 || quantidade < 1){
                cout << "Desculpe, a quantidade inserida não é valida, digite outro número" << endl;
            }
            else{
                break;
            }
        }
        /*
        * @brief Cria string e int discartaveis e constroi o participante dentro de um vetor de jogadores
        */
        cout << endl << "Está na hora de nomear os jogadores!" << endl;
        for(int i = 0; i < quantidade; i++){
            string nome;
            cout << "Qual é o nome do jogador " << i + 1 << "?" << endl;
            cin >> nome;
            cout << endl;
            jogo.criar_jogador(nome);
            participantes.push_back(Jogador(nome));
        }
        /*
        * @brief Setta a quantidade de bots baseado em uma quantidade total de players em 12
        * Essa quantidade total de players pode ser alterada
        */
        cout << "Certo, agora você deseja nomear os bots, ou deseja que a maquina decida?" \
        << endl << "Digite 1 para você escolher e 2 para deixar a maquina decidir." << endl;
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
            cout << endl;
            for(int i = 0; i < (12 - quantidade); i++){
            string nome;
            cout << "Qual é o nome do Bot " << i + quantidade + 1 << "?" << endl;
            cin >> nome;
            jogo.criar_bot(nome);
            participantes.push_back(Jogador(nome));
        }}
        /*
        * @brief Cria nomes aleatorios e alteraveis para os bots
        * Novamente baseado em 12 pessoas sendo isso alteravél
        * 
        */
        if(desc == 2){
            cout << endl;
            jogo.criar_bot("Carla_Maluca");
            jogo.criar_bot("Ana");
            jogo.criar_bot("Carlos");
            jogo.criar_bot("Marisa");
            jogo.criar_bot("João_Matador");
            jogo.criar_bot("Júnior_Espertinho");
            jogo.criar_bot("Eliane");
            int j = quantidade + 7;
            int i = 2;
            while(j < 12){
                string nome_desc = "Jorge" + std::to_string(i);
                jogo.criar_bot(nome_desc);
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