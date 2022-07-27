/*FACULTY OF COMPUTERS AND ARTIFICIAL INTELLIGENCE, CAIRO UNIVERSITY
Author :Abdelrhman sayed ali
Program Name: Rational Calculator Program.c plus plus*/
#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <map>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include<windows.h>

using namespace std;


string displaymenu();

void Addition();
string isValidRational_add();

void subtraction();
string isValidRational_subtract();

void multiplication();
string isValidRational_multi();

void dividation();
string isValidRational_divid();


string substring(int first, int last, string str);
int lastBackSlash(string experation);
int midBackSlash(string experation);
int g_c_d(int NumResult, int DenomResult);


void setTextColor(int n);

int main() 
{
    setTextColor(10);
    system("cls");
    cout << "         ===================================================================================\n";
    cout << "                       ******[---- Welcome to Rational Calculator Program ----]******"<<endl;
    cout << "         ===================================================================================="<<endl;
   
    /*string num1,num2,denom1,denom2;
    int n1,n2,d1,d2;
    int num_Result,denom_result,choice;*/
    string choice;
    while (true)
    {
/*        if (!cin)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }*/
        choice = displaymenu();
        //cout << "done" << endl;
        if(choice =="1")
        {
            system("cls");
            Addition();
            //
            cout << "\n                [==--------------------------------------------------------------------------==]\n\n";
            continue;
            //displaymenu();
        }
        else if (choice == "2")
        {
            system("cls");
            subtraction();
            cout << "\n                [==--------------------------------------------------------------------------==]\n\n";
            continue;
            //displaymenu();
        }
        else if (choice == "3")
        {
            system("cls");
            multiplication();
            cout << "\n                [==--------------------------------------------------------------------------==]\n\n";
            continue;
            //displaymenu();

        }
        else if (choice == "4")
        {
            system("cls");
            dividation();
            cout << "\n                [==--------------------------------------------------------------------------==]\n\n";
            continue;
            //displaymenu();
        }
        else if(choice == "5")
        {
            cout <<"\n\n\t\t****** Thank you for using rational number calculator ******\n\n\n";
            return 0;
        }
    }
}

