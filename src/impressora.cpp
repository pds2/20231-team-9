// #include "../include/impressora.h"
// #include "../third_party/tabulate.hpp"

// Impressora::Impressora(){
//     mapa.add_row({"\nCavernas = 7\n\n","\nSavana = 8\n\n", "\nDeserto = 2\n\n"});
//     mapa.add_row({"\nRuinas = 6\n\n","\nCentro = 0\n\n", "\nMontanhas = 5\n\n"});
//     mapa.add_row({"\nCampo = 4\n\n","\nFloresta = 1\n\n", "\nPantano = 3\n\n"});

//     mapa.format().font_style({tabulate::FontStyle::bold});
//     mapa.format().width(15);
//     mapa.format().font_align(tabulate::FontAlign::center);

//     mapa.format()
//         .border_top("")
//         .border_bottom("")
//         .border_left("")
//         .border_right("")
//         .corner("");
    
//     mapa[0][0].format().font_background_color(tabulate::Color::grey);
//     mapa[0][1].format().font_background_color(tabulate::Color::yellow);
//     mapa[0][2].format().font_background_color(tabulate::Color::yellow);

//     mapa[1][0].format().font_background_color(tabulate::Color::magenta);
//     mapa[1][1].format().font_background_color(tabulate::Color::white);
//     mapa[1][1].format().font_color(tabulate::Color::grey);
//     mapa[1][2].format().font_background_color(tabulate::Color::red);

//     mapa[2][0].format().font_background_color(tabulate::Color::green);
//     mapa[2][1].format().font_background_color(tabulate::Color::green);
//     mapa[2][2].format().font_background_color(tabulate::Color::cyan);
// }

// void Impressora::imprime_mapa(){
//     std::cout << mapa << std::endl;
// }

// void Impressora::imprime_titulo(){}