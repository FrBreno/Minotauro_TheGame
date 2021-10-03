#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //Para usar a função getche() -> Ler um carctere e retorna ele como char.
#include <time.h>  //Para utilizar a função _sleep() -> Faz um delay antes de executar a próxima linha de código.
#include <windows.h>

char **lerCabecalho_minoGame(int definicao)
{
  FILE *pf_minotauroGame = NULL;
  char **minotauroGame = NULL;
  char **gameOver = NULL;

  pf_minotauroGame = fopen("cabecalho_minotauroGame.txt", "r"); //Abri o arquivo que contém os cabeçalhos
  //ALOCAÇÃO DAS MATRIZES:
  minotauroGame = (char **)malloc(6 * sizeof(char *));
  for (int i = 0; i < 6; i++)
  {
    minotauroGame[i] = (char *)malloc(146 * sizeof(char));
  }
  gameOver = (char **)malloc(4 * sizeof(char *));
  for (int i = 0; i < 4; i++)
  {
    gameOver[i] = (char *)malloc(59 * sizeof(char));
  }
  //LENDO CABEÇALHO "MINOTAUROGAME":
  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 146; j++)
    {
      fscanf(pf_minotauroGame, "%c", &minotauroGame[i][j]);
    }
    fscanf(pf_minotauroGame, "\n");
  }
  fscanf(pf_minotauroGame, "\n");
  //LENDO CABEÇALHO "GAME OVER":
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 59; j++)
    {
      fscanf(pf_minotauroGame, "%c", &gameOver[i][j]);
    }
    fscanf(pf_minotauroGame, "\n");
  }

  fclose(pf_minotauroGame);

  //OBS: A variável definição determina qual endereço retornar de acordo com a solicitação.
  if (definicao == 0)
  {
    return minotauroGame;
  }
  else
  {
    return gameOver;
  }
}

void imprimirCabecalho_minoGame(char **minotauroGame) //Imprime o cabeçalho "MINOTAUROGAME"
{
  for (int j = 0; j < 145; j++)
  {
    printf("%c", minotauroGame[0][j]);
  }
  printf("\n");
  for (int j = 0; j < 146; j++)
  {
    printf("%c", minotauroGame[1][j]);
  }
  printf("\n");
  for (int j = 0; j < 143; j++)
  {
    printf("%c", minotauroGame[2][j]);
  }
  printf("\n");
  for (int j = 0; j < 144; j++)
  {
    printf("%c", minotauroGame[3][j]);
  }
  printf("\n");
  for (int j = 0; j < 145; j++)
  {
    printf("%c", minotauroGame[4][j]);
  }
  printf("\n");
  for (int j = 0; j < 146; j++)
  {
    printf("%c", minotauroGame[5][j]);
  }
  printf("\n");
  return;
}

void imprimirCabecalho_gameOver(char **gameOver) //Imprime o cabeçalho "GAMEOVER"
{
  printf("  ");
  for (int j = 2; j < 58; j++)
  {
    printf("%c", gameOver[0][j]);
  }
  printf("\n");
  for (int i = 1; i < 4; i++)
  {
    for (int j = 0; j < 59; j++)
    {
      if (gameOver[i][j] == '.')
      {
        printf(" ");
      }
      else
      {
        printf("%c", gameOver[i][j]);
      }
    }
    printf("\n");
  }
  return;
}

