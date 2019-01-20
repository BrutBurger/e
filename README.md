# e
It's a simple spell, but quite unbreakable.
-------------------------------------------
Project e is a simple program written in c++. It can be used for code obfuscation or just for fun.

IMPORTANT: For now, your code must not contain lines starting with "#define" or "typedef", otherwise the program will not work.
Maybe I will fix this in the future.
------------------------------------
Now the most important question:  
How to use project e?  
First, download the code and compile it. Then run the compiled code with the following arguments:  
->The first argument is the name of file containing the c++ code you want to be obfuscated.  
->The second argument is the name of file you want to save the obfuscated code.  
->The third argument is the set of latin characters you want be used in the process of obfuscation.  
Example:  

Command ./e xd.cpp xd2.cpp ea  
Used on following code saved in file xd.cpp:  

#include<bits/stdc++.h>  
using namespace std;  

int main(){  
	
	cout<<"THIS IS A TEST!";
	cout<<"HAVE FUN WITH PROJECT E!\n";
	
	return 0;
}

Will produce the following code:

#include<bits/stdc++.h>  
#define eae 0;  
#define eee cout<<"HAVE FUN WITH PROJECT E!\n";  
#define aa cout<<"THIS IS A TEST!";  
#define ae int  
#define ea main(){  
#define a namespace  
#define aee return  
#define ee std;  
#define e using  
#define aae }  
e a ee ae ea aa eee aee eae aae   


You can check that this code works.  


~BrutBurger  
