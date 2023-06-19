#include "../third_party/doctest.h"
#include "../include/armas.h"

TEST_CASE("Testa se a classe Arma é funcionando corretamente") {
    Arma a(armas::espada);
    CHECK(a.get_tipo() == armas::espada);
    CHECK(a.get_poder() == 4);
}