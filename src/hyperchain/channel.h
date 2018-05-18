// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2018 The HyperStake developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef HYPERSTAKE_CHANNEL_H
#define HYPERSTAKE_CHANNEL_H

#include <base58.h>
#include <serialize.h>

class CChannel : public CBitcoinAddress
{
private:
    std::set<CKeyID> setWhitelistedKeys;
    CChannelID channelID;
public:
    void AddToWhitelist(const CKeyID& hashKey);
    bool IsValid();
    CChannelID GetID() const { return channelID; };
    std::set<CKeyID> GetWhitelistedNodes() const { return setWhitelistedKeys; }
    bool Set(const CTxDestination& dest);
    bool Set(const CScriptID& id) = delete;
    bool Set(const CKeyID& id) = delete;

    IMPLEMENT_SERIALIZE
    (
        READWRITE(channelID);
        READWRITE(setWhitelistedKeys);
    )
};

#endif //HYPERSTAKE_CHANNEL_H
