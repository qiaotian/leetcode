#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

#define PB          push_back
#define MP(x,y)     make_pair(x,y)
#define CLR(x,y)    memset(x, y, sizeof(x))

#define FOR(i,l,r)   for(int i=l; i<=r; i++)
#define ROF(i,l,r)   for(int i=r; i>=l; i--)

#define RI(x)        cin>>x
#define RII(x,y)     RI(x),RI(y)
#define RIII(x,y,z)  RI(x),RI(y),RI(z)

int main() {
    string ipath = "";
    string opath = "";

    ifstream infile(ipath);
    ofstream outfile(opath);

    if(!infile || !outfile) {
        cout << "----> open files failed" << endl;
        return EXIT_FAILURE;
    }

    // Preprocess

    // Preprocess

    // Output



    infile.close();
    outfile.close();
    return 0;
}
