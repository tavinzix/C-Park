#include <stdio.h>
#include <Windows.h>

int quantidadeCarro = 0;

void opcao1(void);

void menu(){
    int opcao;

    do{
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
            opcao1();
            break;
        case 2:
            opcao2();
            break;
        case 3:
            opcao3();
            break;
        case 4:
            opcao4();
            break;
        case 5:
            break;
        default:
            printf("Opcao invalida!");
            system("cls");
        }
    } while (opcao != 5);
}

void opcao1(){
	int i = 1;
	
	if(quantidadeCarro == 10){
		printf("Estacionamento esta cheio");
		return 1;
	}else{
		entradaVeiculo();
		printf("Veiculo ja pode estacionar");
		Sleep(2000);
		system("cls");
		quantidadeCarro++;
		return 1;
	}	
}

void entradaVeiculo() {
	FILE *arq;
	
	arq = fopen("teste.txt", "w");
	
    char placa[8];
    char motorista[30];
    char marca[30];
    char modelo[30];
    char horarioEntrada[6];
    int flag;
    
    do {
        flag = 0;
        printf("Informe a placa: ");
        fflush(stdin); //limpa o buffer do teclado
        scanf("%s", placa);
        
        flag = conferePlaca(placa);
        
    } while (flag == 1);
    
    printf("Informe o nome do motorista: ");
    fflush(stdin);
	scanf("%s", motorista);
       
    printf("Informe a marca do carro: ");
    fflush(stdin);
    scanf("%s", marca);
    
    printf("Informe o modelo do carro: ");
    fflush(stdin);
    scanf("%s", modelo);
    
    printf("Informe o horario de entrada do carro: ");
    fflush(stdin);
    scanf("%s", horarioEntrada);
    
    fputs(placa, arq);
    fputs(" ", arq);
    fputs(motorista, arq);
    fputs(" ", arq);
    fputs(marca, arq);
    fputs(" ", arq);
    fputs(modelo, arq);
    fputs(" ", arq);
    fputs(horarioEntrada, arq);
    fputs("\n", arq);
    
    fclose(arq);
}

int conferePlaca(char placa[]) {
    int flag = 0;
    int tamanhoPlaca = strlen(placa);
    
    if (tamanhoPlaca != 7) {
        if (tamanhoPlaca < 7) {
            printf("Placa invalida\n Digitos insuficientes\n\n");
        } else {
            printf("Placa invalida\n Muitos digitos\n\n");
        }
        flag = 1;
    }
    
    for (int i = 0; i < 7; i++) {
        placa[i] = toupper(placa[i]);  
    }

    return flag;
}

void opcao2(){
	char placa[8];
	char horarioSaida[6];
	int flag, i;
	int valorTotal = 0;
	
	do {
        flag = 0;
        printf("Informe a placa: ");
        scanf("%s", placa);
        
        flag = conferePlaca(placa);
        
    } while (flag == 1);
	
	if(placa == placa){
		printf("Informe o horario de saida do carro: ");
    	scanf("%s", horarioSaida);
		
		//valorTotal = (horarioSaida - horarioEntrada)*valorHora;
		
		printf("veiculo ja pode sair");
		Sleep(2000);
		system("cls");
		quantidadeCarro--;
	}else{
		printf("Veiculo nao esta no estacionamento");
	}
	
	
}

void opcao3(){
	FILE *arq;
	char dadosVeiculo[105];
	
	arq = fopen("teste.txt", "r");
	
	if (arq == NULL){
     printf("Nao ha dados!");
    }else{
        while (!feof(arq)){ //representa final de arquivo.
          fgets(dadosVeiculo, 105, arq);
          printf("%s", dadosVeiculo);
        }
    }
	
	fclose(arq);
	
	printf("\nquantidade estacionada %d", quantidadeCarro);
	
	Sleep(5000);
	system("cls");
}

void opcao4(){
	float valor;
	
	printf("valor atual e %.2f\n", valor);
	printf("Qual sera o novo valor? ");
	scanf("%f", &valor);
	
	printf("Valor atualizado para %.2f", valor);
	Sleep(2000);
	system("cls");
}

main(){
    menu();
}
