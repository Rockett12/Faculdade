#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/*
    Desenvolvido por:

    - Angelo Ricardo;
    - Diego Dantas; @Feelss
    - Felipe Cardoso; e
    - Mateus Do Carmo.
*/

typedef struct{
    short int dia;
    short int mes;
    short int ano;

} Data;

typedef struct {
    int nroConta; /* número da conta (id) */
    char nome[150];
    char senha[105];
    short int estadocivil; /* 1 - Casado, 2- Solteiro */
    double saldo;
    short int status; /* 1- Ativada, 2-Desativada, 3-Bloqueada */
    Data dataDeNascimento;

} Conta;

int carregarDados(Conta contas[]);
void salvarDados(Conta v[],int indiceMax);
int criarConta(Conta contas[],int indiceMax);
void depositar(Conta *user);
int loginConta(Conta contas[],int indiceMax);
int transferencia(Conta v[], int indiceMax, int idLogin);
int desativarConta(Conta* user);
void emitirSaldo(Conta* user);
void continuar();
void sacar(Conta* user);



int main()
{
    Conta vet[2017];
    int option,option2,indiceMax=0,idLogin,on=1,logado,veri;
    indiceMax = carregarDados(vet);

    while(on)
	{
        system("cls");
        printf("\n      *BANK OF HOPE v0.9*        \n");
        printf("\n\n1 - LOGIN\n2 - CRIAR CONTA\n3 - SAIR\n");

        while(scanf("%d",&option)!=1 || option>3 || option<1)
		{
            fflush(stdin);
            printf("Entrada nao reconhecida pelo sistema. Tente novamente.\n");

        }
        fflush(stdin);
        system("cls");

        if(option == 1)
        {
            idLogin=loginConta(vet,indiceMax);
            if(idLogin>-1)
            {
                logado = 1;
                while(logado)
				{
                    system("cls");
                    printf("\n  *LOGADO*    \n");
                    printf("\nConta de ");
                    puts(vet[idLogin].nome);
                    printf("\n1 - Deposito\n2 - Transferencias\n3 - Sacar dinheiro\n4 - Emitir saldo\n5 - Desativar conta\n6 - Logout\n");

                    while(scanf("%d",&option2)!= 1 || option2>6 || option2<1)
					{
                        fflush(stdin);
                        printf("Entrada nao reconhecida pelo sistema. Tente novamente.\n");
                    }
                    fflush(stdin);

                    while(1)
					{
                        if(option2 == 1)
                        {
                            depositar(vet+idLogin);
                            continuar();
                            break;
                        }
                        else if(option2 == 2)
                        {
                            if(transferencia(vet,indiceMax,idLogin)==1)
                                printf("Operacao realizado com sucesso!");

                            continuar();
                            break;
                        }
                        else if(option2 == 3)
                        {
                            sacar(vet+idLogin);
                            continuar();
                            break;
                        }
                        else if(option2 == 4)
                        {
                            emitirSaldo(vet+idLogin);
                            continuar();
                            break;
                        }
                        else if(option2 == 5)
                        {
                            veri = desativarConta(vet+idLogin);
                            if(veri == 1)
                                logado = 0;

                            continuar();
                            break;

                        }
                        else
                        {
                            printf("Saindo da conta...\n");
                            logado = 0;
                            break;
                        }

                    }
                }
            }
            else
			{
                continuar();
                continue;
            }
        }
        else if(option == 2)
        {
            indiceMax = criarConta(vet,indiceMax);
            continuar();
        }
        else
        {
            printf("Feito por Feels, Rockett, Cowboy e Do Carmo.\n");
            printf("The End ~~\n\n");
            salvarDados(vet,indiceMax);
            return 0;
        }
    }
}

