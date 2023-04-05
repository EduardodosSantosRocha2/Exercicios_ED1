#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


typedef struct{
    int codigo;
    char nome[100];
    int fone;
}Cli;

typedef struct {
    int num;
    float valor;

    int anoEmissao;
    int mesEmissao;
    int diaEmissao;

    int anoVenc;
    int mesVenc;
    int diaVenc;

    int codcli;
}Rec;


void LerCliente(Cli *cli,int n){
    int i;

    for(i=0;i<n;i++){
        printf("Digite o codigo do %d° cliente que deseja cadrastrar: \n",i+1);
        scanf("%d",&cli[i].codigo);

        printf("Digite o nome do %d° cliente que deseja cadrastrar: \n",i+1);
        setbuf(stdin, NULL);
        fgets(cli[i].nome,19, stdin);

        printf("Digite o telefone do %d° cliente que deseja cadrastrar: \n",i+1);
        scanf("%d",&cli[i].fone);
        printf("*******************************************************\n");



    }
}

void LerRecebimentos(Rec *rec, Cli *cli, int n ){
   int i, x, codigo, salvarvalor = 0;
   for(i = 0; i<n; i++){
        printf("Digite o numero do recebimento do cliente: \n");
        scanf("%d",&rec[i].num);

        printf("Digite o valor do recebimento do cliente: \n");
        scanf("%f",&rec[i].valor);

        printf("Digite a data de emissao dessa maneira por exemplo 7/9/2022 (lembrando de respeitar o octal,ou seja,nao colocando o 0 a esquerda): \n");
        scanf("%d%d%d",&rec[i].diaEmissao, &rec[i].mesEmissao, &rec[i].anoEmissao);

        printf("Digite a data de vencimeto dessa maneira por exemplo 7/9/2022 (lembrando de respeitar o octal,ou seja,nao colocando o 0 a esquerda): \n");
        scanf("%d%d%d",&rec[i].diaVenc, &rec[i].mesVenc, &rec[i].anoVenc);

        do{
        printf("Digite o codigo do cliente do recebimento : \n");
        scanf("%d",&rec[i].codcli);

        codigo = rec[i].codcli;
        x =  Incluirrecebimentos(cli, codigo, 3);


        if(x==1){
            x = Verificarrecebimentos(rec, codigo, 3);
            if(x>2){
                printf("Cliente ja possui 2 recebimentos\n");

            }
            else x=1;
        }

        else{
            printf("Digite de um cliente que ja esta cadastrado!\n");
        }

        }while(x!=1);

        printf("*******************************************************\n");







    }


}












int Incluirrecebimentos(Cli *cli,int codigo, int n){
    int i, j, cont = 0;

        for(j = 0; j<n; j++){
            if(cli[j].codigo == codigo ){
                cont++;
            }
        }
            return cont;




    }



int Verificarrecebimentos(Rec *rec ,int codigo, int n){
    int i, j, cont = 0;

        for(j = 0; j<n; j++){
            if(rec[j].codcli == codigo ){
                cont++;
            }
        }
            return cont;




    }





void Altereocadastrodeclientes(Cli *cli, int n){

    int codigo, i, escolha, cod,fone;
    char nome[100];
    printf("Digite o codigo do cliente que deseja alterar: \n");
    scanf("%d",&codigo);
    printf("Digite:\n1:Alterar codigo do cliente\n2:Alterar nome do cliente\n3:Alterar o numero do cliente\n");
    scanf("%d",&escolha);

    for(i =0; i<n;i++){
        if(codigo == cli[i].codigo){
            if(escolha == 1){
                printf("Digite o novo codigo: \n");
                scanf("%d",&cod);
                cli[i].codigo = cod;
            }

            else if(escolha == 2){
                printf("Digite o novo nome: \n");
                setbuf(stdin,NULL);
                fgets(nome,19,stdin);
                strcpy(cli[i].nome, nome);

            }

            else if(escolha == 3){
                printf("Digite o novo numero: \n");
                scanf("%d",&fone);
                cli[i].fone = fone;
            }

        }


    }
    printf("*******************************************************\n");

}
void Recebimentosdata(Rec *rec, int n, Cli *cli){
    setlocale(LC_ALL,"portuguese");

    int i;
    for(i=0;i<n;i++){
        if(rec[i].anoEmissao> 1998 && rec[i].mesEmissao > 02 && rec[i].diaEmissao > 10 && rec[i].anoVenc < 2023 && rec[i].mesVenc <10 && rec[i].diaVenc < 30){
            printf("\nNome: %s\nTelefone: %d\nValor: %2.f\n",cli[i].nome, cli[i].fone, rec[i].valor);
            printf("*******************************************************\n");

        }
    }



}











int main()
{
    int escolha;
    setlocale(LC_ALL,"portuguese");
    Rec rec[3];
    Cli cli[3];

    do{
    printf("******************************************\n");
    printf(" Digite a sua escolha                     \n");
    printf(" 1:Ler Cliente  e  Ler Recebimento        \n");
    printf(" 2:Altere o cadastro do clientes          \n");
    printf(" 3:Recebimentos data                      \n");
    printf(" 0:Sair                                   \n");
    printf("******************************************\n");
    scanf("%d",&escolha);




    switch(escolha){
        case 1:
        LerCliente(cli,3);
        LerRecebimentos(rec,cli,3);
        break;

        case 2:
            Altereocadastrodeclientes(cli,3);
            break;

        case 3:
            Recebimentosdata(rec,3,cli);
            break;

        default:
            printf("Fim!");
            break;

    }
    }while(escolha !=0);


    return 0;


}
