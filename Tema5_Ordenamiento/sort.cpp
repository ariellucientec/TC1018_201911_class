#include<iostream>
class Sort  //clase abstracta pq tiene al menos un método virtual puro
{
public:
    virtual int* sort(int* array, int size) = 0; //método abstracto (método virtual puro) 
    void printArray(int* array, int size) //método concreto
    {
        for(int i=0;i<size; i++)
            std::cout << array[i] << " ";
        std::cout << std::endl;
    }
};

class Merge : public Sort  //clase que hereda de manera pública (como en java)
{
public:
    int* sort(int* array, int size);
    int* merge(int* arr1, int size1, int* arr2, int size2);
};

int* Merge::sort(int* array, int size)  //implementación del método sort de la clase Merge
{
    if(size==1) //caso base
        return array;
    else
    {
        // dividir los arreglos
        int size1 = (size>2)?(size/2+1):(size/2);
        int size2 = size - size1;                
        int* arr1 = new int[size1];
        int* arr2 = new int[size2];
        for(int i=0,j=0; j<size;i++)
        {
            if(i<size1)
                arr1[i] = array[i];
            else
                arr2[j++] = array[i];
        }                      
        //****** fin dividir los arreglos          
        int* merged1 = sort(arr1, size1); //sort de la parte izquierda
        int* merged2 = sort(arr2, size2); //sort de la parte derecha
        return merge(merged1, size1, merged2, size2); //merge de los arreglos anteriores
    }
}
int* Merge::merge(int* arr1, int size1, int* arr2, int size2)
{   
    int i=0; //contador para arreglo izquierdo
    int j=0; //contador para arreglo derecho
    int cont=0; //contador para arreglo unión de izquierdo y derecho
    int* mergedArray = new int[size1+size2];
    while(i<size1 && j<size2)
    {                       
        if(arr1[i] > arr2[j])
            mergedArray[cont++] = arr2[j++];            
        else
            mergedArray[cont++] = arr1[i++];                                      
    }
    for(;i<size1;i++) //ciclo para agregar los elementos restantes del arreglo izquierdo
        mergedArray[cont++] = arr1[i];
    for(;j<size2;j++) //ciclo para agregar los elementos restantes del arreglo derecho
        mergedArray[cont++] = arr2[j];
    return mergedArray;
}
int main()
{
    int array1[]{3,27,38,43,0,9, 10, 82, 85, 2,1};
    Merge m; //objeto creado y guardado en el STACK
    int* res = m.sort(array1, 11); //resultado guardado en el HEAP
    m.printArray(res, 11);
}