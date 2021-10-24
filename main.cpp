#include <iostream>

using namespace std;

class Block
{
    private:
        int PreviousHash;
        string Transaction;
        int BlockHash;
    
    public:
        
        int GetPreviousHash () const {return PreviousHash; }
        string GetTransaction () const {return Transaction; }
        int GetBlockHash () const {return BlockHash; }

        void SetPreviousHash (int _PreviousHash) {PreviousHash = _PreviousHash;}
        void SetTransaction (string _Transaction) {Transaction = _Transaction;}
        void SetBlockHash (int _BlockHash) {BlockHash = _BlockHash;}
};
int main()
{
    Block Block1;

    Block1.SetPreviousHash (123456);
    Block1.SetTransaction ("Aistis 5 Margaritai");
    Block1.SetBlockHash (23456);

    Block Block2;

    Block2.SetPreviousHash (125678);
    Block2.SetTransaction ("Aistis 5 Margaritai");
    Block2.SetBlockHash (24326);

    cout << Block1.GetBlockHash() << endl;
    cout << Block2.GetBlockHash() << endl;


    return 0;
}