int carregarDados(Conta contas[]) /*Retorna indiceMax*/
{
    printf("Carregando... ");
    int i=0;
    FILE *arquivo;
    arquivo=fopen("bankSys.txt","r");
    if(arquivo!=NULL)
	{
		rewind(arquivo);
		while((fscanf(arquivo,"%d\n",&contas[i].nroConta))!= EOF)
		{
            fgets(contas[i].nome,150,arquivo);
            fscanf(arquivo,"%hd\n%s\n%hd %hd %hd\n%lf\n%hd\n",&contas[i].estadocivil,contas[i].senha,&contas[i].dataDeNascimento.dia,&contas[i].dataDeNascimento.mes,&contas[i].dataDeNascimento.ano,&contas[i].saldo,&contas[i].status);
			i++;
		}
		printf("Carregado!\n");
    }
    else{
        printf("ERROR 404\n");
        return 0;
    }
    fclose(arquivo);
    return i;
}

void salvarDados(Conta v[],int indiceMax)
{
	fflush(stdin);
    int i;
    FILE* arq = fopen("bankSys.txt", "w");
    rewind(arq);
    if(arq!=NULL)
    {
        for(i = 0; i<indiceMax; ++i)
        {
            fprintf(arq, "%d\n", v[i].nroConta);
            fputs(v[i].nome, arq);
            fprintf(arq, "\n%hd\n", v[i].estadocivil);
            fprintf(arq, "%s\n", v[i].senha);
            fprintf(arq, "%hd %hd %hd\n", v[i].dataDeNascimento.dia, v[i].dataDeNascimento.mes, v[i].dataDeNascimento.ano);
            fprintf(arq, "%lf\n", v[i].saldo);
            fprintf(arq, "%hd\n", v[i].status);

        }
        fflush(arq);
        fclose(arq);
    }
    else puts("erro ao salvar os dados\n");
}

int criarConta(Conta contas[],int indiceMax)
{
    contas[indiceMax].saldo=0;
    char senha2[105];
    int sim,i;
    printf("\n\nCriando uma nova conta...\n");
    printf("Nome completo: ");

    gets(contas[indiceMax].nome);
    printf("Data de nascimento - ");
    printf("\nDia: ");
    scanf("%hd",&contas[indiceMax].dataDeNascimento.dia);
    fflush(stdin);
    while(1)
	{
        if(contas[indiceMax].dataDeNascimento.dia<32 && contas[indiceMax].dataDeNascimento.dia>0)
            break;
        printf("Entrada nao valida. Tente novamente.");
        printf("\nDia: ");
        scanf("%hd",&contas[indiceMax].dataDeNascimento.dia);
        fflush(stdin);

    }
    printf("Mes: ");
    scanf("%hd",&contas[indiceMax].dataDeNascimento.mes);
    fflush(stdin);
    while(1)
	{
        if(contas[indiceMax].dataDeNascimento.mes<13 && contas[indiceMax].dataDeNascimento.mes>0)
            break;
        printf("Entrada nao valida. Tente novamente.");
        printf("\nMes: ");
        scanf("%hd",&contas[indiceMax].dataDeNascimento.mes);
        fflush(stdin);
    }
    printf("Ano: ");
    scanf("%hd",&contas[indiceMax].dataDeNascimento.ano);
    fflush(stdin);
    while(1)
	{
        if(contas[indiceMax].dataDeNascimento.ano<2002 && contas[indiceMax].dataDeNascimento.ano>1900)
            break;
        printf("Entrada nao valida. Tente novamente.");
        printf("\nAno: ");
        scanf("%hd",&contas[indiceMax].dataDeNascimento.ano);
        fflush(stdin);
    }
    printf("Estado Civil: ");
    while(1)
	{
        printf("\nDigite 1 caso seja solteiro(a). Digite 2 caso seja casado(a)\n");
        scanf("%hd",&contas[indiceMax].estadocivil);
        fflush(stdin);
        if(contas[indiceMax].estadocivil==1 || contas[indiceMax].estadocivil==2)
            break;
        printf("Entrada nao reconhecida. Tente novamente.");

    }

    printf("\nSenha: ");
    gets(contas[indiceMax].senha);
    printf("Repita a senha: ");
    gets(senha2);

    while(1)
	{
        if(strcmp(contas[indiceMax].senha,senha2)==0)
            break;
        printf("As senhas sao diferentes. Tente novamente.\n");
        printf("Senha: ");
        gets(contas[indiceMax].senha);
        printf("Repita a senha: ");
        gets(senha2);
    }
    printf("Conta criada com sucesso!\n");
    printf("\nDeseja adicionar algum saldo inicial?\nCaso deseje digite 1 caso contrario 2.\n");
    while(scanf("%d",&sim) != 1 || sim < 1 || sim > 2)
	{
        printf("Entrada nao reconhecida. Tente novamente.\n");
        fflush(stdin);
    }
    fflush(stdin);
    if(sim == 1)
	{
        printf("Insira o valor a ser adicionado: ");
        while(scanf("%lf",&contas[indiceMax].saldo)!=1 || contas[indiceMax].saldo<0)
        {
            fflush(stdin);
            printf("Insira o valor a ser adicionado: ");
        }
        fflush(stdin);
        printf("\nValor adicionado com sucesso.\nObrigado por escolher nossos servicos!\n");
    }
    else
        printf("Nenhum Saldo adicionado. Obrigado por escolher nossos servicos!\n");

    contas[indiceMax].nroConta=indiceMax;
    contas[indiceMax].status=1;
    printf("\nNumero de conta: %d (Nao esqueca!!)\n",indiceMax);
    return indiceMax+1;
}

