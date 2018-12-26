#include <iostream>
using namespace std;

int subsequence(char arr[],int size,string output []){ // returning size of the output array and putting subsequence string in it

    if(size==0){
        output[0]="";    // if an empty string is sent then 1 subsequence i.e. empty string is possible
        return 1;
    }
    int smalloutput = subsequence(arr+1,size-1,output); // reaching to the tail of the character array

    for(int i=0;i<smalloutput;i++){
        output[i+smalloutput] = arr[0]+output[i];  // attaching each new element arr[0] to the existing elements in output array
    }
    return 2*smalloutput;       // since we attached a new element to the existing elements in output array the size would have
                               // doubled of the output array so returning double of it
}

int subsequenceUsingStrings(string input,string output []){ // returning size of the output array and putting subsequence string in it

    if(input.empty()){
        output[0]="";       // if an empty string is sent then 1 subsequence i.e. empty string is possible
        return 1;
    }
    string smallstring = input.substr(1);
    int smalloutput = subsequenceUsingStrings(smallstring,output); // reaching to the tail of the character array

    for(int i=0;i<smalloutput;i++){
        output[i+smalloutput] = input[0]+output[i];  // attaching each new element arr[0] to the existing elements in output array
    }
    return 2*smalloutput;     // since we attached a new element to the existing elements in output array the size would have
                              // doubled of the output array so returning double of it
}

int main(){
    char arr[] = {'a','b','c','d'};
    string * output = new string[16];
    //string input = "abcd" ;
    string input;
    cin>>input;

    int size =  subsequenceUsingStrings(input,output);
    // int size = subsequence(arr,4,output);

    for(int i=0;i<size;i++){
        cout<<output[i]<<endl;
    }
    return 0;
}
