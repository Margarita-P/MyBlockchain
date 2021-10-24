#include <iostream>
#include "hashFunction.cpp"

using namespace std;

class Block
{
    private:
        int PreviousHash;
        string Transaction;
        string BlockHash;
    
    public:
        
        int GetPreviousHash () const {return PreviousHash; }
        string GetTransaction () const {return Transaction; }
        string GetBlockHash () const {return BlockHash; }

        void SetPreviousHash (int _PreviousHash) {PreviousHash = _PreviousHash;}
        void SetTransaction (string _Transaction) {Transaction = _Transaction;}
        void SetBlockHash (string _BlockHash) {BlockHash = _BlockHash;}
};
int main()
{
    Block Block1;

    Block1.SetPreviousHash (123456);
    Block1.SetTransaction ("Aistis 5 Margaritai");
    string hash1;
    hash1 = HASH("labas");
    Block1.SetBlockHash(hash1);

    Block Block2;

    Block2.SetPreviousHash (125678);
    Block2.SetTransaction ("Aistis 5 Margaritai");
    string hash2;
    hash2 = HASH("sveikas");
    Block2.SetBlockHash(hash2);

    cout << Block1.GetBlockHash() << endl;
    cout << Block2.GetBlockHash() << endl;

    return 0;
}