void sacar(Conta* user)
{
    double saque = 0;
    int choice;

    printf("\n\nEntre com valor para saque: ");
    while(scanf("%lf",&saque)!=1 || saque<0 || saque > user->saldo)
    {
        fflush(stdin);
        printf("\nOperacao invalida\n");
        printf("Deseja tentar novamente?\n");
        printf("Sim.......digite 1\nNao......digite 2\n");
        while(scanf("%d", &choice)!=1 || choice>2 || choice<1)
        {
            fflush(stdin);
            puts("Escolha invalida!");
            printf("Deseja tentar novamente?\n");
            printf("Sim.......digite 1\nNao......digite 2\n");
        }
        fflush(stdin);
        if(choice==2)
            return;
        else if(choice==1)
            printf("\n\nEntre com valor para saque: ");
    }
    fflush(stdin);

    user->saldo-=saque;
    printf("\nVOCE SACOU R$%.2lf\n",saque);
}

int loginConta(Conta contas[],int indiceMax)
{
    int aux,aux2=4,id2,sucesso=0,choice,choice2;
    char sen[105];
    printf("\n\n    **Login**\n\nInsira o numero da sua conta: ");


    while(scanf("%d",&id2)!=1 || id2<0 || id2>=indiceMax) //validacao do numero da conta
    {
        fflush(stdin);
        printf("Numero de conta invalido!\n");
        while(1)
        {
            printf("Deseja tentar novamente?\n");
            printf("Sim.......digite 1\nNao......digite 2\n");
            scanf("%d", &choice);
            fflush(stdin);
            if(choice==2){
                printf("Cancelado pelo usuario.\n");
                return -1;
            }
            else if(choice==1)
            {
                printf("Insira o numero da sua conta: ");
                break;
            }


            else
                puts("Escolha invalida!");

        }
    }
    printf("Insira sua senha para poder acessar a conta: ");
    fflush(stdin);
    gets(sen);
    while(aux2!=1){
        if(strcmp(contas[id2].senha,sen)==0){
            sucesso=1;
            break;
        }
        printf("Senha errada. Tentar novamente? (%d tentativas restantes)\nDigite 1 se desejar 2 caso contrario.\n",aux2-1);
        while(scanf("%d",&choice2)!=1){
            fflush(stdin);
            if(choice2==2)
                break;
            printf("Entrada invalida. Tente novamente.\n");
        }
        if(choice2 == 2)
            break;

        fflush(stdin);
        printf("Sua senha: ");
        gets(sen);
        aux2--;

        if(aux2==1){
            printf("Sua conta foi bloqueada.\n");
            contas[id2].status=3;
        }
    }
    if(sucesso && contas[id2].status == 1){
        printf("Logado com sucesso!\n");
        return id2;
    }
    else{
        printf("Falha no login.\n");
        return -1;
    }
}

