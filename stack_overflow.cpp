#include <iostream>
using namespace std;

struct Node {
    int data;      // Almacena el valor del nodo
    Node* next;    // Apunta al siguiente nodo
};

class Stack {
private:
    Node* topNode; // Apunta al nodo superior de la pila
    int maxSize;   // Tamaño máximo del stack
    int currentSize; // Número de elementos actuales en el stack

public:
    // Constructor: inicializa la pila vacía y establece la capacidad máxima
    Stack(int capacity) : topNode(nullptr), maxSize(capacity), currentSize(0) {}

    // Inserta un nuevo elemento en la pila
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow: No se pueden agregar más elementos.\n";
            return;
        }
        Node* newNode = new Node();   // Crear un nuevo nodo dinámicamente
        newNode->data = value;        // Asignar valor al nodo
        newNode->next = topNode;      // Apunta al nodo anterior
        topNode = newNode;            // El nuevo nodo es el tope de la pila
        currentSize++;                // Incrementar el tamaño actual
    }

    // Elimina el nodo superior de la pila
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow: La pila está vacía.\n"<<endl;
            return;
        }
        Node* temp = topNode;         // Nodo temporal para eliminar
        topNode = topNode->next;      // Avanzar al siguiente nodo
        delete temp;                  // Liberar memoria
        currentSize--;                // Decrementar el tamaño actual
    }

    // Devuelve el valor del nodo superior
    int top() {
        if (isEmpty()) {
            cout << "El stack está vacío.\n";
            return -1;
        }
        return topNode->data;         // Retorna el valor del nodo superior
    }

    // Verifica si la pila está vacía
    bool isEmpty() {
        return topNode == nullptr;
    }

    // Verifica si la pila está llena
    bool isFull() {
        return currentSize == maxSize;
    }
};

int main() {
    Stack stack(3);  // Crear un stack con capacidad máxima de 3

    stack.push(30);
    stack.push(50);
    stack.push(70);

    cout << "\nEl elemento top: " << stack.top() << endl;
    // Intentar agregar otro elemento causará un overflow

    stack.push(90);  

    stack.pop();
    cout << "El elemento después del pop: " << stack.top() << endl;

    stack.pop();
    stack.pop();

    // Intentar hacer un pop adicional provocará underflow
    stack.pop();  

    return 0;
}
