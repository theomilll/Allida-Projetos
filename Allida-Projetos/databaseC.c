#include<stdio.h>
#include<stdlib.h>
 struct node
{
    struct node* ant;
    int dados;
    struct node* prox;
};

struct node* head = NULL;

void inserir(int);
void printar();

struct node* criar_lista(int);

int tamanho();
int main()
{
    int tam,info,queda_c,queda_f;
    int dados, position,batimentos,giroscopio,acelerometro;
    int batimentos_cmp,giroscopio_cmp,acelerometro_cmp,cont=0;

    /*FILE *fp;
    fp = fopen("fall.txt", "w");
    if (fp == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(fp, "This is testing for fprintf...\n");
    fputs("This is testing for fputs...\n", fp);
    fclose(fp);
    return 0;*/
  
    while (1){                              
        printf("\nDigite a captacao do sensor de batimentos: ");
        scanf("%d",&batimentos); //Foi captado os dados hipotéticos dos batimentos cardíacos
      
        if (batimentos==2222) // Condição de parada do loop (a ser desenvolvida)
            break;

        // Para fins de validação, com o intuito de testarmos o programa, idealizamos parâmetros hipotéticos para os três sensores. Para o giroscópio e acelerômetro, estabelecemos uma escala de 0 a 10, onde 0 é representa ausência de movimentos e 10, movimentos muito bruscos
      
        printf("Digite a captacao do giroscopio: ");
        scanf("%d",&giroscopio);// Foi captado os dados hipotéticos do giroscopio
        printf("Digite a captacao do acelerometro: ");
        scanf("%d",&acelerometro);// Foi captado os dados hipotéticos do acelerômetro

        // Os seguintes parâmetros de verificação de quedas são apenas ilustrativos, com base na escala definida acima

        if ((batimentos-batimentos_cmp>=40||batimentos-batimentos_cmp<=-40)&& acelerometro-acelerometro_cmp>=5 && giroscopio-giroscopio_cmp>=5 && cont>0){
          printf("\nFoi detectada uma queda aqui!\n");
            FILE *fp;
            fp = fopen("fall.txt", "w");
            if (fp == NULL){
                printf("Error opening file!\n");
                exit(1);
            }
            fprintf(fp, "1");
            fclose(fp);
            return 0;

        // Caso seja detectada uma queda, a variação dos dados registrados pelos sensores é armazenado numa lista encadeada
          
          inserir(batimentos-batimentos_cmp);
          inserir(acelerometro-acelerometro_cmp);
          inserir(giroscopio-giroscopio_cmp);

        }
        batimentos_cmp=batimentos;
        giroscopio_cmp=giroscopio;
        acelerometro_cmp=acelerometro;
        cont++;
    }
    system("cls");
    tam=tamanho();

  
    printf("\nNo total, fora detectadas %d quedas!\n",tam/3);
    while(1){ // É mostrando o total de quedas durante a execução
        printf("\nVoce deseja ver informacoes de qual das quedas? \n");
        scanf("%d",&info);
        system("cls");
        
        if(info>=1 || info<=tam/3){
            queda_c=(info*3)-3;
            printf("\t Dados da queda %d \t",info); // É mostrado todas as variações dos dados coletados na queda em questão
            printar(queda_c);
          
        }
        else{
            printf("Voce digitou um valor invalido! Encerrando programa...");
          
            break;
        }
    }


}

struct node* criar_lista(int dados)
{
    struct node* novo = (struct node*) malloc(sizeof(struct node));
 
    if (novo == NULL)
    {
        return NULL;
    }
    else
    {
        novo->ant = NULL;
        novo->dados = dados;
        novo->prox = NULL;
    }
}
void inserir(int dados)
{
    struct node* novo = criar_lista(dados);
 
    if (novo == NULL)
    {
        return;
    }
    else if (head == NULL)
    {
        head = novo;
    }
    else
    {
        struct node* temp = head;
        while (temp->prox != NULL)
        {
            temp = temp = temp->prox;
        }
        temp->prox = novo;
        novo->ant = temp;
    }
}

void printar(int c)
{
    struct node* temp = head;
    int cont=0;
    while (temp != NULL)
    {  
        if(c==cont){
        printf("\n Variacao dos batimentos cardiacos: %d  ", temp->dados); // É mostrada a variação dos dados dos batimentos cardíacos
        temp = temp->prox;
        printf("\n Variacao do acelerometro: %d  ", temp->dados);
        temp = temp->prox; // É mostrada a variação dos dados do acelerômetro
        printf("\n Variacao do giroscopio: %d  ", temp->dados);
        temp = temp->prox;// É mostrada a variação dos dados do giroscópio
    }
    temp = temp->prox;
        cont++;

    }
}
int tamanho()
{
    struct node* temp = head;
    int count = 0;
 
    while (temp != NULL)
    {
        count += 1;
        temp = temp->prox;    
    }
 
    return count;
}

/*int fallTransferWrite(void){
    FILE *fp;
    fp = fopen("fall.txt", "w");
    if (fp == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(fp, "This is testing for fprintf...\n");
    fputs("This is testing for fputs...\n", fp);
    fclose(fp);
    return 0;
}*/