//
//  Homework_10_tester.cpp
//  ECE309Tester
//
//  Created by Christian Burke on 11/19/18.
//  Copyright © 2018 Christian Burke. All rights reserved.
//

#include <stdio.h>
#include "IntInf.h"


using namespace ece309;

int main()
{
    // I tested the following lines of code by using the debugger to analyze each value, rather than printing.
    
    
    
    IntInf num = IntInf(10);
    IntInf num2 = IntInf(5);
    IntInf negInf = IntInf(false);
    IntInf posInf = IntInf(true);
    
    IntInf test = IntInf();
    
    // ------------ = testers -------------
    test = 5;
    test = negInf;
    test = posInf;
    
    // ------------ + testers -------------
    test = (num + num2);
    test = (num + posInf);
    test = (num + negInf);
    
    test = (posInf + num);
    test = (posInf + posInf);
    test = (posInf + negInf);
    
    test = (negInf + num);
    test = (negInf + posInf);
    test = (negInf + negInf);
    
    // ------------ - testers -------------
    test = (num - num2);
    test = (num - posInf);
    test = (num - negInf);
    
    test = (posInf - num);
    test = (posInf - posInf);
    test = (posInf - negInf);
    
    test = (negInf - num);
    test = (negInf - posInf);
    test = (negInf - negInf);
    
    // ------------ * testers -------------
    test = (num * num2);
    test = (num * posInf);
    test = (num * negInf);
    
    test = (posInf * num);
    test = (posInf * posInf);
    test = (posInf * negInf);
    
    test = (negInf * num);
    test = (negInf * posInf);
    test = (negInf * negInf);
    
    // ------------ / testers -------------
    test = (num / num2);
    test = (num / posInf);
    test = (num / negInf);
    
    test = (posInf / num);
    test = (posInf / posInf);
    test = (posInf / negInf);
    
    test = (negInf / num);
    test = (negInf / posInf);
    test = (negInf / negInf);
    
    // ------------ == testers -------------

    bool boolTest = (num == num);
    boolTest = (num == num2);
    boolTest = (num == negInf);
    boolTest = (num == negInf);
    
    boolTest = (posInf == num);
    boolTest = (posInf == posInf);
    boolTest = (posInf == negInf);
    
    boolTest = (negInf == num);
    boolTest = (negInf == posInf);
    boolTest = (negInf == negInf);
    
    // ------------ > testers -------------
    boolTest = (num > num2);
    boolTest = (num > posInf);
    boolTest = (num > negInf);
    
    boolTest = (posInf > num);
    boolTest = (posInf > posInf);
    boolTest = (posInf > negInf);
    
    boolTest = (negInf > num);
    boolTest = (negInf > posInf);
    boolTest = (negInf > negInf);
    
    // ------------ < testers -------------
    boolTest = (num < num2);
    boolTest = (num < posInf);
    boolTest = (num < negInf);
    
    boolTest = (posInf < num);
    boolTest = (posInf < posInf);
    boolTest = (posInf < negInf);
    
    boolTest = (negInf < num);
    boolTest = (negInf < posInf);
    boolTest = (negInf < negInf);
    
    test.is_int = boolTest;
    
    return 0;
}