void menu(char *n_fase, char *n_dificuldade, char **minotauroGame) //Escolher fase do labirinto e dificuldade do minotauro
{
  char barra = 176;
  do
  {
    //CABEÇALHO:
    system("cls"); //Limpar tela.
    imprimirCabecalho_minoGame(minotauroGame);
    printf("\n");
    for (int i = 0; i < 146; i++)
    {
      printf("%c", barra);
      _sleep(1);
    }
    printf("\n");

    //MENU:
    printf("%c Escolha uma fase:                                \n%c\n", 176, 176);
    printf("%c 1 - FACIL                                        \n", 176);
    printf("%c 2 - MEDIO                                        \n", 176);
    printf("%c 3 - DIFICIL                                      \n", 176);
    printf("%c 4 - MENU DE AJUDA                                     \n%c\n", 176, 176);
    printf("%c Tecle o numero correspondente a fase desejada: ", 176);
    *n_fase = getche(); //Ler um carctere e retorna ele como char.
    system("cls");

    //MENU DE AJUDA:
    if (*n_fase == '4')
    {
      printf("    _        _   _   _   ___      _\n");
      printf("   /_%c    _ | | | | | | |   %c    /_%c\n", 92, 92, 92);
      printf("  / _ %c  | || | | |_| | | |) |  / _ %c\n", 92, 92);
      printf(" /_/ %c_%c  %c__/   %c___/  |___/  /_/ %c_%c\n\n", 92, 92, 92, 92, 92, 92);
      for (int i = 0; i < 78; i++)
      {
        printf("%c", barra);
        _sleep(1);
      }

      printf("\n");
      printf("01. As fases estao relacionadas a montagem do labirnto, sendo que a \n    fase FACIL apresenta um labirinto 20x20, a MEDIO 30x30 e a DIFICL 50x50.\n");
      printf("\n02. Dificuldade FACIL: O minotauro escolhe uma posicaoo proxima valida,\n    e da um passo para essa posicao. Com isso, podemos dizer que nem sempre\n    o minotauro tomara a decisao mais inteligente.\n");
      printf("\n03. Dificuldade MEDIO: Aqui o minotauro continua tomando decisoes nao tao\n    inteligentes, mas dessa vez ele pode dar dois passos por rodada.\n");
      printf("\n04. Dificuldade DIFICIL: Nessa dificuldade o minotauro tentara seguir o\n    caminho de menor distancia ate o personagem (SO corra :D).\n");
      printf("\n05. Lembrando que o jogo apresenta um esquema de pontos baseados na\n    quantidade de '.' que o personagem coletar. Voce pode utilizar isso\n    para criterio de desempate, caso esteja jogando com amigos.\n\n");

      for (int i = 0; i < 78; i++)
      {
        printf("%c", barra);
      }
      printf("\n\n");
      system("pause");
    }

  } while (*n_fase != '1' && *n_fase != '2' && *n_fase != '3'); //Filtro.

  do
  {
    //CABEÇALHO 02:
    imprimirCabecalho_minoGame(minotauroGame);
    printf("\n");
    for (int i = 0; i < 146; i++)
    {
      printf("%c", barra);
    }
    printf("\n");

    //MENU 02:
    printf("%c Escolha o nivel de dificuldade do Minotauro:     \n%c\n", 176, 176);
    printf("%c 1 - FACIL                                        \n", 176);
    printf("%c 2 - MEDIO                                        \n", 176);
    printf("%c 3 - DIFICIL                                      \n%c\n", 176, 176);
    printf("%c Tecle o numero correspondente ao nivel desejado: ", 176);
    *n_dificuldade = getche();
    system("cls");
  } while (*n_dificuldade != '1' && *n_dificuldade != '2' && *n_dificuldade != '3'); //Filtro.

  //TELA DE LOADING:
  printf("LOADING");
  _sleep(200);
  printf(".");
  _sleep(200);
  printf(".");
  _sleep(200);
  printf(".");
  _sleep(500);
  system("cls");

  return;
}

char **lerLabirinto(FILE *pf, int *nl, int *nc, int *l, int *c, int *l_mino, int *c_mino, int *l_saida, int *c_saida) //Ler o arquivo em uma matriz tipo char **.
{
  char **L = NULL;                                                                         //Matriz auxiliar.
  fscanf(pf, "%d %d %d %d %d %d %d %d\n", nl, nc, l, c, l_mino, c_mino, l_saida, c_saida); // Lê a 1a linha do arquivo do labirinto e determina as dimenssões da matriz.

  //ALOCANDO MEMÓRIA:
  L = (char **)malloc(*nl * sizeof(char *));
  for (int i = 0; i < *nl; i++)
  {
    L[i] = (char *)malloc(*nc * sizeof(char));
  }
  //LENDO O ARQUIVO:
  for (int i = 0; i < *nl; i++)
  {
    for (int j = 0; j < *nc; j++)
    {
      fscanf(pf, "%c", &L[i][j]);
    }
    fscanf(pf, "\n");
  }
  return L;
}

void imprimirLabirinto(char **L, int nl, int nc, int *score) //Printa o labirinto na tela.
{
  for (int i = 0; i < nl; i++)
  {
    for (int j = 0; j < nc; j++)
    {
      printf("%c", L[i][j]);
    }
    printf("\n");
  }
  printf("\n\nSCORE: %d\n\n", *score);
}

