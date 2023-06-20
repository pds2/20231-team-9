#include "../third_party/doctest.h"
#include "../include/mapa.h"

TEST_CASE("Testa se os personagens são colocados no mapa") {
    Mapa mapa;
    map<string, Participante*> my_map;

    Jogador Felipe = Jogador("Felipe",10);
    my_map ["Felipe"] = &Felipe;

    bool aux = false;

    mapa.inicio(my_map);
    vector<string> centro = mapa.get_participantes_centro();

    for(string nome : centro) {
        if(nome == "Felipe") {
            aux == true;
        }
    }

    CHECK(aux == true);
}

TEST_CASE("Testa se um personagem muda de região corretamente") {
    Mapa mapa;
    map<string, Participante*> my_map;

    Jogador Arthur = Jogador("Arthur",10);
    my_map ["Arthur"] = &Arthur;
    mapa.inicio(my_map);

    mapa.mover_do_centro(floresta,my_map["Arthur"]);

    //Regiao Floresta(8,7,2,0,regioes::floresta);
    Regiao R_Arthur = my_map["Arthur"]->get_atual();
    bool aux = true;

    if(R_Arthur.get_nome() != regioes::floresta) {
        aux == false;
    }

    CHECK(aux); 

}