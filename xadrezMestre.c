/* 
 * O código abaixo implementa um jogo de xadrez simples, onde o usuário pode mover diferentes peças 
 (Torre, Bispo, Rainha e Cavalo) em um tabuleiro.
 * As funções são definidas para cada peça, utilizando recursão e loops aninhados para simular os movimentos das peças.
 * O programa exibe um menu para o usuário escolher a peça que deseja mover e executa a função correspondente.
 * O loop continua até que o usuário escolha sair do jogo.
 */

#include <stdio.h>

// Função recursiva para mover a Torre
void moverTorre(int t) {
    if (t > 0) {
        printf("Direita\n"); // Imprime "Direita" para cada casa que a Torre se move
        moverTorre(t - 1); // Chama a função recursivamente com casas - 1
    }
}

// Função para mover o Bispo com loop aninhado
void moverBispo(int b) {
    printf("Movimento do Bispo:\n");

    for (int i = 1; i <= b; i++) { // Loop externo para o movimento vertical
        printf("Cima "); // Imprime "Cima" na mesma linha

        for (int j = 1; j <= b; j++) { // Loop interno para o movimento horizontal
            printf("Direita "); // Imprime "Direita" na mesma linha 
            break; // O Bispo se move apenas uma casa na diagonal por iteração
        }

        printf("\n"); // Quebra de linha após cada movimento diagonal
    }
}

void moverRainha(int r) {
    if (r > 0) {
        printf("Esquerda\n"); // Imprime "Esquerda" para cada casa que a Rainha se move
        moverRainha(r - 1); // Chama a função recursivamente com casas - 1
    }
}

// Função para mover o Cavalo com loop aninhado utilizando continue e break
void moverCavalo() {
    printf("Movimento do Cavalo em 'L':\n");

    for (int i = 0; i < 2; i++) { // Loop para as duas casas para cima
        printf("Cima\n");
        if (i == 1) { // Após a segunda casa para cima, continue para o próximo movimento
            continue; // Ignora o restante do loop e continua para o próximo movimento
        }
    }

    for (int j = 0; j < 1; j++) { // Loop para uma casa para a direita
        printf("Direita\n");
        break; // Finaliza o movimento do Cavalo
    }

}

int main() {
    //Apresentação do jogo
    printf("Jogo de xadrez para Principiantes!\n");
    printf("Neste jogo, você pode escolher entre mover a Torre, o Bispo, a Rainha, ou o Cavalo.\n");
    printf("Cada peça pode se mover um número específico de casas já estabelecido.\n");
    printf("Vamos lá!\n");

    int option;//Declaração da variável option

    // Loop em do-while para exibir o menu e permitir que o usuário escolha uma opção
    do {
        printf("\n");
        printf("Menu:\n");
        printf("1. Mova a Torre 5 casas \n");
        printf("2. Mova o Bispo 5 casas\n");
        printf("3. Mova a Rainha 8 casas\n");
        printf("4. Mova o Cavalo\n");
        printf("5. Sair do Jogo\n");
        printf("\n");
        printf("Escolha uma opção: \n");
        scanf("%d", &option);
        printf("\n");
        
        // Switch-case para executar o código com base na opção escolhida pelo usuário
        switch (option) {
            case 1:
                printf("Você escolheu a Torre\n");
                moverTorre(5); // Chama a função para mover a Torre
                break;

            case 2:
                printf("Você escolheu o Bispo\n");
                moverBispo(5); // Chama a função para mover o Bispo
                break;

            case 3:
                printf("Você escolheu a Rainha\n");
                moverRainha(8); // Chama a função para mover a Rainha
                break;

            case 4:
                printf("Você escolheu o Cavalo\n");
                moverCavalo(); // Chama a função para movimentação complexa do Cavalo
                break;
            
            case 5:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }

    } while (option != 5);//Condição para repetir o loop//até que a opção escolhida seja 5

    return 0;
}