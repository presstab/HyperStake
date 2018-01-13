// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "wallet.h"
#include "walletdb.h"
#include "bitcoinrpc.h"
#include "init.h"
#include "main.h"
#include "base58.h"
#include "coincontrol.h"

#include <sstream>
#include <boost/lexical_cast.hpp>

using namespace json_spirit;
using namespace std;
using namespace boost;

Value createchannel(const Array& params, bool fHelp)
{
    if (fHelp || params.size() != 1)
        throw runtime_error(
                "createchannel <name>\n"
                        "create a new hyperchain channel.");

    CPubKey keyChannel = pwalletMain->GenerateNewKey();
    CChannelID id = keyChannel.GetChannelID();
    Object ret;
    ret.push_back("channel_address", CBitcoinAddress(id).ToString());
}

Value subscribetochannel(const Array& params, bool fHelp)
{
    if (fHelp || params.size() != 1)
        throw runtime_error(
                "subscribetochannel <channel>\n"
                        "subscribe to a hyperchain channel.");
}

