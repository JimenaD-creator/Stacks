#include <iostream>
using namespace std;
struct Node
    {
        int data; //Almacena el valor del nodo
        Node* next; //Apunta al siguiente nodo
    };
class Stack{
    private:
    Node* topNode; //Apunta al nodo superior de la pila
    public: //Top Node se inicializa con un nullptr
    Stack(): topNode(nullptr){}
    void push(int value){ //Inserción
        Node* newNode = new Node(); //Crear un nuevo nodo dinámicamente en memoria
        newNode -> data = value; //Asigna el valor pasado a la función value al campo data del nuevo nodo
        newNode -> next = topNode; //El nuevo nodo apunta al nodo que antes era el tope de la pila
        topNode = newNode; //Actualiza para que apunte al nuevo nodo
    }
    void pop(){
        if(isEmpty()){
            cout << "El stack está vacio: " <<endl;
            return;

        }
        Node* temp = topNode; //Guarda temporalmente el nodo superior
        topNode = topNode -> next; //Actualiza topNode para que apunte al siguiente nodo
        delete temp; //Elimina el nodo que era el tope de la fila
    }
    int top(){
        if(isEmpty()){
            cout << "El stack esta vacio";
            return -1; 
        }
        return topNode -> data; //Devuelve el valor almacenado en el nodo superior de la pila
    } 
    bool isEmpty(){
        return topNode == nullptr; //Indica que no hay nodos en la pila

    }
    
};
int main(){
    Stack stack;
    stack.push(30);
    stack.push(50);
    stack.push(70);

    cout << "El elemento top: " <<stack.top() <<endl;

    stack.pop();
    cout << "El elemento despues del pop: " <<stack.top();

}