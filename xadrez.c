#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída (para usar printf e scanf)

// Função recursiva para movimentar a Torre (direita)
void moverTorre(int casas) { 
    if (casas == 0) return; // Condição de parada da recursão
    printf("Direita\n");
    moverTorre(casas - 1); // Chama a função novamente com uma casa a menos
}

// Função recursiva para movimentar a Rainha (esquerda)
void moverRainha(int casas) {
    if (casas == 0) return; // Condição de parada da recursão
    printf("Esquerda\n");
    moverRainha(casas - 1); // Chama a função novamente com uma casa a menos
}

// Função recursiva com loop aninhado para movimentar o Bispo (cima, direita)
void moverBispo(int linha, int coluna, int limite) {
    if (linha >= limite || coluna >= limite) return; // Condição de parada: chegou ao limite do tabuleiro

    for (int i = linha; i < linha + 1; i++) {        // Loop externo para representar linha
        for (int j = coluna; j < coluna + 1; j++) {  // Loop interno para representar coluna
            printf("Cima, Direita\n");
        }
    }

    moverBispo(linha + 1, coluna + 1, limite);       // Chamada recursiva, move uma casa na diagonal
}

// Função com loops aninhados para movimentar o Cavalo (2 para cima e 1 para direita)
void moverCavalo() {
    int movimentos = 1;                               // Quantidade de movimentos em L
    printf("\nMovimentação do Cavalo\n");

    for (int i = 0; i < movimentos; i++) {            // Loop externo: controla a quantidade de "L"
        for (int passo = 0; passo < 3; passo++) {     // Loop interno: 2 passos cima + 1 direita
            if (passo < 2) {
                printf("Cima\n");
                continue;                             // Continua para o próximo passo
            }

            if (passo == 2) {
                printf("Direita\n");
                break;                               // Encerra o loop interno
            }
        }
    }
}

// Função para exibir o menu e armazenar a escolha do usuário
void exibirMenu() {
    int opcao; // Variável que irá armazenar a escilha do usuário
    // Exibe o menu de opções
    do {
        printf("\n========= Menu =========\n");
        printf("1 - Mover Torre\n");
        printf("2 - Mover Bispo\n");
        printf("3 - Mover Rainha\n");
        printf("4 - Mover Cavalo\n");
        printf("5 - Sair\n");
        printf("========================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao); // Lê a opção escolhida pelo usuário

        switch (opcao) {
            case 1:
                printf("\nMovimentação da Torre\n");
                moverTorre(5);                      // Chama função da Torre com 5 casas
                break;  
            case 2:
                printf("\nMovimentação do Bispo\n");
                moverBispo(0, 0, 5);               // Começa o movimento do Bispo a partir de (0,0) com 5 casas
                break;
            case 3:
                printf("\nMovimentação da Rainha\n");
                moverRainha(8);                    // Chama função da Rainha com 8 casas
                break;
            case 4:
                moverCavalo();                     // Chama a função do Cavalo
                break;
            case 5:
                printf("\nSaindo do programa...\n");            // Mensagem de encerramento
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n"); // Trata entrada inválida
        }

    } while (opcao != 5);   // Repete o menu enquanto a opção não for "5 - Sair"
}

// Função principal
int main() {
    exibirMenu();       // Chama a função que mostra o menu e executa as ações
    return 0;
}