//addition
string displaymenu()
{
    string choice;
    cout<<endl;
    cout << "\n\t\t\t\t<----Choice From List---->\n\n";
    cout << "\t\t1) Add" << endl;
    cout << "\t\t2) Subtract" << endl;
    cout << "\t\t3) Multiply" << endl;
    cout << "\t\t4) Divide" << endl;
    cout << "\t\t5) Quit" << endl;
    
    cout << "\n\n<<<Enter the operation you want: \n>>>";
    cin >> choice;
    
    regex filter("(1|2|3|4|5){1}");
    if (regex_match(choice, filter) == 1)
    {
        return choice;
    }
    else 
    {
        cout << "\n\t\t***** Invaild Input *****";
        displaymenu();
    }
   
}
//this function to calculate experation of Addition.
void Addition()
{
    string experation;
    string num1, denom1, num2, denom2;
    long long numI1, denomI1, numI2, denomI2;
    long long NumResult, denomResult;
    long lastBackS;
    experation = isValidRational_add();
    lastBackS = lastBackSlash(experation);
    num1 = substring(0, experation.find('/'), experation);
    denom1 = substring(experation.find('/') + 1, experation.find('+'), experation);
    num2 = substring(experation.find('+') + 1, lastBackS, experation);
    denom2 = substring(lastBackS + 1, experation.size(), experation);
    numI1 = stoi(num1);
    denomI1 = stoi(denom1);
    numI2 = stoi(num2);
    denomI2 = stoi(denom2);

    NumResult = (numI1 * denomI2) + (numI2 * denomI1);
    denomResult = denomI1 * denomI2;
    cout << "\nThe output for this experation is ---->>> \n";
    cout << NumResult << '/' << denomResult << endl;

    if (NumResult < 0)
    {
        NumResult *= -1;
        
        long maxDivisor = g_c_d(NumResult, denomResult);
        if (maxDivisor != 1)
        {
            cout << (NumResult / maxDivisor) * -1 << '/' << denomResult / maxDivisor << "\n\n";
        }
        // cout << "rational ..>>> " << (((double)NumResult / maxDivisor) * -1) / ((double)denomResult / maxDivisor) <<" \n\n";
    }
    else 
    {
        long maxDivisor = g_c_d(NumResult, denomResult);
        if (maxDivisor != 1)
        {
            cout << NumResult / maxDivisor << '/' << denomResult / maxDivisor << "\n\n";
        }
        //cout << "rational ..>>> " << (((double)NumResult / maxDivisor)) / ((double)denomResult / maxDivisor) <<" \n\n";
    }

    
 
}
//this function to check the experation of Addition.
string isValidRational_add()
{
    string experation;
    cout << "\n<<<Please, Enter the Experation of addition : \n>>>";
    cin >> experation;
    regex validRational_add("[-+]?[0-9]+(/[1-9][0-9]*)?[+][0-9]+(/[1-9][0-9]*)?");
    if (regex_match(experation, validRational_add) == 1)
    {
        return experation;
    }
    else
    {
        cout << "\n*** This experation invaild! ***\n\n";
        isValidRational_add();
    }
    
}
//this function to calculate experation of subtraction.
void subtraction()
{
    string experation;
    string num1, denom1, num2, denom2;
    long long numI1, denomI1, numI2, denomI2;
    long long NumResult, denomResult;
    long lastBackS;
    experation = isValidRational_subtract();
    lastBackS = lastBackSlash(experation);
    num1 = substring(0, experation.find('/'), experation);
    denom1 = substring(experation.find('/') + 1, experation.find('-'), experation);
    num2 = substring(experation.find('-') + 1, lastBackS, experation);
    denom2 = substring(lastBackS + 1, experation.size(), experation);
    numI1 = stoi(num1);
    denomI1 = stoi(denom1);
    numI2 = stoi(num2);
    denomI2 = stoi(denom2);

    NumResult = (numI1 * denomI2) - (numI2 * denomI1);
    denomResult = denomI1 * denomI2;

    cout << "\nThe output for this experation is ---->>> \n";
    cout << NumResult << '/' << denomResult << endl;
    if (NumResult < 0)
    {
        NumResult *= -1;
        
        long maxDivisor = g_c_d(NumResult, denomResult);
        if (maxDivisor != 1)
        {
            cout << (NumResult / maxDivisor) * -1 << '/' << denomResult / maxDivisor << "\n\n";
        }
    }
    else 
    {
        long maxDivisor = g_c_d(NumResult, denomResult);
        if (maxDivisor != 1)
        {
            cout << NumResult / maxDivisor << '/' << denomResult / maxDivisor << "\n\n";
        } 
    }
}
//this function to check the experation of subtraction.
string isValidRational_subtract()
{
    string experation;
    cout << "\n<<<Please, Enter the Experation of subtraction : \n>>>";
    cin >> experation;
    regex validRational_subtract("[-+]?[0-9]+(/[1-9][0-9]*)?[-][0-9]+(/[1-9][0-9]*)?");
    if (regex_match(experation, validRational_subtract) == 1)
    {
        return experation;
    }
    else
    {
        cout << "\n*** This experation invaild! ***\n\n";
        isValidRational_subtract();
    }
    
}
//this function to calculate experation of multiplication.
void multiplication()
{
    string experation;
    string num1, denom1, num2, denom2;
    long long numI1, denomI1, numI2, denomI2;
    long long NumResult, denomResult;
    long lastBackS;
    experation = isValidRational_multi();
    lastBackS = lastBackSlash(experation);
    num1 = substring(0, experation.find('/'), experation);
    denom1 = substring(experation.find('/') + 1, experation.find('*'), experation);
    num2 = substring(experation.find('*') + 1, lastBackS, experation);
    denom2 = substring(lastBackS + 1, experation.size(), experation);
    numI1 = stoi(num1);
    denomI1 = stoi(denom1);
    numI2 = stoi(num2);
    denomI2 = stoi(denom2);

    NumResult = numI1 * numI2 ;
    denomResult = denomI1 * denomI2;

    cout << "\nThe output for this experation is ---->>> \n";
    cout << NumResult << '/' << denomResult << endl;

    if (NumResult < 0)
    {
        NumResult *= -1;
        
        long maxDivisor = g_c_d(NumResult, denomResult);
        if (maxDivisor != 1)
        {
            cout << (NumResult / maxDivisor) * -1 << '/' << denomResult / maxDivisor << "\n\n";
        }     
    }
    else 
    {
        long maxDivisor = g_c_d(NumResult, denomResult);
        if (maxDivisor != 1)
        {
           cout << NumResult / maxDivisor << '/' << denomResult / maxDivisor << "\n\n";
        }     
    }

}
//this function to check the experation of multiplication.
string isValidRational_multi()
{
    string experation;
    cout << "\n<<<Please, Enter the Experation of multiplication : \n>>>";
    cin >> experation;
    regex validRational_multi("[-+]?[0-9]+(/[1-9][0-9]*)?[*][0-9]+(/[1-9][0-9]*)?");
    if (regex_match(experation, validRational_multi) == 1)
    {
        return experation;
    }
    else
    {
        cout << "\n*** This experation invaild! ***\n\n";
        isValidRational_multi();
    }
    
}

