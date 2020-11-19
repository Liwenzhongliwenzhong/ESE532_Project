#include "lzw.h"

using namespace std; 
void lzw(const unsigned char* chunk, unsigned char* output) 
{ 	
    // cout << "Encoding\n"; 
	std::string s1((char*)chunk);
    unordered_map<string, int> table; 
    for (int i = 0; i <= 255; i++) { 
        string ch = ""; 
        ch += char(i); 
        table[ch] = i; 
    } 
  
    string p = "", c = ""; 
    p += s1[0]; 
    int code = 256; 
    vector<int> output_code; 

    for (int i = 0; i < (int)s1.length(); i++) { 
        if (i != (int)s1.length() - 1) 
            c += s1[i + 1]; 
        if (table.find(p + c) != table.end()) { 
            p = p + c; 
        } 
        else { 
            output_code.push_back(table[p]); 
            table[p + c] = code; 
            code++; 
            p = c; 
        } 
        c = ""; 
    } 
    // cout << p << "\t" << table[p] << endl; 
    output_code.push_back(table[p]); 
	unsigned char* buffer = (unsigned char*)&output_code[0];
	memcpy(output, buffer, output_code.size());
    return; 
} 