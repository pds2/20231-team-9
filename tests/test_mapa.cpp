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