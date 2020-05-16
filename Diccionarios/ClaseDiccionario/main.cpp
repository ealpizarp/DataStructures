#include <iostream>
#include "UnsortedArrayDictionary.h"

using namespace std;

void printKeys(UnsortedArrayDictionary<int, string> &dict){
    List<int>* keys = dict.getKeys();
    cout<<"Llaves del diccionario: ";
    for(keys->goToStart(); !keys->atEnd(); keys->next()){
        cout<< keys->getElement() << " ";
    }
    cout<<endl;
    delete keys;
}
void printValues(UnsortedArrayDictionary<int, string> &dict){
    List<string>* values = dict.getValues();
    cout<<"Valores del diccionario: ";
    for(values->goToStart(); !values->atEnd(); values->next()){
        cout<< values->getElement() << " ";
    }
    cout<<endl;
    delete values;
}

int main()
{
    UnsortedArrayDictionary<int, string> dict;

    dict.insert(3, "tres");
    dict.insert(1, "uno");
    dict.insert(2, "dos");
    dict.insert(5,"cinco");
    dict.insert(4, "cuatro");

    printKeys(dict);
    printValues(dict);
    dict.remove(2);
    printKeys(dict);
    printValues(dict);
    dict.insert(93, "noventa y tres");
    printKeys(dict);
    printValues(dict);
    dict.insert(2, "dos");
    printKeys(dict);
    printValues(dict);

    try{
        dict.insert(93, "noventa");
    }

    catch(runtime_error e){
        cout<< "ERROR: "<< e.what();
        cout<<endl;
    }

    dict.remove(93);
    printKeys(dict);
    printValues(dict);




    return 0;
}