void controle(char **L, int *linha, int *coluna, int nl, int nc, int *cont, int *teclaIncorreta, int *sairDoJogo, int *score) //Para controlar o personagem.
{
  /*CONTROLES:
  ¬ Pressione W para cima (decrementa linha em -1);
  ¬ Pressione S para baixo (incrementa linha em +1);
  ¬ Pressione A para esquerda (decrementa coluna em -1);
  ¬ Pressione D para direita (incrementa coluna em +1);
  */
  char buffer = 0;     //Recebe o caractere de movimento (W, S, A, D).
  *teclaIncorreta = 0; //Vai guardar 1 se o usuário digitar uma tecla diferente da solicitada.
  *sairDoJogo = 0;     //Vai guardar 1 se o usuário teclar para sair do jogo.
  //Valores máximos que as variáveis "linha" e "coluna" podem assumir:
  nl -= 1;
  nc -= 1;
  //Entrada:
  printf("\nPressione uma tecla (w, s, a, d) para mover o personagem, ou (p) para sair do jogo: ");
  buffer = getche();
  //Movimentação:
  //SE O USUÁRIO PRESSIONAR W:
  if (buffer == 'w' || buffer == 'W') //Press W.
  {
    //Movimento inválido - Caso haja um muro ou o usuário tente extrapolar a matriz:
    if ((L[*linha - 1][*coluna] == '|') || (*linha - 1 < 0))
    {
      system("cls");
      printf("\nComando invalido!! (Cuidado com os muros '-')\n");
      *teclaIncorreta = 1;
      _sleep(1500);
    }

    //Movimento válido - Atualizando o labirinto:
    else
    {
      if (L[*linha - 1][*coluna] == '.')
      {
        *score += 1;
      }
      L[*linha][*coluna] = ' ';
      *linha -= 1;
      L[*linha][*coluna] = 'P';
    }
  }

  //SE O USUÁRIO PRESSIONAR S:
  else if (buffer == 's' || buffer == 'S') //Press S.
  {
    //Movimento inválido - Caso haja um muro ou o usuário tente extrapolar a matriz:
    if ((L[*linha + 1][*coluna] == '|') || (*linha + 1 > nl))
    {
      system("cls");
      printf("\nComando invalido!! (Cuidado com os muros '-')\n");
      *teclaIncorreta = 1;
      _sleep(1500);
    }

    //Movimento válido - Atualizando o labirinto:
    else
    {
      if (L[*linha + 1][*coluna] == '.')
      {
        *score += 1;
      }
      L[*linha][*coluna] = ' ';
      *linha += 1;
      L[*linha][*coluna] = 'P';
    }
  }

  //SE O USUÁRIO PRESSIONAR A:
  else if (buffer == 'a' || buffer == 'A') //Press A.
  {
    //Movimento inválido - Caso haja um muro ou o usuário tente extrapolar a matriz:
    if ((L[*linha][*coluna - 1] == '|') || (*coluna - 1 < 0))
    {
      system("cls");
      printf("\nComando invalido!! (Cuidado com os muros '-')\n");
      *teclaIncorreta = 1;
      _sleep(1500);
    }

    //Movimento válido - Atualizando o labirinto:
    else
    {
      if (L[*linha][*coluna - 1] == '.')
      {
        *score += 1;
      }
      L[*linha][*coluna] = ' ';
      *coluna -= 1;
      L[*linha][*coluna] = 'P';
    }
  }

  //SE O USUÁRIO PRESSIONAR D:
  else if (buffer == 'd' || buffer == 'D') //Press D.
  {
    //Movimento inválido - Caso haja um muro ou o usuário tente extrapolar a matriz:
    if ((L[*linha][*coluna + 1] == '|') || (*coluna + 1 > nc))
    {
      system("cls");
      printf("\nComando invalido!! (Cuidado com os muros '-')\n");
      *teclaIncorreta = 1;
      _sleep(1500);
    }

    //Movimento válido - Atualizando o labirinto:
    else
    {
      if (L[*linha][*coluna + 1] == '.')
      {
        *score += 1;
      }
      L[*linha][*coluna] = ' ';
      *coluna += 1;
      L[*linha][*coluna] = 'P';
    }
  }

  else if (buffer == 'p' || buffer == 'P') //Para kitar do game no meio da partida.
  {
    *cont = -1;
    *sairDoJogo = 1;
    return;
  }

  else //filtro - Caso o usuário pressione uma tecla diferente de W, S, A ou D:
  {
    *teclaIncorreta = 1;
    //system("cls");
    printf("\n\nComando invalido!! (somente w, s, a, d ou p)\n");
    _sleep(1500);
  }

  system("cls"); //Limpar tela.

  return;
}

//FUNÇÕES QUE MOVIMENTAM O MINOTAURO NA LABIRINTO:
void paraCima(char **L, int *linhaMino, int *colunaMino)
{
  L[*linhaMino][*colunaMino] = ' ';
  *linhaMino -= 1;
  L[*linhaMino][*colunaMino] = 'M';
  return;
}

void paraBaixo(char **L, int *linhaMino, int *colunaMino)
{
  L[*linhaMino][*colunaMino] = ' ';
  *linhaMino += 1;
  L[*linhaMino][*colunaMino] = 'M';
  return;
}

void paraDireita(char **L, int *linhaMino, int *colunaMino)
{
  L[*linhaMino][*colunaMino] = ' ';
  *colunaMino += 1;
  L[*linhaMino][*colunaMino] = 'M';
  return;
}

void paraEsquerda(char **L, int *linhaMino, int *colunaMino)
{
  L[*linhaMino][*colunaMino] = ' ';
  *colunaMino -= 1;
  L[*linhaMino][*colunaMino] = 'M';
  return;
}

