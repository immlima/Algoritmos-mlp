#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

double pri_grau(double x, vector<double>parametros){
    return (parametros[0]*x) + parametros[1];
}

double seg_grau(double x, vector<double>parametros){
    return (parametros[0]*x*x) + (parametros[1]*x) + parametros[2];
}

double exp(double x, vector<double>parametros){
    return parametros[0]*pow(parametros[1],parametros[2]*x);
}

double riemman(double (*func)(double, vector<double>), double x1, double x2, int n, vector<double>param,double cont){


    double dx =(abs(x2-x1)/n);
    for(double i=x1;i<x2;i=i+dx){
      double cont=cont+(dx*(i-1));
    }
    return cont ;
}

double Parametros(int escolha){

    double area, valor, xinicial, xfinal, aux;
    int retangulos = -1;
    vector <double> param;
    //Resolve o problema se o usuário digitar um número negativo para a quantidade retângulos
    while(retangulos < 0){
        cout << "Digite a quantidade de retangulos aproximantes: ";
        cin >> retangulos;
        if(retangulos < 0){
            cout << "valor invalido! Digite novamente:";
            cout << endl;
        }
    }

    cout << "Digite o intervalo: " << endl;
    cout << "x inicial: ";
    cin >> xinicial;
    cout << "x final: ";
    cin >> xfinal;
    //Resolve o problema se o usuário digitar o intervalo errado
    if(xfinal < xinicial){
        cout << endl;
        cout << "Intervalo invalido, x final menor que o inicial." << endl;
        aux = xinicial;
        xinicial = xfinal;
        xfinal = aux;
        cout << "O intervalo foi invertido para o calculo ser realizado." << endl;
        cout << endl;
        cout << "x inicial: " << xinicial << endl;
        cout << "x final: " << xfinal << endl;
        cout << endl;
    }

    cout << "Digite o parametro a: ";
    cin >> valor;
    param.push_back(valor);
    cout << "Digite o parametro b: ";
    cin >> valor;
    param.push_back(valor);

}

int opcaomenu(){

    int opcao;
    cout << "Digite a opcao de função para calcular a area: " << endl;
    cout << "1 - Primeiro Grau - f(x) = ax + b" << endl;
    cout << "2 - Segundo Grau - f(x) = ax^2 + bx + c" << endl;
    cout << "3 - Exponencial - f(x) = a*b^c" << endl;
    cin >> opcao;
    return opcao;
}


    switch(opcaomenu()){
        case 1:
            area = riemman(pri_grau, x1, x2, n, param);
            break;
        case 2:
            cout << "Digite o parametro c: ";
            cin >> valor;
            param.push_back(valor);
            area = riemman(seg_grau, x1, x2, n, param);
            break;
        case 3:
            cout << "Digite o parametro c: ";
            cin >> valor;
            param.push_back(valor);
            area = riemman(exp, x1, x2, n, param);
            break;
        return area;

    }

int main()
{
    int opcao;
    double area;
    cout << "Programa para calcular a area de uma funcao pelo metodo de Riemman!" << endl;
    cout << endl;
    opcao = opcaomenu();
    area = Parametros(opcao);
    cout << "A area eh aproximadamente: " << area << endl;
    return 0;
}
