#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <conio.h>

/*

Universidade Estadual do Maranhão
Controle de Produtos - Estrutura de Dados
Aluno: João Mateus Cardoso Dutra

*/
typedef struct noProduto{
    char nome_Produto[50];
    int codigo;
    char descricao[100];
    float valor_Unitario;
    int quant_Unidade;
    struct noProduto *prox;

}Produto;


typedef struct noCliente{
    int codigo_Cliente;
    char nome_Cliente[50];
    char cpf[11];
    struct noCliente *prox;
}Cliente;


typedef struct noVendas{
    int codigo_venda;
    int codigo_produto;
    char cpf_venda[11];
    float valor_total;
    struct noVendas *prox;
}Venda;

typedef struct noEstoque_Copia{
    char nome_Produto[50];
    int codigo;
    char descricao[100];
    float valor_Unitario;
    int quant_Unidade;
    struct noProduto *prox;

}EstoqueCopia;


//Criar Lista Vazia/NULL
Cliente *crialista_Cliente_Produto_Vendas() {
    return NULL;
}


//Criar Lista Cliente
Cliente *inserir_Cliente(Cliente *lista){

    Cliente *novo = (Cliente*)malloc(sizeof(Cliente));
    if(lista==NULL){
        lista = novo;
        novo->prox = NULL;
    }else{
    novo->prox = lista;
    lista = novo;
    }
    return lista;
}

//Ordenar Cliente em SelectionSort usando o código do Cliente
void selectionSortClientes(Cliente *lista) {
    Cliente *atual = lista;
    Cliente *index = NULL;
    Cliente *temp = NULL;

    while (atual != NULL) {
        index = atual->prox;
        while (index != NULL) {
            if (atual->codigo_Cliente > index->codigo_Cliente) {
                temp = (Cliente *)malloc(sizeof(Cliente));
                temp->codigo_Cliente = atual->codigo_Cliente;
                strcpy(temp->nome_Cliente, atual->nome_Cliente);
                strcpy(temp->cpf, atual->cpf);

                atual->codigo_Cliente = index->codigo_Cliente;
                strcpy(atual->nome_Cliente, index->nome_Cliente);
                strcpy(atual->cpf, index->cpf);

                index->codigo_Cliente = temp->codigo_Cliente;
                strcpy(index->nome_Cliente, temp->nome_Cliente);
                strcpy(index->cpf, temp->cpf);

                free(temp);
            }
            index = index->prox;
        }
        atual = atual->prox;
    }
}
//Alterar informações do cliente
Cliente *alterar_cliente(Cliente *lista, int codigo_cliente, char novo_nome[50], char novo_cpf[11]) {
    Cliente *verificador = lista;

    while (verificador != NULL && verificador->codigo_Cliente != codigo_cliente) {
        verificador = verificador->prox;
    }

    if (verificador != NULL) {
        strcpy(verificador->nome_Cliente, novo_nome); //Troca de informações
        strcpy(verificador->cpf, novo_cpf); //Troca de informações
    } else {
        printf("\nCliente não encontrado.\n");
    }

    return lista;
}

//Exibir Clientes
void exibir_Clientes(Cliente *lista){
    printf("\n-------Exibindo Clientes-----------\n");
    while(lista!=NULL){
        printf("\n----------------------\n");
        printf("Nome: %s",lista->nome_Cliente);
        printf("\nCPF: %s",lista->cpf);
        printf("\nCódigo do cliente: %d",lista->codigo_Cliente);
        printf("\n-----------------------");
        lista = lista->prox;

    }

}
//Excluir cliente da Lista
void excluir_Cliente(Cliente *lista, int codigo_cliente_excluir){
    Cliente *atual = lista;
    Cliente *anterior = NULL;

    while (atual != NULL && atual->codigo_Cliente != codigo_cliente_excluir) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL) {
        if (anterior == NULL) {
            lista = atual->prox;
        } else {
            anterior->prox = atual->prox;
        }

        free(atual);
    } else {
        printf("\nCliente não encontrado.\n");
    }

    return lista;
}
//Inserir produto na Lista encadeada
Produto *inserir_Produto(Produto *lista){

    Produto *novo = (Produto*)malloc(sizeof(Produto));
    if(lista==NULL){
        lista = novo;
        novo->prox = NULL;
    }else{
    novo->prox = lista;
    lista = novo;
    }
    return lista;
}

