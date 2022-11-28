#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

//Prototipos de Funciones---------------
void cargarDatos(  int Vprod[], string Nombres[], char Nombre[], int Vc[], int Vord[]);
void puntoA(int Vprod[], int t, string Nombres[] , int tam);
void puntoB(int Vc[], int tam);
void puntoC(int Vord[],int tam);
void puntoD(int Vord[], int tam);

//-------------------------
int main()
{
    int opc;
    char Nombre[30];//esta variable se usa para la funcion strcpy
    int Vprod[10]={0};
    string Nombres[10];//vector para guardar los 10 nombres
    int Vcant[10]={0};
    int Vordenes[10]={0};


     while(true)
{
    system("cls");

    cout<<"MENU PRODUCCION"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"1) CARGAR DATOS"<<endl;
    cout<<"2) PUNTO A"<<endl;
    cout<<"3) PUNTO B"<<endl;
    cout<<"4) PUNTO C"<<endl;
    cout<<"5) PUNTO D"<<endl;

    cout<<"------------------------------"<<endl;
    cout<<"0) SALIR"<<endl;

    cout<<"ingrese una opcion"<<endl;
    cin>>opc;

    system("cls");

    switch(opc)
    {
        case 1: cargarDatos( Vprod, Nombres, Nombre, Vcant, Vordenes);
        break;
        case 2: puntoA(Vprod,10, Nombres, 10);
            //en el caso de usar strcpy(), usamos la linea comentada de abajo
            //cout<<"Producto con orden menor a $2000: "<<Nombre<<endl;
        break;
        case 3: puntoB(Vcant, 10);
        break;
        case 4: puntoC(Vordenes, 10);
        break;
        case 5: puntoD( Vordenes, 10);
        break;
        case 0: cout<<"Gracias por utilizar nuestro software"<<endl<<endl;
        return 0;
        break;
        default: cout<<"Error, opcion incorrecta"<<endl<<endl;
        break;
    }
    system("pause");

}
    cout<<"Hola Git!!"<<endl;
    return 0;
}

//Funciones
void cargarDatos(int Vprod[], string Nombres[], char Nombre[], int Vc[], int Vord[])
{
    int N, Nplanta, Cod, Cant;
    float Costo;
    char Name[30];

    cout<<"Ingrese numero de orden: \n";
    cin>>N;
    while(N!=0)
    {
        cout<<"Ingrese numero de planta(1 a 5): "<<endl;
        cin>>Nplanta;
        cout<<"Ingrese codigo de producto(1 a 10): \n";
        cin>>Cod;
        cout<<"Ingrese nombre: "<<endl;
        cin>>Name;
        cout<<"Ingrese cantidad producida: "<<endl;
        cin>>Cant;
        cout<<"Ingrese costo de produccion: "<<endl;
        cin>>Costo;

        //puntoA
        if( Costo < 2000){
           // strcpy(Nombre, Name);
           Vprod[Cod -1] = Costo;
           Nombres[Cod-1] = Name;
        }

        //puntoB
        Vc[Cod - 1] += Cant;

        //puntoC
        Vord[Cod - 1] +=1;

        cout<<"Ingrese numero de orden: \n";
        cin>>N;
    }
}
////funcion A usando un vector de char para guardar todos los nombres(10)
void puntoA(int Vprod[], int t, string Nombres[] , int tam){
    for(int i=0; i<tam; i++){
            if((Vprod[i]!=0)&&(Vprod[i] < 2000)){
                        cout<<"El producto con menos de $2000 de costo es: "<<Nombres[i]<<endl;
            }
    }
}
//funcion B
void puntoB(int Vc[], int tam){
    int MenorCantidad ; //Importante no ponerle nada a MenorCantidad sino clavas el resultado
    int NroMenorCant ;
    for(int i=0; i<tam; i++)
    {
        if((Vc[i]!=0) &&(Vc[i] < MenorCantidad)){
            MenorCantidad = Vc[i];
            NroMenorCant = i+1;
        }
    }
    cout<<"El numero de producto con menor cantidad producida es: "<<NroMenorCant<<endl;
}
//funcion C
void puntoC(int Vord[],int tam){
    cout<<"Cantidad de ordenes para el producto 1: "<<Vord[0]<<endl;
}
//funcion D
void puntoD(int Vord[], int tam){
    for(int i=0; i<tam; i++){
        if(Vord[i] > 0){
            cout<<"Los productos con ordenes de produccion son: "<< i + 1 <<endl;
        }
    }
}




