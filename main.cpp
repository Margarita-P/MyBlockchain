#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
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
        string Name[30];
        string publicKey[30];
        int Balance[30];
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

        clear ()
        {
            string x;
            int y = 0;
            SetPreviousHash (x);
            SetBlockHash (x);
            SetBlockName (x);
            SetTimeStamp (y);
            SetNonce (y);
            SetVersion (y);
        }
};

pair<string, string> splitInTwo(string val) {
    string arg;
    string::size_type pos = val.find('0');
    if(val.npos != pos) {
        arg = val.substr(pos + 1);
        val = val.substr(0, pos);
    }
    return make_pair(val, arg);
}

int counter = 0;
int TBlock = 10;
int BlockSk = 10;
int x = 0;
vector <string> T1;
vector <string> T2;

bool checkHash (Block Block1, string hash)
{
    if(hash == Block1.GetBlockHash()) return true;
    else return false;
}
string MerkleHash2 ();
void readUsedTransactions (vector <string> &checkTrans);
void Mining (string parentHash, Block Block1)
{
    vector <string> checkTrans;
    parentHash = MerkleHash2();

    if(checkHash(Block1,parentHash) == true) cout << "Block valid" << endl;
    else {
        Block1.clear();
        cout << "Blokas negali buti sukurtas" << endl;
    }
    readUsedTransactions (checkTrans);
    for(int i=0; i<TBlock; i++)
    {
        for(int j=0; j<checkTrans.size(); j++)
        {
            if(T2[i] == checkTrans[j]) 
            {
                Block1.clear();
                cout << "Transakcija kartojasi" << endl;
            }
        }
    }
}
void readUsedTransactions (vector <string> &checkTrans)
{
    checkTrans.clear();
    string line;
    string input;
    ifstream in("UsedTransactions.txt");
    while(getline(in,line))
    {
        checkTrans.push_back(line);
    }
}
string MerkleHash2 ()
{
    int kint = TBlock;
    string h1, h2, h3;
    vector <string> mHash;
    vector <string> mHash1;
    for(int i=0; i<TBlock; i++)
    {
        h1.clear();
        h2.clear();
        h1 = HASH(T2[i]);
        pair<string, string> pr = splitInTwo(h1);
        h2 = pr.first;
        mHash.push_back(h2);
    }
    while (mHash.size() != 1)
    {
        mHash1.clear();
        mHash1.resize(mHash.size()/2);
        for(int i=0; i<mHash.size(); i++)
        {
            h1 = mHash[i];
            h1 += mHash[i+1];
            mHash1.push_back(h1);
            i++;
        }
        for(int i=0; i<mHash1.size(); i++)
        {
            mHash.clear();
            mHash.push_back(mHash1.back());
            mHash1.pop_back();
        }
    }
    h2 = mHash[0];
    h3 = HASH(h2);

    return h3;
}
string MerkleHash ()
{
    int kint = TBlock;
    string h1, h2, h3;
    vector <string> mHash;
    vector <string> mHash1;
    for(int i=0; i<TBlock; i++)
    {
        h1.clear();
        h2.clear();
        h1 = HASH(T1[i]);
        pair<string, string> pr = splitInTwo(h1);
        h2 = pr.first;
        mHash.push_back(h2);
    }
    while (mHash.size() != 1)
    {
        mHash1.clear();
        mHash1.resize(mHash.size()/2);
        for(int i=0; i<mHash.size(); i++)
        {
            h1 = mHash[i];
            h1 += mHash[i+1];
            mHash1.push_back(h1);
            i++;
        }
        for(int i=0; i<mHash1.size(); i++)
        {
            mHash.clear();
            mHash.push_back(mHash1.back());
            mHash1.pop_back();
        }
    }
    h2 = mHash[0];
    h3 = HASH(h2);

    return h3;
}
void PrintNoBlocks ()
{
    ofstream out4 ("info.txt");
    out4 << x + BlockSk;
    out4.close();
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
        if(T.User1 == U.publicKey[i])
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
        in2 >> U.Name[i] >> U.Balance[i] >> U.publicKey[i];
    }
}
void UpdateBalance (Users &U, Transactions T)
{
    if(CheckTransaction (U, T) == true)
    {
        for(int i=0; i<BlockSk; i++)
        {
            if(T.User1 == U.publicKey[i])
            {
                U.Balance[i] = U.Balance[i] - T.coin;
            }
            if(T.User2 == U.publicKey[i])
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
void PrintBlockInfo (Block Block1, Users U)
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
    out.close();

    
    ofstream out3 ("NewBalance.txt", ios::app);
    out3 << Block1.GetBlockName() << endl;
    for( int i=0; i<BlockSk; i++)
    {
        out3 << U.Name[i] <<" " << U.Balance[i] << endl;
    }
    out3 << endl;
    out3.close();

    ofstream out4 ("UsedTransactions.txt", ios::app);
    for(int i=0; i<TBlock; i++)
    {
        out4 << Block1.Transactions[i] << endl;
    }
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
        T1.clear();
        T2.clear();
        
        Block1.SetBlockName(GetBlockName(BlockName));
        Block1.SetPreviousHash (hash2);
        Block1.SetTimeStamp(20211027+counter);
        for(int j=0; j<TBlock; j++)
        {
            getline(in,input);
            Block1.Transactions.push_back(input);
            in2 >> T.User1 >> T.coin >> T.User2;
            UpdateBalance (U,T);
            Transactions += T.User1;
            T1.push_back(T.User1);
            T2.push_back(T.User1);
        }
        
        hash1 = MerkleHash();
        Block1.SetBlockHash(hash1);
        Block1.SetNonce(counter+x);
        PrintBlockInfo(Block1, U);
        hash2 = Block1.GetBlockHash();
        Block1.SetVersion(1);
        if(i > 2) {
        Mining(hash2, Block1);}
    }
}
int main()
{
    Block Block1;
    Block GenesisBlock;
    Users U;
    Transactions T;

    GetBlockNo ();

    GenesisBlock.SetBlockName("Block0");
    GenesisBlock.SetPreviousHash("0000");
    GenesisBlock.SetTimeStamp(0);
    GenesisBlock.Transactions.push_back("GenesisBlock");
    GenesisBlock.SetBlockHash("0");
    GenesisBlock.SetNonce(0000);
    GenesisBlock.SetVersion(1);

    GetTransactions (Block1,GenesisBlock,T, U);

    ofstream out2 ("UserFinalBalance.txt", ios::app);
    out2 << Block1.GetBlockName() << endl;
    for( int i=0; i<BlockSk; i++)
    {
        out2 << U.Name[i] <<" " << U.Balance[i] << endl;
    }
    out2 << endl;
    out2.close();
    PrintNoBlocks ();

    return 0;
}
