#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include "pilha.h"

using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");
    Pilha<char> p(80);
    string frase;
    char letra;
    unsigned tam; //Tamanho
    unsigned i, x;
    int opc, igual;

    do{
        cout<< "\n   (ABC)  -  É  Um  Pangrama?  -  (ABC)\n\n" <<endl;
        cout<< "             1  -  Verificar" <<endl;
        cout<< "             2  -  Sair" <<endl;
        cout<< "\n\n   Selecione: ";
        cin>> opc;
        //cin.ignore();

        system("cls");
        cout<< "\n   (ABC)  -  É  Um  Pangrama?  -  (ABC)\n\n" <<endl;

        switch(opc){
            //Verificar s é um Pangrama
            case 1:
                cin.ignore();
                cout<< "   Frase: ";
                getline(cin, frase);

                //cout<< "l: "<<frase;

                tam = frase.size(); //Tamanho da Frase
                i = 0;

                while(i < tam){
                    letra = frase.at(i);

                    //Se elemento é uma Letra
                    if((letra >= 97 && letra <= 122) || (letra >= 65 && letra <=90)){
                        //Se Pilha estiver Vazia
                        if(p.pilhaVazia()){
                            p.empilha(letra);
                        }
                        else{
                            igual=0;
                            for(x=0; x<=p.getTopo(); x++){
                                //Se a Letra da Frase for igual ao que já está na Pilha
                                if(letra == p.getValor(x)){
                                    igual++;
                                }
                            }
                            x=0;
                            //Se a Letra da Frase é diferente de todas que já estão na Pilha
                            if(igual == 0){
                                //cout<<"\n "<<letra;
                                p.empilha(letra);
                            }

                        }
                    }
                    i++;
                }

                if(p.getTopo() == 25){
                    cout<< "\n   Essa Frase é um Pangrama! \n\n   ";
                }
                else{
                    cout<< "\n   Essa Frase não é um Pangrama!\n\n   ";
                }

                //Resetando a Pilha
                while(p.getTopo() != -1){
                    p.desempilha();
                }
                break;

            //Sair
            case 2:
                return 0;
                break;

            default:
                continue;
                break;
        }
        system("pause");
        system("cls");
    }while(opc != 2);
}