void minotauroFacil(char **L, int *linha, int *coluna, int nl, int nc, int *buffer2, int *buffer3, int *buffer4)
{
  system("cls");

  srand(time(NULL));          //Cria uma seed como referência para a função "rand()".
  int aleatorio = rand() % 4; //A função "rand()" gera um número aleatório de 0 a 3 (nesse caso).
  /*
    0 -> Subida.
    1 -> Esquerda.
    2 -> Direita.
    3 -> Descida.
  */

  //Subida:
  if (aleatorio == 0)
  {
    if ((L[*linha - 1][*coluna] != '|') && (*linha - 1 >= 0) && (L[*linha - 1][*coluna] != 'O'))
    {
      paraCima(L, linha, coluna);
      return;
    }
    else if ((L[*linha + 1][*coluna] != '|') && (*linha + 1 < nl) && (L[*linha + 1][*coluna] != 'O'))
    {
      paraBaixo(L, linha, coluna);
      return;
    }
    else if ((L[*linha][*coluna - 1] != '|') && (*coluna - 1 >= 0) && (L[*linha][*coluna - 1] != 'O'))
    {
      paraEsquerda(L, linha, coluna);
      return;
    }
    else
    {
      paraDireita(L, linha, coluna);
      return;
    }
  }

  //Esquerda:
  if (aleatorio == 1)
  {
    if ((L[*linha][*coluna - 1] != '|') && (*coluna - 1 >= 0) && (L[*linha][*coluna - 1] != 'O'))
    {
      paraEsquerda(L, linha, coluna);
      return;
    }
    else if ((L[*linha + 1][*coluna] != '|') && (*linha + 1 < nl) && (L[*linha + 1][*coluna] != 'O'))
    {
      paraBaixo(L, linha, coluna);
      return;
    }
    else if ((L[*linha][*coluna + 1] != '|') && (*coluna + 1 < nc) && (L[*linha][*coluna + 1] != 'O'))
    {
      paraDireita(L, linha, coluna);
      return;
    }
    else
    {
      paraCima(L, linha, coluna);
      return;
    }
  }

  //Direira:
  if (aleatorio == 2)
  {
    if ((L[*linha][*coluna + 1] != '|') && (*coluna + 1 < nc) && (L[*linha][*coluna + 1] != 'O'))
    {
      paraDireita(L, linha, coluna);
      return;
    }
    else if ((L[*linha + 1][*coluna] != '|') && (*linha + 1 < nl) && (L[*linha + 1][*coluna] != 'O'))
    {
      paraBaixo(L, linha, coluna);
      return;
    }
    else if ((L[*linha][*coluna - 1] != '|') && (*coluna - 1 >= 0) && (L[*linha][*coluna - 1] != 'O'))
    {
      paraEsquerda(L, linha, coluna);
      return;
    }
    else
    {
      paraCima(L, linha, coluna);
      return;
    }
  }

  //Descida:
  if (aleatorio == 3)
  {
    if ((L[*linha + 1][*coluna] != '|') && (*linha + 1 < nl) && (L[*linha + 1][*coluna] != 'O'))
    {
      paraBaixo(L, linha, coluna);
      return;
    }
    else if ((L[*linha - 1][*coluna] != '|') && (*linha - 1 >= 0) && (L[*linha - 1][*coluna] != 'O'))
    {
      paraCima(L, linha, coluna);
      return;
    }
    else if ((L[*linha][*coluna + 1] != '|') && (*coluna + 1 < nc) && (L[*linha][*coluna + 1] != 'O'))
    {
      paraDireita(L, linha, coluna);
      return;
    }
    else
    {
      paraEsquerda(L, linha, coluna);
      return;
    }
  }
  return;
}

void minotauroMedio(char **L, int *linha, int *coluna, int nl, int nc, int *buffer2, int *buffer3, int *buffer4)
{
  system("cls");

  srand(time(NULL));
  int aleatorio = rand() % 4;
  /*
    0 -> Subida.
    1 -> Esquerda.
    2 -> Direita.
    3 -> Descida.
  */

  //Subida:
  if (aleatorio == 0)
  {
    if ((L[*linha - 1][*coluna] != '|') && (*linha - 1 >= 0) && (L[*linha - 1][*coluna] != 'O'))
    {
      paraCima(L, linha, coluna);
      return;
    }
    else if ((L[*linha + 1][*coluna] != '|') && (*linha + 1 < nl) && (L[*linha + 1][*coluna] != 'O'))
    {
      paraBaixo(L, linha, coluna);
      return;
    }
    else if ((L[*linha][*coluna - 1] != '|') && (*coluna - 1 >= 0) && (L[*linha][*coluna - 1] != 'O'))
    {
      paraEsquerda(L, linha, coluna);
      return;
    }
    else
    {
      paraDireita(L, linha, coluna);
      return;
    }
  }

  //Esquerda:
  if (aleatorio == 1)
  {
    if ((L[*linha][*coluna - 1] != '|') && (*coluna - 1 >= 0) && (L[*linha][*coluna - 1] != 'O'))
    {
      paraEsquerda(L, linha, coluna);
      return;
    }
    else if ((L[*linha + 1][*coluna] != '|') && (*linha + 1 < nl) && (L[*linha + 1][*coluna] != 'O'))
    {
      paraBaixo(L, linha, coluna);
      return;
    }
    else if ((L[*linha][*coluna + 1] != '|') && (*coluna + 1 < nc) && (L[*linha][*coluna + 1] != 'O'))
    {
      paraDireita(L, linha, coluna);
      return;
    }
    else
    {
      paraCima(L, linha, coluna);
      return;
    }
  }

  //Direira:
  if (aleatorio == 2)
  {
    if ((L[*linha][*coluna + 1] != '|') && (*coluna + 1 < nc) && (L[*linha][*coluna + 1] != 'O'))
    {
      paraDireita(L, linha, coluna);
      return;
    }
    else if ((L[*linha + 1][*coluna] != '|') && (*linha + 1 < nl) && (L[*linha + 1][*coluna] != 'O'))
    {
      paraBaixo(L, linha, coluna);
      return;
    }
    else if ((L[*linha][*coluna - 1] != '|') && (*coluna - 1 >= 0) && (L[*linha][*coluna - 1] != 'O'))
    {
      paraEsquerda(L, linha, coluna);
      return;
    }
    else
    {
      paraCima(L, linha, coluna);
      return;
    }
  }

  //Descida:
  if (aleatorio == 3)
  {
    if ((L[*linha + 1][*coluna] != '|') && (*linha + 1 < nl) && (L[*linha + 1][*coluna] != 'O'))
    {
      paraBaixo(L, linha, coluna);
      return;
    }
    else if ((L[*linha - 1][*coluna] != '|') && (*linha - 1 >= 0) && (L[*linha - 1][*coluna] != 'O'))
    {
      paraCima(L, linha, coluna);
      return;
    }
    else if ((L[*linha][*coluna + 1] != '|') && (*coluna + 1 < nc) && (L[*linha][*coluna + 1] != 'O'))
    {
      paraDireita(L, linha, coluna);
      return;
    }
    else
    {
      paraEsquerda(L, linha, coluna);
      return;
    }
  }
  return;
}