void depositar(Conta* user)
{
    double dep;
    int choice;
    system("cls");
    printf("\n      **DEPOSITO**        \n");

    printf("Valor a ser depositado em sua conta: ");
    while(scanf("%lf", &dep)!=1 || dep<0)
    {
        fflush(stdin);
        puts("Valor invalido.");
        printf("Deseja tentar novamente?\n");
        printf("Sim.......digite 1\nNao......digite 2\n");
        scanf("%d", &choice);
        fflush(stdin);
        if(choice==2)
            return;
        else if(choice==1)
            printf("Valor a ser depositado em sua conta: ");
        else
        {
            puts("Escolha invalida!");
        }
    }
    fflush(stdin);
    user->saldo+=dep;
    printf("Operacao realizada com sucesso!\n");

}

int transferencia(Conta v[], int indiceMax, int idLogin)// retorna 1 se a transacao for bem sucedida, senao retorna 0
{
    int numConta, sair, loop, choice;
    double money;


    printf("Digite o numero da conta de destino: ");



    while(scanf("%d", &numConta)!=1 || numConta<0 || numConta>=indiceMax || idLogin == numConta) //validacao do numero da conta
    {
    	fflush(stdin);
        printf("Numero de conta invalido!\n");
        printf("Deseja tentar novamente?\n");
        printf("Sim.......digite 1\nNao......digite 2\n");
        while(scanf("%d", &choice)!=1 || choice>2 || choice<1)
        {
            fflush(stdin);
            puts("Escolha invalida!");
            printf("Deseja tentar novamente?\n");
            printf("Sim.......digite 1\nNao......digite 2\n");
        }
        fflush(stdin);
        if(choice==2)
            return 0;
        else if(choice==1)
            printf("Digite o numero da conta de destino: ");
    }
    fflush(stdin);
	printf("Digite o valor a ser tranferido: ");
    while( scanf("%lf", &money)!=1 || money<0 || v[idLogin].saldo<money)
    {
    	fflush(stdin);
        if(money<0)
        {
            puts("Entrada Invalida.");
            printf("Digite o valor a ser tranferido: ");
            continue;
        }
        printf("saldo insuficiente\n");
        printf("Deseja tentar novamente?\n");
        printf("Sim.......digite 1\nNao......digite 2\n");
        while(scanf("%d", &choice)!=1 || choice>2 || choice<1)
        {
        	fflush(stdin);
        	puts("Escolha invalida!");
        	printf("Deseja tentar novamente?\n");
        	printf("Sim.......digite 1\nNao......digite 2\n");

        }
        fflush(stdin);
        if(choice==2)
                return 0;
            else if(choice==1)
                printf("Digite o valor a ser tranferido: ");

    }
	fflush(stdin);


    int i;
    for(i=0; i<indiceMax; ++i)
    {
        if(v[i].nroConta == numConta)
            break;
    }

    if(i!=indiceMax && v[i].status==1)
    {
        v[idLogin].saldo-=money;
        v[i].saldo+=money;
    }
    else
    {
        system("cls");
        puts("Falha na transferencia\n");
        return  0;
    }


    return 1;

}

int desativarConta(Conta* user)
{
    int choice;
	printf("Tem certeza que deseja desativar sua conta?\n\n");
    printf("Sim......Digite 1\nNao......Digite 2\n");
    while(scanf("%d", &choice)!=1 || choice>2 || choice<1)
    {

        fflush(stdin);

        puts("Entrada invalida!");
        printf("Tem certeza que deseja desativar sua conta?\n\n");
	    printf("Sim......Digite 1\nNao......Digite 2\n");

    }
    fflush(stdin);


    if(choice==1)
    {
        user->status = 2;
        system("cls");
        printf("Conta desativada.\n");
        return 1;
    }
    else if(choice==2)
    {
        system("cls");
        printf("Procedimento cancelado. Voltando ao menu...\n\n");
        return 0;
    }
}
void emitirSaldo(Conta* user) /* Recebe a referencia para o usuario logado*/
{
    printf("\n      **SALDO**        \n");
    printf("Saldo = R$ %.2lf \n",user->saldo);
}
void continuar()
{
    printf("\nPressione qualquer tecla para continuar... ");
    getch();
    fflush(stdin);
}


