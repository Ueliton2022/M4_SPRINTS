#include <iostream>
#include <string>
using namespace std;
// 1 -  Fa�a uma fun��o que recebe uma certa medida e ajusta ela percentualmente
// entre dois valores m�nimo e m�ximo e retorna esse valor
double converteSensor(double valor, double minimo, double maximo) {
    double intervalo = maximo - minimo;
    valor = valor - minimo;
    double razao = valor/intervalo;
    double percent = razao*100;
    return percent;
}
// 2 - Fa�a uma fun��o que simule a leitura de um sensor lendo o
// valor do teclado ao final a fun��o retorna este valor
double leituraSensor() {

    double entrada;
    cout << "Digite o valor abaixo:" << "\n";
    cin >> entrada;
    return entrada;
    
}
// 3 - Fa�a uma fun��o que armazena uma medida inteira qualquer
// em um vetor fornecido. Note que como C n�o possui vetores
// nativos da linguagem, lembre-se que voc� precisa passar o
// valor m�ximo do vetor assim como a �ltima posi��o preenchida
// Evite tamb�m que, por acidente, um valor seja escrito em
// uma �rea de mem�ria fora do vetor

int armazenaVetor(int *ptr, int tamanhoVetor, int posicao, int medida) {
    *(ptr+posicao) = medida;
    if (posicao == (tamanhoVetor-1)) {
        return posicao;
    }
    else {
        return posicao + 1;
    }
}

// 4 - Fa�a uma fun��o que recebe um vetor com 4 posi��es que cont�m
// o valor da dist�ncia de um pequeno rob� at� cada um dos seus 4 lados.
// A fun��o deve retornar duas informa��es: A primeira � a dire��o
// de maior dist�ncia ("Direita", "Esquerda", "Frente", "Atras") e a
// segunda � esta maior dist�ncia.
char *direcaoMenorCaminho(int *vetor, int *variavel) {
    char *direita = "direita";
    char *esquerda = "esquerda";
    char *frente = "frente";
    char *atras = "atras";
    int index;
    for (int n = 0; n < 4; n++) {
        if (*(vetor + n) > *variavel) {
            *variavel = *(vetor + n);
            index = n;
        }
    }
    if (index == 0) {
        return direita;
    }
    else if (index == 1) {
        return esquerda;
    }
    else if (index == 2) {
        return frente;
    }
    else {
        return atras;
    }
}
// 5 - Fa�a uma fun��o que pergunta ao usu�rio se ele deseja continuar o mapeamento e
// retorna verdadeiro ou falso
bool leComando() {
    int escolha = 0;
    cout << "Deseja continuar?" << endl;
    cout << "1 - Sim" << endl;
    cout << "2 - Nao" << endl;
    cin >> escolha;
    if (escolha == 1) {
        return 1;
    }
    return 0;
}
// 6 - A fun��o abaixo (que est� incompleta) vai "dirigindo" virtualmente um rob�
// e atrav�s de 4 sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda",
// "Frente", "Atras").
//      A cada passo, ele verifica as dist�ncias aos objetos e vai mapeando o terreno
// para uma movimenta��o futura.
//      Ele vai armazenando estas distancias em um vetor fornecido como par�metro
// e retorna a ultima posicao preenchida do vetor.
//      Esta fun��o deve ir lendo os 4 sensores at� que um comando de pare seja enviado
//
//      Para simular os sensores e os comandos de pare, use as fun��es j� constru�das
// nos �tens anteriores e em um looping cont�nuo at� que um pedido de parada seja
// enviado pelo usu�rio.
//
//      Complete a fun��o com a chamada das fun��es j� criadas
int dirige(int *v,int maxv){
    int maxVetor = maxv;
    int *vetorMov = v;
    int posAtualVetor = 0;
    int dirigindo = 1;
    while(dirigindo){
        int medida = leituraSensor();// .. Chame a fun��o de de leitura da medida para a "Direita"
        medida = converteSensor(medida,0,830);
        posAtualVetor = armazenaVetor(v, maxVetor, posAtualVetor, medida);// Chame a fun��o para armazenar a medida no vetor
        ///////////////////////////////////////////////////////////////////////////
        // Repita as chamadas acima para a "Esquerda", "Frente", "Tras"
        // ................
        ///////////////////////////////////////////////////////////////////////////
        dirigindo = leComando();
    }
    return posAtualVetor;
}
// O trecho abaixo ir� utilizar as fun��es acima para ler os sensores e o movimento
// do rob� e no final percorrer o vetor e mostrar o movimento a cada dire��o baseado
// na maior dist�ncia a cada movimento
void percorre(int *v,int tamPercorrido){
    system("cls");
    int *vetorMov = v;
    int maiorDir = 0;
    for(int i = 0; i< tamPercorrido; i+=4){
        char *direcao = direcaoMenorCaminho(&(vetorMov[i]),&maiorDir);
        printf("Movimentando para %s distancia = %i\n", direcao, maiorDir);
    }
}
int main() {
    int maxVetor = 100;
    int vetorMov[maxVetor*4];
    int posAtualVet = 0;
    posAtualVet = dirige(vetorMov,maxVetor);
    percorre(vetorMov,posAtualVet);
    return 0;
}