//this function to calculate experation of dividation.
void dividation()
{
    string experation;
    string num1, denom1, num2, denom2;
    long long numI1, denomI1, numI2, denomI2;
    long long NumResult, denomResult;
    long lastBackS;
    long midBackS;
    experation = isValidRational_divid();
    lastBackS = lastBackSlash(experation);
    midBackS = midBackSlash(experation);
    //cout << "mid / : " << midBackS << endl;
    num1 = substring(0, experation.find('/'), experation);
    denom1 = substring(experation.find('/') + 1, midBackS, experation);
    num2 = substring(midBackS + 1, lastBackS, experation);
    denom2 = substring(lastBackS + 1, experation.size(), experation);
    numI1 = stoi(num1);
    denomI1 = stoi(denom1);
    numI2 = stoi(num2);
    denomI2 = stoi(denom2);

    NumResult = numI1 * denomI2 ;
    denomResult = denomI1 * numI2;
    
    cout << "\nThe output for this experation is ---->>> \n";
    cout << NumResult << '/' << denomResult << endl;
    if (NumResult < 0)
    {
        NumResult *= -1;
        
        int maxDivisor = g_c_d(NumResult, denomResult);
        if (maxDivisor != 1)
        {
            cout << (NumResult / maxDivisor) * -1 << '/' << denomResult / maxDivisor << "\n\n";
        }  
    }
    else 
    {
        int maxDivisor = g_c_d(NumResult, denomResult);
        if (maxDivisor != 1)
        {
            cout << NumResult / maxDivisor << '/' << denomResult / maxDivisor << "\n\n";
        }     
    }

}
//this function to check the experation of dividation.
string isValidRational_divid()
{
    string experation;
    cout << "\n<<<Please, Enter the Experation of dividation : \n>>>";
    cin >> experation;
    regex validRational_divid("[-+]?[0-9]+(/[1-9][0-9]*)?[/][0-9]+(/[1-9][0-9]*)?");
    if (regex_match(experation, validRational_divid) == 1)
    {
        return experation;
    }
    else
    {
        cout << "\n*** This experation invaild! ***\n\n";
        isValidRational_divid();
    }
    
}


//This funtion to take a part specific of string (like a funtion substring).
string substring(int first, int last, string str)
{
   
    string substr = ""; 
   
   
    for (int i = first; i < last; i++)
    {
        substr += str[i];
    }
    return substr;
}
//this function to find the index of last back slash in experation.
int lastBackSlash(string experation)
{
    for (int i = experation.size() - 1; i >= 0; i--)
    {
        if (experation[i] == '/')
        {
            return i;
            break;
        }
    }
}

//this function to find the index of mid back slash in experation.
int midBackSlash(string experation)
{
    int counter = 0;
    for (int i = experation.size() - 1; i > 0; i--)
    {
        if (experation[i] == '/')//78/78/78/78
        {
            counter += 1;
            if (counter == 2)
            {
                return i;
                break;
            }
        }
    }  
}

//this function to exit the greatest commen divisor. 
int g_c_d(int NumResult, int DenomResult)
{
    int max_divisor = 1;

    for (int i = 1; i <= NumResult; i++)
    {
        for (int i = 1; i <= DenomResult; i++)
        {
            if(NumResult % i == 0 && DenomResult % i == 0)
            {
                if(max_divisor < i)
                {
                    max_divisor = i;
                }
            }
        }
    
    }

    if (max_divisor != 1)
    {
        cout << "\nThe simplification of this experation is --->> \n";
        return max_divisor;
    }
    else if(max_divisor == 1)
    {
        cout << "\n\t\t***** Not exit greatest commen divisor! *****" <<
        "\n\t*** Then not exit simplification for this experation ***\n\n\n";
        return 1;
    }
}

//********************************************************************************************************


void setTextColor(int n)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, n);
}