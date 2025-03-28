#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10
    int tabuleiro[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    int startl = 2, startc = 4, ad = 0;
    for (int i = 1; i < 4; i++) {
        for (int j = 0; j < (i + ad); j++) {
            tabuleiro[startl][startc + j] = 1;
        } 
        startl++;
        startc--;
        ad++;
    }
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0
    for (int i = 1; i < 3; i++) {
        //fazer a linha vertical
        for (int j = 0; j < 3; j++) {
            tabuleiro[6][4 + j] = 1;
        } 
        //fazer a linha horizontal
        for (int j = 0; j < 3; j++) {
            tabuleiro[5 + j][5] = 1;
        } 
    }

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
    for (int i = 1; i < 3; i++) {
        //fazer a linha vertical
        for (int j = 0; j < 5; j++) {
            tabuleiro[8][0 + j] = 1;
        } 
        //fazer a linha horizontal
        for (int j = 0; j < 3; j++) {
            tabuleiro[9 - j][2] = 1;
        } 
    }

    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    for (int iteracao = 1; iteracao < 5; iteracao++) {
        int l, c;

        //Mostra o tabuleiro pro jogador
        printf("Tabuleiro: \n");
        for (int l = 0; l < 10; l++) {
            for (int c = 0; c < 10; c++) {
                printf("%d  ", tabuleiro[l][c]);
            }
            printf("\n");
        }

        while (1) {
            int direcao;
            //Vê se é o primeiro navio
            if (iteracao == 1) {
                //Pergunta qual a direção que o navio
                printf("Qual a linha da coordenada inicial do 1° navio (Horizontal para a direita): \n");
                scanf("%d", &l);
                printf("Qual a coluna da coordenada inicial do 1° navio (Horizontal para a direita): \n");
                scanf("%d", &c);

                //Checa se o navio sairá do mapa
                if (c != 10 && (c + 1) != 10 && (c + 2) != 10) {
                    //Checa se tem outro navio naquela direção
                    if (tabuleiro[l][c] != 3 && tabuleiro[l][c + 1] != 3 && tabuleiro[l][c + 2] != 3) {
                        for (int i = 0; i < 3; i++) {
                            tabuleiro[(l)][(c + i)] = 3;
                        }   
                        break;
                    } else {
                        //Navio saiu do mapa
                        printf("Existe outro navio nessa direção, insira outras coordenadas. \n");
                        continue;
                    }
                } else {
                    //Tem outro navio no caminho
                    printf("O navio saiu do tabuleiro, insira outras coordenadas. \n");
                    continue;
                }

            //Vê se é o segundo navio
            } else if (iteracao == 2) {
                //Pergunta qual a direção que o navio
                printf("Qual a linha da coordenada inicial do 2° navio (Vertical para a cima): \n");
                scanf("%d", &l);
                printf("Qual a coluna da coordenada inicial do 2° navio (Vertical para cima): \n");
                scanf("%d", &c);

                //Checa se o navio sairá do mapa
                if (l != -1 && (l - 1) != -1 && (l - 2) != -1) {
                    //Checa se tem outro navio naquela direção
                    if (tabuleiro[l][c] != 3 && tabuleiro[l - 1][c] != 3 && tabuleiro[l - 2][c] != 3) {
                        for (int i = 0; i < 3; i++) {
                            tabuleiro[(l - i)][c] = 3;
                        }   
                        break;
                    } else {
                        //Navio saiu do mapa
                        printf("Existe outro navio nessa direção, insira outras coordenadas. \n");
                        continue;
                    }
                } else {
                    //Tem outro navio no caminho
                    printf("O navio saiu do tabuleiro, insira outras coordenadas. \n");
                    continue;
                }
            } else if (iteracao == 3) {
                //Pergunta qual a direção que o navio
                printf("Qual a linha da coordenada inicial do 3° navio (Diagonal: Baixo esquerda): \n");
                scanf("%d", &l);
                printf("Qual a coluna da coordenada inicial do 3° navio (Diagonal: Baixo esquerda): \n");
                scanf("%d", &c);

                //Checa se o navio sairá do mapa
                if (l != -1 && (l - 1) != -1 && (l - 2) != -1 && c != -1 && (c + 1) != -1 && (c + 2) != -1) {
                    //Checa se tem outro navio naquela direção
                    if (tabuleiro[l][c] != 3 && tabuleiro[l + 1][c - 1] != 3 && tabuleiro[l + 2][c - 2] != 3) {
                        for (int i = 0; i < 3; i++) {
                            tabuleiro[(l + i)][c - i] = 3;
                        }   
                        break;
                    } else {
                        //Navio saiu do mapa
                        printf("Existe outro navio nessa direção, insira outras coordenadas. \n");
                        continue;
                    }
                } else {
                    //Tem outro navio no caminho
                    printf("O navio saiu do tabuleiro, insira outras coordenadas. \n");
                    continue;
                }
            } else {
                //Pergunta qual a direção que o navio
                printf("Qual a linha da coordenada inicial do 4° navio (Diagonal: Cima direita): \n");
                scanf("%d", &l);
                printf("Qual a coluna da coordenada inicial do 4° navio (Diagonal: Cima direita): \n");
                scanf("%d", &c);

                //Checa se o navio sairá do mapa
                if (l != 10 && (l + 1) != 10 && (l + 2) != 10 && c != 10 && (c - 1) != 10 && (c - 2) != 10) {
                    //Checa se tem outro navio naquela direção
                    if (tabuleiro[l][c] != 3 && tabuleiro[l - 1][c + 1] != 3 && tabuleiro[l - 2][c + 2] != 3) {
                        for (int i = 0; i < 3; i++) {
                            tabuleiro[(l - i)][c + i] = 3;
                        }   
                        break;
                    } else {
                        //Navio saiu do mapa
                        printf("Existe outro navio nessa direção, insira outras coordenadas. \n");
                        continue;
                    }
                } else {
                    //Tem outro navio no caminho
                    printf("O navio saiu do tabuleiro, insira outras coordenadas. \n");
                    continue;
                }                
            }
            
        }
    }

    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.
    printf("Tabuleiro: \n");
    for (int l = 0; l < 10; l++) {
        for (int c = 0; c < 10; c++) {
            printf("%d  ", tabuleiro[l][c]);
        }
        printf("\n");
    }



    return 0;
}
