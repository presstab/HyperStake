#include <string>

class CSixBitChar
{
private:
    std::vector<unsigned char> vch;

public:
    bool FromString(std::string str);
    void SetVCH(std::vector<unsigned char> vchNew) { this->vch = vchNew; }
    std::string ToString() const;
    std::vector<unsigned char> const GetVCH() { return vch; }
};