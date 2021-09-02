// PROGRAMA DE JOGO DA VELHA
//
//1 - VALORES VALIDOS? 0 OU X - WHILE/IF
//2 - GANHA:
//    - 3 VALORES IGUAIS NA COLUNA
//    - 3 VALORES IGUAIS NA LINHA
//   - 3 VALORES IGUAIS NAS DIAGONAIS
//3 - EMPATE
//    - NENHUMA DAS ANTERIORES
//4 - QUANDO ACONTECE A VITORIA?
//    - QUANDO UM JOGADOR ATENDE PRIMEIRO UMA DAS REGRAS DO ITEM 2
//5 - 2 JOGADORES:
//    JOGAM ALTERNADAMENTE ENTRE SI
//6 - ANALISE DO VENCEDOR:
//    - A CADA JOGADA CONFERE SE HOUVE GANHADOR
//7 - RESULTADOS: APRESENTAR O VENCEDOR E A MATRIZ
//    RESULTADO
//8 - ESCOLHER QUEM JOGA COM X E QUEM JOGA COM 0


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vencedor, rodada = 9, vezDoJogador = 0, linhaEscolhida, colunaEscolihda,
        lin, col, fimDeJogo=0;
    char pecaJogador1, pecaJogador2, pecaVitoria, matrizVitoria,
         matrizDoJogo[3][3], elementoVazio = ' ';

    printf("\n");
        for(lin = 1; lin < 4; lin++) {
            for(col = 1; col < 4; col++) {
                matrizDoJogo[lin][col] = elementoVazio;
            }
        }

    void funcaoImprimirMatriz() {
        for(lin = 1; lin < 4; lin++) {
            printf("|");
            for(col = 1; col < 4; col++) {
                printf("%c|", matrizDoJogo[lin][col]);
            }
            printf("\n");
        }
    }

    void funcaoEscolherPecaJogador1() {
        printf("Jogador 1 - Digite com qual peça deseja jogar [x ou 0]:");
        scanf("%c%*c", &pecaJogador1);
        if(pecaJogador1 == 'x' || pecaJogador1 == '0') {

        } else {
            printf("Peça não existente... escolha novamente\n");
            funcaoEscolherPecaJogador1();
        }
    }

    void funcaoEscolherPecaJogador2() {
        printf("Jogador 2 - Digite com qual peça deseja jogar [x ou 0]:");
        scanf("%c%*c", &pecaJogador2);
        if((pecaJogador2 != pecaJogador1) && (pecaJogador2 == 'x' || pecaJogador2 == '0'))  {

        } else {
            printf("Peça não existente ou repetida... escolha novamente\n");
            funcaoEscolherPecaJogador2();
        }
    }

    funcaoEscolherPecaJogador1();
    funcaoEscolherPecaJogador2();

    funcaoImprimirMatriz();

    do {
        if(
           (matrizDoJogo[1][1] == 'x' && matrizDoJogo[1][2] =='x' && matrizDoJogo[1][3] == 'x') ||
           (matrizDoJogo[2][1] == 'x' && matrizDoJogo[2][2] =='x' && matrizDoJogo[2][3] == 'x') ||
           (matrizDoJogo[3][1] == 'x' && matrizDoJogo[3][2] =='x' && matrizDoJogo[3][3] == 'x') ||
           (matrizDoJogo[1][1] == 'x' && matrizDoJogo[2][1] =='x' && matrizDoJogo[3][1] == 'x') ||
           (matrizDoJogo[1][2] == 'x' && matrizDoJogo[2][2] =='x' && matrizDoJogo[3][2] == 'x') ||
           (matrizDoJogo[1][3] == 'x' && matrizDoJogo[2][3] =='x' && matrizDoJogo[3][3] == 'x') ||
           (matrizDoJogo[1][1] == 'x' && matrizDoJogo[2][2] =='x' && matrizDoJogo[3][3] == 'x') ||
           (matrizDoJogo[1][3] == 'x' && matrizDoJogo[2][2] =='x' && matrizDoJogo[3][1] == 'x')
           ||
           (matrizDoJogo[1][1] == '0' && matrizDoJogo[1][2] =='0' && matrizDoJogo[1][3] == '0') ||
           (matrizDoJogo[2][1] == '0' && matrizDoJogo[2][2] =='0' && matrizDoJogo[2][3] == '0') ||
           (matrizDoJogo[3][1] == '0' && matrizDoJogo[3][2] =='0' && matrizDoJogo[3][3] == '0') ||
           (matrizDoJogo[1][1] == '0' && matrizDoJogo[2][1] =='0' && matrizDoJogo[3][1] == '0') ||
           (matrizDoJogo[1][2] == '0' && matrizDoJogo[2][2] =='0' && matrizDoJogo[3][2] == '0') ||
           (matrizDoJogo[1][3] == '0' && matrizDoJogo[2][3] =='0' && matrizDoJogo[3][3] == '0') ||
           (matrizDoJogo[1][1] == '0' && matrizDoJogo[2][2] =='0' && matrizDoJogo[3][3] == '0') ||
           (matrizDoJogo[1][3] == '0' && matrizDoJogo[2][2] =='0' && matrizDoJogo[3][1] == '0')
           ){
            fimDeJogo = 1;
            system("cls");

            if (vezDoJogador == 1) {
                pecaVitoria = pecaJogador1;
            } else {
                pecaVitoria = pecaJogador2;
            }

            printf("Vitória do jogador %d - Peça %c\n\n", vezDoJogador, pecaVitoria);

            funcaoImprimirMatriz();

            printf("\nA matriz vitória do jogador foi:\n");
        } else if (rodada <= 0){
            fimDeJogo = 1;
            system("cls");

            funcaoImprimirMatriz();

            printf("\nEmpate !!\n");
            printf("\Nenhum dos jogadores venceram.\n");
        } else {
            system("cls");

            funcaoImprimirMatriz();

            printf("\nRodada: %d\n\n", rodada);

            printf("Jogador 1: %c\n", pecaJogador1);
            printf("Jogador 2: %c\n\n", pecaJogador2);

            void funcaoVezJogador(int jogador, char peca) {
                printf("---- Vez do Jogador %d - Peça: %c ----\n", jogador, peca);
                printf("Digite os números da parte do tabuleiro que deseja marcar [apenas números inteiros]\n");

                void funcaoEscolherLinha() {
                    printf("Linha: ");
                    scanf("%d%*c", &linhaEscolhida);
                    if (linhaEscolhida == 1 || linhaEscolhida == 2 || linhaEscolhida == 3) {

                    } else {
                        printf("Erro. Digite apenas números inteiros!\n");
                        funcaoEscolherLinha();
                    }
                }

                funcaoEscolherLinha();

                printf("Coluna: ");
                scanf("%d%*c", &colunaEscolihda);
                matrizDoJogo[linhaEscolhida][colunaEscolihda] = peca;
            }

            if(vezDoJogador == 0) {
                funcaoVezJogador(1, pecaJogador1);
                vezDoJogador = 1;
            } else {
                funcaoVezJogador(2, pecaJogador2);
                vezDoJogador = 0;
            }

            getch();
            rodada--;
        }

    } while(fimDeJogo != 1);

    return 0;
}
