#include <iostream>
#include <algorithm>

#include "votecharset.h"
#include "uint256.h"
#include "script.h"

static const std::string strCharCodes = "0123456789abdefghijklmnopqrstuvwxyz ,.?!";

//first 8 bits - uint8_t with character count
bool CSixBitChar::FromString(std::string str)
{
    //Already initialized
    if (!vch.empty())
        return false;

    //string too big
    if (str.size() > 82)
        return false;

    //Convert everything to lowercase
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    uint512 bits = 0;
    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        uint512 pos = strCharCodes.find(c);
        if (pos != std::string::npos) {
            //shift over 6 bits to make room for the new character and then add in the character
            bits >>= 6;
            bits |= pos << 506;
        } else {
            //Character does not exist in the charset
            return false;
        }
    }

    //The first 8 bits are a uint8_t representing the total amount of characters that follow
    bits >>= 8;
    uint512 nSize = str.size();
    nSize <<= 504;
    bits |= nSize;

    vch = ToByteVector(bits);
    return true;
}

std::string CSixBitChar::ToString() const
{
    // Rearrange characters to be in correct order
    uint512 n = 0;
    for (int i = 0; i < vch.size(); i++) {
        n >>= 8;
        n |= uint512(vch[i]) << 504;
    }
    uint512 FrontSixMask = 0x3f;
    FrontSixMask <<= 506;

    // Starts with 8 bit number indicating the number of characters
    uint512 nSize = n >> 504;
    n <<= 8 ;
    std::string strRet;
    for (int i = 0; i < nSize; i++) {
        //The character being extracted
        uint512 j = n >> 506;

        //Remove character
        n <<= 6;

        //Convert
        char c = strCharCodes.at(j.Get64());
        strRet += c;
    }

    std::reverse(strRet.begin(), strRet.end());
    return strRet;
}
