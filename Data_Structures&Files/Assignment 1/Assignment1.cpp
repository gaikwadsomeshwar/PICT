#include "Stack.h"

class Conversion {

	char *str;

public:

	Conversion();
	~Conversion();
	void accept();
	void display();
	int priority(char ch);
	char* Reverse(char *Str);
	float Operation(float x,float y,char op);
	char* IntoPost();
	char* IntoPre();
	float EvalPost(char *Str);
	float EvalPre(char *Str);
};

Conversion::Conversion() { str=new char(15); }

Conversion::~Conversion() { delete str; }

void Conversion::accept() {

	cout<<"Enter Expression: ";
	cin>>str;
}

void Conversion::display() {

	cout<<"Expression: "<<str<<endl;
}

int Conversion::priority(char ch) {

	if(ch=='^')
		return 3;

	else if(ch=='*' || ch=='/' || ch=='%')
		return 2;

	else if(ch=='+' || ch=='-')
		return 1;

	return -1;
}

float Conversion::Operation(float x,float y,char op) {

	switch(op) {

			case '+': return (x+y);
			case '-': return (x-y);
			case '*': return (x*y);
			case '/': return (x/y);
			case '%': return ((int)x%(int)y);
			case '^': return 0;
			default: return -1;
		}
}

char* Conversion::Reverse(char *Str) {

	char *rev=new char(strlen(Str));
	int i,j=0;

	for(i=(strlen(Str))-1;i>=0;i--) {

		if(Str[i]=='(')
			rev[j++]=')';

		else if(Str[i]==')')
			rev[j++]='(';

		else
			rev[j++]=Str[i];
	}

	rev[j]='\0';

	return rev;
}

char* Conversion::IntoPost() {

	Stack S;
	char *out;
	int len=strlen(str),j=0;
	out=new char[len];

	for(int i=0;i<len;i++) {

		char ch=str[i];

		if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z'))
			out[j++]=ch;

		else switch(ch) {

			case '(': {

				S.push((int)ch);
				break;
			}
			case ')': {

				char c;
				while((char)S.showTop()!='(') {

					c=(char)S.pop();
					out[j++]=c;
				}
				if((char)S.showTop()=='(')
					c=S.pop();
				break;
			}
			case '+':
			case '-':
			case '*':
			case '/':
			case '%': {

				while(priority(ch)<=priority((char)S.showTop())) {

					out[j++]=(char)S.pop();
				}
				S.push((int)ch);
				break;
			}
			case '^': {

				while(priority(ch)<priority((char)S.showTop())) {

					out[j++]=(char)S.pop();
				}
				S.push((int)ch);
			}
		}
	}
	while(!S.isEmpty())
		out[j++]=S.pop();

	return out;
}

char* Conversion::IntoPre() {

	Stack S;
	char *out,*Str;
	int len=strlen(str),j=0;

	out=new char[len];
  Str=new char[len];

	strcpy(Str,str);
	str=Reverse(str);

	for(int i=0;i<len;i++) {

		char ch=str[i];

		if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z'))
			out[j++]=ch;

		else switch(ch) {

			case '(': {

				S.push((int)ch);
				break;
			}
			case ')': {

				char c;
				while((char)S.showTop()!='(') {

					c=(char)S.pop();
					out[j++]=c;
				}
				if((char)S.showTop()=='(')
					c=S.pop();
				break;
			}
			case '+':
			case '-':
			case '*':
			case '/':
			case '%': {

				while(priority(ch)<priority((char)S.showTop())) {

					out[j++]=(char)S.pop();
				}
				S.push((int)ch);
				break;
			}
			case '^': {

				while(priority(ch)<=priority((char)S.showTop())) {

					out[j++]=(char)S.pop();
				}
				S.push((int)ch);
			}
		}
	}
	while(!S.isEmpty())
		out[j++]=S.pop();

	strcpy(str,Str);
	return out;
}

