// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2018 The PIVX developers
// Copyright (c) 2018 The BinkDogCoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "libzerocoin/Params.h"
#include "chainparams.h"
#include "amount.h"
#include "base58.h"
#include "random.h"
#include "util.h"
#include "uint256.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */
static bool regenerate = false;

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
    (0, uint256("0x0000063c711700807164f57e9db4347669a569cceb386dafeb9901c34b1638a3"));
static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1542388633, // * UNIX timestamp of last checkpoint block
    0,    // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    2000        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of
    (0, uint256("0x000008a8f382055c16c4a9d9111ed72c7026f466aabf52f56e07a087ace99199"));
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1542388633,
    0,
    250};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of
    (0, uint256("0x25dadd0e3925833d40fc3becec6556cb7bc6d14ee45ef25542050923734d5659"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1542388633,
    0,
    100};

libzerocoin::ZerocoinParams* CChainParams::Zerocoin_Params(bool useModulusV1) const
{
    assert(this);
    static CBigNum bnHexModulus = 0;
    if (!bnHexModulus)
        bnHexModulus.SetHex(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParamsHex = libzerocoin::ZerocoinParams(bnHexModulus);
    static CBigNum bnDecModulus = 0;
    if (!bnDecModulus)
        bnDecModulus.SetDec(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParamsDec = libzerocoin::ZerocoinParams(bnDecModulus);

    if (useModulusV1)
        return &ZCParamsHex;

    return &ZCParamsDec;
}

static CBlock CreateGenesisBlock(const char* pszTimestamp, const CScript& genesisOutputScript, uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    CMutableTransaction txNew;
    txNew.nVersion = 1;
    txNew.vin.resize(1);
    txNew.vout.resize(1);
    txNew.vin[0].scriptSig = CScript() << 504365040 << CScriptNum(4) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
    txNew.vout[0].nValue = genesisReward;
    txNew.vout[0].scriptPubKey = genesisOutputScript;

    CBlock genesis;
    genesis.nTime    = nTime;
    genesis.nBits    = nBits;
    genesis.nNonce   = nNonce;
    genesis.nVersion = nVersion;
    genesis.vtx.push_back(txNew);
    {
	//Dev - Governance start
        txNew.vout[0].nValue = 100000000000000;
        txNew.vout[0].scriptPubKey = CScript() << OP_DUP << OP_HASH160 << ParseHex(DecodeBase58ToHex(std::string("72iTFEifRs83inxF9f8fQhpURgxSrSS9Fw"))) << OP_EQUALVERIFY << OP_CHECKSIG;
	genesis.vtx.push_back(txNew);
	txNew.vout[0].nValue = 100000000000000;
        txNew.vout[0].scriptPubKey = CScript() << OP_DUP << OP_HASH160 << ParseHex(DecodeBase58ToHex(std::string("6jNxw3D3gzCjShdQLLhC1khUMSN64gE7Fq"))) << OP_EQUALVERIFY << OP_CHECKSIG;
genesis.vtx.push_back(txNew);
        txNew.vout[0].nValue = 100000000000000;
        txNew.vout[0].scriptPubKey = CScript() << OP_DUP << OP_HASH160 << ParseHex(DecodeBase58ToHex(std::string("6gnAK5YWL5HgbJ88X1ZT1z4WyBwccivC7H"))) << OP_EQUALVERIFY << OP_CHECKSIG;
genesis.vtx.push_back(txNew);
        txNew.vout[0].nValue = 100000000000000;
        txNew.vout[0].scriptPubKey = CScript() << OP_DUP << OP_HASH160 << ParseHex(DecodeBase58ToHex(std::string("6m9KnaFxHMJgmfYH85F4Acmfrz4Q5qzXLK"))) << OP_EQUALVERIFY << OP_CHECKSIG;
genesis.vtx.push_back(txNew);
        txNew.vout[0].nValue = 100000000000000;
        txNew.vout[0].scriptPubKey = CScript() << OP_DUP << OP_HASH160 << ParseHex(DecodeBase58ToHex(std::string("6ede16pWasg8KVfm7ENjeQc2cckVWacTxE"))) << OP_EQUALVERIFY << OP_CHECKSIG;
genesis.vtx.push_back(txNew);
        txNew.vout[0].nValue = 100000000000000;
        txNew.vout[0].scriptPubKey = CScript() << OP_DUP << OP_HASH160 << ParseHex(DecodeBase58ToHex(std::string("6qNTpovirHMKzB4hdaEBsikkfpM6HF8jow"))) << OP_EQUALVERIFY << OP_CHECKSIG;




    }
    genesis.hashPrevBlock = 0;
    genesis.hashMerkleRoot = genesis.BuildMerkleTree();
    return genesis;
};

static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward, const string addr1, const string addr2, const string addr3)
{
    const char* pszTimestamp = "Bitcoin Block 550321 - 0000000000000000000a0177bf9fc4ad4c92a61f9ab84dbf8fdbfaaa349414e4 at 2018-11-16 16:35:46";
    const CScript genesisOutputScript = CScript() << OP_2 << ParseHex(DecodeBase58ToHex(addr1)) << ParseHex(DecodeBase58ToHex(addr2)) << ParseHex(DecodeBase58ToHex(addr3)) << OP_3 << OP_CHECKMULTISIG;
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
};

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x2f;
        pchMessageStart[1] = 0x24;
        pchMessageStart[2] = 0x53;
        pchMessageStart[3] = 0xb8;
        vAlertPubKey = ParseHex("0x"); // Disabled
        nDefaultPort = 18721;
        bnProofOfWorkLimit = ~uint256(0) >> 20; // BinkDogCoin starting difficulty is 1 / 2^12
        nSubsidyHalvingInterval = 210240;
        nMaxReorganizationDepth = 100;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // BinkDogCoin: 1 day
        nTargetSpacing = 60;  // BinkDogCoin: 1 minute
        nMaturity = 15;
        nMasternodeCountDrift = 20;
        nMaxMoneyOut = 100000000 * COIN;

        /** Height or Time Based Activations **/
        nLastPOWBlock = 100000; //  1 per minute  - 14 days @ 1440 per day
        //if the lowest block height (vSortedByTimestamp[0]) is >= switch height, use new modifier calc
        // nModifierUpdateBlock = 0; // (PIVX: 615800)
        nZerocoinStartHeight = 71000; // (PIVX: 863787, Phore 90000)
        nZerocoinStartTime = 1542207671; //  Wednesday, November 14, 2018 3:01:11 PM GMT
        // nBlockEnforceSerialRange = 90003; //Enforce serial range starting this block (Phore 90003)
        nBlockRecalculateAccumulators = 71000; // (PIVX: 895400, Phore 90005) //Trigger a recalculation of accumulators
        // nBlockFirstFraudulent = 90002; // (PIVX: 908000, Phore 90002) //First block that bad serials emerged
        nBlockLastGoodCheckpoint = 71000; // (PIVX: 891730, Phore 90005) //Last valid accumulator checkpoint
        // nBlockEnforceInvalidUTXO = 0; // (PIVX: 902850) //Start enforcing the invalid UTXO's
        // nInvalidAmountFiltered = 268200*COIN; // (PIVX: 268200) //Amount of invalid coins filtered through exchanges, that should be considered valid
        nBlockZerocoinV2 = 710000; // (PIVX: 1153160) //!> The block that zerocoin v2 becomes active - roughly Tuesday, May 8, 2018 4:00:00 AM GMT
        nEnforceNewSporkKey = 1525158000; // (PIVX: 1525158000) //!> Sporks signed after (GMT): Tuesday, May 1, 2018 7:00:00 AM GMT must use the new spork key
        nRejectOldSporkKey = 1527811200; // (PIVX: 1527811200) //!> Fully reject old spork key after (GMT): Friday, June 1, 2018 12:00:00 AM

        genesis = CreateGenesisBlock(
                    1542388633,                          // nTime
                    1701943,                               // nNonce
                    0x1e0ffff0,                          // nBits
                    3,                                   // nVersion
                   treasuryDeposit,                      // genesisReward (treasury deposit)
                   "8eqCEt9zBB8VvLansnFWSeo1bD4dUeeJQm",  // first NEW treasury address
                   "8ye6Kprb2GuTjQWLuKFxPdxAZcUx1re3Kf",  // second NEW treasury address
                   "8miQ2oYixNeESmPy7M2AXZKnt5hrzLdsbc"  // third NEW treasury address
                    );

        hashGenesisBlock = genesis.GetHash();
        if (regenerate) {
            hashGenesisBlock = uint256S("");
            genesis.nNonce = 0;
            if (true && (genesis.GetHash() != hashGenesisBlock)) {
                uint256 hashTarget = CBigNum().SetCompact(genesis.nBits).getuint256();
                while (genesis.GetHash() > hashTarget)
                {
                    ++genesis.nNonce;
                    if (genesis.nNonce == 0)
                    {
                        ++genesis.nTime;
                    }
                }
                std::cout << "// Mainnet ---";
                std::cout << " nonce: " << genesis.nNonce;
                std::cout << " time: " << genesis.nTime;
                std::cout << " hash: 0x" << genesis.GetHash().ToString().c_str();
                std::cout << " merklehash: 0x"  << genesis.hashMerkleRoot.ToString().c_str() <<  "\n";



            }
        } else {
            LogPrintf("Mainnet ---\n");
            LogPrintf(" nonce: %u\n", genesis.nNonce);
            LogPrintf(" time: %u\n", genesis.nTime);
            LogPrintf(" hash: 0x%s\n", genesis.GetHash().ToString().c_str());
            LogPrintf(" merklehash: 0x%s\n", genesis.hashMerkleRoot.ToString().c_str());
            assert(hashGenesisBlock == uint256("0x0000063c711700807164f57e9db4347669a569cceb386dafeb9901c34b1638a3"));
            assert(genesis.hashMerkleRoot == uint256("0x9d297802ffddeb9af12d4bcb324d0faf3a76ce66ba9fa513d4aeaa8a5ca471a2"));
        }


        vSeeds.push_back(CDNSSeedData("dns01", "dnsseed01.binkdogcoin.org"));
        vSeeds.push_back(CDNSSeedData("dns02", "dnsseed02.binkdogcoin.org"));
        vSeeds.push_back(CDNSSeedData("dns03", "dnsseed03.binkdogcoin.org"));
        vSeeds.push_back(CDNSSeedData("dns04", "dnsseed04.binkdogcoin.org"));
        vSeeds.push_back(CDNSSeedData("dns05", "dnsseed05.binkdogcoin.org"));
        vSeeds.push_back(CDNSSeedData("dns06", "dnsseed06.binkdogcoin.org"));


        // BinkDogCoin addresses start with '8 or 9'
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,14);
        // BinkDogCoin script addresses start with '3'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,12);
        // BinkDogCoin private keys start with '7' (uncompressed) or 'V' (compressed)
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,18);
        // BinkDogCoin BIP32 pubkeys start with 'xpub' (Bitcoin defaults)
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        // BinkDogCoin BIP32 prvkeys start with 'xprv' (Bitcoin defaults)
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();
        // BinkDogCoin BIP44 coin type (pending BIP44-capable wallet, use Bitcoin type)
        base58Prefixes[EXT_COIN_TYPE]  = boost::assign::list_of(0x80)(0x00)(0x00)(0xe2).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;

        nPoolMaxTransactions = 3;
        strSporkKey = "0499A7AF4806FC6DE640D23BC5936C29B77ADF2174B4F45492727F897AE63CF8D27B2F05040606E0D14B547916379FA10716E344E745F880EDC037307186AA25B7";
        strSporkKeyOld = "04B433E6598390C992F4F022F20D3B4CBBE691652EE7C48243B81701CBDB7CC7D7BF0EE09E154E6FCBF2043D65AF4E9E97B89B5DBAF830D83B9B7F469A6C45A717";
        strObfuscationPoolDummyAddress = "S87q2gC9j6nNrnzCsg4aY6bHMLsT9nUhEw";
        nStartMasternodePayments = 1527634800; // 2018-05-30 00:00:00

        /** Zerocoin */
        zerocoinModulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
            "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
            "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
            "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
            "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
            "31438167899885040445364023527381951378636564391212010397122822120720357";
        nMaxZerocoinSpendsPerTransaction = 7; // Assume about 20kb each
        nMinZerocoinMintFee = 1 * CENT; //high fee required for zerocoin mints
        nMintRequiredConfirmations = 20; //the maximum amount of confirmations until accumulated in 19
        nRequiredAccumulation = 1;
        nDefaultSecurityLevel = 100; //full security level for accumulators
        nZerocoinHeaderVersion = 4; //Block headers must be this version once zerocoin is active
        nZerocoinRequiredStakeDepth = 200; //The required confirmations for a zpiv to be stakable

        nBudget_Fee_Confirmations = 6; // Number of confirmations for the finalization fee
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0xf4;
        pchMessageStart[1] = 0x20;
        pchMessageStart[2] = 0x7c;
        pchMessageStart[3] = 0x0b;
        vAlertPubKey = ParseHex("");
        bnProofOfWorkLimit = ~uint256(0) >> 1; // 0x207fffff, BinkDogCoin testnet starting difficulty
        nSubsidyHalvingInterval = 210240;
        nDefaultPort = 18722;
        nEnforceBlockUpgradeMajority = 51;
        nRejectBlockOutdatedMajority = 75;
        nToCheckBlockUpgradeMajority = 100;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // BinkDogCoin: 1 day
        nTargetSpacing = 60;  // BinkDogCoin: 1 minute
        nLastPOWBlock = 100000;
        nMaturity = 15;
        nMasternodeCountDrift = 2;
        // nModifierUpdateBlock = 0; //approx Mon, 17 Apr 2017 04:00:00 GMT
        nMaxMoneyOut = 100000000 * COIN;
        nZerocoinStartHeight = 1000;
        nZerocoinStartTime = 1530801782;
        // nBlockEnforceSerialRange = 0; //Enforce serial range starting this block
        nBlockRecalculateAccumulators = 999999999; //Trigger a recalculation of accumulators
        // nBlockFirstFraudulent = 999999999; //First block that bad serials emerged
        nBlockLastGoodCheckpoint = 999999999; //Last valid accumulator checkpoint
        // nBlockEnforceInvalidUTXO = 0; //Start enforcing the invalid UTXO's
        // nInvalidAmountFiltered = 0; //Amount of invalid coins filtered through exchanges, that should be considered valid
        nBlockZerocoinV2 = 1000; //!> The block that zerocoin v2 becomes active
        nEnforceNewSporkKey = 1521604800; //!> Sporks signed after Wednesday, March 21, 2018 4:00:00 AM GMT must use the new spork key
        nRejectOldSporkKey = 1522454400; //!> Reject old spork key after Saturday, March 31, 2018 12:00:00 AM GMT

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis = CreateGenesisBlock(
                    1542388633,                          // nTime
                    377935,                              // nNonce
                    0x1e0ffff0,                          // nBits
                    3,                                   // nVersion
                    treasuryDeposit,                     // genesisReward (treasury deposit)
                   "msYBKKuARmcmMHmzMGxc8j8XYi8bqEeBJr", // first treasury address
                   "mfYcNVRnTNHDw6BwKPhk3Z8xXp4F8CEMtZ", // second treasury address
                   "mkGv2mrvZvKriZ1tzwQheHQzYyW5o9ir5J"  // third treasury address
                    );

        hashGenesisBlock = genesis.GetHash();
        if (regenerate) {
            hashGenesisBlock = uint256S("");
            genesis.nNonce = 0;
            if (true && (genesis.GetHash() != hashGenesisBlock)) {
                uint256 hashTarget = CBigNum().SetCompact(genesis.nBits).getuint256();
                while (genesis.GetHash() > hashTarget)
                {
                    ++genesis.nNonce;
                    if (genesis.nNonce == 0)
                    {
                        ++genesis.nTime;
                    }
                }
                std::cout << "// Testnet ---";
                std::cout << " nonce: " << genesis.nNonce;
                std::cout << " time: " << genesis.nTime;
                std::cout << " hash: 0x" << genesis.GetHash().ToString().c_str();
                std::cout << " merklehash: 0x"  << genesis.hashMerkleRoot.ToString().c_str() <<  "\n";

            }
        } else {
            LogPrintf("Testnet ---\n");
            LogPrintf(" nonce: %u\n", genesis.nNonce);
            LogPrintf(" time: %u\n", genesis.nTime);
            LogPrintf(" hash: 0x%s\n", genesis.GetHash().ToString().c_str());
            LogPrintf(" merklehash: 0x%s\n", genesis.hashMerkleRoot.ToString().c_str());
            assert(hashGenesisBlock == uint256("0x000008a8f382055c16c4a9d9111ed72c7026f466aabf52f56e07a087ace99199"));
            assert(genesis.hashMerkleRoot == uint256("0x2a5f0ba615f84ce85e2dfa17f2623536a71481df173010f36fa85d83e4ee47ab"));
        }

        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("dns01", "dnsseed01.binkdogcoin.org"));
        vSeeds.push_back(CDNSSeedData("dns02", "dnsseed02.binkdogcoin.org"));
        vSeeds.push_back(CDNSSeedData("dns03", "dnsseed03.binkdogcoin.org"));
        vSeeds.push_back(CDNSSeedData("dns04", "dnsseed04.binkdogcoin.org"));
        vSeeds.push_back(CDNSSeedData("dns05", "dnsseed05.binkdogcoin.org"));
        vSeeds.push_back(CDNSSeedData("dns06", "dnsseed06.binkdogcoin.org"));


        // Testnet BinkDogCoin addresses start with 'X'
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,10);
        // Testnet BinkDogCoin script addresses start with 'Y'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,22);
        // Testnet private keys start with 'X' (uncompressed) or 'c' (compressed)
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,5);
        // Testnet BinkDogCoin BIP32 pubkeys start with 'tpub' (Bitcoin defaults)
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        // Testnet BinkDogCoin BIP32 prvkeys start with 'tprv' (Bitcoin defaults)
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();
        // Testnet BinkDogCoin BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE]  = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;
        fSkipProofOfWorkCheck = true;

        nPoolMaxTransactions = 2;
        strSporkKey = "";
        strSporkKeyOld = "";
        strObfuscationPoolDummyAddress = "m57cqfGRkekRyDRNeJiLtYVEbvhXrNbmox";
        nStartMasternodePayments = 1527634800; //30th May 2018 00:00:00
        nBudget_Fee_Confirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short
                                       // here because we only have a 8 block finalization window on testnet
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        pchMessageStart[0] = 0xe0;
        pchMessageStart[1] = 0x2a;
        pchMessageStart[2] = 0xb4;
        pchMessageStart[3] = 0x6e;
        nSubsidyHalvingInterval = 150;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // BinkDogCoin: 1 day
        nTargetSpacing = 60;  // BinkDogCoin: 1 minute
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        nDefaultPort = 18724;

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis = CreateGenesisBlock(
                    1542388633,                          // nTime
                    20,                                   // nNonce
                    0x207fffff,                          // nBits
                    3,                                   // nVersion
                    treasuryDeposit,                     // genesisReward (treasury deposit)
                   "8eqCEt9zBB8VvLansnFWSeo1bD4dUeeJQm",  // first NEW treasury address
                   "8ye6Kprb2GuTjQWLuKFxPdxAZcUx1re3Kf",  // second NEW treasury address
                   "8miQ2oYixNeESmPy7M2AXZKnt5hrzLdsbc"  // third NEW treasury address
                    );

        hashGenesisBlock = genesis.GetHash();

        if (regenerate) {
            hashGenesisBlock = uint256S("");
            if (true && (genesis.GetHash() != hashGenesisBlock)) {
                uint256 hashTarget = CBigNum().SetCompact(genesis.nBits).getuint256();
                while (genesis.GetHash() > hashTarget)
                {
                    ++genesis.nNonce;
                    if (genesis.nNonce == 0)
                    {
                        ++genesis.nTime;
                    }
                }
                std::cout << "// Regtestnet ---";
                std::cout << " nonce: " << genesis.nNonce;
                std::cout << " time: " << genesis.nTime;
                std::cout << " hash: 0x" << genesis.GetHash().ToString().c_str();
                std::cout << " merklehash: 0x"  << genesis.hashMerkleRoot.ToString().c_str() <<  "\n";

            }
        } else {
            LogPrintf("Regtestnet ---\n");
            LogPrintf(" nonce: %u\n", genesis.nNonce);
            LogPrintf(" time: %u\n", genesis.nTime);
            LogPrintf(" hash: 0x%s\n", genesis.GetHash().ToString().c_str());
            LogPrintf(" merklehash: 0x%s\n", genesis.hashMerkleRoot.ToString().c_str());
            assert(hashGenesisBlock == uint256("0x25dadd0e3925833d40fc3becec6556cb7bc6d14ee45ef25542050923734d5659"));
            assert(genesis.hashMerkleRoot == uint256("0x9d297802ffddeb9af12d4bcb324d0faf3a76ce66ba9fa513d4aeaa8a5ca471a2"));
        }


        if (regenerate)
            exit(0);

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
        // fSkipProofOfWorkCheck = true;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 18726;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
