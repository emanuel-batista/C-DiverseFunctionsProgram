/*
    Váriaveis utilizando qualquer letra do alfabeto são apenas auxiliares para funções estéticas do programa
    feito por: Emanuel 
    https:\\www.linkedin.com\in\emanuel-b-silva

    O que foi pedido:
        Criar um programa em C para inserir todas as funcionalidades a seguir, dependendo da opção selecionada:

        1 - Crie uma função que valida se um número de CPF é válido.
        2 - Implemente uma função que converta um dado número de horas em segundos.
        3 - Crie funções para realizar operações básicas de uma calculadora (adição, subtração, multiplicação, divisão).
        4 - Implemente funções para converter temperatura de Celsius para Fahrenheit e vice-versa.
        5 - Escreva funções para converter valores entre diferentes moedas (por exemplo, Real para Dólar).

        *Para o desenvolvimento desta atividade pode ser utilizado um looping (do while) + um conjunto de condições (switch)
*/


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int cp[9], f[2], i, j, k, aux; //variáveis para validação de cpf
float seletortemperatura=1; //variável global para algoritmo de conversao de temperatura

//COMEÇO DO SISTEMA DE VALIDAR CPF
int digitarCPF()
{

    int a = 0;

    for (i = 0; i < 9; i++)
    {
        j = i + 1;
        printf("Digite o %dº numero do seu CPF: ", j);
        scanf("%d", &cp[i]);
    }

    for (aux = 0; aux < 2; aux++)
    {
        int aux2 = aux + 1;
        printf("Digite o %dº dos 2 ultimos digitos do seu cpf: ", aux2);
        scanf("%d", &f[aux]);
    }

    return 0;
}

int validarPrimeiroDigito()
{
    // int validacao =  5 * 11 + 2 * 10 + 9 * 9 + 9 * 8 + 8 * 7 + 2 * 6 + 2 * 5 + 4 * 4 + 7 * 3 + 2 * 2;
    int temp1 = 0;
    temp1 = cp[0] * 10 + cp[1] * 9 + cp[2] * 8 + cp[3] * 7 + cp[4] * 6 + cp[5] * 5 + cp[6] * 4 + cp[7] * 3 + cp[8] * 2;
    // printf("\n%d\n", temp1);

    int validarD1 = (temp1 * 10) % 11;
    if (validarD1 == 10)
    {
        validarD1 = 0;
    }

    return validarD1;
}

int validarSegundoDigito()
{
    int temp2 = 0;
    int temp3 = validarPrimeiroDigito();
    temp2 = cp[0] * 11 + cp[1] * 10 + cp[2] * 9 + cp[3] * 8 + cp[4] * 7 + cp[5] * 6 + cp[6] * 5 + cp[7] * 4 + cp[8] * 3 + temp3 * 2;
    int validarD2 = (temp2 * 10) % 11;
    if (validarD2 == 10)
    {
        validarD2 = 0;
    }

    return validarD2;
}
//FINAL DO SISTEMA DE VALIDAR CPF

//COMEÇO DO ALGORITMO DE VALIDAÇÃO DE HORAS
int conveterHoras(int a)
{
    return (a * 60) * 60;
}
//FINAL DO ALGORITMO DA VALIDAÇÃO DE HORAS

//COMEÇO DO SISTEMA DE CALCULADORA
int somar(int n1, int n2)
{
    return n1 + n2;
}

int subtrair(int n1, int n2)
{
    return n1 - n2;
}

int multiplicar(int n1, int n2)
{
    return n1 * n2;
}

float dividir(int n1, int n2)
{
    if (n2 == 0)
    {
        return 0;
    }

    return n1 / n2;
}
//FINAL DO SISTEMA DE CALCULADORA

//ALGORITMO PARA CONVERSOR DE TEMPERATURA
float conveterTemperatura(float temperatura)
{
    //eu optei por utilizar o if aqui apenas por uma questao estetica pessoal minha, mas poderia ser utilizado o switch case como em varios outros exemplos no codigo
    if (seletortemperatura == 1)
    {
        return temperatura * 1.8 + 32;
    }else if (seletortemperatura == 2)
    {
        return (temperatura - 32) / 1.8;
    }else{
        printf("Operacao invalida!");
        return 0;
    }  
}
//FINAL DO ALGORITMO DE CONVERSOR DE TEMPERATURA

