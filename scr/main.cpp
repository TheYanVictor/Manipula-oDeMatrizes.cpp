/**Programa feito por TheYanVictor*/

#include <iostream>

using namespace std;

#define MAX 4

//Declaracao das funcoes
int sum_total(); //Somatoria de todos os elementos
int sum_pares_princ(); //A somatória dos números pares da diagonal principal
int sum_impares_sec(); //A somatória dos números ímpares da diagonal secundária
int quant_impares_diag(); //A quantidade de números ímpares nas duas diagonais
int quant_pares(); //A quantidade de números pares na matriz
void divide_cinco(); //Os números divisíveis por 5 na matriz
int maior_sec(); //O maior elemento da diagonal secundária
int dif_diagonais(); //A diferença da somatória dos elementos da diagonal principal com a diagonal secundária. 

//Matriz de vetores para referencia
int *matriz_pont[MAX][MAX];
    
int main()
{
    //Definicao da metriz

    //Variaveis
    int matriz[MAX][MAX];
    int i, j, op;
    int acc_total = 0, acc_pares_princ = 0, acc_impares_sec = 0, contador = 0;
    

    //Recebendo valores para a matriz
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
        	cout << "Numero da posicao A(" << i << ")(" << j << "): ";
            cin >> matriz[i][j];
            matriz_pont[i][j] = &matriz[i][j]; //Atribuindo os ponteiros aos valores
        }
    }

	
    //Criando o menu
    do
    {
        system("cls");
        
        //Mostrando a matriz
    	cout << "***Matriz em questao***\n";
    	for (i = 0; i < MAX; i++)
    	{
        	for (j=0; j < MAX; j++)
        	{
            	cout << matriz[i][j] << "\t";
        	}
        	cout << endl;
    	}
    	
    	//Opcoes do menu
        cout << "\n\n***MENU***\n\n";
        cout << "1 - A somatoria dos elementos da matriz" << endl;
        cout << "2 - A somatoria dos numeros pares da diagonal principal" << endl;
        cout << "3 - A somatoria dos numeros impares da diagonal secundaria" << endl;
        cout << "4 - A quantidade de numeros impares nas duas diagonais" << endl;
        cout << "5 - A quantidade de numeros pares na matriz" << endl;
        cout << "6 - Os numeros divisiveis por 5 na matriz" << endl;
        cout << "7 - O maior elemento da diagonal secundaria" << endl;
        cout << "8 - A diferenca da somatoria dos elementos da diagonal principal com a diagonal secundaria" << endl;
        cin >> op;
    

        //Acoes possiveis
        switch(op)
        {
            //Somatoria total
            case 1:
            {
            	system("cls");
                cout << "A somatoria dos elementos eh: " << sum_total(); //Chamada da funcao
    			cout << "\n";
    			system("pause");
                break;
            }

        	//Somatoria dos pares na diagonal principal
           case 2:
                {
                	system("cls");
                    cout << "A soma dos numeros pares na diagonal principal eh: " << sum_pares_princ();//Chamada da funcao
                    cout << "\n";
                    system("pause");
                    break;
                }

            //Somatoria dos numeros impares da diagonal secundaria
            case 3:
                {
                    system("cls");
                    cout << "A somatoria dos numeros impares da diagonal secundaria eh: " << sum_impares_sec();//Chamada da funcao
                    cout << "\n";
                    system("pause");
                    break;
                }

            //Impares nas diagonais
            
            case 4:
            	system("cls");
                cout << "A quantidade de impares nas duas diagonais eh: " << quant_impares_diag();//Chamada da funcao
                cout << "\n";
                system("pause");
                break;

            //Pares na matriz
            case 5:
                system("cls");
                cout << "A quantidade de numeros pares eh: " << quant_pares();//Chamada da funcao
                cout << "\n";
                system("pause");
                break;

            //Divisiveis por 5
            case 6:
                {
                    system("cls");
                    divide_cinco();//Chamada da funcao
                    cout << "\n";
                    system("pause");
                    break;
                }

            //Maior elemento da diagonal secundaria
            case 7:
                {
                    system("cls");
                    cout << "Maior numero da diagonal secundaria: " << maior_sec();//Chamada da funcao
                    cout << "\n";
                    system("pause");
                    break;
                }

            //Diferenca da entre as somatorias das diagonais
            case 8:
                {
                    system("cls");
                    cout << "A diferenca entre a diferenca na somatoria da diagonal principal e da secundaria eh: " << dif_diagonais();//Chamada da funcao
                    cout << "\n";
                    system("pause");
                    break;
                }
        }

    }while(op != 0);

    return 0;
   
}


