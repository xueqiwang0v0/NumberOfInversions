#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon May 25 19:21:48 2020

@author: xueqiwang
"""
def mergeAndCount(a, b):
    count = 0
    arr = []
    i = 0
    j = 0
    
    while i<len(a) and j<len(b):
        arr.append(min(a[i],b[j]))
        if a[i] < b[j]:
            i += 1
        else:
            count += len(a[i:])
            j += 1
    arr.extend(a[i:])
    arr.extend(b[j:])
    
    return arr, count
            
    
def sortAndCount(lst):
    if len(lst) <= 1:
        return lst, 0
    
    a,x = sortAndCount(lst[ :int(len(lst)/2)])
    b,y = sortAndCount(lst[int(len(lst)/2): ])
    c,z = mergeAndCount(a, b)
    
    return c, x+y+z


file = open("IntegerArray.txt")
nums = [int(line) for line in file]
file.close()

print(sortAndCount(nums)[1])