//Ordenar os Produtos de forma crescente na Lista Encadeada
void Ordenar_Produtos(Produto *lista) {
    Produto *atual = lista;
    Produto *index = NULL;
    Produto *temp = NULL;

    while (atual != NULL) {
        index = atual->prox;
        while (index != NULL) {
            if (atual->codigo > index->codigo) {
                temp = (Produto *)malloc(sizeof(Produto));

                temp->codigo = atual->codigo;
                temp->valor_Unitario = atual->valor_Unitario;
                temp->quant_Unidade = atual->quant_Unidade;
                strcpy(temp->nome_Produto, atual->nome_Produto);
                strcpy(temp->descricao, atual->descricao);

                atual->codigo = index->codigo;
                atual->valor_Unitario = index->valor_Unitario;
                atual->quant_Unidade = index->quant_Unidade;
                strcpy(atual->nome_Produto, index->nome_Produto);
                strcpy(atual->descricao, index->descricao);

                index->codigo = temp->codigo;
                index->valor_Unitario = temp->valor_Unitario;
                index->quant_Unidade = temp->quant_Unidade;
                strcpy(index->nome_Produto, temp->nome_Produto);
                strcpy(index->descricao, temp->descricao);

                free(temp);
            }
            index = index->prox;
        }
        atual = atual->prox;
    }
}
//Exibir estoque de Produtos
void exibir_Estoque_Produtos(Produto *lista){
    printf("\n-------Exibindo Estoque-----------\n");
    while(lista!=NULL){
        printf("\n----------------------\n");
        printf("Nome do produto: %s",lista->nome_Produto);
        printf("Estoque do produto: %d unidadas",lista->quant_Unidade);
        printf("\nCódigo do produto: %d",lista->codigo);
        printf("\n-----------------------");
        lista = lista->prox;

    }

}

//Alterar o produto
Produto *alterar_produto(Produto *lista, int codigo_produto, char novo_nome[50], char nova_descricao[100], int nova_quant, float novo_valorunit) {
    Produto *verificador = lista;

    while (verificador != NULL && verificador->codigo != codigo_produto) {
        verificador = verificador->prox;
    }

    if (verificador != NULL) {
        strcpy(verificador->nome_Produto, novo_nome);
        strcpy(verificador->descricao, nova_descricao);
        verificador->quant_Unidade = nova_quant;
        verificador->valor_Unitario = novo_valorunit;
    } else {
        printf("\nProduto não encontrado.\n");
    }

    return lista;
}
//Excluir Produto
void excluir_Produto(Produto *lista, int codigo_produto_excluir){
    Produto *atual = lista;
    Produto *anterior = NULL;

    while (atual != NULL && atual->codigo != codigo_produto_excluir) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL) {
        if (anterior == NULL) {
            lista = atual->prox;
        } else {
            anterior->prox = atual->prox;
        }

        free(atual);
    } else {
        printf("\nProduto não encontrado.\n");
    }

    return lista;
}

//Realizar venda
void realizarVenda(Produto* estoque) {
    Produto* produto = estoque;

    if (produto == NULL) {
        printf("Produto não encontrado.\n");
        return;
    }

    if (produto->quant_Unidade == 0) {
        printf("Não há mais quantidade no estoque.\n");
        return;
    }

    produto->quant_Unidade--;

    printf("\nVenda realizada com sucesso para o cliente!");
}

