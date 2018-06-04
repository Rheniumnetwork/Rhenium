// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
<<<<<<< HEAD
// Copyright (c) 2016-2017 The PIVX developers
// Copyright (c) 2017 The Rhenium developers
=======
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "wallet_ismine.h"

#include "key.h"
#include "keystore.h"
#include "script/script.h"
#include "script/standard.h"
<<<<<<< HEAD
#include "util.h"
=======
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e

#include <boost/foreach.hpp>

using namespace std;

typedef vector<unsigned char> valtype;

unsigned int HaveKeys(const vector<valtype>& pubkeys, const CKeyStore& keystore)
{
    unsigned int nResult = 0;
    BOOST_FOREACH (const valtype& pubkey, pubkeys) {
        CKeyID keyID = CPubKey(pubkey).GetID();
<<<<<<< HEAD
        if(keystore.HaveKey(keyID))
=======
        if (keystore.HaveKey(keyID))
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e
            ++nResult;
    }
    return nResult;
}

isminetype IsMine(const CKeyStore& keystore, const CTxDestination& dest)
{
    CScript script = GetScriptForDestination(dest);
    return IsMine(keystore, script);
}

isminetype IsMine(const CKeyStore& keystore, const CScript& scriptPubKey)
{
<<<<<<< HEAD
    if(keystore.HaveWatchOnly(scriptPubKey))
        return ISMINE_WATCH_ONLY;
    if(keystore.HaveMultiSig(scriptPubKey))
        return ISMINE_MULTISIG;

    vector<valtype> vSolutions;
    txnouttype whichType;
    if(!Solver(scriptPubKey, whichType, vSolutions)) {
        if(keystore.HaveWatchOnly(scriptPubKey))
            return ISMINE_WATCH_ONLY;
        if(keystore.HaveMultiSig(scriptPubKey))
            return ISMINE_MULTISIG;

=======
    vector<valtype> vSolutions;
    txnouttype whichType;
    if (!Solver(scriptPubKey, whichType, vSolutions)) {
        if (keystore.HaveWatchOnly(scriptPubKey))
            return ISMINE_WATCH_ONLY;
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e
        return ISMINE_NO;
    }

    CKeyID keyID;
    switch (whichType) {
    case TX_NONSTANDARD:
    case TX_NULL_DATA:
        break;
<<<<<<< HEAD
    case TX_ZEROCOINMINT:
    case TX_PUBKEY:
        keyID = CPubKey(vSolutions[0]).GetID();
        if(keystore.HaveKey(keyID))
=======
    case TX_PUBKEY:
        keyID = CPubKey(vSolutions[0]).GetID();
        if (keystore.HaveKey(keyID))
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e
            return ISMINE_SPENDABLE;
        break;
    case TX_PUBKEYHASH:
        keyID = CKeyID(uint160(vSolutions[0]));
<<<<<<< HEAD
        if(keystore.HaveKey(keyID))
=======
        if (keystore.HaveKey(keyID))
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e
            return ISMINE_SPENDABLE;
        break;
    case TX_SCRIPTHASH: {
        CScriptID scriptID = CScriptID(uint160(vSolutions[0]));
        CScript subscript;
<<<<<<< HEAD
        if(keystore.GetCScript(scriptID, subscript)) {
            isminetype ret = IsMine(keystore, subscript);
            if(ret != ISMINE_NO)
=======
        if (keystore.GetCScript(scriptID, subscript)) {
            isminetype ret = IsMine(keystore, subscript);
            if (ret == ISMINE_SPENDABLE)
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e
                return ret;
        }
        break;
    }
    case TX_MULTISIG: {
        // Only consider transactions "mine" if we own ALL the
        // keys involved. multi-signature transactions that are
        // partially owned (somebody else has a key that can spend
        // them) enable spend-out-from-under-you attacks, especially
        // in shared-wallet situations.
        vector<valtype> keys(vSolutions.begin() + 1, vSolutions.begin() + vSolutions.size() - 1);
<<<<<<< HEAD
        if(HaveKeys(keys, keystore) == keys.size())
=======
        if (HaveKeys(keys, keystore) == keys.size())
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e
            return ISMINE_SPENDABLE;
        break;
    }
    }

<<<<<<< HEAD
    if(keystore.HaveWatchOnly(scriptPubKey))
        return ISMINE_WATCH_ONLY;
    if(keystore.HaveMultiSig(scriptPubKey))
        return ISMINE_MULTISIG;

=======
    if (keystore.HaveWatchOnly(scriptPubKey))
        return ISMINE_WATCH_ONLY;
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e
    return ISMINE_NO;
}
