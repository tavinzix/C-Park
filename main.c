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
	
	arq = fopen("veiculos.txt", "a");
	
    char placa[8];
    char motorista[15];
    char marca[15];
    char modelo[15];
    char horarioEntrada[6];
    int flag;
    
    do {
        flag = 0;
        printf("Informe a placa: ");
        fflush(stdin); //limpa o buffer do teclado
        scanf("%s", placa);
        
        flag = conferePlaca(placa);
        
    } while (flag == 1);
    
    printf("Informe o primeiro nome do motorista: ");
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
    
    fputs("\n", arq);
    fputs(placa, arq);
    fputs(" ", arq);
    fputs(motorista, arq);
    fputs(" ", arq);
    fputs(marca, arq);
    fputs(" ", arq);
    fputs(modelo, arq);
    fputs(" ", arq);
    fputs(horarioEntrada, arq);
   	
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
	FILE *arq, *arqTemp, *val;
  
  	char placa[8];
	char horarioSaida[6];
	int flag, flagPlaca;
	int valorTotal = 0;
	char dadosVeiculo[105];
	int horaEnt,minEnt,horaSai, minSai,tminEnt,tminSai,T_total;
	char leituraValor[10];
	
	do {
        flag = 0;
        printf("Informe a placa: ");
        scanf("%s", placa);
        
        flag = conferePlaca(placa);
        
    } while (flag == 1);
    
    arq = fopen("veiculos.txt", "r+");
    arqTemp = fopen("temp.txt", "w");
    val = fopen("valor.txt", "r");
	
	if (arq == NULL){
    	printf("Nao ha dados!");
    }else{
		while (fgets(dadosVeiculo, 150, arq) != NULL) {
			
			dadosVeiculo[strcspn(dadosVeiculo, "\n")] = 0; //tira o \n do final da linha
			flagPlaca = 0;

	        if (strlen(dadosVeiculo) > 0) {
	            if (strncmp(dadosVeiculo, placa, 7) == 0) {
	                flagPlaca = 1;
	                
	                printf("Informe o horario de saida do carro: ");
			    	scanf("%s", horarioSaida);
					getc(stdin);

					char *separador = strtok(dadosVeiculo, " ");
					char *horaEntrada = separador;
					
					while (separador != NULL) {
						horaEntrada = separador;
						separador = strtok(NULL, " ");
					}
										
					int hE = atoi(horaEntrada);
					int hS = atoi(horarioSaida);	
					float v2 = atoi(fgets(leituraValor, 10, val));
										
					float horaFinal = hS - hE;					
					float valorTotal = (hS - hE)*v2;
										
					printf("Horario estacionado: %f\n", horaFinal);
					printf("Valor R$: %f\n", v2);
					printf("Valor final R$: %f\n", valorTotal);
					
					printf("veiculo ja pode sair");
					Sleep(2000);
					system("cls");
	                continue; 
	            }
	        }
	    fputs("\n", arqTemp);
        fputs(dadosVeiculo, arqTemp);
    }
	    if (!flagPlaca) {
	        printf("Esse veiculo nao esta no estacionamento\n");
	        Sleep(2000);
			system("cls");
	    }   
	}
        fclose(arq);
        fclose(arqTemp);
        
        remove("veiculos.txt");
        rename("temp.txt", "veiculos.txt");
}
	
void opcao3(){
	FILE *arq;
	char dadosVeiculo[105];
	
	arq = fopen("veiculos.txt", "a+");
	
	if (arq == NULL){
    	printf("Nao ha dados!");
    }else{
        while (!feof(arq)){ //representa final de arquivo.
        	fgets(dadosVeiculo, 105, arq);
		    if(dadosVeiculo != NULL ){
		    	if(strlen(dadosVeiculo) > 1){
					printf("   %s", dadosVeiculo);
				 }       
			 }	    
        }
    }
	
	fclose(arq);
	Sleep(5000);
	system("cls");
}

void opcao4(){
	FILE *val;
	val = fopen("valor.txt", "w+");
	char user[5];
	int senha = 0;
	char valor[5];
	
	printf("Faca login para alterar o valor\n");
	
	printf("User:"); scanf("%s", user);
	printf("Senha:"); scanf("%d", &senha);
	
	int cod = strcmp(user, "adm");
	
	if(cod == 0 && senha == 123){
		printf("Qual sera o novo valor? ");
		scanf("%s", valor);
	    fflush(stdin);
	    fputs(valor, val);
	    fclose(val);
	    
	    float valor2 = atoi(valor);
	    	
	   	printf("Valor atualizado para %.2f", valor2);
	   	
	   	Sleep(2000);
		system("cls");
		
	}else{
		printf("Usuario ou senha nao encontrado");
	}
}

main(){
    menu();
}
