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

Command    ./e in.cpp out.cpp ea    used on following code saved in file xd.cpp:  

'''
#include<bits/stdc++.h>  
using namespace std;  

int main(){  
	
	cout<<"THIS IS A TEST!";  
	cout<<"HAVE FUN WITH PROJECT E!\n";  
	
	return 0;  
}
'''

Will produce the following code:  

'''
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
'''

You can check that this code works.  
As you may see, every define is created by breaking the code between every two white characters (except the code placed in the pair of quotation marks). 


But, be careful while choosing the set of characters. If your original code contained command named the same as one of produced defines, the output code will not compile.    
Example:  
  
The original code contains following line: "int ab".  
If both the letters 'a' and 'b' would be chosen as the members of characters set, one of the very first defines will look like this: #define ab <any command in c++>. In this case, the output code will fail to compile.  

To avoid similar situations, I recommend the following solution:  
Look in the original code for short commands (especially short variable names and commands like for,if etc). While choosing the characters set do not use all letters that any short command contains. (example: if the original code contains the 'for' command, you should not choose all three letters 'f','o' and 'r' for the characters set).    


~BrutBurger    
