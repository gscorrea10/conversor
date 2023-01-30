#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"

/* Binário para Decimal (Base 2 --> Base 10)
Para converter da base Binária (Base 2) para Decimal (Base 10),
deve se multiplicar todos os números da Base Binária por 2 elevado a potência,
conforme for acrescentando e depois somar os resultados.
 */
int converterBinToDec(int binary_value)
{
    int decimal_value = 0; // valor decimal
    int resto;             // resto da divisão
    int i = 0;             // contador

    while (binary_value != 0)
    {
        resto = binary_value % 10;          // pega o resto da divisão
        binary_value /= 10;                 // divide o valor por 10
        decimal_value += resto * pow(2, i); // soma o resultado da multiplicação do resto por 2 elevado a potência i (contador)
        ++i;                                // incrementa o contador
    }

    return decimal_value;
}

/*
Binário para Octal (Base 2 -> Base 8)
A conversão de Binário para Octal, é totalmente simples,
basta verificar os números binários (ou olhando na tabela, ou convertendo para decimal),
e depois o resultado final, soma se os algarimos.
*/

int converterBinToOctal(int binary_value)
{
    int octal_value = 0;   // valor octal
    int decimal_value = 0; // valor decimal
    int i = 0;

    while (binary_value != 0) // enquanto o valor binário for diferente de 0
    {
        decimal_value += (binary_value % 10) * pow(2, i); // soma o resultado da multiplicação do resto por 2 elevado a potência i (contador)
        ++i;
        binary_value /= 10; // divide o valor por 10
    }

    i = 1;                     // reinicia o contador
    while (decimal_value != 0) // enquanto o valor decimal for diferente de 0
    {
        octal_value += (decimal_value % 8) * i; // soma o resultado da multiplicação do resto por 8 elevado a potência i (contador)
        decimal_value /= 8;                     // divide o valor por 8
        i *= 10;                                // incrementa o contador
    }
    return octal_value;
}

/*
* Decimal para Binário (Base 10 -> Base 2)
Para converter de Decimal para binário, basta ir dividindo o valor Decimal para Binário,
e depois pegar apenas os restos da divisão, da direita para esquerda.
*/

int converterDecToBin(int decimal_value)
{
    int binary_value = 0; // valor binário
    int resto;
    int i = 1;

    while (decimal_value != 0)
    {
        resto = decimal_value % 2; // pega o resto da divisão
        decimal_value /= 2;        // divide o valor por 2
        binary_value += resto * i; // soma o resultado da multiplicação do resto por 2 elevado a potência i (contador)
        i *= 10;
    }

    return binary_value;
}

/*
Decimal para Octal (Base 10 -> Base 8)
Transforma-se primeiro Decimal em Binário, e depois converte o valor transformado para Octal.
*/

int converterDecToOct(int decimal_value)
{
    int octal_value = 0; // valor octal
    int i = 1;

    while (decimal_value != 0)
    {
        octal_value += (decimal_value % 8) * i; // soma o resultado da multiplicação do resto por 8 elevado a potência i (contador)
        decimal_value /= 8;                     // divide o valor por 8
        i *= 10;
    }

    return octal_value;
}

/*
Octal para HexaDecimal (Base 8 -> Base 16)
Transforma-se primeiro Octal em Binário ou Decimal, e depois converte o valor transformado para Hexa
*/

void converterDecToHex(int decimal_value, char hexa_value[100])
{
    int quotient = 0; // valor quociente
    int resto = 0;    // valor resto
    int i = 0;

    while (decimal_value != 0)
    {
        resto = decimal_value % 16; // pega o resto da divisão
        if (resto < 10)             // se o resto for menor que 10
        {
            hexa_value[i] = resto + 48; // soma o resto com 48
        }
        else
        {
            hexa_value[i] = resto + 55; // soma o resto com 55
        }
        i++;
        decimal_value = decimal_value / 16; // divide o valor por 16
    }

    if (i == 0) // se o contador for igual a 0
    {
        hexa_value[0] = '0'; // o valor hexadecimal é 0
        i = 1;
    }

    hexa_value[i] = '\0';   // finaliza a string
    reverse(hexa_value, i); // inverte a string
}

/*
Octal para Decimal (Base 8 -> Base 10)
Assim como binário para decimal, a conversão basta ir multiplicando por 8 em potência.
*/

int converterOctToDec(int octal_value)
{
    int decimal_value = 0;
    int i = 0;

    while (octal_value != 0)
    {
        decimal_value += (octal_value % 10) * pow(8, i); // soma o resultado da multiplicação do resto por 8 elevado a potência i (contador)
        ++i;
        octal_value /= 10; // divide o valor por 10
    }

    return decimal_value;
}

/*
Hexadecimal para Decimal (Base 16 -> Base 10)
Mesmo caso de Binário para Decimal e Octal para Decimal, cada numero do HexaDecimal,
multiplica-se por 16 em potência (sempre acrescentando).
*/

int converterHexToDec(char hexa_value[100])
{
    int decimal_value = 0;
    int i = 0;
    int base = 1; // base

    int size_string = strlen(hexa_value); // tamanho da string

    for (i = size_string--; i >= 0; i--) // percorre a string de trás para frente
    {
        if (hexa_value[i] >= '0' && hexa_value[i] <= '9') // se o valor for entre 0 e 9
        {
            decimal_value += (hexa_value[i] - 48) * base; // se o caractere na possição 'i' for um número (entre 0 e 9), subtrai 48 para obter o valor numérico
            base *= 16;                                   // é multiplicada por 16 a cada iteração para corretamente refletir o valor decimal
        }
        else if (hexa_value[i] >= 'a' && hexa_value[i] <= 'f') // se o valor for entre a e f
        {
            decimal_value = (hexa_value[i] - 87) * base; // se o caractere na possição 'i' for uma letra (entre a e f), subtrai 87 para obter o valor numérico
            base *= 16;
        }
        else if (hexa_value[i] >= 'A' && hexa_value[i] <= 'F') // se o valor for entre A e F
        {
            decimal_value = (hexa_value[i] - 55) * base; // se o caractere na possição 'i' for uma letra (entre A e F), subtrai 55 para obter o valor numérico
            base *= 16;
        }
    }
}

void reverse(char str[], int length) // função para inverter a string
{
    int start = 0;        // inicia a string
    int end = length - 1; // finaliza a string  (tamanho da string - 1)
    while (start < end)   // enquanto o inicio for menor que o final
    {
        char temp = str[start]; // variável temporária recebe o valor do inicio da string
        str[start] = str[end];  // o valor do inicio da string recebe o valor do final da string
        str[end] = temp;        // o valor do final da string recebe o valor da variável temporária
        start++;                // incrementa o inicio
        end--;                  // decrementa o final
    }
}