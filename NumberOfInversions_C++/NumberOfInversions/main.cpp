//
//  main.cpp
//  NumberOfInversions
//
//  Created by 王雪琪 on 5/25/20.
//  Copyright © 2020 Xueqi Wang. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int length = 100000;

int* getArray(string path){
    int array[length];
    
    // 打开文件，读入数组
    ifstream file;
    string line;
    
    file.open(path);
    int i = 0;
    while(!file.eof()){
        getline(file, line);
        int num = atoi(line.c_str());
        array[i] = num;
        i++;
    }
    file.close();
    return array;
}

struct arr{
    int *array;
    int count;
};

arr mergeAndCount(int *p1, int size1, int *p2, int size2){
    arr temp;
    temp.count = 0;
    
    static int* merge;
    merge = (int*)malloc((size1+size2)*sizeof(int));
    int i=0;
    
    while(size1>0 || size2>0){
        if(size1>0 && size2>0){
            if(*p1 < *p2){
                //cout << "p1 smaller ";
                //cout << "left " << *p1 << " right " << *p2 << endl;
                merge[i] = *p1;
                p1 ++;
                i ++;
                size1 --;
            }
            else{
                //cout << "p2 smaller ";
                //cout << "left " << *p1 << " right " << *p2 << endl;
                merge[i] = *p2;
                p2 ++;
                i ++;
                size2 --;
                temp.count += size1;
            }
        }
        else if(size1>0){
            merge[i] = *p1;
            p1 ++;
            i ++;
            size1 --;
        }
        else if(size2>0){
            merge[i] = *p2;
            p2 ++;
            i ++;
            size2 --;
        }
    }
    int *p = merge;
    //cout << "merge: ";
    //for(int j=0; j<(t1+t2); j++)
    //   cout << *(p+j);
    //cout << endl;
    //cout << "count: " << temp.count << endl;
    temp.array = p;
    return temp;
}

arr sortAndCount(int *p, int size){
    if(size<=1){
        arr temp;
        temp.array = p;
        temp.count = 0;
        return temp;
    }

    arr left = sortAndCount(p, size/2);
    //for(int i=0; i<size/2; i++){
     //   cout << *(left.array+i);
    //}
    //cout << endl;
    arr right = sortAndCount((p+size/2), size - size/2);
    //for(int i=0; i<(size-size/2); i++){
    //    cout << *(right.array+i);
   // }
    //cout << endl;
    arr merge = mergeAndCount(left.array, size/2, right.array, size - size/2);
    
    merge.count += left.count + right.count;
    
    return merge;
}

int main(int argc, const char * argv[]) {
    // 读入数组
    //int *array = getArray("/Users/xueqiwang/Desktop/C++ code/NumberOfInversions/IntegerArray.txt");
    
    int k[6] = {6,5,4,3,2,1};
    int *array = k;
    arr merge = sortAndCount(array, 6);
    //cout << merge.array << endl;
    //cout << merge.array << endl;
    cout << merge.count << endl;
    
    return 0;
}
