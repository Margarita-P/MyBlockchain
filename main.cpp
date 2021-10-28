#include <iostream>
#include <fstream>
#include "hashFunction.cpp"

using namespace std;

class Transactions
{
    public:
        string User1;
        string User2;
        int coin;
};
class Users 
{
    public: 
        string Name[10];
        //string publicKey[10];
        int Balance[10];
    private: 
        //string privateKey;
};
class Block
{
    private:
        string PreviousHash;
        string BlockHash;
        string Name;
        int TimeStamp;
        int Nonce;
        int version;
    
    public:

        vector <string> Transactions;
        
        string GetPreviousHash () const {return PreviousHash; }
        string GetBlockHash () const {return BlockHash; }
        string GetBlockName () const {return Name; }
        int GetTimeStamp () const {return TimeStamp; }
        int GetNonce () const {return Nonce; }
        int GetVersion () const {return version; }

        void SetPreviousHash (string _PreviousHash) {PreviousHash = _PreviousHash;}
        void SetBlockHash (string _BlockHash) {BlockHash = _BlockHash;}
        void SetBlockName (string _Name) {Name = _Name;}
        void SetTimeStamp (int _TimeStamp) {TimeStamp = _TimeStamp;}
        void SetNonce (int _Nonce) {Nonce = _Nonce;}
        void SetVersion (int _version) {version = _version;}
};

int counter = 0;
int TBlock = 3;
int BlockSk = 10;
int x = 0;

void PrintNoBlocks ()
{
    ofstream out4 ("info.txt");
    out4 << x + BlockSk;
}
void GetBlockNo ()
{
    ifstream in ("info.txt");
    in >> x;
}
bool CheckTransaction (Users U, Transactions T)
{
    for(int i=0; i<BlockSk; i++)
    {
        if(T.User1 == U.Name[i])
        {
            if(T.coin > U.Balance[i])
            {
                return false;
            }
            else return true;
        }
    }
}
void GetUsers (Users &U)
{
    ifstream in2 ("Users.txt");
    for(int i=0; i<BlockSk; i++)
    {
        in2 >> U.Name[i] >> U.Balance[i];
    }
}
void UpdateBalance (Users &U, Transactions T)
{
    if(CheckTransaction (U, T) == true)
    {
        for(int i=0; i<BlockSk; i++)
        {
            if(T.User1 == U.Name[i])
            {
                U.Balance[i] = U.Balance[i] - T.coin;
            }
            if(T.User2 == U.Name[i])
            {
                U.Balance[i] = U.Balance[i] + T.coin;
            }
        }
    }
    else 
    {
        cout << "Negalima transakcija: " << T.User1 << " " << T.coin << " " << T.User2 << endl;
    }
}
void PrintBlockInfo (Block Block1)
{
    ofstream out ("BlockInfo.txt", ios::app);
    out << Block1.GetBlockName() << endl;
    for(int i=0 ; i<TBlock; i++)
    {
        out << "Transaction: " << Block1.Transactions[i] << endl;
    }
    out << "Hash: " << Block1.GetBlockHash() << endl;
    out << "Previous Hash: " << Block1.GetPreviousHash() << endl;
    out << "Time stamp: " << Block1.GetTimeStamp() << endl;
    out << "Nonce: " << Block1.GetNonce() << endl;
    out << "Version: " << Block1.GetVersion() << endl;
    out << endl;
}
string GetBlockName (string BlockName)
{
    int kint = 0;
    counter ++;
    kint = counter + x;
    BlockName = "Block";
    BlockName += to_string(kint);

    return BlockName;
}
void GetTransactions (Block Block1, Block GenesisBlock, Transactions &T, Users &U)
{
    GetUsers (U);
    string hash1;
    string hash2 ;
    string BlockName;
    string input;
    string Transactions;
    ifstream in ("Transactions.txt");
    ifstream in2 ("Transactions.txt");
    hash2 = GenesisBlock.GetBlockHash();
    for (int i = 0; i<BlockSk; i++)
    {
        
        hash1.clear();
        input.clear();
        Transactions.clear();
        Block1.Transactions.clear();
        
        Block1.SetBlockName(GetBlockName(BlockName));
        Block1.SetPreviousHash (hash2);
        Block1.SetTimeStamp(20211027+counter);
        for(int j=0; j<TBlock; j++)
        {
            getline(in,input);
            Block1.Transactions.push_back(input);
            in2 >> T.User1 >> T.coin >> T.User2;
            UpdateBalance (U,T);
            Transactions += input;
        }
        hash1 = HASH(Transactions);
        Block1.SetBlockHash(hash1);
        Block1.SetNonce(counter+x);
        PrintBlockInfo(Block1);
        hash2 = Block1.GetBlockHash();
        Block1.SetVersion(1);
    }
}
int main()
{
    Block Block1;
    Block GenesisBlock;
    Users U;
    Transactions T;

    GetBlockNo ();
    cout << x << "NO Blocks" << endl;

    GenesisBlock.SetBlockName("Block0");
    GenesisBlock.SetPreviousHash("0000");
    GenesisBlock.SetTimeStamp(0);
    GenesisBlock.Transactions.push_back("GenesisBlock");
    GenesisBlock.SetBlockHash("0");
    GenesisBlock.SetNonce(0000);

    GetTransactions (Block1,GenesisBlock,T, U);

    ofstream out3 ("NewBalance.txt", ios::app);
    for( int i=0; i<BlockSk; i++)
    {
        out3 << U.Name[i] <<" " << U.Balance[i] << endl;
    }
    out3 << endl;

    PrintNoBlocks ();

    return 0;
}
