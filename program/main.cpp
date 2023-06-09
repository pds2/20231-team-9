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

    jogo.imprime_titulo();
    
    while(true){
        cout << termcolor::color<221,139,38> << endl << termcolor::reset;
        cout << termcolor::color<221,139,38> << "-----------------------------------------------------------------" << endl << termcolor::reset;
        cout << termcolor::color<221,139,38> << "Configuração da Partida:" << endl << termcolor::reset; 
        cout << termcolor::color<221,139,38> << "-----------------------------------------------------------------" << termcolor::reset << endl;

        cout << "Inicialmente, quantos players gostariam de jogar?" << endl;
        cout << "Digite um número de 1 a 5:" << endl;
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

        /*
        * @brief Cria nomes aleatorios e alteraveis para os bots
        * Novamente baseado em 12 pessoas sendo isso alteravél
        * 
        */
        if(desc == 2){
            cout << endl;
            jogo.criar_bot("Carla_Maluca", &Centro);
            jogo.criar_bot("Ana", &Centro);
            jogo.criar_bot("Carlos", &Centro);
            jogo.criar_bot("Marisa", &Centro);
            jogo.criar_bot("João_Matador", &Centro);
            jogo.criar_bot("Júnior_Espertinho", &Centro);
            jogo.criar_bot("Eliane", &Centro);
            int j = quantidade + 7;
            int i = 2;
            while(j < 12){
                string nome_desc = "Jorge" + std::to_string(i);
                jogo.criar_bot(nome_desc, &Centro);
                i++;
                j++;
            }
        }

        /*
        * @brief Cria string e int discartaveis e constroi o participante dentro de um vetor de jogadores
        */
        cout << endl << "Está na hora de nomear os jogadores!" << endl;
        for(int i = 0; i < quantidade; i++){
            string nome;
            cout << "Qual é o nome do jogador " << i + 1 << "?" << endl;
            while(1) {
                cin >> nome;
                try {
                    cout << endl;
                    jogo.criar_jogador(nome, &Centro);
                    participantes.push_back(Jogador(nome, &Centro));
                    break;

                } catch(participante_ja_existe_e) {
                    cout << "Já existe um participante com esse nome. Insira outro nome." << endl;
                }
            }
        }
        
        if(desc == 1){
            
            cout << endl << "Está na hora de nomear os bots!" << endl;;
            for(int i = 0; i < (12 - quantidade); i++){
            string nome;
            cout << "Qual é o nome do Bot " << i + quantidade + 1 << "?" << endl;
            while(1) {
                cin >> nome;
                try {
                    cout << endl;
                    jogo.criar_bot(nome, &Centro);
                    participantes.push_back(Jogador(nome, &Centro));
                    break;

                } catch(participante_ja_existe_e) {
                    cout << "Já existe um participante com esse nome. Insira outro nome." << endl;
                }
            }
        }}

        jogo.inicio();
        jogo.Jogo();
        
    break;
    }
    return 0;

}