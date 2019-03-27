#include "SoftExample.C"
#include <fstream>

int main()
{
    std::ifstream fin("datalist.txt");
    std::string line;

    TChain *chain=new TChain("tout","");
    while(std::getline(fin,line))
    {
        TString tin=line;
	chain->Add(tin);
    }
    SoftExample* ana = new SoftExample(chain);
    ana->Loop();
    return 0;
}