//ALGORITMO DE CONVERSAO DE MOEDA(DOLAR PARA REAL)
float converterMoeda(float v){
   return v * 4.97;//cotação do dia 13/03 as 08:12
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int a = 1;
    int b, c = 1, d, e, calculadora, o1, o2;
    float temperatura, valor;

    do
    {
        if (c > 1)
            printf("\n*******Nova operacao!*******\n");
        else
            printf("---------Bem-vindo(a) ao programa multifuncoes---------\n");

        printf("Digite um dos numeros atribuidos as funcoes abaixo para prosseguir:\n1 - Validacao de CPF\n2 - Conversao de horas em segundos\n3 - Calculadora\n4 - Conversao de temperatura\n5 - Conversao de real para dolar\n>>>Operacao desejada: ");
        scanf("%d", &b);
        switch (b)
        {
        case 1:
            digitarCPF();
            int v1 = validarPrimeiroDigito();
            int v2 = validarSegundoDigito();

            if (v1 != f[0] || v2 != f[1])
            {
                printf("CPF invalido!");
            }
            else
            {
                printf("CPF valido!");
            }
            fflush(stdin);

            break;

        case 2:
            printf("\n>>>Horas a serem convertidas: ");
            scanf("%d", &d);
            printf("%d horas sao %d em segundos.", d, conveterHoras(d));
            fflush(stdin);
            break;

        case 3:
            printf("Digite:\n1 para adicao\n2 para subtracao\n3 para multiplicacao\n4 para divisao\n");
            scanf("%d", &calculadora);

            switch (calculadora)
            {
            case 1:
                printf("Digite dois valores para somar, separados por virgula(ex: 1,3):");
                scanf("%d,%d", &o1, &o2);
                printf("A soma resultou em %d", somar(o1, o2));
                break;
            case 2:
                printf("Digite dois valores para subtrair, separados por virgula(ex: 5,3):");
                scanf("%d,%d", &o1, &o2);
                printf("A subtracao resultou em %d", subtrair(o1, o2));
                break;
            case 3:
                printf("Digite dois valores para multiplicar, separados por virgula(ex: 4,3):");
                scanf("%d,%d", &o1, &o2);
                printf("A multiplicacao resultou em %d", multiplicar(o1, o2));
                break;
            case 4:
                printf("Digite dois valores para dividir, separados por virgula(ex: 10,2):");
                scanf("%d,%d", &o1, &o2);
                if (dividir(o1, o2) == 0)
                {
                    printf("Denominador 0. Divisao invalida!");
                    break;
                }

                printf("A divisao resultou em %.2f", dividir(o1, o2));
                break;

            default:
                printf("Operacao invalida!");
                break;
            }
            fflush(stdin);
            break;
        case 4:
            printf("\n>>>Se voce deseja converter de Celsius para Fahrenheit, digite 1. Caso deseje converter de Fahreinheit para Celsius, digite 2: ");
            scanf("%f", &seletortemperatura);
            if (seletortemperatura == 2)
            {
                printf(">>>Digite a temperatura: ");
                scanf("%f", &temperatura);
                printf("A temperatura em Fahrenheit e igual a: %1.f", conveterTemperatura(temperatura));
            }else if (seletortemperatura == 1)
            {
                printf(">>>Digite a temperatura: ");
                scanf("%f", &temperatura);
                printf("A temperatura em Celsius e igual a: %1.f", conveterTemperatura(temperatura));
            }else{
                printf("Operacao invalida!");
            }
            fflush(stdin);
            break;
        case 5:
            printf("\n>>>Digite o valor em dolar que deseja converter para real: ");
            scanf("%f", &valor);
            printf("O valor convertido para real e de %.2f", converterMoeda(valor));
            fflush(stdin);
            break;    
        default:
            printf("\nOperacao invalida!\n"); 
            break;
        }

        c++;
        printf("\n>>>Deseja realizar uma nova operacao? Digite 1 para sim ou 2 para nao: ");
        scanf("%d", &a);
        if (a == 2)
        {
            printf("\n--------------Obrigado por utilizar o programa :)--------------");
        }
        
        fflush(stdin);

    } while (a == 1);
}