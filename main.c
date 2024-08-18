#include <stdio.h>

void menu(){
    int opcao;

    do
    {
        printf("\nC-PARK");
        printf("\n\n\n\n");
        printf("1. Informar entrada de veiculo\n");
        printf("2. Informar saida do veiculo \n");
        printf("3. Listar veiculos no patio\n");
        printf("4. Alterar valor\n");
        printf("5. Sair\n\nOpcao: ");
        scanf("%d", &opcao);
        system("cls");

        switch (opcao)
        {
        case 1:
            cadastrarVeiculo();
            break;
        case 2:
            printf("entrou no 2 \n\n");
            break;
        case 3:
            printf("entrou no 3 \n\n");
            break;
        case 4:
            printf("-------------------------------------------\n\n");
            break;
        case 5:
            break;
        default:
            printf("Opcao invalida!");
            // getch();
            system("cls");
        }
    } while (opcao != 5);
}

main(){
    menu();
}
