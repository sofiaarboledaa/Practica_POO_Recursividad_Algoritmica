#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int n;
void menu(){
    cout<<"Menu - Laboratorio 13. "<<endl;
    cout<<"1. Solucion iterativa. "<<endl;
    cout<<"2. Solucion recursiva. "<<endl;
    cout<<"3. Informacion de estudiantes de algoritmica. "<<endl;
    cout<<"0. Salir. "<<endl;
    cout<<"Ingrese una opcion: ";
}

int valor(){
    int num;
    system("cls");
    cout<<"Ingrese N: "; cin>>num;
    return num;
}

void llenareimprimirarreglo(int a[], int n){
    srand(time(NULL));
    for(int i=0; i<n; i++){
        a[i]=10+rand()%100;
    }
    cout<<"Imprimiendo el arreglo generado aleatoriamente: "<<endl;
    for(int i=0; i<n; i++){
        cout<<i<<"; "<<a[i]<<endl;
    }
    cout<<endl;
}

void solucioniterativa(int a[], int n){
    int inicio=0;
    int fin=n-1;
    while(inicio<fin){
        int temporal=a[0];
        a[inicio]=a[fin];
        a[fin]=temporal;
        inicio++;
        fin--;
    }
    cout<<"El arreglo invertido es: "<<endl;
    for(int i=0; i<n; i++){
        cout<<i<<"; "<<a[i]<<endl;
    }
    cout<<endl;
}

void solucionrecursiva(int a[], int inicio, int fin){
    if(inicio>=fin){
        return;
    }else{
        int temporal=a[inicio];
        a[inicio]=a[fin];
        a[fin]=temporal;
        solucionrecursiva(a, inicio+1, fin-1);
    }
    cout<<"El arreglo invertido es: "<<endl;
    for(int i=0; i<fin+1; i++){
        cout<<i<<"; "<<a[i]<<endl;
    }
    cout<<endl;
}
class estudiante{
    private:
    string codigo;
    string nombre;
    float notafinal;
    public:
    estudiante(){
        codigo="0000";
        nombre="Sin nombre";
        notafinal=0.0;
    }
    estudiante(string _codigo, string _nombre, float _notafinal){
        codigo=_codigo;
        nombre=_nombre;
        notafinal=_notafinal;
    }
    ~estudiante(){
        cout<<"Destructo ejecutado para el estudiante: "<<nombre<<endl;
    }
    void setcodigo(string _codigo){
        codigo=_codigo;
    }
    void setnombre(string _nombre){
        nombre=_nombre;
    }
    void setnotafinal(float _notafinal){
        notafinal=_notafinal;
    }
    string getcodigo(){
        return codigo;
    }
    string getnombre(){
        return nombre;
    }
    float getnotafinal(){
        return notafinal;
    }
    void mostrardatos(){
        cout<<"Datos del estudiante: "<<endl;
        cout<<"Codigo: "<<getcodigo()<<endl;
        cout<<"Nombre: "<<getnombre()<<endl;
        cout<<"Nota final: "<<getnotafinal()<<endl;
    }
};
int main(){
char opc=' ';
do{
    system("cls");
    menu(); cin>>opc;
    switch(opc){
        case '1':{
            system("cls");
            n=valor();
            int a[n];
            cout<<"1. Solucion iterativa. "<<endl;
            llenareimprimirarreglo(a, n);
            solucioniterativa(a, n);
            system("pause");
            break;
        }
        case '2':{
            system("cls");
            n=valor();
            int a[n];
            cout<<"2. Solucion recursiva. "<<endl;
            llenareimprimirarreglo(a, n);
            solucionrecursiva(a, 0, n-1);
            system("pause");
            break;
        }
        case '3':{
            system("cls");
            cout<<"3. Informacion de estudiantes de algoritmica. "<<endl;
            estudiante estudiante1;
            cout<<"Mostramos los datos del estudiante1 creado con el constructor por defecto. "<<endl;
            estudiante1.mostrardatos();
            cout<<"Ahora crearemos un estudiante2 usando el constructor parametrizado y mostraremos sus datos"<<endl;
            estudiante estudiante2("2222", "Pedro", 13);
            estudiante2.mostrardatos();
            cout<<"Asignaremos datos al estudiante 1 usando setters"<<endl;
            estudiante1.setcodigo("1111");
            estudiante1.setnombre("Sofia");
            estudiante1.setnotafinal(14.5);
            estudiante1.mostrardatos();
            cout<<"Ahora modificaremos la nota final del estudiante2 y mostraremos la modificacion. "<<endl;
            estudiante2.setnotafinal(20);
            estudiante2.mostrardatos();
            cout<<"Finalmente accederemos al nombre del estudiante1 usando un getter. "<<endl;
            cout<<"Nombre: "<<estudiante1.getnombre()<<endl;
            system("pause");
            break;
        }
        case '0':{
            break;
        }
        default:{
            cout<<"Error. Ingrese una opcion valida. "<<endl;
        }
    }

}while(opc!='0');
    return 0;
}