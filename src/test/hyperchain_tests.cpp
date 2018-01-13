#include <boost/test/unit_test.hpp>
#include <base58.h>

#include "script.h"
using namespace std;


BOOST_AUTO_TEST_SUITE(hyperchain_tests)

BOOST_AUTO_TEST_CASE(create_channel)
{
    CKey key;
    key.MakeNewKey(true);
    CPubKey keyChannel = key.GetPubKey()
    CChannelID id = keyChannel.GetChannelID();
    CBitcoinAddress address(id);
    cout << address.ToString();
}

BOOST_AUTO_TEST_SUITE_END()

