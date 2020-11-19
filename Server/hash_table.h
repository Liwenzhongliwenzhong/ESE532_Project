#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<cstdint>

using namespace std;
//8-bit hash
const int T_S = 255;

class HashTableEntry {
   public:
      uint8_t* k;
      unsigned char* v;
      HashTableEntry(uint8_t* k, unsigned char* v) {
         this->k = k;
         this->v = v;
      }
};

class HashMapTable {
   private:
      HashTableEntry **t;
   public:
      HashMapTable() {
         t = new HashTableEntry * [T_S];
         for (int i = 0; i< T_S; i++) {
            t[i] = NULL;
         }
      }
      int HashFunc(uint8_t* k) {
		int hash = k[0];
		for (int i=1; i<32; i++)
			hash ^= k[i];
		return (hash%T_S);
      }
      void Insert(uint8_t* k, unsigned char* v) {
         int h = HashFunc(k);
         while (t[h] != NULL && t[h]->k != k) {
            h = (h + 1)%T_S;
         }
         if (t[h] != NULL)
            delete t[h];
         t[h] = new HashTableEntry(k, v);
      }
      unsigned char* SearchKey(uint8_t* k) {
         int h = HashFunc(k);
         while (t[h] != NULL && t[h]->k != k) {
            h = (h + 1)%T_S;
         }
         if (t[h] == NULL)
            return NULL;
         else
            return t[h]->v;
      }
      void Remove(uint8_t* k) {
         int h = HashFunc(k);
         while (t[h] != NULL) {
            if (t[h]->k == k)
               break;
            h = (h + 1)%T_S;
         }
         if (t[h] == NULL) {
            cout<<"No Element found at key "<<k<<endl;
            return;
         } else {
            delete t[h];
         }
         cout<<"Element Deleted"<<endl;
      }
      ~HashMapTable() {
         for (int i = 0; i < T_S; i++) {
            if (t[i] != NULL)
               delete t[i];
            // delete[] t;
         }
      }
};