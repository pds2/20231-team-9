# 20231-team-9

GRUPO
Arthur Buzelin
Cecília Junqueira
Felipe Gomide
Lucas Junqueira

USER STORIES

Participante da Edição do Jogo:
- Ao ser criado, o participante deverá receber uma porcentagem de energia e uma taxa de hidratação (é a mesma para todos os jogadores).
- Ele pode ganhar utensílios (comidas, remédio, água...) e armas de patrocinadores e/ou dos organizadores do Jogo. Se usar um dos utensílios/armas, ele será retirado da coleção.
- Ele será capaz de “brigar” com participantes de distritos inimigos. O vencedor da briga é definido como aquele que tem as armas mais poderosas. Ao fim da briga, o perdedor morre e o vencedor tem sua energia reduzida pela diferença do poder da sua arma com a do adversário.
- Se o campo “_energia” ou o “_hidratacao” estiverem iguais a zero, o participante está morto. Se ele bebe água, “_hidratacao” volta a 100.
Patrocinador:
- Pode mandar comidas, remédios, armas, etc, aos participantes que ele apoia.
- Cada patrocinador deverá ser capaz de dar uma nota a cada participante.
- O patrocinador deverá ser capaz de visualizar o nível de hidratação e de machucado de cada participante do jogo.
- O patrocinador deve ser capaz de adicionar utensílios e armas aos respectivos containers dos participantes que ele escolher.
  
Batalhas
- O jogador deverá ser capaz de calcular a distância para os inimigos e escolher aquele mais perto para atacá-lo.
- O jogador deverá poder escolher a arma que ele quer usar (de acordo com a arma do adversário, comparando o poder de cada uma). Se a arma dele for menos poderosa, ele morre. Caso contrário, ele permanece vivo, mas tem seu saldo de energia reduzido.
Criação de uma partida:

Ao iniciar o programa, o usuário deverá inserir a quantidade de personagens totais da partida e depois definir os seguintes parâmetros para cada um deles:
- Nome e distrito ao qual o personagem pertence.
- Se o personagem é um jogador, controlado por suas escolhas ou um bot, com escolhas arbitrárias baseadas em probabilidade.

A cada dia, os jogadores tomam as decisões de seus determinados personagens e a máquina determina as ações dos bots.
No final de cada dia, a máquina exibe um relato escrito de todos os acontecimentos do dia e se obtiveram sucesso ou não.
Ao restar um único personagem restante, este é declarado o vencedor da partida.

Formas diferentes de se jogar baseado nas escolhas da criação da partida:
- Simulação: todos os personagens são bots, e o usuário apenas observa os acontecimentos e a sucessiva criação de uma história.
- Misto: existem jogadores e bots que interagem entre si.
- Competição: todos os personagens são controlados por jogadores que tomam decisões e competem pela partida.

Funcionamento da partida durante o Jogo:
O jogo acontecerá em um mapa, que é um plano cartesiano de tamanho pré definido, e os personagens serão pontos neste plano. Dessa forma, as possíveis implementações serão possíveis:
- Os personagens irão se movimentar pelo mapa durante o jogo (os bots de forma aleatória e os jogadores de forma orientada por eles mesmos). Aqueles que estiverem próximos terão uma maior probabilidade de interagir entre si, seja de forma positiva ou negativa.
- As escolhas possíveis que o jogador poderá realizar durante um dia irão depender da região em que seu personagem está. Isso acontecerá pois as regiões do mapa terão características distintas, de modo que certas regiões possam oferecer benefícios, como aumentar a probabilidade de o personagem achar um item ou abrigo.    