float Conversion::EvalPost(char *Str) {

	Stack S;
	float value[26],x,y,res;
	int len=strlen(Str),ch;

	for(int i=0;i<26;i++) value[i]=0;

	while(true) {

		cout<<"----------------------------\n";
		cout<<"Select the Options\n";
		cout<<"----------------------------\n";
		cout<<"1. Enter value of Operand\n";
		cout<<"2. Exit\n";
		cout<<"Your Choice: ";
		cin>>ch;
		cout<<"----------------------------\n\n";

		if(ch==1) {
			char ch;
			cout<<"Operand: ";
			cin>>ch;
			cout<<"Value: ";

			if(ch>='a' && ch<='z')
				cin>>value[(int)ch-97];

			else if(ch>='A' && ch<='Z')
				cin>>value[(int)ch-65];
			cout<<"----------------------------\n\n";
		}
		else break;
	}

	for(int i=0;i<len;i++) {

		char ch=Str[i];

		if(ch>='a' && ch<='z')
			S.push(value[(int)ch-97]);

		else {
			y=S.pop();
			x=S.pop();
			res=Operation(x,y,ch);
			S.push(res);
		}
	}
	return (S.pop());
}

float Conversion::EvalPre(char *Str) {

	Stack S;
	float value[26],x,y,res;
	int len=strlen(Str),ch;
	Str=Reverse(Str);

	for(int i=0;i<26;i++) value[i]=0;

	while(true) {

		cout<<"----------------------------\n";
		cout<<"Select the Options\n";
		cout<<"----------------------------\n";
		cout<<"1. Enter value of Operand\n";
		cout<<"2. Exit\n";
		cout<<"Your Choice: ";
		cin>>ch;
		cout<<"----------------------------\n\n";

		if(ch==1) {
			char ch;
			cout<<"Operand: ";
			cin>>ch;
			cout<<"Value: ";

			if(ch>='a' && ch<='z')
				cin>>value[(int)ch-97];

			else if(ch>='A' && ch<='Z')
				cin>>value[(int)ch-65];
			cout<<"----------------------------\n\n";
		}
		else break;
	}

	for(int i=0;i<len;i++) {

		char ch=Str[i];

		if(ch>='a' && ch<='z')
			S.push(value[(int)ch-97]);

		else {
			x=S.pop();
			y=S.pop();
			res=Operation(x,y,ch);
			S.push(res);
		}
	}
	return (S.pop());
}

int main() {

	Conversion Exp;

	int ch,flag,pos;
	float value;

	do {

		cout<<"----------------------------\n";
		cout<<"Select the Options\n";
		cout<<"----------------------------\n";
		cout<<"1. Enter Expression\n";
		cout<<"2. Display Expression\n";
		cout<<"3. Convert to PostFix\n";
		cout<<"4. Evaluate PostFix\n";
		cout<<"5. Convert to PreFix\n";
		cout<<"6. Evaluate PretFix\n";
		cout<<"7. Exit\n\n";
		cout<<"Your Choice: ";
		cin>>ch;
		cout<<"----------------------------\n\n";

		if(ch==1 || flag==1 || ch==7) {

			switch(ch) {

				case 1: {

					Exp.accept();
					flag=1;
					break;
				}

				case 2: {

					Exp.display();
					break;
				}

				case 3: {

					Exp.display();
					cout<<"Postfix: "<<Exp.IntoPost()<<endl;
					break;
				}

				case 4: {

					cout<<"Postfix: "<<Exp.IntoPost()<<endl;
					value=Exp.EvalPost(Exp.IntoPost());
					cout<<"Value: "<<value<<endl;
					break;
				}

				case 5: {

					Exp.display();
					cout<<"Prefix: "<<Exp.Reverse(Exp.IntoPre())<<endl;
					break;
				}

				case 6: {

					cout<<"Prefix: "<<Exp.Reverse(Exp.IntoPre())<<endl;
					value=Exp.EvalPre(Exp.Reverse(Exp.IntoPre()));
					cout<<"Value: "<<value<<endl;
					break;
				}

				case 7: {

					cout<<"End\n";
					break;
				}

				default: cout<<"Select Correct Option\n\n";
			}
		}
		else {

			cout<<"Enter an Expression to Proceed\n\n";
		}
	}
	while(ch!=7);
	return 0;
}
