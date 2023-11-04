#include <iostream>

using namespace std;

// class Definition
class Roman {
    private: 
    string roman;
    int num, N;
    public:
    string double_Roman();
    int roman_decimal();
    string getRoman();
    double getNum();
    double getN();
    string str;
};

string Roman::getRoman() {
    return roman;
}

double Roman::getN() {
    return N;
}

double Roman::getNum(){
    return num;
}

// convert from decimals to roman numeral
string Roman::double_Roman() {
    cout <<  "Please enter a number to convert to Roman: " << endl;
    cin >> N;
    
    // Gives error message if number less than 0
    if (N <= 0) {
        cout << "Invalid number. (please enter a number bigger than 0)" << endl;
    }
    else {
        if(N >=1000) {
            num = (N / 1000);

            for(int i = 0; i < num; i++) {
                roman +='M';
            }
            N %= 1000;
        }
        if(N >=100) {
            num = (N / 100);

            if (num == 9) {
                roman += "CM";
            }
            else if (num >= 5) {
                roman += 'D';

                for (int i = 0; i < num - 5; i++) {
                    roman +='C';
                }
            }
            else if(N == 4) {
                roman += "CD";
            }
            else if (N >= 1) {
                for(int i = 0; i < num; i++) {
                    roman +='C';
                }
            }
            N %= 100;
        }

        if (N >= 10) {
            num = (N / 10);

            if (num == 9) {
                roman += "XC";
            }
            else if (num >= 5) {
                roman += 'L';

                for (int i = 0; i< num - 5; i++) {
                    roman += 'X';
                }
            }
            else if (num == 4) {
                roman += "XL";
            }
            else if (num >= 1) {
                for (int i = 0; i < num; i++) {
                    roman += 'X';
                }
            }
            N %= 10;
        }

        if (N >= 1) {
            num = N;

            if (num == 9) {
                roman += "IX";
            }
            else if (num >= 5) {
                roman += "V";
                
                for (int i = 0; i < num - 5; i++) {
                    roman += 'I';
                }
            }
            else if (num == 4) {
                roman += "IV";
            }
            else if (num >= 1) {
                for (int i = 0; i < num; i ++){
                    roman += 'I';
                }
            }
        }
        cout << "Roman Numeral: " << roman << endl;
    }
    return roman;
}

// convert from roman to decimal
int Roman::roman_decimal() {
    
    cout << "Enter the Roman numeral: " << endl;
    cin >> str;
    
    // for loop to 
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'I')
            N++;
        if (str[i] == 'V') {
            if (i > 0 && str[i - 1] == 'I')
                N -= 2;
            N +=5;
        }
        if (str[i] == 'X') {
            if (i > 0 && str[i - 1] == 'I')
                N -= 2;
            N +=10;
        }
        if (str[i] == 'L') {
            if (i > 0 && str[i - 1] == 'X')
                N -= 2;
            N +=50;
        }
        if (str[i] == 'C') {
            if (i > 0 && str[i - 1] == 'L')
                N-= 2;
            N +=100;
        }
        if (str[i] == 'D') {
            if (i > 0 && str[i - 1] == 'C')
                N -=2;
            N +=500;
        }
        if (str[i] == 'M') {
            if (i > 0 && str[i - 1] == 'D') 
                N -=2;
            N +=1000;
        }
    }
    cout << N << endl;
    return N;

}

int main (){
    Roman roman;
    string ans;
    cout << "Enter 'roman' to Convert from decimals to Roman ." << endl;
    cout << "Enter 'decimal' to Convert from Roman to decimals." << endl;
    cin >> ans;
    if (ans == "Roman" || ans == "roman" || ans == "Romans" || ans == "romans") {
        roman.double_Roman();
        cout << "-----------------------------------------------" << endl;
    }
    
    if (ans == "Decimal" || ans == "decimal" || ans == "decimals" || ans == "Decimals") {
        roman.roman_decimal();
        cout << "-----------------------------------------------" << endl;
    }

    return 0;

}