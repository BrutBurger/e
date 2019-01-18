#include<cstdio>
#include<cstring>
#include<map> 
#include<vector>
 
#include<bits/stdc++.h> 
 
using namespace std;

map<string,string>map1; 
map<string,int>map2;
map<int,string>map3;
map<string,string>map4;
vector<int>w;
int t[10007];
int kt[307];
string def="#define",actual_name="";

void getnext(const char *cset){
	int len=strlen(cset);
	if(!actual_name.size()){
		actual_name=cset[0];
		return;
	}
	if(kt[actual_name[0]]==len-1) actual_name[0]='$';
	else actual_name[0]=cset[kt[actual_name[0]]+1];
	
	for(int i=0; i<actual_name.size(); i++){
		if(actual_name[i]!='$') return;
		if(i==actual_name.size()-1) actual_name+='@';
		actual_name[i]=cset[0];
		if(actual_name[i+1]=='@') actual_name[i+1]=cset[0];
		else if(kt[actual_name[i+1]]==len-1) actual_name[i+1]='$';
		else actual_name[i+1]=cset[kt[actual_name[i+1]]+1];		
	}	
}
 
bool e(const char *input_file, const char *output_file, const char *cset){
    FILE *in = fopen(input_file, "rb");
    FILE *out = fopen(output_file, "wb");
 	int ad=0,as=0;
 	
 	for(int i=0; i<strlen(cset); i++) if((cset[i]<'a'||cset[i]>'z')&&(cset[i]>'Z'||cset[i]<'A')) return false;
 	for(int i=0; i<strlen(cset); i++) kt[cset[i]]=i;
 
    if(in!=NULL && out!=NULL){
        char nxt;
        int last=0;
        string s,s2;
 	
 		s.clear();	
        while(1){
            nxt=fgetc(in);
            if(nxt==EOF) break;
            bool ok=0;
            if(nxt=='\'') as^=1;
            if(nxt=='\"') ad^=1;
            if((nxt>126||nxt<33)&&!ad&&!as){
            	if(!s.size()) continue;
            	if(map1.find(s)!=map1.end()) w.push_back(map2[map1[s]]);
            	else{
            		if(s[0]=='#'){
            			for(int i=0; i<s.size(); i++) fputc(s[i],out);
            			fputc('\n',out);
            			s.clear();
            			continue;
            		}
            		getnext(cset);
					s2=actual_name;
            		last++;
            		map2[s2]=last;
            		map3[last]=s2;
            		map1[s]=s2;
            		map4[s2]=s;
            		w.push_back(last);
            	}
            	s.clear();
            	continue;
            }
            else s+=nxt;
        }
        
        for(map<string,string>::iterator ii=map1.begin(); ii!=map1.end(); ii++){
        	s=ii->first;
        	s2=ii->second;
        	for(int j=0; j<def.size(); j++) fputc(def[j],out);
        	fputc(' ',out);
        	for(int j=0; j<s2.size(); j++) fputc(s2[j],out);
        	fputc(' ',out);
        	for(int j=0; j<s.size(); j++) fputc(s[j],out);
        	fputc('\n',out);
        }
        
        for(int i=0; i<w.size(); i++){
        	s=map3[w[i]];
        	for(int j=0; j<s.size(); j++) fputc(s[j],out);
        	fputc(' ',out);
        	if(i%10==9) fputc('\n',out);
        }
        
        if(!fclose(in) && !fclose(out)) return true;
        return false;
    }
   	return false;
}
 
int main (int argc, char *argv[]){
    if(argc>=3){
        if(e(argv[1], argv[2], argv[3])) printf("FULL SUCCESS!");
        else printf("ERROR :(");
    }
    else printf("\nUsage: \n%s <input filename> <output filename> <set of latin characters without spaces>", argv[0]);
    return 0;
}