//Funcao de soma de todos os elementos
int sum_total()
{
	//Variaveis
	int i, j, acc_total = 0;
	
	//Loop de contagem
    for (i = 0; i < MAX; i++)
    {
        for (j=0; j < MAX; j++)
            {
                acc_total += *matriz_pont[i][j];
            }
    }
    
    return acc_total;
}

//Funcao para a somatória dos números pares da diagonal principal
int sum_pares_princ()
{
	//Variaveis
	int i, acc_pares_princ = 0;
	
	//Pares da diagonal
    for (i = 0; i < MAX; i++)
    {
        if(*matriz_pont[i][i] % 2 == 0)
        acc_pares_princ += *matriz_pont[i][i];
    }
    return acc_pares_princ;
}

//Funcao para a somatória dos números ímpares da diagonal secundária
int sum_impares_sec()
{
	//Variaveis
	int i, acc_impares_sec = 0;
	
	//Processamento
	for(i = 0;  i < MAX; i++)
    {
        if (*matriz_pont[i][MAX -1 - i] % 2 != 0) //impar
            {
                acc_impares_sec += *matriz_pont[i][MAX -1 - i];
            }
    }
    return acc_impares_sec;
}

//Funcao para a quantidade de números ímpares nas duas diagonais
int quant_impares_diag()
{
	//Variaveis
	int i, j=0;
	
	//Processamento
	for(i = 0; i < MAX; i++)
    {
        if(*matriz_pont[i][MAX -1 - i] % 2 != 0)
            j += 1;
        if(*matriz_pont[i][i] % 2 != 0)
            j += 1;
    }
    return j;
} 

//Funcao para a quantidade de números pares na matriz
int quant_pares()
{
	//Variaveis
	int i, j, contador = 0;
	
	//Processamento
	for(i = 0; i < MAX; i++)
    {
        for(j = 0; j < MAX; j++)
            {
                if((*matriz_pont[i][j] % 2 == 0) && *matriz_pont[i][j] != 0)
                    contador += 1;
            }
    }
    return contador;
}

//Funcao para achar os números divisíveis por 5 na matriz
void divide_cinco()
{
	//Variaveis
	int i, j;
	
	//Processamento
	for (i = 0; i < MAX; i++)
    {
        for(j = 0; j < MAX; j++)
        {
            if (*matriz_pont[i][j] % 5 == 0)
                cout << *matriz_pont[i][j] << "\t";
        }
    }
}

//Funcao para achar o maior elemento da diagonal secundária
int maior_sec() 
{
	//Variaveis
	int maior, i;

    //Estabelecendo maior
    maior =  *matriz_pont[0][MAX - 1];

    //Fazer a troca
    for(i = 1; i < MAX; i++)
    {
        if(maior < *matriz_pont[i][MAX - 1 - i])
            maior = *matriz_pont[i][MAX - 1 - i];
    }
	return maior;
}

//Funcao para calcular a diferença da somatória dos elementos da diagonal principal com a diagonal secundária. 
int dif_diagonais()
{
	//Variaveis
	int i, acc_princ = 0, acc_sec = 0;
	
	//Processamento
    for(i = 0; i < MAX; i++)
    {
        acc_princ += *matriz_pont[i][i];
    }

    for(i = 0; i < MAX; i++)
    {
        acc_sec += *matriz_pont[i][MAX - 1 - i];
    }
	return acc_princ - acc_sec;
}
