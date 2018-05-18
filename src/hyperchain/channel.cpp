// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2018 The HyperStake developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "channel.h"

void CChannel::AddToWhitelist(const CKeyID &hashKey)
{
    setWhitelistedKeys.emplace(hashKey);
}

bool CChannel::Set(const CTxDestination &dest)
{
    //CChannelID is the 4th item in the boost::variant
    if (dest.which() != 3)
        return error("%s: Trying to set a TxDestination that is not a HyperChain channel", __func__);

    bool fSuccess = boost::apply_visitor(CBitcoinAddressVisitor(this), dest);
    if (fSuccess)
        this->channelID = boost::get<CChannelID>(dest);

    return fSuccess;
}
