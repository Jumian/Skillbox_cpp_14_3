#include <iostream>
#include "vector"

void print(std::vector<std::vector<int>> a){
    for (int i=0;i<4;++i){
        for(int k=0;k<4;++k){
            std::cout << a[i][k] << " ";
        }
        std::cout << std::endl;
    }
}

bool isEqual(std::vector<std::vector<int>> a, std::vector<std::vector<int>> b){
    for (int i=0;i<4;++i){
        for(int k=0;k<4;++k){
            if(a[i][k]!=b[i][k]) return false;
        }
    }
    return true;
}

std::vector<std::vector<int>> diagMatrix(std::vector<std::vector<int>> a){
    for (int i=0;i<4;++i)
        for(int k=0;k<4;++k)
            if(i!=k) a[i][k]=0;
    return a;
}

std::vector<std::vector<int>> input(std::vector<std::vector<int>> a, std::string str){
    std::cout<< str<<std::endl;
    for(int i=0;i<4;++i)
        for(int k=0;k<4;++k)
            std::cin >> a[i][k];
    return a;
}

int main() {
    std::vector<std::vector<int>> a = {{1,2,3,4},
               {5,6,7,8},
               {9,10,11,12},
               {13,14,15,16}};
    std::vector<std::vector<int>> b = {{1,2,3,4},
               {5,6,7,8},
               {9,10,11,12},
               {13,14,15,16}};

    a= input(a,"Input matrix 1:");
    b=input(b,"Input matrix 2:");
    std::cout <<"Matrix 1 " <<(isEqual(a,b)?"equal":"not equal") << " matrix 2. Diag matrix:" << std::endl;
    if (isEqual(a,b)) a= diagMatrix(a);
    print(a);
    return 0;
}