void minotauroDificil(char **L, int *linhaMino, int *colunaMino, int nl, int nc, int *linhaP, int *colunaP, int *buffer2, int *linAnterior, int *colAnterior)
{
  system("cls");

  //SE O MINOTAURO FICAR INCURRALADO EM TRÊS PAREDES (Incluindo a saída -> já que o minotauro não pode ultrapassá-la):

  //Única via livre -> movimento para esquerda:
  if ((L[*linhaMino + 1][*colunaMino] == '|') && (L[*linhaMino - 1][*colunaMino] == '|'))
  {
    if ((L[*linhaMino][*colunaMino + 1] == '|') || (L[*linhaMino][*colunaMino + 1] == 'O'))
    {
      paraEsquerda(L, linhaMino, colunaMino);
      return;
    }
  }

  //Única via livre -> movimento para direita:
  if ((L[*linhaMino + 1][*colunaMino] == '|') && (L[*linhaMino - 1][*colunaMino] == '|') && (L[*linhaMino][*colunaMino - 1] == '|'))
  {
    paraDireita(L, linhaMino, colunaMino);
    return;
  }

  //Única via livre -> movimento para cima:
  if ((L[*linhaMino + 1][*colunaMino] == '|') && (L[*linhaMino][*colunaMino - 1] == '|'))
  {
    if ((L[*linhaMino][*colunaMino + 1] == '|') || (L[*linhaMino][*colunaMino + 1] == 'O'))
    {
      paraCima(L, linhaMino, colunaMino);
      return;
    }
  }

  //Única via livre -> movimento para baixo:
  if ((L[*linhaMino - 1][*colunaMino] == '|') && (L[*linhaMino][*colunaMino - 1] == '|'))
  {
    if ((L[*linhaMino][*colunaMino + 1] == '|') || (L[*linhaMino][*colunaMino + 1] == 'O'))
    {
      paraBaixo(L, linhaMino, colunaMino);
      return;
    }
  }

  //SE O MINOTAURO ESTIVER DO LADO DO PERSONAGEM -> ELE TEM QUE PERSEGUIR O PERSONAGEM

  //Se o personagem estiver em baixo do minotauro:
  if (*linAnterior - 1 == *linhaMino)
  {
    if ((L[*linhaMino + 1][*colunaMino] != '|') && (*linhaMino + 1 < nl) && (L[*linhaMino + 1][*colunaMino] != 'O'))
    {
      paraBaixo(L, linhaMino, colunaMino);
      return;
    }
  }

  //Se o personagem estiver em cima do minotauro:
  if (*linAnterior + 1 == *linhaMino)
  {
    if ((L[*linhaMino - 1][*colunaMino] != '|') && (*linhaMino - 1 >= 0) && (L[*linhaMino - 1][*colunaMino] != 'O'))
    {
      paraCima(L, linhaMino, colunaMino);
      return;
    }
  }

  //Se o personagem estiver a direita do personagem:
  if (*colAnterior - 1 == *colunaMino)
  {
    if ((L[*linhaMino][*colunaMino + 1] != '|') && (*colunaMino + 1 < nc) && (L[*linhaMino][*colunaMino + 1] != 'O'))
    {
      paraDireita(L, linhaMino, colunaMino);
      return;
    }
  }

  //Se o personagem estiver a esquerda do personagem:
  if (*colAnterior + 1 == *colunaMino)
  {
    if ((L[*linhaMino][*colunaMino - 1] != '|') && (*colunaMino - 1 >= 0) && (L[*linhaMino][*colunaMino - 1] != 'O'))
    {
      paraEsquerda(L, linhaMino, colunaMino);
    }
    return;
  }

  //SE O PERSONAGEM E O MINOTAURO ESTIVEREM NA MESMA COLUNA:
  if (*colunaP == *colunaMino)
  {
    //SE O MINOTAURO ESTIVER ACIMA DO PERSONAGEM:
    if (*linhaMino < *linhaP)
    {
      if ((L[*linhaMino + 1][*colunaMino] != '|') && (*linhaMino + 1 < nl) && (L[*linhaMino + 1][*colunaMino] != 'O'))
      {
        paraBaixo(L, linhaMino, colunaMino);
        return;
      }
    }

    //SE ELE ESTIVER ABAIXO (JÁ QUE SE ELE ESTIVEREM NA MESMA POSIÇÃO É GAME OVER):
    else
    {
      if ((L[*linhaMino - 1][*colunaMino] != '|') && (*linhaMino - 1 >= 0) && (L[*linhaMino - 1][*colunaMino] != 'O'))
      {
        paraCima(L, linhaMino, colunaMino);
        return;
      }
    }
  }

  //SE O PERSONAGEM E O MINOTAURO ESTIVEREM NA MESMA LINHA:
  if (*linhaP == *linhaMino)
  {
    //SE O MINOTAURO ESTIVER A ESQUERDA DO PERSONAGEM:
    if (*colunaMino < *colunaP)
    {
      if ((L[*linhaMino][*colunaMino + 1] != '|') && (*colunaMino + 1 < nc) && (L[*linhaMino][*colunaMino + 1] != 'O'))
      {
        paraDireita(L, linhaMino, colunaMino);
        return;
      }
      else if (L[*linhaMino][*colunaMino - 1] == '|')
      {
        if ((L[*linhaMino - 1][*colunaMino] != '|') && (*linhaMino - 1 >= 0) && (L[*linhaMino - 1][*colunaMino] != 'O'))
        {
          paraCima(L, linhaMino, colunaMino);
          return;
        }
        if ((L[*linhaMino + 1][*colunaMino] != '|') && (*linhaMino + 1 < nl) && (L[*linhaMino + 1][*colunaMino] != 'O'))
        {
          paraBaixo(L, linhaMino, colunaMino);
          return;
        }
      }
    }
    //SE ESTIVER A DIREITA (SE ESTIVEREM NA MESMA POSIÇÃO É GAME OVER):
    else
    {
      if ((L[*linhaMino][*colunaMino - 1] != '|') && (*colunaMino - 1 >= 0) && (L[*linhaMino][*colunaMino - 1] != 'O'))
      {
        paraEsquerda(L, linhaMino, colunaMino);
        return;
      }
      else if (L[*linhaMino][*colunaMino + 1] == '|' || (L[*linhaMino][*colunaMino + 1] == 'O'))
      {
        if ((L[*linhaMino - 1][*colunaMino] != '|') && (*linhaMino - 1 >= 0) && (L[*linhaMino - 1][*colunaMino] != 'O'))
        {
          paraCima(L, linhaMino, colunaMino);
          return;
        }
        if ((L[*linhaMino + 1][*colunaMino] != '|') && (*linhaMino + 1 < nl) && (L[*linhaMino + 1][*colunaMino] != 'O'))
        {
          paraBaixo(L, linhaMino, colunaMino);
          return;
        }
      }
    }
  }

  //SE O PERSONAGEM SE DESLOCOU PARA DIREITA -> MINOTAURO TAMBÉM VAI PRA DIREITA SE POSSÍVEL
  if (*colAnterior + 1 == *colunaP)
  {
    if ((L[*linhaMino][*colunaMino + 1] != '|') && (*colunaMino + 1 < nc) && (L[*linhaMino][*colunaMino + 1] != 'O'))
    {
      paraDireita(L, linhaMino, colunaMino);
      return;
    }
  }

  //SE O PERSONAGEM SE DESLOCOU PARA ESQUERDA -> MINOTAURO TAMBÉM VAI PRA ESQUERDA SE POSSÍVEL
  if (*colAnterior - 1 == *colunaP)
  {
    if ((L[*linhaMino][*colunaMino - 1] != '|') && (*colunaMino - 1 >= 0) && (L[*linhaMino][*colunaMino - 1] != 'O'))
    {
      paraEsquerda(L, linhaMino, colunaMino);
      return;
    }
  }

  //SE O PERSONAGEM SE DESLOCOU PARA BAIXO -> MINOTAURO TAMBÉM VAI PRA BAIXO SE POSSÍVEL
  if (*linAnterior + 1 == *linhaP)
  {
    if ((L[*linhaMino + 1][*colunaMino] != '|') && (*linhaMino + 1 < nl) && (L[*linhaMino + 1][*colunaMino] != 'O'))
    {
      paraBaixo(L, linhaMino, colunaMino);
      return;
    }
  }

  //SE O PERSONAGEM SE DESLOCOU PARA CIMA -> MINOTAURO TAMBÉM VAI PRA CIMA SE POSSÍVEL
  if (*linAnterior - 1 == *linhaP)
  {
    if ((L[*linhaMino - 1][*colunaMino] != '|') && (*linhaMino - 1 >= 0) && (L[*linhaMino - 1][*colunaMino] != 'O'))
    {
      paraCima(L, linhaMino, colunaMino);
      return;
    }
  }

  //CASO AS SENTENÇAS ACIMA NÃO FOREM ATENDIDAS, E O PERSONAGEM E O MINOTAURO ESTIVEREM EM LINHAS DIFERENTES:
  if (*linhaP != *linhaMino)
  {
    //LP - LM > 0
    if ((L[*linhaMino + 1][*colunaMino] != '|') && (*linhaMino + 1 < nl) && (*buffer2 == 0) && (L[*linhaMino + 1][*colunaMino] != 'O'))
    {
      paraBaixo(L, linhaMino, colunaMino);
      return;
    }
    //LP - LM < 0
    if ((L[*linhaMino - 1][*colunaMino] != '|') && (*linhaMino - 1 >= 0) && (*buffer2 == 0) && (L[*linhaMino - 1][*colunaMino] != 'O'))
    {
      paraCima(L, linhaMino, colunaMino);
      *buffer2 = 1;
      return;
    }
  }

  //CASO AS SENTENÇAS ACIMA NÃO FOREM ATENDIDAS, E O PERSONAGEM E O MINOTAURO ESTIVEREM EM COLUNAS DIFERENTES:
  if (*colunaP != *colunaMino)
  {
    *buffer2 = 0;
    //CP - CM > 0
    if ((L[*linhaMino][*colunaMino + 1] != '|') && (*colunaMino + 1 < nc) && (L[*linhaMino][*colunaMino + 1] != 'O'))
    {
      paraDireita(L, linhaMino, colunaMino);
      return;
    }
    //CP - CM < 0
    if ((L[*linhaMino][*colunaMino - 1] != '|') && (*colunaMino - 1 >= 0) && (L[*linhaMino][*colunaMino - 1] != 'O'))
    {
      paraEsquerda(L, linhaMino, colunaMino);
      return;
    }
  }

  return;
}

