#include <cstdio>
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;
int index = 0;
bool factor_value(char ops[]);
bool term_value(char ops[]);
bool expression_value(char ops[]);


bool expression_value(char ops[]) {
	// printf("do expres:\n");
	bool result = term_value(ops);
	bool more = true;
	while (more) {
		char op = ops[index];
		// printf("expres get op:%c\n", op);
		if (op == '&' || op == '|') {
			index++;
			bool value = term_value(ops);
			if (op == '&') {
				result = result&value;
			} else {
				result = result|value;
			}
		} else {
			more = false;
		}
	}
	return result;
}

bool term_value(char ops[]) {
	// printf("do term:\n");
	bool result;
	char op = ops[index];
	// printf("term get op:%c\n", op);
	if (op == '!') {
		index++;
		result = !factor_value(ops);
		// printf("qufan: !!!!%d\n", result);
	} else {
		result = factor_value(ops);
	}
	// printf("term result = %d\n", result);
	return result;
}

bool factor_value(char ops[]) {
	// printf("do factor:\n");
	bool result;
	char c = ops[index];
	// printf("factor get c:%c\n", c);
	if (c == '(') {
		index++;
		result = expression_value(ops);
		index++;
	} else if(c == '!'){
        result = term_value(ops);  
    } else if (c == 'V') {
		index++;
		result = true;
	} else if (c == 'F') {
		index++;
		result = false;
	}
	// printf("factor result=%d\n", result);
	return result;
}
int main(int argc, char const *argv[]) {
	/*
	The objective of the program you are going to produce is to evaluate boolean expressions as the one shown next: 
	Expression: ( V | V ) & F & ( F | V )
	计算布尔表达式
	where V is for True, and F is for False. The expressions may include the following operators: ! for not , & for and, | for or , the use of parenthesis for operations grouping is also allowed. 
	V是真，F是假，！是！，&是&&，|是||
	To perform the evaluation of an expression, it will be considered the priority of the operators, the not having the highest, and the or the lowest. The program must yield V or F , as the result for each expression in the input file. 
	！优先级最高，||最低
	输入
	The expressions are of a variable length, although will never exceed 100 symbols. Symbols may be separated by any number of spaces or no spaces at all, therefore, the total length of an expression, as a number of characters, is unknown. 

	The number of expressions in the input file is variable and will never be greater than 20. Each expression is presented in a new line, as shown below. 
	输出
	For each test expression, print "Expression " followed by its sequence number, ": ", and the resulting value of the corresponding test expression. Separate the output for consecutive test expressions with a new line. 

	Use the same format as that shown in the sample output shown below.  
	*/
	// freopen("in.txt", "r", stdin);

	string expres[20];
	int countStr = 0;
	// seperate string
	while (getline(cin, expres[countStr])) {
		countStr++;
	}
	// seperate char
	for (int i = 0; i < countStr; ++i) {
		char ops[100] = "";
		int countOps = 0;
		istringstream input(expres[i]);
		while(input >> ops[countOps]) {
			countOps++;
		}
		// countOps--;
		cout << "Expression " << i+1 << ": ";
		if (expression_value(ops)){
			cout << "V" << endl;
		} else {
			cout << "F" << endl;
		}
		index = 0;
	}

	// cout << expression_value() << endl;
	return 0;
}