//Criar lista encadeada de Venda
Venda *inserir_Venda(Venda *lista){

    Venda *novo = (Venda*)malloc(sizeof(Venda));
    if(lista==NULL){
        lista = novo;
        novo->prox = NULL;
    }else{
    novo->prox = lista;
    lista = novo;
    }
    return lista;
}

//Exibir as vendas
void exibir_Vendas(Venda *lista){
    printf("\n-------Exibindo Vendas-----------\n");
    while(lista!=NULL){
        printf("\n----------------------\n");
        printf("Código do produto: %d",lista->codigo_produto);
        printf("\nCódigo da venda: 0%d ",lista->codigo_venda);
        printf("\nCPF do comprados: %s",lista->cpf_venda);
        printf("\nTotal do valor: %.2f", lista->valor_total);
        printf("\n-----------------------");
        lista = lista->prox;

    }

}

// Função para copiar o estoque e colocar em uma lista encadeada
Produto* copiarEstoque(Produto* estoqueOriginal) {
    Produto* estoqueCopia = NULL;
    Produto* atualOriginal = estoqueOriginal;

    while (atualOriginal != NULL) {
        Produto* novoProduto = (Produto*)malloc(sizeof(Produto));
        novoProduto->codigo = atualOriginal->codigo;
        strcpy(novoProduto->nome_Produto, atualOriginal->nome_Produto);
        strcpy(novoProduto->descricao, atualOriginal->descricao);
        novoProduto->valor_Unitario = atualOriginal->valor_Unitario;
        novoProduto->quant_Unidade = atualOriginal->quant_Unidade;
        novoProduto->prox = NULL;

        // Adiciona o novo produto à lista encadeada de produtos da cópia
        if (estoqueCopia == NULL) {
            estoqueCopia = novoProduto;
        } else {
            Produto* atualCopia = estoqueCopia;
            while (atualCopia->prox != NULL) {
                atualCopia = atualCopia->prox;
            }
            atualCopia->prox = novoProduto;
        }

        atualOriginal = atualOriginal->prox;
    }

    return estoqueCopia;
}
//Busca binária para produto
int buscaBinaria(Produto* lista, int numero) {
    Produto * atual = lista;
    while (atual != NULL) {
        if (atual->codigo == numero) {
            return 1; // Encontrou o elemento
        }
        atual = atual->prox;
    }
    return 0; // Não encontrou o elemento
}