int main()
{
  int buffer2 = 0, buffer3 = 0, buffer4 = 0; //utilizado na função minotauro fácil e médio -> Apenas para guardar 0 ou 1 de acordo com situações específicas.

  int linhaAnterior = 0, colunaAnterior = 0; //Vai guardar a posição anterior a cada movimento do personagem.

  int teclaIncorreta = 0, sairDoJogo = 0; //Variáveis utilizados em laço em casos de teclagem incorreta ou solicitação para sair do jogo.

  int posicaoLinha = 0, posicaoColuna = 0;           //Posição inicial do personagem.
  int posicaoLinha_mino = 0, posicaoColuna_mino = 0; //Posição inicial do minotauro.
  int linha_saida = 0, coluna_saida = 0;             //Posição da saída.

  int score = 0; //Guarda a pontuação.

  //CABEÇALHOS
  char **minotauroGame = NULL;
  char **gameOver = NULL;
  minotauroGame = lerCabecalho_minoGame(0);
  gameOver = lerCabecalho_minoGame(1);

  //MENU:
  char n_fase = 0, n_minotauroDificuldade = 0;
  menu(&n_fase, &n_minotauroDificuldade, minotauroGame);

  //MATRIZ - LABIRINTO:
  char **L = NULL;
  FILE *pf = NULL;
  int nl = 0, nc = 0; //Guarda as dimensões da matriz.

  //Abrindo o arquivo de acordo com a fase escolhida:
  //FASE FÁCIL:
  if (n_fase == '1')
  {
    pf = fopen("fase_facil.txt", "r");
  }

  //FASE MÉDIO:
  else if (n_fase == '2')
  {
    pf = fopen("fase_medio.txt", "r");
  }

  //FASE DIFÍCIL
  else
  {
    pf = fopen("fase_dificil.txt", "r");
  }

  //LENDO O ARQUIVO ESCOLHIDO:
  if (pf == NULL)
  {
    printf("ERROR!\n\n");
  }
  else
  {
    L = lerLabirinto(pf, &nl, &nc, &posicaoLinha, &posicaoColuna, &posicaoLinha_mino, &posicaoColuna_mino, &linha_saida, &coluna_saida);
    fclose(pf);
  }

  //PRINTANDO O LABIRINTO E LAÇO DE ATUALIZAÇÃO:
  int cont = 1; //Condição de existência do laço.
  imprimirLabirinto(L, nl, nc, &score);

  //LAÇO DE EXECUÇAO DO JOGO:
  do
  {
    linhaAnterior = posicaoLinha;   //Guarda a posição de linha anterior antes do movimento do personagem.
    colunaAnterior = posicaoColuna; //Guarda a posição de coluna anterior antes do movimento do personagem.
    do
    {
      controle(L, &posicaoLinha, &posicaoColuna, nl, nc, &cont, &teclaIncorreta, &sairDoJogo, &score);

      if (sairDoJogo == 1)
      {
        system("cls");
        printf("\nVOCE SAIU DO JOGO :/\n\n"); //DESALOCANDO MEMÓRIA DOS PONTEIROS:
        for (int i = 0; i < nl; i++)
        {
          free(L[i]);
          L[i] = NULL;
        }
        free(L);
        L = NULL;

        free(pf);
        pf = NULL;
        printf("\n\nJogo criado por Francisco Breno (Matricula: 511429)\n\n");
        _sleep(4000);
        return 0;
      }

      imprimirLabirinto(L, nl, nc, &score);
    } while (teclaIncorreta == 1);

    //Se "P" avançar para cima do minotauro:
    if ((posicaoLinha == posicaoLinha_mino) && (posicaoColuna == posicaoColuna_mino))
    {
      L[posicaoLinha][posicaoColuna_mino] = 'X';
      system("cls");
      imprimirLabirinto(L, nl, nc, &score);
      _sleep(500);
      system("cls");

      imprimirCabecalho_gameOver(gameOver);
      printf("\n");

      printf("\nSCORE: %d\n\n\n", score);
      //DESALOCANDO MEMÓRIA DOS PONTEIROS:
      for (int i = 0; i < nl; i++)
      {
        free(L[i]);
        L[i] = NULL;
      }
      free(L);
      L = NULL;

      free(pf);
      pf = NULL;
      printf("\n\nJogo criado por Francisco Breno (Matricula: 511429)\n\n");
      _sleep(4000);
      return 0;
    }

    //Se "P" alcançar a saída:
    if (posicaoLinha == linha_saida && posicaoColuna == coluna_saida)
    {
      system("cls");
      printf(" __      __  ___   _  _   _  _   _  _   _   _\n");
      printf(" %c %c    / / |_ _| | %c| | | %c| | | %c| | | | | |\n", 92, 92, 92, 92, 92);
      printf("  %c %c/%c/ /   | |  | .` | | .` | | .` | |_| |_|\n", 92, 92, 92);
      printf("   %c_/%c_/   |___| |_|%c_| |_|%c_| |_|%c_| (_) (_)\n", 92, 92, 92, 92, 92);

      printf("\n\nSCORE: %d\n\n\n", score);
      cont -= 1;
      //DESALOCANDO MEMÓRIA DOS PONTEIROS:
      for (int i = 0; i < nl; i++)
      {
        free(L[i]);
        L[i] = NULL;
      }
      free(L);
      L = NULL;

      free(pf);
      pf = NULL;
      printf("\n\nJogo criado por Francisco Breno (Matricula: 511429)\n\n");
      _sleep(4000);
      return 0;
    }

    //DIFICULDADE DA IA DO MINOTAURO:
    //Fácil:
    if (n_minotauroDificuldade == '1')
    {
      minotauroFacil(L, &posicaoLinha_mino, &posicaoColuna_mino, nl, nc, &buffer2, &buffer3, &buffer4);
      imprimirLabirinto(L, nl, nc, &score);
    }

    //Médio:
    else if (n_minotauroDificuldade == '2')
    {
      int repet = 2;
      while (repet > 0)
      {
        repet--;
        minotauroMedio(L, &posicaoLinha_mino, &posicaoColuna_mino, nl, nc, &buffer2, &buffer3, &buffer4);
        imprimirLabirinto(L, nl, nc, &score);
        _sleep(300);
        //Se "P" avançar para cima do minotauro:
        if ((posicaoLinha == posicaoLinha_mino) && (posicaoColuna == posicaoColuna_mino))
        {
          L[posicaoLinha][posicaoColuna_mino] = 'X';
          system("cls");
          imprimirLabirinto(L, nl, nc, &score);
          _sleep(500);
          system("cls");

          imprimirCabecalho_gameOver(gameOver);
          printf("\n");

          printf("\nSCORE: %d\n\n\n", score);

          //DESALOCANDO MEMÓRIA DOS PONTEIROS:
          for (int i = 0; i < nl; i++)
          {
            free(L[i]);
            L[i] = NULL;
          }
          free(L);
          L = NULL;

          free(pf);
          pf = NULL;
          printf("\n\nJogo criado por Francisco Breno (Matricula: 511429)\n\n");
          _sleep(4000);
          return 0;
        }
      }
    }

    //Difícil:
    else
    {
      minotauroDificil(L, &posicaoLinha_mino, &posicaoColuna_mino, nl, nc, &posicaoLinha, &posicaoColuna, &buffer2, &linhaAnterior, &colunaAnterior);
      imprimirLabirinto(L, nl, nc, &score);
    }

    //Se o minotauro alcançar "P":
    if ((posicaoLinha == posicaoLinha_mino) && (posicaoColuna == posicaoColuna_mino))
    {
      L[posicaoLinha][posicaoColuna_mino] = 'X';
      system("cls");
      imprimirLabirinto(L, nl, nc, &score);
      _sleep(500);
      system("cls");

      imprimirCabecalho_gameOver(gameOver);
      printf("\n");

      printf("\nSCORE: %d\n\n\n", score);

      //DESALOCANDO MEMÓRIA DOS PONTEIROS:
      for (int i = 0; i < nl; i++)
      {
        free(L[i]);
        L[i] = NULL;
      }
      free(L);
      L = NULL;

      free(pf);
      pf = NULL;
      printf("\n\nJogo criado por Francisco Breno (Matricula: 511429)\n\n");
      _sleep(4000);
      return 0;
    }
  } while (cont == 1);

  //DESALOCANDO MEMÓRIA DOS PONTEIROS:
  for (int i = 0; i < nl; i++)
  {
    free(L[i]);
    L[i] = NULL;
  }
  free(L);
  L = NULL;

  for (int i = 0; i < 6; i++)
  {
    free(minotauroGame[i]);
    minotauroGame[i] = NULL;
  }
  free(minotauroGame);

  for (int i = 0; i < 4; i++)
  {
    free(gameOver[i]);
    gameOver[i] = NULL;
  }
  free(gameOver);

  free(pf);
  pf = NULL;

  return 0;
}
