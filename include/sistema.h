#ifndef PDS2_SISTEMA_H
#define PDS2_SISTEMA_H

#include "participante.h"
#include "jogador.h"
#include "bot.h"

class participante_ja_existe_e {};

class Sistema{
    private:
    //pensei em colocar Participante como ponteiro
    map<string, Participante*> participantes_;
    map<string,Regiao*> map_regioes_;
    vector<Participante*> _mortos; // acho q não vamos usar
    unsigned int contador_dias_noites_;
    unsigned int contador_vivos_;

    public:
    /**
     * @brief Construtor
    */
   Sistema();
   /**
    * @brief Insere a Regiao no map de regioes
   */
  void insere_regiao(Regiao* lugar);
    /*
     * @brief Cria um jogador recebendo nome, idade e destrito
     * @throws Lança uma excessão se destrito > 12
     * @throws Lança uma excessão se o participante ja existe
     */
    void criar_jogador(string nome);
    /*
     * @brief Cria um bot
     */
    void criar_bot(string nome);
    /**
     * @brief Inicia o jogo, colocanto todos no centro 
    */
   void inicio();
    /*
     * @brief Remove o participante do map de vivos e insere ele
             no vetor com os nomes dos mortos
     */
    //void morrer(Participante &fulano);

    /*
     * @brief retorna o mapa com os participantes vivos
     */
    map<string,Participante*> get_participantes();
    /**
     * @brief Realiza uma rodada com os jogadores vivos
    */
   void Rodada();
   /**
    * @brief Realiza um Jogo com um Conjunto de Rodadas
   */
  void Jogo();
   /**
    * @brief Retorna um vetor embaralhado com os nomes dos participantes 
    *        que estão vivos
   */
   vector<Participante*> EmbaralhaParticipantesVivos();
   /**
    * @brief Retorna um set com os participantes na mesma Região que o
    *        Participante escolhido
    * 
    * @param Participante
   */
  set<Participante*> ParticipanteNaMesmaRegiao(Participante* fulano);
};

#endif