void menu(){

        system("cls");
        printf("\n|----------------------------------Controle de Produtos---------------------------------------------|\n");
        printf("\n|-----------------------------Pelo Aluno: J. Mateus C. Dutra--------------------------------------|\n\n");
        printf("|1- Inserir produto de forma já ordenada (crescente) usando lista encadeada ------------------------|\n");
        printf("|2- Buscar produto usando a busca binária ----------------------------------------------------------|\n");
        printf("|3- Alterar produto --------------------------------------------------------------------------------|\n");
        printf("|4- Excluir produto --------------------------------------------------------------------------------|\n");
        printf("|5- Exibir estoque----------------------------------------------------------------------------------|\n");
        printf("|6- Inserir Cliente e manter em ordem crescente aplicando o selectionSort --------------------------|\n");
        printf("|7- Alterar Cliente --------------------------------------------------------------------------------|\n");
        printf("|8- Excluir Cliente --------------------------------------------------------------------------------|\n");
        printf("|9- Exibir Clientes --------------------------------------------------------------------------------|\n");
        printf("|10- Realizar vendas e manter em ordem crescente aplicando o insertionSort -------------------------|\n");
        printf("|11- Criar uma cópia do estoque para em outra lista encadeada --------------------------------------|\n");
        printf("|12- Consultar vendas ------------------------------------------------------------------------------|\n");
        printf("|13- Sair ------------------------------------------------------------------------------------------|\n");
        printf("\n|---------------------------------------------------------------------------------------------------|\n");
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    Produto *myProdutos;
    Cliente *myClientes;
    Venda   *myVendas;
    EstoqueCopia *myCopiaEstoque;

    myClientes = crialista_Cliente_Produto_Vendas(); //criando Lista em retorno NULL;
    myProdutos = crialista_Cliente_Produto_Vendas();
    myVendas = crialista_Cliente_Produto_Vendas();
    myCopiaEstoque = crialista_Cliente_Produto_Vendas();

    int opcao;

    do{
    menu();
    printf("\nDigite a opção a ser escolhida: ");
    scanf("%d", &opcao);

        switch(opcao){

            case 1:
            {
                myProdutos = inserir_Produto(myProdutos);
                printf("\n-------------Adicionar Produto---------------\n");
                fflush(stdin);
                printf("\nDigite o nome do produto: ");
                fgets(myProdutos->nome_Produto, sizeof(myProdutos->nome_Produto), stdin);
                fflush(stdin);
                printf("\nDigite a descrição do produto: ");
                fgets(myProdutos->descricao, sizeof(myProdutos->descricao), stdin);
                fflush(stdin);
                printf("\nDigite o valor do produto: ");
                scanf("%f", &myProdutos->valor_Unitario);
                fflush(stdin);
                printf("\nDigite a quantidade produtos: ");
                scanf("%d", &myProdutos->quant_Unidade);
                srand(time(NULL));
                int numero_aleatorio_produto = rand() % 1000;
                printf("\nCódigo do produto gerado: %d", numero_aleatorio_produto);
                myProdutos->codigo = numero_aleatorio_produto;
                printf("\n\n----Aperte qualquer tecla para retornar-----!");
                Ordenar_Produtos(myProdutos);

            }
            getch();
            break;

            case 2:
            {
            int codigo;
            int verificar;
            printf("\n------Busca binária Produto----------");
            printf("\nDigite o código do produto a ser buscado: ");
            scanf("%d", &codigo);
            verificar=buscaBinaria(myProdutos, codigo);
                if(verificar==1){
                    printf("\n\nSeu produto foi encontrado, e está no estoque!");
                }else{
                    printf("\n\nProduto não encontrado ou não está no estoque!!");
                }
            }
            printf("\n\n----Aperte qualquer tecla para retornar-----!");
            getch();
            break;

            case 3:
                 {
                    int quantUnitNew;
                    char nomeProdNew[50];
                    char DescrProdNew[100];
                    float valorNew;
                    int codigo_Prod;

                    printf("\n-----------Alterar informações de Produto------------");
                    printf("\nDigite o código do produto: ");
                    scanf("%d", &codigo_Prod);
                    fflush(stdin);
                    printf("\nDigite o novo nome do produto: ");
                    fgets(nomeProdNew, sizeof(nomeProdNew), stdin);
                    printf("\nDigite a nova descrição do produto: ");
                    fflush(stdin);
                    fgets(DescrProdNew, sizeof(DescrProdNew), stdin);
                    printf("\nDigite a nova quantidade de produtos: ");
                    fflush(stdin);
                    scanf("%d", &quantUnitNew);
                    printf("\nDigite o novo valor do produto: ");
                    fflush(stdin);
                    scanf("%f", &valorNew);
                    alterar_produto(myProdutos, codigo_Prod, nomeProdNew, DescrProdNew, quantUnitNew, valorNew);
                    printf("\n----Aperte qualquer tecla para retornar-----!");

                }
            getch();
            break;

            case 4:
            {
            int codigoProduto_excluir;
            printf("\n-----------Excluir Produto---------------");
            printf("\nDigite o código do produto a ser excluido: ");
            scanf("%d", &codigoProduto_excluir);
            excluir_Produto(myProdutos, codigoProduto_excluir);
            printf("\n-------------Produto exclúido---------------\n");
            printf("\n----Aperte qualquer tecla para retornar-----!");
            }
            getch();
            break;

            case 5:
            exibir_Estoque_Produtos(myProdutos);
            printf("\n\n----Aperte qualquer tecla para retornar-----!");
            getch();
            break;

            case 6:
            {
            myClientes = inserir_Cliente(myClientes);
            printf("\n----------Novo Cliente----------\n");
            printf("Digite o nome do cliente: ");
            fflush(stdin);
            scanf("%s", myClientes->nome_Cliente);
            printf("Digite o CPF do cliente: ");
            fflush(stdin);
            scanf("%s", myClientes->cpf);
            srand(time(NULL));
            int numero_aleatorio = rand() % 1000;
            printf("Código do cliente gerado: %d", numero_aleatorio);
            myClientes->codigo_Cliente = numero_aleatorio;
            printf("\n----Aperte qualquer tecla para retornar-----!");
            selectionSortClientes(myClientes); // ordenando clientes
            }
            getch();
            break;

            case 7:
            {
            char nome_alterar[50];
            char cpf_alterar[50];
            int codigo_cliente;
            printf("\n--------Alterar Cliente/Alterar Informação-----------\n");
            printf("\nDigite o código do cliente: ");
            scanf("%d", &codigo_cliente);
            printf("\nDigite o novo nome a corrigir: ");
            fflush(stdin);
            scanf("%s", &nome_alterar);
            printf("\nDigite o CPF a corrigir: ");
            fflush(stdin);
            scanf("%s", &cpf_alterar);
            alterar_cliente(myClientes, codigo_cliente, nome_alterar, cpf_alterar);
            printf("\n----Aperte qualquer tecla para retornar-----!");
            }
            getch();
            break;

            case 8:
            {
            int codigocliente_excluir;
            printf("\n-----------Excluir Cliente---------------");
            printf("\nDigite o código do cliente a ser excluido: ");
            scanf("%d", &codigocliente_excluir);
            excluir_Cliente(myClientes, codigocliente_excluir);
            printf("\n-------------Cliente exclúido---------------\n");
            printf("\n----Aperte qualquer tecla para retornar-----!");
            }
            getch();
            break;

            case 9:
            exibir_Clientes(myClientes);
            printf("\n\n----Aperte qualquer tecla para retornar-----!");
            getch();
            break;

            case 10:
                {
                    int quantidade_comprar;
                    myVendas = inserir_Venda(myVendas);
                    printf("----------------Vendas de Produtos------------------");
                    printf("\nDigite o código do produto: ");
                    fflush(stdin);
                    scanf("%d", &myVendas->codigo_produto);
                    printf("\nDigite a quantidade do produto que irá comprar: ");
                    scanf("%d", &quantidade_comprar);
                    printf("\nDigite o CPF do cliente: ");
                    fflush(stdin);
                    fgets(myVendas->cpf_venda, sizeof(myVendas->cpf_venda), stdin);
                    realizarVenda(myProdutos);
                    printf("\n\n----Aperte qualquer tecla para retornar-----!");
                    float valor_total = quantidade_comprar*(myProdutos->valor_Unitario);
                    myVendas->valor_total = valor_total;
                    myVendas->codigo_venda = rand() %1000;

                }
            getch();
            break;

            case 11:
            printf("\nCopia de estoque realizada com sucesso!");
            myCopiaEstoque = copiarEstoque(myCopiaEstoque);
            printf("\n\n----Aperte qualquer tecla para retornar-----!");
            getch();
            break;

            case 12:
            exibir_Vendas(myVendas);
            printf("\n----Aperte qualquer tecla para retornar-----!");
            getch();
            break;

            case 13:
            printf("\nFechando o programa!!...\n");
            getch();
            break;

            default:
            printf("\nNúmero digitado inválido!");
            printf("\n----Aperte qualquer tecla para retornar-----!");
            getch();
            break;
        }

    }while(opcao!=13);
    return 0;
}
