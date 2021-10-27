#include <iostream>
#include <fstream>
#include "hashFunction.cpp"

using namespace std;

class Block
{
    private:
        string PreviousHash;
        string Transaction;
        string Transaction2;
        string Transaction3;
        string BlockHash;
        string Name;
        int TimeStamp;
        int Nonce;
    
    public:
        
        string GetPreviousHash () const {return PreviousHash; }
        string GetTransaction () const {return Transaction; }
        string GetTransaction2 () const {return Transaction2; }
        string GetTransaction3 () const {return Transaction3; }
        string GetBlockHash () const {return BlockHash; }
        string GetBlockName () const {return Name; }
        int GetTimeStamp () const {return TimeStamp; }
        int GetNonce () const {return Nonce; }

        void SetPreviousHash (string _PreviousHash) {PreviousHash = _PreviousHash;}
        void SetTransaction (string _Transaction) {Transaction = _Transaction;}
        void SetTransaction2 (string _Transaction2) {Transaction2 = _Transaction2;}
        void SetTransaction3 (string _Transaction3) {Transaction3 = _Transaction3;}
        void SetBlockHash (string _BlockHash) {BlockHash = _BlockHash;}
        void SetBlockName (string _Name) {Name = _Name;}
        void SetTimeStamp (int _TimeStamp) {TimeStamp = _TimeStamp;}
        void SetNonce (int _Nonce) {Nonce = _Nonce;}
};
int counter = 0;
void PrintBlockInfo (Block Block1)
{
    ofstream out ("BlockInfo.txt", ios::app);
    out << Block1.GetBlockName() << endl;
    out << "Transaction: " << Block1.GetTransaction() << endl;
    out << "Transaction: " << Block1.GetTransaction2() << endl;
    out << "Transaction: " << Block1.GetTransaction3() << endl;
    out << "Hash: " << Block1.GetBlockHash() << endl;
    out << "Previous Hash: " << Block1.GetPreviousHash() << endl;
    out << "Time stamp: " << Block1.GetTimeStamp() << endl;
    out << "Nonce: " << Block1.GetNonce() << endl;
    out << endl;
}
string GetBlockName (string BlockName)
{
    counter ++;

    BlockName = "Block";
    BlockName += to_string(counter);

    return BlockName;
}
void GetTransactions (Block Block1, Block GenesisBlock)
{
    string hash1;
    string hash2 ;
    string BlockName;
    string input;
    string Transactions;
    ifstream in ("Users.txt");
    hash2 = GenesisBlock.GetBlockHash();
    for (int i = 0; i<10; i++)
    {
        
        hash1.clear();
        input.clear();
        Transactions.clear();
        
        Block1.SetBlockName(GetBlockName(BlockName));
        Block1.SetPreviousHash (hash2);
        Block1.SetTimeStamp(20211027+counter);
        getline(in,input);
        Block1.SetTransaction (input);
        Transactions += input;
        getline(in,input);
        Block1.SetTransaction2 (input);
        Transactions += input;
        getline(in,input);
        Block1.SetTransaction3 (input);
        Transactions += input;
        cout << "transactions: " << Transactions << endl;
        hash1 = HASH(Transactions);
        Block1.SetBlockHash(hash1);
        Block1.SetNonce(counter);
        PrintBlockInfo(Block1);
        hash2 = Block1.GetBlockHash();
    
    }
}
int main()
{
    Block Block1;
    Block GenesisBlock;

    GenesisBlock.SetBlockName("Block0");
    GenesisBlock.SetPreviousHash("0000");
    GenesisBlock.SetTimeStamp(0);
    GenesisBlock.SetTransaction("GenesisBlock");
    GenesisBlock.SetBlockHash("0");
    GenesisBlock.SetNonce(0000);

    GetTransactions (Block1,GenesisBlock);

    return 0;
}
